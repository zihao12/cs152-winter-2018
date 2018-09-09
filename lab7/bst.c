#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst* bst_singleton(vcard* vc)
{
  bst* s = calloc(1,sizeof(bst));
  s->vc = vc;
  return s;
}

int bst_insert(bst* t, vcard* vc)
{
  if(!t){
    fprintf(stderr, _bst_todo_format, "bst_insert");
    exit(1);
  }
  int cmp = strcmp(vc->cnet,t->vc->cnet);
  if (!cmp)
    return 0;

  

  if (cmp > 0){// insert to the right
    if(!t->rsub){ // at the end of r
      bst* new = bst_singleton(vc);
      t->rsub = new;
      return 1;
    }
    return bst_insert(t->rsub,vc);
  }  

  
  if(!t->lsub){ // at the end of l
    bst* new = bst_singleton(vc);
    t->lsub = new;
    return 1;
  }
  return bst_insert(t->lsub,vc);
  

  
}

unsigned int bst_num_entries(bst* t)
{
  if(!t) return 0;
  return 1+bst_num_entries(t->rsub) + bst_num_entries(t->lsub);
}

unsigned int bst_height(bst* t)
{
  if (!t) return 0;
  unsigned long int lh = bst_height(t->lsub);
  unsigned long int rh = bst_height(t->rsub);

  if (lh <= rh)
    return 1 + rh;
  return 1+lh;
}

vcard* bst_search(bst* t, const char* cnet, int* n_comparisons)
{
  // how to initialize n_comparisons?
 // *n_comparisons = 0;
  if(!t) return NULL;

  (*n_comparisons)++;

  if(!strcmp(t->vc->cnet,cnet)){
    return t->vc;
  }
  if (strcmp(t->vc->cnet,cnet) < 0) // to the right
    return bst_search(t->rsub,cnet,n_comparisons);
  return bst_search(t->lsub,cnet,n_comparisons);
  
}

unsigned int bst_prefix_show(FILE* f, bst* t, const char* prefix)
{
  if (!t){
  //  fprintf(f,"cannot show empty bst\n");
    return 0;
  }
  unsigned long int c = 0;
  int cmp = strncmp(prefix, t->vc->cnet,strlen(prefix));
  if (!cmp){
    c = 1 + bst_prefix_show(f,t->lsub,prefix);
    fprintf(f,"%s\n",t->vc->cnet);
    c += bst_prefix_show(f,t->rsub,prefix);
    return c;
  }

  if (cmp>0)
    return bst_prefix_show(f,t->rsub,prefix);
  return bst_prefix_show(f,t->lsub,prefix);
}

void bst_free(bst* t)
{
  if (!t) return;
  vcard_free(t->vc);
//  if (!t->rsub)
    bst_free(t->rsub);
//  if (!t->lsub)
    bst_free(t->lsub);
  free(t);
}
