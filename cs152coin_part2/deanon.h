#ifndef _DEANON_H
#define _DEANON_H

#include "hmap.h"

typedef struct dep_wd dep_wd_t;
typedef struct hmap hmap_t;


// A linked list representation of a cluster of related addresses
typedef struct cluster {
    char* addr;
    struct cluster* next;
} cluster_t;
// ====================================================================
// Declare any other structs you need in order to implement deanon here

// store clusters we find in get cluster
typedef struct cluster_stack cls;

struct cluster_stack{
	cluster_t* value;
	cls* next;
};

// this struct contains neighbor and cluster number 
typedef struct neclu neclu; 
struct neclu{
	cluster_t* neighbors;
	cluster_t* cluster; 
	int visited;
};




// ====================================================================

typedef struct deanon {
    // ===================================
    // Fill in with the appropriate fields
	unsigned long int n_cluster;
	hmap_t* g;
	cls* clusters;
    // ===================================
} deanon_t;


// Returns a new heap-allocated data structure used to facilitate deanonimization
deanon_t* deanon_new();

// Frees a heap-allocated deanonimization data structure
void deanon_free(deanon_t* d);

// Adds an address addr to the deanonimization data structure
void add_address(const char* addr, deanon_t* d);

// Record that all of the supplied transaction inputs are associated with each other.
void add_associations(dep_wd_t* trans_inputs[], unsigned int num_inputs, deanon_t* d);

// Returns the cluster of addresses associated with the supplied address.
// A cluster is a linked list of cluster elements.
//
// IMPORTANT: If the supplied address belongs to a cluster that has never been returned before,
// get_cluster is allowed to take O(a + b) time where a is the total number of addresses
// and b is the number of pairs of addresses that have at some point appeared together as
// inputs to a transaction. 
//
// On the other hand, if the supplied address belongs to a cluster that has been returned before,
// then get_cluster should take constant -- i.e., O(1) -- time on average.
cluster_t* get_cluster(const char* addr, deanon_t* d);

// Returns a new heap-allocated cluster element that stores the supplied address.
// Makes a deep copy of the address string.
cluster_t* cluster_new(const char* addr);

// Frees a heap-allocated cluster element
void cluster_free(cluster_t* c);


// =======================================================================
// Declare any other functions you need in order to implement deanon below
// =======================================================================



#endif