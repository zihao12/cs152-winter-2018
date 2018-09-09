#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addr_bal.h"


addr_bal_t* addr_bal_new()
{
  addr_bal_t* ab = calloc(1,sizeof(addr_bal_t));
  if(!ab){
  	fprintf(stderr,"ADDR_BAL_T CANNOT BE calloc\n");
  	exit(1);
  }
  // do i need to allocate for different buckets?
/*  for (int i = 0; i < NUM_BUCKETS; i++){
  	ab->buckets[i] = calloc(1,sizeof(bucket));
  }
 */ return ab;
}

void addr_bal_free(addr_bal_t* ab)
{
    for (int i = 0; i < NUM_BUCKETS; i++){
		bucket* t = ab->buckets[i];
		bucket* tt;
		while(t){
			tt = t->next;
			bucket_free(t);
			t = tt;
		}
    }
}

int get_balance(const char* addr, double* out_bal, addr_bal_t* ab)
{
    unsigned long int hash = (ab->hash_func)(addr);
    unsigned long int index = hash % NUM_BUCKETS;
    bucket* t = ab->buckets[index];
    while(t){
    	if(hash==t->hash){
			*(out_bal) = t->bal;
			return 1;
    		}
    	t = t->next;
    }
    return 0;
}

void set_balance(const char* addr, double bal, addr_bal_t* ab)
{
    unsigned long int hash = (ab->hash_func)(addr);
    unsigned long int index = hash % NUM_BUCKETS;
    bucket* t = ab->buckets[index];
    bucket* tt = t;
    while(t){
    	tt = t;
    	if (hash == t->hash)
    		t->bal = bal;
    	t = t->next;
    }
    bucket* tail = bucket_new();
    tail->bal = bal;
    tail->addr = strdup(addr);
    tail->hash = hash;
    if (!tt){// this is the first bucket!
    	ab->buckets[index] = tail;
    	return;
    }// then tt should point to the last bucket
    tt->next = tail;
}


// =====================================================================
// Add any other functions you need in order to implement addr_bal below
bucket* bucket_new()
{
	bucket* b = calloc(1,sizeof(bucket));
	if (!b){
		fprintf(stderr,"BUCKET CANNOT BE CALLOC\n");
		exit(1);
	}
	return b;
}

void bucket_free(bucket* b)
{
	if (!b){
		fprintf(stderr, "CANNOT FREE NULL BUCKET*\n");
		exit(1);
	}
	free(b->addr);
	free(b);
}


// =====================================================================














