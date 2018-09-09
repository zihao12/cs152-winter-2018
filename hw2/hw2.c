/* Zihao Wang
 * cmsc152 win 2018
 * Jan 20, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hw2.h"
/*Problem 0*/
int xor(int b1, int b2)
{
	int eval1, eval2;
	if (b1) eval1 =1; 
	else eval1 = 0;
	if (b2) eval2 =1;
	else eval2 =0;
	if (eval1-eval2) return 1;
	else return 0;
}



/*Problem 1*/
void show_array(int *a, unsigned int len)
{
	for (int i = 0; i < len; i++){
		fprintf(stdout,"a[%d] %d\n", i,*(a+i));
		}
}

/*Problem 2*/

void add_to_all(int n, int *a, unsigned int len)
{
	for (int i = 0; i < len; i++){
		*(a+i) = n + *(a+i); 
		}
}

/*Problem 3*/

int occurrences_of(int n, int *a, unsigned int len)
{
	int count = 0;
	for (int i = 0; i < len; i++){
	if (*(a+i)==n) count++;
	}
	return count;
}

/*Problem 4*/

int any_odd (int *a, unsigned int len)
{
	int eval = 0;
	for (int i = 0; i < len; i++){
	if (*(a+i) % 2) eval =1;
	}
	return eval;
}

/*Problem 5*/


void swap(int *a, int *b) /*swap the values of two variables*/
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int *a, unsigned int len)
{
	int mid = floor(len/2)-1; /*Careful here!*/
	for (int i = 0; i <= mid; i++){
		swap(a+i, a+(len-i-1)); /*sweeping the address*/
		}
}

/*Problem 6*/
int min(int *a, unsigned int len)
{
	int *winner = a;
	if (len){
		for (int i = 0; i < len; i++){
			if (*winner > *(a+i)) winner = a+i;
		}
	return (*winner);
	} else {
		fprintf(stderr,"min: given 0-length array\n");
		exit(1);
	}
}


/*Problem 7*/
int max(int *a, unsigned int len)
{
        int *winner = a;
        if (len){
                for (int i = 0; i < len; i++){
                        if (*winner < *(a+i)) winner = a+i;
                }
        return (*winner);
        } else {
                fprintf(stderr,"max: given 0-length array\n");
                exit(1);
        }
}

/*Problem 8*/
int equal(int *a1, unsigned int len1, int *a2, unsigned int len2)
{
	int eval = 1;
	if (len1 - len2) eval = 0;
	else {
		for (int i = 0; i < len1; i++){
			if (*(a1+i)-*(a2+i)) eval = 0;
			}
		}
	return eval;
}

/*Problem 9*/
void int_binary(unsigned int n)
{
	for (int i = 0; i < 32; i++){
		if (n < pow(2,(31-i))) printf("0");
		else {
			printf("1");
			n -= pow(2,(31-i));
		}
		if (i%4 == 3) printf(" ");
		}
	printf("\n");
}		


/*Problem 10*/
void int_quaternary(unsigned int n)
{
	for (int i = 0; i < 16; i++){
		if (0<=n && n<pow(4,15-i)) printf("0");
		else if (pow(4,15-i) <= n && n < 2*pow(4,15-i)){printf("1"); n -= pow(4,15-i);}
		else if (2*pow(4,15-i) <= n && n < 3*pow(4,15-i)){printf("2"); n -= 2*pow(4,15-i);}
		else {printf("3");n -= 3*pow(4,15-i);}
		if (i%2 !=0) printf(" ");
		}
		printf("\n");
}
		














