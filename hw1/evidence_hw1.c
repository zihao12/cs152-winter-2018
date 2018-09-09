/*Zihao Wang
 * CS152,Winter 2018
 * Homework 1
 */
#include<stdio.h>
#include"hw1.h"

/*evidence function for valid_room*/
void evidence_valid_room()
{
	fprintf(stdout,"Testing valid_room:\n ");
	fprintf(stdout,"ROOM 336 is expecting 1: %d\n",valid_room(336));
	fprintf(stdout,"ROOM 1336 is expecting 0: %d\n", valid_room(1336));
	fprintf(stdout,"ROOM 5036 is expecting 0: %d\n", valid_room(5036));
	fprintf(stdout,"ROOM 321 is expecting 1: %d\n", valid_room(321));
}

void evidence_rotary_pulses_r()
{
	fprintf(stdout,"Testing rotary_pulses_r:\n");
	fprintf(stdout,"Number 7737021234 is expecting 46: %d\n",rotary_pulses_r(7737021234));
	fprintf(stdout,"Number 3123940229 is expecting 45: %d\n", rotary_pulses_r(3123940229));
}

void evidence_rotary_pulses_i()
{
	fprintf(stdout,"Testing rotary_pulses_i:\n");
	fprintf(stdout,"Number 7737021234 is expecting 46: %d\n",rotary_pulses_i(7737021234));
	fprintf(stdout,"Number 3123940229 is expecting 45: %d\n",rotary_pulses_i(3123940229));
	fprintf(stdout,"Number 9 is expecting 9: %d\n",rotary_pulses_i(9));
	fprintf(stdout,"Number 19 is expecting 10: %d\n",rotary_pulses_i(19));
	fprintf(stdout,"Number 101 is expecting 12: %d\n",rotary_pulses_i(101));
}

void evidence_nth_harmonic()
{
	fprintf(stdout, "Testing nth_harmonic:\n");
	fprintf(stdout, "N=0 is expecting 0: %f\n",nth_harmonic(0));
	fprintf(stdout, "N=1 is expecting 1: %f\n",nth_harmonic(1));
	fprintf(stdout, "N=2 is expecting 1.5: %f\n",nth_harmonic(2));
	fprintf(stdout, "N=3 is expecting 1.8333: %f\n",nth_harmonic(3));
	fprintf(stdout, "N=4 is expecting 2.0833: %f\n",nth_harmonic(4));
}


void evidence_least_ge_harmonic()
{
	fprintf(stdout, "Testing least_ge_harmonic:\n");
	fprintf(stdout,"x=1.01 expecting 2 : %d\n", least_ge_harmonic(1.010000));
	fprintf(stdout,"x=1.51 expecting 3 : %d\n", least_ge_harmonic(1.510000));
	fprintf(stdout,"x=2 expecting 4 : %d\n", least_ge_harmonic(2.000000));
	fprintf(stdout,"x=3 expecting 11 : %d\n", least_ge_harmonic(3.000000));
}
	
void evidence_checkerboard()
{
	fprintf(stdout,"Testing checkboard:\n");
	checkerboard(3,4,'X','-');
	fprintf(stdout,"%c",'\n');
}



int main()
{ 
        fprintf(stdout, "CS152 Homework 1\n");
	evidence_valid_room();
	evidence_rotary_pulses_r();
	evidence_rotary_pulses_i();
	evidence_nth_harmonic();
	evidence_least_ge_harmonic();
	evidence_checkerboard();
	return 0;
}
