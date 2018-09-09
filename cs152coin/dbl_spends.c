#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbl_spends.h"


dbl_spends_t* dbl_spends_new()
{
    dbl_spends_t* dbls = calloc(1,sizeof(dbl_spends_t));
    if (!dbls){
    	fprintf(stderr,"FAIL TO CALLOC DBL_SPENDS_T");
    	exit(1);
    }
    
    return dbls;
}

void dbl_spends_free(dbl_spends_t* ds)
{
	if(!ds){
		fprintf(stderr, "DBL_SPENDS BEING FREED IS EMPTY\n");
		exit(1);
	}
    dbl_t* h = ds->first;
    dbl_t* hh = h;
    while(h){
    	hh = h->next;
    	dbl_free(h);
    	h = hh;
    }
    free(ds);
}

void add_dbl_spend(const char* trans_id, const char* addr, dbl_spends_t* ds)
{
    dbl_t* new = dbl_new();
    new->id = strdup(trans_id);
    new->addr = strdup(addr);

    if (!ds->first){ // the dbl_spends is now empty
    	ds->first = new;
    	ds->last = new;
    	return;
    }

    ds->last->next = new;
    ds->last = new;
}

void dbl_spends_show(dbl_spends_t* ds, FILE* f)
{
    if (!ds){
    	fprintf(stderr, "DBL_SPENDS BEING SHOWED IS EMPTY\n");
    	exit(1);
    }

    dbl_t* t = ds->first;
    while(t){
    	fprintf(f,"TRANSACTION ID: %s\t ACCOUNT ADDRESS: %s\n",t->id,t->addr);
    	t = t->next;
    }
}

// =======================================================================
// Add any other functions you need in order to implement dbl_spends below
dbl_t* dbl_new()
{
	dbl_t* d = calloc(1,sizeof(dbl_t));
	if(!d){
		fprintf(stderr,"FAIL TO CALLOC DBL_T");
		exit(1);
	}
	return d;
}

void dbl_free(dbl_t* d)
{
	if (!d->id) free(d->id);
	if (!d->addr) free(d->addr);
	free(d);
}
// =======================================================================