#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "deanon.h"
#include "cs152coin.h"
#include "hmap.h"


// ===================================================================
// Add any other functions you need in order to implement deanon below

// add to tail;
// only add new key
cluster_t* cluster_snoc(cluster_t* cs, char* new_key) 
{
    if (cs==NULL)
        return cluster_new(new_key);

    cluster_t* curr = cs;
    while(curr->next){
        if (!strcmp(new_key,curr->addr)){
            return cs;
        }
        curr = curr->next;
    }
    if(!strcmp(new_key,curr->addr))
        return cs;       
    curr->next = cluster_new(new_key);
    return cs;
}

neclu* neclu_new()
{
    neclu* new = calloc(1,sizeof(neclu));
    new->visited = 0;
    return new;
}

static void neclu_free(const char* key, neclu* nc)
{
    if (nc==NULL) return;
    cluster_free(nc->neighbors);
    free(nc);
}

cls* cls_new(cluster_t* new_cluster)
{
    cls* new = calloc(1,sizeof(cls));
    new->value = new_cluster;
    return new;
}

cls* cls_cons(cls* c,cluster_t* new_cluster)
{
    if (c==NULL) 
        return cls_new(new_cluster);
    cls* new_cls = cls_new(new_cluster);
    new_cls->next = c;
    return new_cls;
}

void cls_free(cls* cls)
{
    if (cls==NULL) return;
    cls_free(cls->next);
    cluster_free(cls->value);
    free(cls);
}
// ===================================================================


deanon_t* deanon_new()
{
    deanon_t* new = calloc(1,sizeof(deanon_t));
    new->g = hmap_new();
    return new;
}


void deanon_free(deanon_t* d)
{
    if (d==NULL) return;
    hmap_foreach(&neclu_free,d->g);
    hmap_free(d->g);
    cls_free(d->clusters);
    free(d);
}

void add_address(const char* addr, deanon_t* d)
{
    neclu* value = calloc(1,sizeof(neclu));
    if (hmap_put(addr,value,d->g))
        return;
    neclu_free(NULL,value);
    return;
}



void add_associations(dep_wd_t* trans_inputs[], unsigned int num_inputs, deanon_t* d)
{
    for (int i = 0; i < num_inputs; i++){
        char* curr_addr = trans_inputs[i]->addr;
        add_address(curr_addr,d); 
        neclu* add_to_value = (neclu*)hmap_get(curr_addr,d->g);
        for (int j = 0; j < num_inputs; j++){
            if (i!=j)
                add_to_value->neighbors = cluster_snoc(add_to_value->neighbors,trans_inputs[j]->addr);
        }          
    }
}

// ==============================================
// stack 

typedef struct {
  cluster_t* ns;
} chs;


chs *chs_new() 
{
  chs *s = (chs*)malloc(sizeof(chs));
  if (s==NULL) {
    fprintf(stderr,"chs_new: malloc failed\n");
    exit(1);
  }
  s->ns = NULL;
  return s;
}

// add to front
void push(chs *s, char* n)
{
  cluster_t* new = cluster_new(n);
  if (s==NULL)
    s->ns = new;
  new->next = s->ns;
  s->ns = new;
}

char* pop(chs *s)
{
  if (s->ns==NULL){
    fprintf(stderr, "cannot pop empty is\n");
    exit(1);
  }
  char* result = strdup(s->ns->addr);
  cluster_t* tmp = s->ns;
  s->ns = tmp->next;
  free(tmp->addr);
  free(tmp);
  return result;
}

void chs_free(chs*s)
{
  if (s!=NULL) {
    cluster_free(s->ns);
    free(s);
  }
}

// push unvisited neighbors
void push_uv_nei(hmap_t* g,cluster_t* c,chs* s)
{
    cluster_t* t = c;
    while(t!=NULL){
        neclu* curr = (neclu*)hmap_get(t->addr,g);
        if (curr->visited == 0){
            push(s,t->addr);
        }
        t = t->next;
    }
}
// =================================

cluster_t* get_cluster(const char* addr, deanon_t* d)
{
    neclu* curr = (neclu*)hmap_get(addr,d->g);
    if (curr == NULL) 
        return NULL; // starting point does not exist
    if (curr->cluster!=NULL) 
        return curr->cluster;

    cluster_t* result = cluster_new(addr);
    d->clusters = cls_cons(d->clusters,result);
    curr->cluster = result;
    curr->visited = 1;

    chs* s = chs_new(); 
    push_uv_nei(d->g,curr->neighbors,s);

    while(s->ns!=NULL){
        char* curr_addr = pop(s);
        curr = (neclu*)hmap_get(curr_addr,d->g);
        curr->cluster = result;
        curr->visited = 1;
        result = cluster_snoc(result,curr_addr);
        free(curr_addr);// almost forget to free!
        push_uv_nei(d->g,curr->neighbors,s);
    }
    chs_free(s);
    return result;
}

cluster_t* cluster_new(const char* addr)
{
    cluster_t* new = calloc(1,sizeof(cluster_t));
    new->addr = strdup(addr);
    return new;
}



void cluster_free(cluster_t* c)
{
   if (c==NULL) return;
    cluster_free(c->next);
    free(c->addr); 
    free(c);
}


