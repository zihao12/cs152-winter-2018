#include "graph.h"

int main(int argc, char *argv[]) 
{
  printf("=== testing graphs ===\n");
  char *labels[] = {"a","b","c","d","e"};
  graph_show(graph_new(5,labels));
  return 0;
}

