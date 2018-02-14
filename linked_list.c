#include "linked_list.h"

void print_elt(elt e){
    printf("%d", e.value);
}

list* nil() {
	list *liste = NULL;
	liste = malloc(sizeof(list));
	if (liste == NULL) {exit(EXIT_FAILURE);}
	liste->first = NULL;
	liste->size = 0;
	return liste;
}

void cons(list *liste, elt e) {
    if(liste != NULL){
        cell *p_cell = NULL;
        p_cell = malloc(sizeof(cell));
        if (p_cell == NULL) {exit(EXIT_FAILURE);}
        p_cell->data = e;
        p_cell->next = liste->first;
        liste->first = p_cell;
        liste->size++;
    }
}

int size(list *liste) {
    return liste->size;
}

bool is_empty(list *liste) {
	return(liste->first==NULL);
}

elt get_element(list *liste, int n) {
	int i = 0;
	cell *p = liste->first;
	for(i = 0; i < n; i++){p=p->next;}
	return p->data;
}

void insert_element(list *liste, elt e, int place) {
	if(place == 0) {cons(liste, e);}
	else if(place > 0 && place <= size(liste)){
		int i;
		cell *p = liste->first, *new = NULL;
		new = malloc(sizeof(cell));
		if (new == NULL) {exit(EXIT_FAILURE);}
		new->data = e;
		for(i = 1; i < place; i++){p=p->next;}
		new->next = p->next;
		p->next = new;
		liste->size++;
	}
}

void remove_element(list *liste, int place) {
	if(place == 0){
		cell *p_toFree = liste->first;
		liste->first = p_toFree->next;
		free(p_toFree);
	}
	else if(place < size(liste) && place > 0){
		int i;
		cell *p = liste->first;
		for(i = 1; i < place; i++){p=p->next;}
		cell *p_toFree = p->next;
		p->next = p_toFree->next;
		free(p_toFree);
	}
}

void deallocate_list(list *liste) {
	if(!is_empty(liste)){
		cell *p, *pNext;
		p = liste->first; pNext = p->next;
		while(p != NULL){
			free(p);
			p = pNext;
			if(pNext != NULL) pNext = p->next;
		}
	}
	free(liste);
}

void print_list(list *liste) {
	cell *p = liste->first;
	while(p != NULL){
		print_elt(p->data);printf(" -> ");
		p = p->next;
	}
	printf("NULL");
}
