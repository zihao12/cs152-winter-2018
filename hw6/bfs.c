#include <stdio.h>
#include <stdlib.h>

#include "iq.h"
#include "graph.h"

// enqueue unvisited neighbors
void eq_uv_nei(graph* g,unsigned int key, iq* q)
{
  il* nei = graph_neighbors(g,key);
  while(nei){
    if(g->vs[nei->n]->visited==0)
      enqueue(q,nei->n);
    nei = nei->next;
  }
  return;
} 

void mark_visited(graph* g, unsigned int key)
{
  g->vs[key]->visited = 1;
  return;
}


il *bfs(graph *g, unsigned int start_key)
{
  unsigned int num = g->n_vertices;
  if (start_key > num){
    fprintf(stderr,"start_key is not found in graph\n");
    exit(1);
  }

  mark_visited(g,start_key);
  iq* q = iq_new(); // create a new queue
  il* vis = il_singleton(start_key); // store the visited key
  eq_uv_nei(g,start_key,q);

  while(q->n != 0){
    int new_vis = dequeue(q);
    mark_visited(g,new_vis);
    vis = il_snoc(vis,new_vis);
    eq_uv_nei(g,new_vis,q); 
  }
  iq_free(q);
  return vis;
}



int main(int argc, char *argv[])
{
  graph *g;
  if (argc>1)
    g = sample_graph(atoi(argv[1]));
  else
    g = sample_graph(0);
  
  printf("--- graph ---\n");
  graph_show(g);
  putchar('\n');

  printf("--- breadth-first search ---\n");
  il *ns = bfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);
  
  return 0;
}
