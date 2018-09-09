/*Zihao Wang
 *CS152,Winter 2018
 *Homework1
 */

#include<stdio.h>

int valid_room(unsigned int num)
/*see if the given number corresponds to a room number*/
{
	int result; 
	int x = num/100;
	int y = num - x*100;
	result = (((1 <= x)&&(x <= 48)) &&((1 <= y) && (y <= 36)))||(((49 <= x)&&(x <= 99))&&((12 <= y)&&(y <= 24)));
	return(result);
}

unsigned  int rotary_pulses_r(unsigned long long int phone_num)
/* compute the number of rotaries required to dial a given phone number using recursion*/
{
	if (phone_num/10){ /*not the last digit(to the left)*/
		int a = phone_num - (phone_num/10)*10;
		if (a == 0){
			return(10+rotary_pulses_r(phone_num/10));
			}else{
			return(a+rotary_pulses_r(phone_num/10));
			}
	}else {
		return(phone_num);
		}
}


unsigned  int rotary_pulses_i(unsigned long long int phone_num)
/* compute the number of rotaries required to dial a given phone number using iteration*/
{
	unsigned int num = 0;
	unsigned long long int digits; /*REALLY NEED TO BE CAREFUL WITH THIS TYPE; int will report a big negative number*/
	int a ;
	for (digits = phone_num; digits > 9; digits= digits/10){
		 a = digits - (digits/10)*10;
		if(a) {
			num = num + a;
			} else {
			num = num +10;
			}
	}
	num = num + digits;
	return num;
}

double nth_harmonic(unsigned int n)
/*takes in a value of n, an unsigned int, and returns the nth harmonic number as a double*/
{ 
	double result=0;
	double i;  /*careful!! only double can 1/i not be 0!!!*/
	for (i=1; i <=n; i++){
		result = result + 1/i;
	}
	return result;
}	
					
unsigned int least_ge_harmonic(double x)
/*finds the least value of n such that the nth harmonic number is at least x*/
{
	double i=1; /*least index*/
	double s; /*sum*/
	unsigned int result;
	for (s=1; s<x;){
		++i;
		s = s + 1/i;
		}
	return (result = i);
}

/*Below are all all functions for and including checkerboard*/

void consec_checker (unsigned int side, char color)
/*print consecutive specified characters of guven length*/
{
    int i =1 ;
    for (; i <= side; i++){
        fprintf(stdout,"%c",color);
    }
}

void checker_row (unsigned int side, unsigned sq, char light, char dark)
/*print a row of checkerboard*/
{
    int i = 1;
    int j = 1;
    int color_index =0;
    for (; i <= side; i++){
        for (; j <= sq; j++){
            color_index? consec_checker(side,dark): consec_checker(side,light);
            color_index = !color_index;
        }
        j = j+1;
    }
}

void checker_rows (unsigned int side, unsigned sq, char light, char dark)
/*print specified row of checkerboard*/
{
    int i =1;
    for (; i <= side; i++){
        checker_row(side,sq,light,dark);
        fprintf(stdout,"%c",'\n');
    }
}

void checkerboard(unsigned int side, unsigned int sq, char light, char dark)
/*print n*n checkerboard*/
{
    int i = 1;
    int row_index = 0;
    for (; i <= sq; i++){
        row_index? checker_rows (side, sq, light,dark):
                    checker_rows (side, sq, dark, light);
        row_index = !row_index;
    }
}


