#include <stdio.h>
#include <stdlib.h>

#include "is.h"
#include "graph.h"

void push_uv_nei(graph* g, unsigned int key, is* s)
{
  il* nei = graph_neighbors(g,key);
  while(nei){
    if(g->vs[nei->n]->visited==0)
      push(s,nei->n);
    nei = nei->next;
  }
  return;
}

il *dfs(graph *g, unsigned int start_key)
{
  unsigned int num = g->n_vertices;
  if (start_key > num){
    fprintf(stderr,"start_key is not found in graph\n");
    exit(1);
  }
  g->vs[start_key]->visited = 1;
  is* s = is_new();
  il* vis = il_singleton(start_key);
  push_uv_nei(g,start_key,s);

  while(s->ns != NULL){
    int new_vis = pop(s);
    g->vs[new_vis]->visited = 1;
    vis = il_snoc(vis,new_vis);
    push_uv_nei(g,new_vis,s);
  }  
  is_free(s);
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

  printf("--- depth-first search ---\n");
  il *ns = dfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  il_free(ns);
  graph_free(g);

  return 0;
}
