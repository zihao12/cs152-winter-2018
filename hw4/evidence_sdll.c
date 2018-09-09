#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sdll.h"
void node_free(node* nd);


// first, write a con function to generate lists
sdll* cons(char* val, sdll* old)
{
        node* new = malloc(sizeof(node));
        new->value = strdup(val);
        new->prev = NULL;
        new->next = old->first;
        new->next->prev = new;
        old->first = new;
        return old;
}

sdll* ini(char* a, char* b)
{
        sdll* ini = list_new();
        node* ini_f = malloc(sizeof(node));
        node* ini_e = malloc(sizeof(node));
        ini_f->value = strdup(a);
        ini_f->prev=NULL;
        ini_f->next=ini_e;
        ini_e->value = strdup(b);
        ini_e->next=NULL;
        ini_e->prev=ini_f;
        ini->first = ini_f;
        ini->last = ini_e;
        return ini;
}

// write a function to see if the sdll* is a null
void is_null(sdll* list)
{
	if (list==NULL)
		printf("This is an empty list\n");
	else 
		printf("This is not an empty list\n");
}

node* test_node(char *a)
{
	node* test = malloc(sizeof(node));
	test->value = strdup(a);
	test->prev=NULL;	
	test->next=NULL;
	return test;
}

void evidence_node_show()
{
	printf("Now testing node_show:\n");
	node* test=test_node("a");
	node_show(stdout,test);
	node_free(test);
	printf("\n");
}

void evidence_list_show()
{
	printf("Now testing list_show:\n");
	sdll* test = ini("a","b");
	test = cons("c",test);
	list_show(stdout,test,' ');	
	printf("\n");
	test = cons("d",test);
	list_show(stdout,test,' ');	
	printf("\n");
	list_free(test);	
}

void evidence_find_first()
{
	printf("Now testing find_first:\n");
	sdll* test = ini("a","c");
	test = cons("b",test);
//
	printf("find the first a in\n");
	list_show(stdout,test,' ');
	printf("\n");
	node_show(stdout,find_first(test,"a"));
	printf("\n");
//
	test = cons("a",test);
	printf("find the first a in\n");
	list_show(stdout,test,' ');
	printf("\n");
	node_show(stdout,find_first(test,"a"));
	printf("\n");
	node_show(stdout, test->first);
	printf("\n");
	list_free(test);	
}

void evidence_get_something()
{
	printf("Now testing get_first and get_last:\n");
        sdll* test = ini("a","b");
        test = cons("a",(cons("f",test)));
	list_show(stdout,test,' ');
	printf("\n");
	node_show(stdout,get_first(test));
	printf("\n");
	node_show(stdout,get_last(test));
	printf("\n");
	printf("Now testing get_next and get_previous:\n");
	list_show(stdout,test,' ');
	printf("\nexpecting to see f and a:\n");
	node_show(stdout,get_next(test,get_at_index(test,0)));
	printf("\n");
	node_show(stdout,get_previous(test,get_at_index(test,3)));
	printf("\n");
	list_free(test);	
}
	
	

void evidence_get_at_index()
{
	printf("Now testing get_at_index:\n");
	sdll* test = ini("a","b");
	test = cons("a",(cons("f",test)));
	printf("The 0th element and 3th element in:\n");
	list_show(stdout,test,' ');
	printf("\nare:\n");
	node_show(stdout,get_at_index(test,0));
	printf("\tand\t");
	node_show(stdout,get_at_index(test,3));
	printf("\n");
	list_free(test);	
}
void evidence_insert_before()
{
	printf("Now testing insert_before:\n");
        sdll* test = ini("a","b");
	printf("inserting g before the first a:\n");
	list_show(stdout,test,' ');
	printf("\n");
	list_show(stdout,test=insert_before(test,"a","g"),' ');
	printf("\n");
	printf("inserting h before the first a:\n");
        list_show(stdout,test,' ');
        printf("\n");
	list_show(stdout,insert_before(test,"a","h"),' ');
        printf("\n");
	list_free(test);	
}

void evidence_insert_after()
{
        printf("Now testing insert_after:\n");
        sdll* test = ini("a","b");
        printf("inserting g after the first a:\n");
        list_show(stdout,test,' ');
        printf("\n");
        list_show(stdout,test=insert_after(test,"a","g"),' ');
        printf("\n");
        printf("inserting h after the first b:\n");
        list_show(stdout,test,' ');
        printf("\n");
        list_show(stdout,insert_after(test,"b","h"),' ');
        printf("\n");
//	printf("inserting x after the first y:\n");
//        list_show(stdout,test,' ');    
//        printf("\n");
//        list_show(stdout,insert_after(test,"y","x"),' ');
//        printf("\n");
	list_free(test);	
}


void evidence_insert_at_index()
{
        printf("Now testing insert_at_index:\n");
        sdll* test = cons("x",ini("a","b"));
        printf("inserting g at index 2:\n");
        list_show(stdout,test,' ');
        printf("\n");
        list_show(stdout,insert_at_index(test,2,"g"),' ');
        printf("\n");
        printf("inserting h before at index 0:\n");
        list_show(stdout,test,' ');
        printf("\n");
        list_show(stdout,insert_at_index(test,0,"h"),' ');
        printf("\n");
	list_free(test);	
}

void evidence_remove_first()
{
        printf("Now testing remove_first:\n");
        sdll* test1 = cons("a",cons("x",ini("a","b")));
        sdll* test2 = cons("a",cons("x",ini("a","b")));
        sdll* test3 = cons("a",cons("x",ini("a","b")));
        printf("removing the first a:\n");
	list_show(stdout,test1,' ');
	printf("\n");
	list_show(stdout,remove_first(test1,"a"),' ');
	printf("\n");
	printf("removing the first b:\n");
        list_show(stdout,test2,' ');
        printf("\n");
        list_show(stdout,remove_first(test2,"b"),' ');
        printf("\n");
	printf("removing the first x:\n");
        list_show(stdout,test3,' ');
        printf("\n");
        list_show(stdout,remove_first(test3,"x"),' ');
        printf("\n");
	list_free(test1);	
	list_free(test2);	
	list_free(test3);	
}
void evidence_remove_all()
{
        printf("Now testing remove_all:\n");
        sdll* test1 = cons("a",cons("x",ini("a","b")));
        printf("removing all a:\n");
        list_show(stdout,test1,' ');
        printf("\n");
        list_show(stdout,remove_all(test1,"a"),' ');
        printf("\n");
        printf("removing all b:\n");
        list_show(stdout,test1,' ');
        printf("\n");
        list_show(stdout,remove_all(test1,"b"),' ');
        printf("\n");
//        printf("removing all x:\n");
//        list_show(stdout,test1,' ');
//        printf("\n");
//	is_null(remove_all(test1,"x"));
	list_free(test1);	
}



int main()
{
	evidence_node_show();
	evidence_list_show();
	evidence_find_first();
	evidence_get_something();
	evidence_get_at_index();
	evidence_insert_before();
	evidence_insert_after();
	evidence_insert_at_index();
	evidence_remove_first();
	evidence_remove_all();
	return 0;
}
		
