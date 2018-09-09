#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"hw3.h"
// string operations
// 1. 

/*get the logical length of a string*/
int str_len(char *s)
{
	int n = 0;
	for (; *s != '\0';s++){
		n++;
		}
	return n;
}

char* str_duplicate(char *s)
{
	char* copy = (char*)malloc(1+str_len(s)*sizeof(char));
	if (copy == NULL){
		fprintf(stderr,"string length invalid\n");
		exit(1);
	}
	int i =0;
	for (; *s != '\0'; s++){
		copy[i] = *s;
		//printf("%c\n",*copy);
		i++;
		}
		copy[i] = '\0';
	return copy;
}

//2
char* cat(char* s1, char* s2)
{
	int l1 = str_len(s1);
	int l2 = str_len(s2);
	char* combine = malloc(l1+l2+1);
	if (combine == NULL){
		fprintf(stderr,"string lengths invalid");
		exit(1);
		}
	int i = 0;
	for (; i < l1; ++i){
		combine[i] = s1[i];
		}
	for (; i < l1+l2; ++i){
		combine[i] = s2[i-l1];
		}
	combine[l1+l2+1]='\0';
	return(combine);
}	


//3
char* catw(char* s1,char sep, char* s2)
{
        int l1 = str_len(s1);
        int l2 = str_len(s2);
        char* combine = malloc(l1+l2+2);
        if (combine == NULL){
                fprintf(stderr,"string lengths invalid");
                exit(1);
                }
        for (int i =0; i < l1; ++i){
                combine[i] = s1[i];
                }
	combine[l1] = sep;
        for (int j = 0; j < l2; ++j){
                combine[l1+j+1] = s2[j];
                }
        combine[l1+l2+1]='\0';
        return(combine);
} 
//4
// concatenate an array of strings with seperators in between
char* catw_arr(char* ss[], int slen, char sep)
{
// assume slen is correct
//	char* combine = ss[0];
	char* combine = str_duplicate(ss[0]);
	char* temp; // store the location of old combine; free its pointee when it is renewed
	for (int i =1; i < slen; i++){
		temp = combine;
		combine = catw(combine,sep,ss[i]);
		free(temp);
		}
	return combine;
}

// Point fundamentals
//5.
point_t *point_new(double x, double y)
{ 
	point_t *p = malloc(sizeof(point_t));
	if (p == NULL){
		fprintf(stderr,"Invalid point\n");
		exit(1);
		}
	p->x = x;
	p->y = y;
	return p;
}
//6
void point_show(FILE *f, point_t *p)
{
	fprintf(f,"%f %f\n",p->x,p->y);
}

// segment fundamentals

//
// dist: the distance between two points
double dist(point_t *p1, point_t *p2)
{       
        return(sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y)));
}


//7
segment_t *segment_new(point_t *a, point_t *b)
{
	segment_t *seg = malloc(sizeof(segment_t));
	if(seg==NULL || !(dist(a,b))){
		fprintf(stderr,"Invalid segment");
		exit(1);
		}
//	seg->a = a;
//	seg->b = b;
// they can only create a shallow copy
	seg->a = point_new(a->x,a->y);
	seg->b = point_new(b->x,b->y);
	return seg;
}	

//8
void segment_show(FILE *f, segment_t *s)
{
	printf("The two segments consist of two points:\n");
	point_show(f, s->a);
	point_show(f, s->b);
}
	
/* Free the segment and the points it points to. */
void segment_free(segment_t *s)
{
free(s->a);
free(s->b);
free(s);
}

// circle fundamentals
//9
circle_t *circle_new(point_t *center, double r)
{
	circle_t *c = malloc(sizeof(circle_t));
	if (c==NULL){
		fprintf(stderr, "Invalid circle\n");
		exit(1);
		}
	c->center = point_new(center->x, center->y);
	c->r = r;
	return c;
}

//10
void circle_show(FILE *f, circle_t *c)
{
	fprintf(f,"%f %f ; %f\n",(c->center)->x,(c->center)->y,c->r);
}

//11 
void circle_free(circle_t *circ)
{
	free(circ->center);
	free(circ);
}

//operations


//13
double segment_length(segment_t *s)
{
	return(dist(s->a,s->b));
}	

//14
double circle_area(circle_t *circ)
{
	return(circ->r*circ->r*M_PI);
}


//15
int contains(circle_t *circ, point_t *p)
{
	return((dist(circ->center,p)<circ->r)? 1 : 0);
}

//16
segment_t *horiz_diameter(circle_t *circ)
{
	double y = (circ->center)->y;
	double lx = (circ->center)->x-(circ->r);
	double rx = (circ->center)->x+(circ->r);
	point_t *lp = point_new(lx,y);
	point_t *rp = point_new(rx,y);
	return(segment_new(lp,rp));
}
	
//17
segment_t *diameter_through(circle_t* circ, point_t *p)
{
	point_t* c = circ->center;
	double r = circ->r;
	double d = dist(p, c);
	if (d==0 || d>r){
		fprintf(stderr, "invalid point for fucntion diameter_through\n");
		exit(1);
		}
	double dx1 = p->x - c->x;	
	double dy1 = p->y - c->y;
	// by similar triangles
	double dx2 = (r/d)*dx1;
	double dy2 = (r/d)*dy1;
	point_t *lp = point_new(c->x-dx2, c->y-dy2);
	point_t *rp = point_new(c->x+dx2, c->y-dy2);
	return(segment_new(lp,rp));
}

//18
int overlap(circle_t *cir1, circle_t* cir2)
{
	double d = dist(cir1->center, cir2->center);
	return(d > cir1->r+cir2->r? 0 : 1);
}

//19
circle_t* circle_translate(circle_t *circ, double dx, double dy)
{
	point_t *center = circ->center;
	point_t* new_cen = point_new(center->x+dx, center->y+dy);
	return(circle_new(new_cen, circ->r));
}	




































