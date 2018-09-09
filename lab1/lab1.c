/*Zihao Wang
 * CS152,Winter 2018
 * Lab 1
 */
#include<stdio.h>
#include"lab1.h"

long int expt(int a, unsigned int n)
/* compute a^{n} using linear time exponentiation */
{
	if (n==0){
		return 1;
	} else {
		return a*expt(a,n-1);
		}
}


long int ss(int a, unsigned n)
/*do the a^{n} by using square as much as possible*/
{
	if (n==0){
		return 1;
	}else if (n % 2){ /*then n is odd*/
		return a*ss(a, n-1);
	}else {
		return ss(a,n/2)*ss(a, n/2);
	}
}

void show_binary(unsigned long int n)
/*display the binary representation of an unsigned long int*/
/*assume that unsigned long int has 8 bytes, therefore 64 bits*/
/*
{
	long int k;
	for (k=1;k<=64; ++k)
		if (n & ss(2,(64-k))){
			putchar('1');
		}else {
			putchar('0');
			}
} */

{
	if (n == 0){
		putchar('0');
	} else if(n == 1){
		putchar('1');
	} else if(n % 2){
		show_binary((n-1)/2);
		putchar('1');
	} else {
		show_binary(n/2);
		putchar('0');
		}
} 
	


