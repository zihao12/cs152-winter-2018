/* Zihao Wang
* cmsc152 Lab3
* 1/25/2018 */

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include "waves.h"
double dist(double x0, double y0, double x1, double y1); 
double dist(double x0, double y0, double x1, double y1) 
{
	return(sqrt(pow(x0-x1,2)+pow(y0-y1,2)));
}

int point_to_col_gen (double x0, double y0, double x1, double y1, double some_col)
{
	return((int)(127.5*(1.0+sin(some_col * dist(x0,y0,x1,y1)))));
}

void draw_waves_gen(int side_length, int x_offset, int y_offset, double r, double g, double b)
{
	printf("%s\n%d %d\n%d\n","P3",side_length,side_length,255);	
	int i = 0;
	int j = 0;
	for (; i < side_length; i++){
		for (; j < side_length; j++){
			printf("%d %d %d ",
					point_to_col_gen(i,j,x_offset + side_length/2.0,y_offset + side_length/2.0,r),
					point_to_col_gen(i,j,x_offset + side_length/2.0,y_offset + side_length/2.0,g),
					point_to_col_gen(i,j,x_offset + side_length/2.0,y_offset + side_length/2.0,b));
			}
		printf("\n");
		j = 0;
		}
}

