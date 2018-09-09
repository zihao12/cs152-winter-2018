#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sdll.h"


sdll *list_new()
{
	sdll *new = malloc(sizeof(sdll));
	new->first = NULL;
	new->last = NULL;
	return new;
}
// maybe convenient
void node_free(node* nd)
{
        free(nd->value);
        free(nd);
}


void list_free(sdll *list)
{
	node* nd = list->first;
	node* next = nd->next;
	while(next!=NULL){
		free(nd->value);	
		free(nd);
		nd = next;
		next = nd->next;
		}
	free(nd->value);
	free(nd);
	free(list);
}




void node_show(FILE *f, node *nd)
{
	if (nd == NULL) 
//		fprintf(f,"empty node");
	return;
	else{
		fprintf(f, "%s",nd->value);
		}
}

void list_show(FILE *f, sdll *list, char sep)
{
	if(list==NULL){
		fprintf(f,"empty list\n");
		}
	node* nd = list->first;
	while(nd->next!= NULL){
		node_show(f,nd);
		fprintf(f,"%c",sep);
		nd = nd->next;
		}
	node_show(f,nd);
}



node *find_first(sdll *list, char *val)
{
	node* nd = list->first;
	while(nd->next!=NULL){
		if(!strcmp(nd->value,val))
			return nd;
		nd = nd->next;
		}
	return strcmp(nd->value,val)? NULL :  nd;
}


node *get_first(sdll *list)
{
	if (list==NULL){
		fprintf(stderr, "empty list");
		exit(1);
		}
	return (list->first);
}


node *get_last(sdll *list)
{
        if (list==NULL){
                fprintf(stderr, "empty list");
                exit(1);
                }
        return (list->last);
}
node *get_next(sdll *list, node *nd)
{
        if (nd->next==NULL){
                fprintf(stderr, "already the last!");
                exit(1);
                }
        return (nd->next);
}

node *get_previous(sdll *list, node *nd)
{
        if (nd->prev==NULL){
                fprintf(stderr, "already the first!");
                exit(1);
                }
	return (nd->prev);
}

node* get_at_index (sdll* list, size_t index)
{
	node* nd = list->first;
	while(index){
		nd = nd->next;
		index--;
		}
	return nd;
}

sdll *insert_before(sdll *list, char *sought_val, char *new_val)
{
	node* nd = list->first;
	while(nd!=NULL){
		if (!strcmp(nd->value,sought_val)){
			node* new = malloc(sizeof(node));
			new->value = strdup(new_val);
			if (nd->prev==NULL){ //the first node
				new->prev = NULL;
				new->next = nd;
				nd->prev = new;
				list->first = new;
				return list;
				}
			else{
				new->prev = nd->prev;
				new->next = nd;
				(nd->prev)->next = new;
				nd->prev = new;
				return list;
				}
			}
		else nd = nd->next;
		}
	return NULL; 
}

sdll *insert_after(sdll *list, char *sought_val, char *new_val)
{
        node* nd = list->first;
        while(nd!=NULL){
                if (!strcmp(nd->value,sought_val)){
                        node* new = malloc(sizeof(node));
                        new->value = strdup(new_val);
                        if (nd->next==NULL){ //the first node
                                new->next = NULL;
                                new->prev = nd;
                                nd->next = new;
                                list->last = new;
                                return list;
                                }
                        else{
                                new->prev = nd;
                                new->next = nd->next;
                                (nd->next)->prev = new;
                                nd->next = new;
                                return list;
                                }
                        }
                else nd = nd->next;
                }
        return NULL;
}
//my undestanding about the "position", is that before the first one is valid while after the last is not;
sdll *insert_at_index(sdll *list, size_t index, char *new_val)
{
	node* nd = list->first;
	while(index&& nd!=NULL){
		nd = nd->next;
		index--;
		}
	if (nd==NULL) 
		return NULL;
	else {
		node* new = malloc(sizeof(node));
		new->value = strdup(new_val);
		if (nd->prev == NULL){
			new->prev = NULL;
                        new->next = nd;
                        nd->prev = new;
                        list->first = new;
                        return list;
                        }
		else{
                        new->prev = nd->prev;
                        new->next = nd;
                        (nd->prev)->next = new;
                        nd->prev = new;
                        return list;
                        }
		}
}


sdll *remove_first(sdll *list, char *sought_val)
{
	node* nd = list->first;
	while(nd!=NULL){
		if (!strcmp(nd->value,sought_val)){
			if (nd->prev==NULL){
				list->first = nd->next;
				list->first->prev = NULL;
				node_free(nd);
				return list;
				}
			if (nd->next==NULL){
				list->last = nd->prev;
				list->last->next = NULL;
				node_free(nd);
				return list;
				}
			else{
				nd->prev->next = nd->next;
				nd->next->prev = nd->prev;
				node_free(nd);
				return list;
				}
			}
		nd = nd->next;
		}
	return NULL;
}
				
sdll *remove_all(sdll *list, char *sought_val)
{
	sdll* test = remove_first(list,sought_val);
	if(test == NULL)
		return NULL;
	while(test!=NULL)
		test = remove_first(list,sought_val); //list is also changed if the returned is not NULL
	return list;
}
	
		
		





















