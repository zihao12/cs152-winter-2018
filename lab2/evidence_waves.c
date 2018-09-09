#include<stdio.h>
#include<math.h>
#include"waves.h"

void evidence_dist(){
	fprintf(stdout,"TESTING dist:\n");
	fprintf(stdout,"|(3,4)-(0,0)| is expecting 5: %f\n", dist(3,4,0,0));
	fprintf(stdout,"|(5,12)-(0,0)| is expecting 13: %f\n", dist(5,12,0,0));
}
int main(){
	evidence_dist();
}

