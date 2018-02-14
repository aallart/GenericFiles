#include "double_linked_list.h"

#include <stdlib.h>
#include <stdio.h>

void print_elt(elt e){
    printf("%d", e.value);
}

dlist* nil(){
	dlist *p_list = NULL;
    p_list = malloc(sizeof(*p_list));
	if (p_list == NULL) exit(EXIT_FAILURE);
	p_list->first = NULL;
	p_list->last = NULL;
	p_list->size = 0;
	return p_list;
}

void print_list(const dlist *p_list){
    int i;
	cell *p = p_list->first;
	printf("NULL <--> ");
	for(i = 0; i < p_list->size; i++) {
		print_elt(p->data);printf(" <--> ");
		p = p->next;}
	printf("NULL");
}

void cons(dlist *p_list, elt data){
    if (p_list != NULL){
        cell *p_cell = NULL;
        p_cell = malloc(sizeof(cell));
        if (p_cell == NULL) {exit(EXIT_FAILURE);}
        p_cell->data = data;
        p_cell->next = p_list->first;
        p_cell->previous = NULL;
        if (p_list->size > 0)
            (p_list->first)->previous = p_cell;
        else
            p_list->last = p_cell;
        p_list->first = p_cell;
        p_list->size += 1;
    }
}

void snoc(dlist *p_list, elt data){
    if(p_list != NULL){
        cell *p_cell = NULL;
        p_cell = malloc(sizeof(cell));
        if (p_cell == NULL) {exit(EXIT_FAILURE);}
        p_cell->data = data;
        p_cell->previous = p_list->last;
        p_cell->next = NULL;
        if (p_list->size > 0)
            (p_list->last)->next = p_cell;
        else
            p_list->first = p_cell;
        p_list->last = p_cell;
        p_list->size += 1;
    }
}

int size(const dlist *p_list){
    return p_list->size;
}

bool is_empty(const dlist *p_list){
    return size(p_list)==0;
}

elt get_element(const dlist *p_list, int pos){
    int i;
    cell* p = p_list->first;
    for(i = 0; i < pos; i++) {p = p->next;}
    return p->data;
}

void insert_element(dlist *p_list, int pos, elt data){
    if (pos >= 0 && pos <= p_list->size){
        if(pos == 0) cons(p_list, data);
        else if(pos == p_list->size) snoc(p_list, data);
        else{
            int i;
            cell *p = p_list->first, *p_new = NULL;
            p_new = malloc(sizeof(*p_new));
            if(p_new == NULL) exit(EXIT_FAILURE);
            p_new->data = data;
            for(i = 1; i < pos; i++){p = p->next;}
            p_new->next = p->next;
            p_new->previous = p;
            p->next = p_new;
            p->next->previous = p_new;
            p_list->size += 1;
        }
    }
}
