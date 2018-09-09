#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cs152coin.h"
#include <assert.h>
#include "parser.h"


// debugger
void null(void* sth)
{
	printf("******%s******\n",(!sth)? "NULL" : "NOT EMPTY");
}

// This function is already implemented as an example of how to use the parser
dep_wd_t* parse_dep_wd()
{
    char* s = NULL;
    double d = 0;
    if (!read_string(&s)) return NULL;
    dep_wd_type type;
    if (!strcmp(s, "DEPOSIT")) {
        type = DEPOSIT;
    } else if (!strcmp(s, "WITHDRAWAL")) {
        type = WITHDRAWAL;
    } else {
        return NULL;
    }
    next_token();
    
    dep_wd_t* dw = calloc(1, sizeof(dep_wd_t));
    if (dw == NULL) {
        return NULL;
    }
    dw->type = type;
    
    if (!read_string(&s)) {
        dep_wd_free(dw);
        return NULL;
    }
    dw->addr = strdup(s);
    next_token();
    
    if (!read_double(&d)) {
        dep_wd_free(dw);
        return NULL;
    }
    dw->amount = d;
    next_token();
    
    return dw;
}

trans_t* parse_trans()
{
	char* s = NULL;
    int num = 0;
	
	if (!read_string(&s)) return NULL;
	if (!strcmp(s,"BEGIN_TRANSACTION")) 
		next_token();
	else{
		next_token();
		return NULL; //if reaching last transaction, return NULL	
	}

	trans_t* trans = calloc(1,sizeof(trans_t));
	
	if (!read_string(&s)){
		trans_free(trans);
		return NULL;
	}
	trans->id = strdup(s);
	next_token();
//	printf("TRANS ID?:%s\n",trans->id);

	if (!read_string(&s)){
		trans_free(trans);
		return NULL;
	}
//	printf("BEGIN_INPUTS?%s\n",s);
	next_token();	

	if(!read_string(&s)){ // reading the first WITHDRAWAL NOW
		trans_free(trans);
		return NULL;
	}
	dep_wd_t* tmp;
	while ((tmp=parse_dep_wd())){// tmp is not NULL
		// for now assume only WITHDRAWAL is possible here
		trans->inputs[num] = tmp;
//		printf("CURRENT TRANSACTION ADDR: %s\n",trans->inputs[num]->addr);
		num++;
	}
//	printf("NUM_INPUTS?%d\n",num);
// show_trans??
	trans->num_inputs = num;
	
	if (!read_string(&s)){
		trans_free(trans);
		return NULL;
	}
//	printf("END_INPUTS?%s\n",s);		
	next_token();
	
	trans->output = parse_dep_wd();
// show_trans?

	if (!read_string(&s)){
		trans_free(trans);
		return NULL;
	}
//	printf("END_TRANSACTIONS?%s\n");			
	next_token();
	trans_t* next = parse_trans();
	trans->next = next; // works whether it is NULL 
	return trans;
}

block_t* parse_block()
{
	char* s = NULL;
    if (!read_string(&s)) return NULL;
	if (!strcmp(s,"BEGIN_BLOCK")){
		next_token();
	}
	else{
		next_token();
		return NULL;
	}
	
	block_t* block = calloc(1,sizeof(block_t));
//miner
	block->miner = parse_dep_wd();
//trans
	trans_t * trans= parse_trans();// this actually stores the list of trans in heap
	block->trans = trans;
//next
//	next_token(); // this jumps over END_BLOCK THIS BUG TAKES AN HOUR!!!	
	block->next = parse_block();
	return block;
}
	

blockchain_t* parse_blockchain()
{
	blockchain_t* blockchain = calloc(1,sizeof(blockchain_t));
	block_t* blocks = parse_block();
	blockchain->blocks = blocks;
	return blockchain;
}
	
	
		
		


void dep_wd_free(dep_wd_t* dw)
{
	if (dw==NULL){
		printf("dep_wd_free: NOTHING TO FREE\n");
		return;
	}
	if (dw->addr != NULL)
		free(dw->addr);
	free(dw);	
}

void trans_free(trans_t* trans)
{
	if(trans == NULL){
		printf("trans_free: NOTHING TO FREE\n");
		return;
	}
	if (trans->id != NULL)      
		free(trans->id);
	for (int i=0; i < trans->num_inputs; i++)
		dep_wd_free(trans->inputs[i]);
	
	if(trans->output !=NULL)
		dep_wd_free(trans->output);
	// do not free the next trans; 
	
	free(trans);
}

