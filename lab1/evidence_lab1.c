/*Zihao Wang
 * CS152,Winter 2018
 * Lab 1
 */
#include<stdio.h>
#include"lab1.h"


/*evidence_expt: test expt*/
void evidence_expt()
{
	fprintf(stdout, "*** testing expt\n");
	fprintf(stdout,"- expecting 1 : %ld\n", expt(2,0));
	fprintf(stdout, "- expecting 8 : %ld\n", expt(2,3));
}

/* evidence_expt: test ss */
void evidence_ss()
{
    fprintf(stdout, "*** testing ss\n");
    fprintf(stdout, "-expecting 1 : %ld\n",ss(2,0));    
    fprintf(stdout, "expecting 8 : %ld\n",ss(2,3));
}

/* evidence_show_binary: test show_binary */
void evidence_show_binary()
{
    fprintf(stdout, "*** testing show_binary. The following numbers should be 128,127,1,0\n");
    show_binary(128);
    fprintf(stdout,"\n");
    show_binary(127);
    fprintf(stdout,"\n");
    show_binary(1);
    fprintf(stdout,"\n");
    show_binary(0);
    fprintf(stdout,"\n");
}

int main()
{ 
	fprintf(stdout, "CS152 Lab 1\n");
	evidence_expt();
	evidence_ss();
	evidence_show_binary();
	return 0;
}
