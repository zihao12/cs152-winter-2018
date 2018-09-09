#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

bucket* bucket_cons(const char* s, unsigned long int hash, bucket* prev_head)
{
	bucket* new = malloc(sizeof(bucket));
	new->string = strdup(s);
	new->hash = hash;
	new->next = prev_head;
	return new;
}

size_t bucket_size(bucket* b)
{
	bucket* t = b;
	size_t c = 0;
	while(t!=NULL){
		c++;
		t = t->next;	
	}
	return  c;
}

int bucket_contains(const char* s, unsigned long int hash, bucket* b)
{
	bucket* t = b;
	while(t!=NULL){
		if (hash==t->hash){
			return 1;
			}
		t=t->next;
	}
	return 0;
}

void bucket_show(bucket* b)
{
	bucket* t = b;
	while(t!=NULL){
		printf("(%s,%ld)\t",t->string, t->hash);
		t = t->next;
	}
	printf("\n");
}

void bucket_free(bucket* b)
{
	bucket* t = b;
	while(t!=NULL){
		free(t->string);
		bucket * next = t->next;
		free(t);
		t = next;
	}
}

