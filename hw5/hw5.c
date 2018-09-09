#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hw5.h"

// first test remove functions, whose correctness almost guarantees that filters are right
// simply remove_first by filter_first;
// can insert-* be simplied ???
// insert at index can also be simplied by insert at index

sal *list_new()
{
	sal* new = malloc(sizeof(sal));
	new->values = NULL; // how should i malloc in this case?
	new->num_items = 0;
	return new;
}

void list_free(sal* list)
{
	char** t = list->values;
	for (int i = 0; i < list->num_items; i++)
		free(t[i]);
	free(list->values);
	free(list);
}

void list_show(FILE *f, sal *list, char sep)
{
	if(list==NULL)
		fprintf(f,"empty\n");
	char** t = list->values;
	for(int i = 0; i < list->num_items; i++ )
		fprintf(f,"%s%c",t[i],sep);
	fprintf(f,"\n");
}

sal *add_to_front(sal *list, char* val)
{
	size_t n = list->num_items;
	char** new_vals = malloc(sizeof(char*)*(n+1));
	new_vals[0] = strdup(val);
	for (int i = 0; i<n; i++){
		new_vals[i+1] = list->values[i];
		}
	free(list->values);
	list->values = new_vals;
	list->num_items = n+1;
	return list;
} 		

int find_first(sal* list, char* val)
{
	char** t = list->values;
	for (int i = 0; i < list->num_items; i++){
		if (!strcmp(val, t[i]))
			return i;
		}
	return -1;
}

char* get_first(sal* list)
{
	if(list->values[0]==NULL)// is this sufficient?
		return NULL;	
	return (list->values[0]);
}

char* get_last(sal* list)
{
	char* last = list->values[list->num_items-1];
	if(last==NULL)
		return NULL;
	return last;
}

char* get_at_index(sal* list, size_t index)
{
	char* target = list->values[index-1];
	if(target==NULL)
		return NULL;
	return target;
}


sal* insert_after(sal* list, char* sought_val, char* new_val)
{
	int index = find_first(list, sought_val);
	if (index==-1) 
		return NULL;
	size_t n = list->num_items;
	char ** new_vals = malloc((n+1)*sizeof(char*));
	for (int i = 0; i < index+1; i++){
		new_vals[i]=list->values[i];
		}
	new_vals[index+1] = strdup(new_val);
	for (int i = index+1; i < n; i++){
		new_vals[i+1] = list->values[i];
		}
	free(list->values);
	list->values = new_vals;
	list->num_items = n+1;
	return list;
}	

//can be simplied using insert_at_index
sal* insert_before(sal* list, char* sought_val, char* new_val)
{
        int index = find_first(list, sought_val);
        if (index==-1)
                return NULL;
        size_t n = list->num_items;
        char ** new_vals = malloc((n+1)*sizeof(char*));
        for (int i = 0; i < index; i++){
                new_vals[i]=list->values[i];
                }
        new_vals[index] = strdup(new_val);
        for (int i = index; i < n; i++){
                new_vals[i+1] = list->values[i];
                }
        free(list->values);
        list->values = new_vals;
        list->num_items = n+1;
        return list;
}

// here i allow the index to be equal to the num_items
sal* insert_at_index(sal* list, size_t index, char *new_val)
{
	if(index>list->num_items)
		return NULL;
	size_t n = list->num_items;
        char ** new_vals = malloc((n+1)*sizeof(char*));
        for (int i = 0; i < index; i++){
                new_vals[i]=list->values[i];
                }
        new_vals[index] = strdup(new_val);
        for (int i = index; i < n; i++){
                new_vals[i+1] = list->values[i];
                }
        free(list->values);
        list->values = new_vals;
        list->num_items = n+1;
        return list;
}

sal* remove_first(sal* list,char* sought_val)
{
	char** t = list->values;
	size_t n = list->num_items;
	for (int i=0; i<n;i++ ){
		if(!strcmp(sought_val, t[i])){
			free(t[i]);
			for(int j = i; j<n-1;j++)
				t[j]=t[j+1];
		list->num_items = n-1;
		return list;
			}
		}
	return NULL;
}

sal* remove_all(sal* list, char* sought_val)
{
	if ((list=remove_first(list,sought_val))==NULL)
		return NULL;
	while(remove_first(list, sought_val)!=NULL){
		}
	return list;
}

sal* act_on_strings(sal* list, void(*f)(char*))
{
	size_t n = list->num_items;
	char** t = list->values;
	for (int i = 0; i<n; i++){
		(*f)(t[i]);
		}
	return list;
}

// helper function ?? what shall i return if nothing fails?
sal* filter_first(sal* list, int(*test)(char*))
{
	char** t = list->values;
	size_t n = list->num_items;
	for (int i = 0; i<n; i++){
		if(!test(t[i])){ // t[i] fails the test
			free(t[i]);
			for (int j = i; j<n-1; j++)
				t[j]=t[j+1];
		list->num_items = n-1;
		return list;
			}
		}
	return list; // think this is reasonable; modifying a little bit, it can still apply to removes
}

sal* filter(sal* list, int(*test)(char*))
{
	while(list->num_items!=(filter_first(list,test))->num_items){
		}
	return list;
}
			




























































