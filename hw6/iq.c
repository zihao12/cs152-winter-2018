#include "iq.h"

iq *iq_new()
{
  iq *q = (iq*)malloc(sizeof(iq));
  if (q==NULL) {
    fprintf(stderr,"iq_new: malloc failed\n");
    exit(1);
  }
  q->n = 0;
  q->front = q->back = NULL;
  return q;
}

void enqueue(iq *q, int n)
{
  if (q==NULL) {
    fprintf(stderr,"enqueue: cannot enqueue to empty queue\n");
    exit(1);
  }

  il* new = il_singleton(n);

  if(q->n==0){ // new queue
    q->front = q->back = new;
    (q->n)++;
    return;
  }
  

  // no need to use il_snoc
  q->back->next = new;
  q->back = new;
  (q->n)++;
  return;
}

int dequeue(iq *q)
{
  if (!q || !(q->front)){ // empty queue
    fprintf(stderr,"dequeue:cannot dequeue empty queue\n");
    exit(1);
  }

  if (q->n==1){
    int val = q->front->n;
    il_free(q->front);
    q->front = q->back= NULL;
    q->n = 0;
    return val;
  }

  (q->n)--;
  il* tmp = q->front;
  int val = tmp->n;
  q->front = tmp->next;
 

  free(tmp); 
  return val;
}

void iq_show(iq *q)
{
  printf("begin queue (%d items, front shown at left))\n",q->n);
  printf("  ");
  il_show(q->front);
  printf("end queue\n");
}

void iq_free(iq *q)
{
  if (q!=NULL) {
    il_free(q->front);
    free(q);
  }
}
