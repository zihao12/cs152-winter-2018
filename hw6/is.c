#include "is.h"

is *is_new() 
{
  is *s = (is*)malloc(sizeof(is));
  if (s==NULL) {
    fprintf(stderr,"is_new: malloc failed\n");
    exit(1);
  }
  s->ns = NULL;
  return s;
}

// add to front
void push(is *s, int n)
{/*
  il* new = il_singleton(n);
  new->next = s->ns;
  s->ns = new;
*/
  s->ns = il_cons(n,s->ns);
}

int empty(is* s)
{
  return s->ns==NULL;
}



int pop(is *s)
{
  if (empty(s)){
    fprintf(stderr, "cannot pop empty is\n");
    exit(1);
  }

  int result = s->ns->n;
  il* tmp = s->ns;
  s->ns = tmp->next;
  free(tmp);
  return result;
}

void is_show(is *s)
{  
  printf("begin stack (%d items, top shown at left)\n",il_len(s->ns));
  printf("  ");
  il_show(s->ns);
  printf("end stack\n");
}

void is_free(is*s)
{
  if (s!=NULL) {
    il_free(s->ns);
    free(s);
  }
}
