#ifndef _ADDR_BAL_H
#define _ADDR_BAL_H

#define NUM_BUCKETS 100

// ======================================================================
// Declare any other structs you need in order to implement addr_bal here
typedef struct bucket {
	char* addr;
	double bal;
	unsigned long int hash;
	struct bucket* next;
} bucket;
// ======================================================================


typedef struct addr_bal {
    // ===================================
    // Fill in with the appropriate fields
	unsigned long int (*hash_func) (const char*);
	bucket* buckets[NUM_BUCKETS];
    // ===================================
    
} addr_bal_t;


// Returns a new heap-allocated data structure for tracking the balance of each address.
addr_bal_t* addr_bal_new();

// Frees a heap-allocated data structure for tracking the balance of each address.
void addr_bal_free(addr_bal_t* ab);

// Get the balance associated with address addr and store the result in the double
// pointed to by out_bal.
// Returns 0 if the address couldn't be found and nonzero otherwise.
int get_balance(const char* addr, double* out_bal, addr_bal_t* ab);

// Set the balance associated with address addr to bal.
void set_balance(const char* addr, double bal, addr_bal_t* ab);


// =========================================================================
// Declare any other functions you need in order to implement addr_bal below
bucket* bucket_new();

void bucket_free(bucket* b);



// =========================================================================



#endif /* _HSET_H */
