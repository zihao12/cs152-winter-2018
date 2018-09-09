#ifndef _DBL_SPENDS_H
#define _DBL_SPENDS_H

#include <stdio.h>

// ========================================================================
// Declare any other structs you need in order to implement dbl_spends here
typedef struct dbl_t{
	char* id;
	char* addr;
	struct dbl_t* next;
} dbl_t;
// ========================================================================


typedef struct dbl_spends {
    // ===================================
    // Fill in with the appropriate fields
    dbl_t* first;
    dbl_t* last;
    // ===================================
    
} dbl_spends_t;


// Returns a new heap-allocated data structure for tracking double spends.
dbl_spends_t* dbl_spends_new();

// Frees a heap-allocated data structure for tracking double spends.
void dbl_spends_free(dbl_spends_t* ds);

// Add a double spend entry consisting of the id transaction of the transaction
// containing the double spend and the address whose balance went negative.
void add_dbl_spend(const char* trans_id, const char* addr, dbl_spends_t* ds);

// Print all of the double spend entries IN THE ORDER THEY APPEAR IN THE BLOCKCHAIN
// to the file f. Output should be of the form:
// <trans_id>, <addr>
// <trans_id>, <addr>
// ...
void dbl_spends_show(dbl_spends_t* ds, FILE* f);

// ===========================================================================
// Declare any other functions you need in order to implement dbl_spends below

// new dbl_t
dbl_t* dbl_new();

void dbl_free(dbl_t* d);
// ===========================================================================



#endif