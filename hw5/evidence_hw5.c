#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hw5.h"
#include<ctype.h>
// turn a string into lower case
void lower(char* a)  
{
	int i = 0;
	while(a[i]!='\0'){
		a[i]=tolower(a[i]);
		i++;
		}
}

// see if the first character of a is smaller than i 
int smaller_than_i(char* a)
{
	char t = 'i';
	return(a[0]<t);
}

//create a new string list array of three strings
sal* new_strlist(char* a, char* b,char* c)
{
	sal* new = malloc(sizeof(sal));
	new->values= malloc(sizeof(char*)*3);
	new->values[0] = strdup(a);
	new->values[1] = strdup(b);
	new->values[2] = strdup(c);
	new->num_items = 3;
	return new;	
}
void evidence_find_something(sal* list)
{
	printf("testing find_first\n");
	printf("The index of Do is 0?\t");
	printf("%d\n",find_first(list,"Do"));
        printf("testing get_first\n");
        printf("The first of DO I LOVE RACKET is DO?\t");
        printf("%s\n",get_first(list));
	printf("testing get_last\n");
        printf("The last of DO I LOVE RACKET is RACKET?\t");
        printf("%s\n",get_last(list));
	printf("testing get_at_index\n");
        printf("The element with index 2 of DO I LOVE RACKET is LOVE?\t");
        printf("%s\n",get_at_index(list,3));
}

void evidence_insert_something(sal* list)
{
	printf("testing insert_after\n");
	printf("Insert ? after LOVE:\t");
	list_show(stdout,insert_after(list,"LOVE","?"),' ');
	printf("testing insert_before\n");
        printf("Insert ? before LOVE:\t");
        list_show(stdout,insert_before(list,"LOVE","?"),' ');
	printf("testing insert_at_index\n");
        printf("Insert ? at index 6:\t");
        list_show(stdout,insert_at_index(list,6,"?"),' ');

}
	
void evidence_remove_something(sal* list)
{
	printf("testing remove_first\n");
        printf("remove first ?:\t");
        list_show(stdout,remove_first(list,"?"),' ');
	printf("testing remove_all\n");
        printf("remove all ?:\t");
        list_show(stdout,remove_all(list,"?"),' ');
}
int main()
{
	sal* test1 = new_strlist("I","LOVE","RACKET");
	printf("testing list_show\n");
	list_show(stdout,test1,' ');
	printf("testing add_to_front\n");
	test1 = add_to_front(test1,"DO");
	list_show(stdout,test1,' ');	
	evidence_find_something(test1);
	evidence_insert_something(test1);
	evidence_remove_something(test1);
	printf("testing act_on_strings\n");
	list_show(stdout,act_on_strings(test1,lower),' ');
	printf("testing filter\n");
	list_show(stdout,filter(test1,smaller_than_i),' ');
	list_free(test1);
	return 0;
}





