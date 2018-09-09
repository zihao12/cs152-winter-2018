#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"hw3.h"

// how to define a global point???



char* a = "UCHICGAO IS WEIRD!!!";
char* b = "So AM I!!!";



// only strings are allowed to be defined outside functions? how do i free them?

void evidence_str_len()
{	
	int str_len(char *s);
	printf("Testing str_len\n");
	printf("string length of UCHICGAO IS WEIRD!!! is expecting 20:\n");
	printf("result is : %d\n", str_len(a));
	printf("%s\n",a);
}

void evidence_str_duplicate()
{
	char* copy = str_duplicate(a);
	printf("Testing str_duplicate:\n");
	printf("is the copy correct?\n");
	printf("%s\n",a);
	printf("%s\n",copy);
//	printf("%s",a);
//	printf("result is : %d\n", str_len(copy));
	
}

void evidence_cat()
{
	printf("Testing cat:\n");
	printf("Expecting:\n");
	printf("UCHICAGO IS WEIRD!!!SO AM I!!!\n");
	printf("%s\n",cat(a,b));
}

void evidence_catw()
{
        printf("Testing catw:\n");
        printf("Expecting:\n");
        printf("UCHICAGO IS WEIRD!!!&SO AM I!!!\n");
        printf("%s\n",catw(a,'&',b));
}	

void evidence_catw_arr()
{	
	char *test[] = {"I","AM","HOMO","SAPIEN"};
	printf("Testing catw_arr:\n");
	printf("Expecting(using empty space as separator):\n");
	printf("I AM HOMO SAPIEN\n");
	printf("%s\n",catw_arr(test,4,' '));
}

void evidence_point_new()
{
	point_t *p= point_new(3.97,7.83);
	printf("Testing point_new:\n");
	printf("Show the x and y component of point (3.97, 7.83)\n");
	printf("%f %f\n",p->x,p->y);
	free(p);
}


void evidence_point_show()
{
	point_t *p= point_new(3.97,7.83);
	printf("Testing point_show:\n");
	printf("show (3.97, 7.83)\n");
	point_show(stdout,p);
	free(p);
}
void evidence_segment_new()
{
	printf("Testing segment_new:\n");
	printf("showing segment(a(1.0,2.0),b(3.0,4.0))\n");
	point_t *a = point_new(1.0,2.0);
	point_t *b = point_new(3.0,4.0);
	segment_t *seg = segment_new(a,b);
	printf("first point is:\n");
	point_show(stdout,seg->a);
	printf("second point is:\n");
	point_show(stdout,seg->b);
//	segment_t *seg2 = segment_new(a,a);
//	printf("change a into (777,888)\n");
//	a = point_new(777,888);
//	point_show(stdout,seg->a);
	segment_free(seg);
	free(a);
	free(b);
}

void evidence_circle_new()
{
	point_t *center = point_new(2,3);
	double r = 9;
	circle_t *c =circle_new(center, r);
	printf("Testing circle_new:\n");
	point_show(stdout,c->center);
	printf("%f\n",c->r);
	circle_free(c);
	free(center);
}
		
void evidence_circle_show()
{
	printf("Testing circle_show:\n");
	point_t *center = point_new(2,3);
        double r = 9;
        circle_t *c =circle_new(center, r);
	circle_show(stdout,c);
	circle_free(c);
	free(center);
}

void evidence_segment_length()
{
	point_t *p1 = point_new(3,4);
	point_t *p2 = point_new(0,0);
	segment_t *s = segment_new(p1,p2);
	printf("Testing segment_length\n");
	printf("the segment is (0,0)-(3,4)\n");
	printf("The distance is %f\n", segment_length(s));
	segment_free(s);
	free(p1);
	free(p2);
}

void evidence_circle_area()
{
        point_t *center = point_new(2,3);
        double r = 9;
        circle_t *c =circle_new(center, r);
        printf("Testing circle_area:\n");
        printf("%f\n",circle_area(c));
        circle_free(c);
	free(center);
}

void evidence_contains()
{
        point_t *center = point_new(0,0);
        point_t *p1 = point_new(3,4);
        point_t *p2 = point_new(1,2);
        double r = 5;
        circle_t *c =circle_new(center, r);
        printf("Testing contains:\n");
        printf("expecting 0:%d\n",contains(c,p1));
        printf("expecting 1:%d\n",contains(c,p2));
        circle_free(c);
	free(p1);
	free(p2);
	free(center);
}

void evidence_horiz_diameter()
{
        point_t *center = point_new(0,0);
        double r = 5;
        circle_t *c =circle_new(center,r);
        printf("Testing horiz_diameter:\n");
        segment_show(stdout,horiz_diameter(c));
	circle_free(c);
	free(center);
}

void evidence_diameter_through()
{
        point_t *center = point_new(0,0);
        double r = 5;
        circle_t *c =circle_new(center,r);
	point_t* p1 = point_new(1,1);
        printf("Testing diameter_through:\n");
        segment_show(stdout,diameter_through(c,p1));
        circle_free(c);
	free(p1);
	free(center);
}


void evidence_overlap()
{
        point_t *center1 = point_new(0,0);
        double r1 = 4;
        circle_t *c1 =circle_new(center1,r1);
        point_t *center2 = point_new(3,4);
        double r2 = 1;
        circle_t *c2 =circle_new(center2,r2);
	point_t *center3 = point_new(100,0);
        double r3 = 5;
        circle_t *c3 =circle_new(center3,r3);
	printf("Testing overlap:\n");
	printf("expecting 1:%d\n", overlap(c1,c2));
	printf("expecting 0:%d\n", overlap(c1,c3));
        circle_free(c1);
        circle_free(c2);
        circle_free(c3);
	free(center1);
	free(center2);
	free(center3);
}

void evidence_circle_translate()
{
	point_t *center = point_new(0,0);
        double r = 5;
        circle_t *c =circle_new(center,r);
	printf("Testing circle_translate:\n");
	printf("Original circle:\n");
	circle_show(stdout,c);
	printf("move it by (3,4):\n");
	circle_show(stdout,circle_translate(c,3,4));
	circle_free(c);
	free(center);
}
int main()
{	
	evidence_str_len();
	evidence_str_duplicate();
	evidence_cat();
	evidence_catw();
	evidence_catw_arr();
	evidence_point_new();
	evidence_point_show();
	evidence_segment_new();
	evidence_circle_new();
	evidence_circle_show();
	evidence_segment_length();
	evidence_circle_area();
	evidence_contains();
	evidence_horiz_diameter();
	evidence_diameter_through();
	evidence_overlap();
	evidence_circle_translate();
//	double dist(point_t *p1, point_t *p2);
//	printf("%f\n",dist(point_new(3,4), point_new(0,0)));
	return 0;
}

