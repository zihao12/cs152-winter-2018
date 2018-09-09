/* Zihao Wang
 * cmsc152 win 2018
 * Jan 20, 2018
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"hw2.h"

void evidence_xor()
{
	printf("===NOW testing xor:\n");
	printf("3&2 is %d\n", xor(3,2));
	printf("0&0 is %d\n", xor(0,0));
	printf("0&3 is %d\n", xor(0,3));
}

void evidence_show_array()
{
        printf("===NOW testing show_array:\n");
        int a[5] = {0,1,2,3,4};
        show_array(a, 5);
}

void evidence_add_to_all()
{
	printf("===NOW testing add_to_all:\nBefore it is :\n");
        int b[5] = {0,1,2,3,4};
	show_array(b,5);
	printf("After adding 7 to each of its elements, we have:\n");
	add_to_all(7,b,5);
	show_array(b,5);
}

void evidence_occurrences_of()
{	
	printf("===NOW testing occurrences_of:\n7 in the follwoing array is: :\n");
	int c[5] = {7,7,8,9,9};
	show_array(c,5);
	printf("%d\n", occurrences_of(7,c,5));
}

void evidence_any_odd()
{
	printf("===NOW testing any_odd:\nThe arrays is as below, and 1 stands for true while 0 stands for false\n");
	int d[5] = {1,2,3,4,5};
	show_array(d,5);
	printf("Any odd?:%d\n", any_odd(d,5));
	int e[5] = {2,4,6,8,10};
	show_array(e,5);
	printf("Any odd?:%d\n", any_odd(e,5));
}

void evidence_reverse()
{
	printf("===NOW testing reverse:\nThe follwoing arrays is:\n");
	int f[5] = {1,2,3,4,5};
	show_array(f,5);
	printf("swap!\n");
	reverse(f,5);
	show_array(f,5);
	printf("The following array is:\n");
	int g[6] = {1,2,3,4,5,6};
        show_array(g,6);
        printf("swap!\n");
        reverse(g,6);
        show_array(g,6);
}

void evidence_min()
{
	printf("===NOW testing min:\n");
	int h[5] = {3,2,1,3,5};
	show_array(h,5);
	printf("The smallest item is: %d\n", min(h,5));
	printf("Now testing min:\n");
        int i[6] = {8,7,1,3,1,4};
	show_array(i,6);
        printf("The smallest item is: %d\n", min(i,6));
/*	printf("Testing the case when the length is 0.\n");
	min(i,0);
	printf("Check if I have changed the array:\n");
	show_array(h,5);
*/
}

void evidence_max()
{
        printf("===NOW testing max:\n");
        int h[5] = {3,2,7,3,5};
        show_array(h,5);
        printf("The greatest item is: %d\n", max(h,5));
        printf("Now testing max:\n");
        int i[6] = {8,7,10,3,10,4};
        show_array(i,6);
        printf("The greatest item is: %d\n", max(i,6));
/*        printf("Testing the case when the length is 0.\n");
        max(i,0);
*/
}

void evidence_equal()
{
	printf("===NOW testing equal:\n");
	int eq11[5] = {1,2,3,4,5};
	int eq12[5] = {1,2,3,4,5};
	int eq21[6] = {1,2,3,4,5,6};
	int eq31[6] = {2,2,3,4,5,6};
	show_array(eq11,5);
	show_array(eq12,5);
	printf("Equal? %d\n",equal(eq11,5,eq12,5));
	show_array(eq11,5);
        show_array(eq21,6);
        printf("Equal? %d\n",equal(eq11,5,eq21,6));
	show_array(eq21,6);
        show_array(eq31,6);
        printf("Equal? %d\n",equal(eq21,6,eq31,6));
}

void evidence_int_binary()
{	
        printf("===NOW testing int_binary:\n");
	printf("32 expecting: 0000 0000 0000 0000 0000 0000 0010 0000\n");
	printf("..............");
	int_binary(32);
	printf("35 expecting: 0000 0000 0000 0000 0000 0000 0010 0011\n");
        printf("..............");
        int_binary(35);
	printf("1048576 expecting: 0000 0000 0001 0000 0000 0000 0000 0000\n");
        printf("...................");
        int_binary(1048576);
	printf("1048577 expecting: 0000 0000 0001 0000 0000 0000 0000 0001\n");
        printf("...................");
        int_binary(1048577);
}

void evidence_int_quaternary()
{
	printf("===NOW testing int_quaternary:\n");
	printf("32 expecting: 00 00 00 00 00 00 02 00\n");
	printf("..............");
	int_quaternary(32);
	printf("10086 expecting: 00 00 00 00 02 13 12 12\n");
        printf(".................");
        int_quaternary(10086);
}

int main()
{
	evidence_xor();
        evidence_show_array();
        evidence_add_to_all();
        evidence_occurrences_of();
        evidence_any_odd();
        evidence_reverse();
	evidence_min();
	evidence_max();
	evidence_equal();
	evidence_int_binary();
	evidence_int_quaternary();
        return 0;
}