void block_free(block_t* block)
{
	dep_wd_free(block->miner);
// free the list of transactions
	trans_t* tmp1 = block->trans;
	trans_t* tmp2 = tmp1;
	while(tmp1){
		tmp2 = tmp1->next;
		trans_free(tmp1);
		tmp1 = tmp2;	
	}
	free(block);	
}

void blockchain_free(blockchain_t* bc)
{
	block_t* t = bc->blocks;
	block_t* tt = bc->blocks;
	while(t){
		tt = tt->next;
		block_free(t);
		t = tt;
	}
	addr_bal_free(bc->addr_bal);
	free(bc);
}


unsigned long int good_hash(const char* s)
{
//	return strtoul(s, NULL, 16);
	// take the first 4 digits
	unsigned long int result = 17;
	for (int i = 0; i < 3; i++){
		result = result*37+s[i];
	}
	return result;
}

// update balance;
// return  balance of the account after the transaction
// only a double spends when WITHDRAWAL && return negative
double bal_dbl_update (dep_wd_t* dw, addr_bal_t* ab)
{	
	int sign = 1;
	switch(dw->type){
		case DEPOSIT:
			break;
		case WITHDRAWAL:
			sign = -1;
			break;
		default:
			fprintf(stderr,"wrong type in dw\n");
			exit(1);
	}

	unsigned long int hash = (ab->hash_func)(dw->addr);
	unsigned long int index = hash % NUM_BUCKETS;
	bucket* t = ab->buckets[index];
	bucket* tt = t;
	while(t){
		tt = t;
		if(hash==t->hash){
			if(!strcmp(t->addr,dw->addr)){ // find the account
				t->bal += sign * dw->amount;
				return t->bal;
			}
		}
		t = t->next;
	}

	// now add tail to ab
	bucket* tail = bucket_new();
	tail->bal = sign * dw->amount;
	tail->hash = hash;
	tail->addr = strdup(dw->addr);

	if(!tt){// first bucket!
		ab->buckets[index] = tail;
		return tail->bal;
	}
	tt->next = tail;
	return tail->bal;
}


void compute_stats(blockchain_t* bc)
{
	bc->addr_bal = addr_bal_new();
	bc->addr_bal->hash_func = &good_hash;
	bc->dbl_spends = dbl_spends_new();

    unsigned long int n_b = 0;
    unsigned long int n_t = 0;
    double s_t = 0; // sum of all transactions

   	block_t* b = bc->blocks; // track blocks
    trans_t* t;
    addr_bal_t* ab = bc->addr_bal;
    dbl_spends_t* ds = bc->dbl_spends;



    while(b){// loop over block

    	t = b->trans;
    	n_b++;

    	double trash = bal_dbl_update(b->miner,ab);
    	while(t){
    		n_t++;
    		s_t += t->output->amount;
    		trash = bal_dbl_update(t->output,ab);

    		for (int i = 0; i < t->num_inputs; i++){ 
    		//	int dbl_flag = 0;
    			if (bal_dbl_update(t->inputs[i],ab) < 0)
    			//	dbl_flag = 1;
    				add_dbl_spend(t->id,t->inputs[i]->addr,ds);
    		}

    		t = t->next;
    	}

    	b = b->next;
    }
    bc->num_blocks = n_b;
    bc->num_trans = n_t;
    bc->avg_trans_value = s_t/n_t;
}






static void print_stats(blockchain_t* bc)
{
    if (bc == NULL) return;
    
    printf("Number of blocks: %lu\n", bc->num_blocks);
    printf("Number of transactions: %lu\n", bc->num_trans);
    printf("Average transaction value: %lf\n", bc->avg_trans_value);
    printf("\n");
    
    printf("Double spends:\n");
   dbl_spends_show(bc->dbl_spends, stdout);
    printf("\n");
}


int main(int argc, char* argv[])
{
    init_parser();
    blockchain_t* bc = parse_blockchain();
    compute_stats(bc);

   print_stats(bc);

    for (int i = 1; i < argc; i++) {
        double bal = 0;
        if (get_balance(argv[i], &bal, bc->addr_bal)) {
            printf("Balance for address %s: %lf\n", argv[i], bal);
        } else {
            printf("Address %s: not found\n", argv[i]);
        }
    }



    blockchain_free(bc);
}



