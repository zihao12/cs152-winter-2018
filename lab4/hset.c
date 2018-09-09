#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hset.h"

unsigned long int good_hash(const char* s)
{
	unsigned long int  result = 17;
	while(*s!='\0'){
		result = result*37+(*s);
		s++;
	}
	//free(t);
	return result;
}

unsigned long int bad_hash(const char* s)
{
	unsigned long int result = 0;
	while(*s!='\0'){
		result = 2*result;
		s++;
	}
	//free(t);
	return result;
}

hset* hset_new(unsigned long int(*hash_func)(const char*), size_t sz)
{
	hset* new = malloc(sizeof(hset));
	new->hash_func = hash_func;
	new->n_buckets = sz;
	new->buckets = malloc(sizeof(bucket*)*sz);
	return new;
}

size_t hset_size(hset* hs)
{
	bucket** tt = hs->buckets;
	size_t result =0;
	int c = hs->n_buckets;
	for (int i = 0; i < c; i++){
		result += bucket_size(tt[i]);
	}
	return result; 
}

double hset_load_factor(hset* hs)
{
	return (hset_size(hs)/hs->n_buckets);
}

size_t hset_max_bucket(hset* hs)
{
	bucket** tt = hs->buckets;
	size_t max;
	size_t c = hs->n_buckets;
	for(int i =0; i < c; i++){
		size_t cha =  bucket_size(tt[i]);
		if (max<cha)
			max = cha;
	}
	return max;
}

size_t hset_insert(const char* s, hset* hs)
{
	unsigned long int hash = (hs->hash_func)(s);
	int index = hash % hs->n_buckets;
	(hs->buckets)[index] = bucket_cons(s,hash,(hs->buckets)[index]);
	return bucket_size((hs->buckets)[index]);
}

int hset_contains(const char* s, hset* hs)
{
 //       exit(1);
        unsigned long int hash = (*(hs->hash_func))(s);
        int index = hash % hs->n_buckets;
        bucket** tt = hs->buckets + index;
	return bucket_contains(s,hash,*tt);
}

void hset_show(hset* hs)
{
	bucket** tt = hs->buckets;
        size_t l = hs->n_buckets;
        size_t c = l;
	for (int i=0; i <c; i++ ){
		printf("%d : ",i);
		bucket_show(tt[i]);
	}
}

void hset_free(hset* hs)
{
	size_t c = hs->n_buckets;
	bucket** tt = hs->buckets;
	for(int i =0; i< c; i++){
		bucket_free(tt[i]);
	}
	free(hs);
}
