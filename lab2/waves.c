/* Zihao Wang
* cmsc152 Lab2
* 1/18/2018 */

#include<stdio.h>
#include<math.h>
#include "waves.h"
double dist(double x0, double y0, double x1, double y1) 
{
	return(sqrt(pow(x0-x1,2)+pow(y0-y1,2)));
}

int point_to_col (double x0, double y0, double x1, double y1)
{
	return((int)(127.5*(1.0+sin(dist(x0,y0,x1,y1)))));
}

void draw_waves(int side_length, int x_offset, int y_offset)
{
	printf("%s\n%d %d\n%d\n","P3",side_length,side_length,255);	
	int i = 0;
	int j = 0;
	for (; i < side_length; i++){
		for (; j < side_length; j++){
			printf("%d %d %d ",0,0,point_to_col(i,j,x_offset + side_length/2.0,y_offset + side_length/2.0));
			}
		printf("\n");
		j = 0;
		}
}




















