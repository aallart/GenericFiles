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
