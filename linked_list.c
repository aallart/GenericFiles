#include "linked_list.h"

linked_list_int* nil() {
	linked_list_int *liste = NULL;
	liste = malloc(sizeof(linked_list_int));
	if (liste == NULL) {exit(EXIT_FAILURE);}
	liste->first = NULL;
	return liste;
}

void cons(linked_list_int *liste, int e) {
	cell_int *p_cell = NULL;
	p_cell = malloc(sizeof(cell_int));
	if (p_cell == NULL || liste == NULL) {exit(EXIT_FAILURE);}
	p_cell->value = e;
	p_cell->next = liste->first;
	liste->first = p_cell;
}

int size(linked_list_int *liste) {
	int size = 0;
	cell_int* p = liste->first;
	while(p != NULL){
		size++;
		p = p->next;
	}
	return size;
}

bool is_empty(linked_list_int *liste) {
	return(liste->first==NULL);
}

int get_element(linked_list_int *liste, int n) {
	assert(n >= 0);assert(n <= size(liste));
	int i = 1;
	cell_int *p = liste->first;
	for(i = 1; i < n; i++){p=p->next;}
	return p->value;
}

void insert_element(linked_list_int *liste, int e, int place) {
	if(place == 0) {cons(liste, e);}
	else{
		if(place > size(liste)+1) {place = size(liste)+1;}
		int i = 1;
		cell_int *p = liste->first, *new = NULL;
		new = malloc(sizeof(cell_int));
		if (new == NULL) {exit(EXIT_FAILURE);}
		new->value = e;
		for(i = 1; i < place-1; i++){p=p->next;}
		new->next = p->next;
		p->next = new;
	}
}

void remove_element(linked_list_int *liste, int place) {
	if(place == 1){
		cell_int *p_toFree = liste->first;
		liste->first = p_toFree->next;
		free(p_toFree);
	}
	else if(place < size(liste) && place > 0){
		int i;
		cell_int *p = liste->first;
		for(i = 1; i < place-1; i++){p=p->next;}
		cell_int *p_toFree = p->next;
		p->next = p_toFree->next;
		free(p_toFree);
	}
}

void deallocate_list(linked_list_int *liste) {
	if(!is_empty(liste)){
		cell_int *p, *pNext;
		p = liste->first; pNext = p->next;
		while(p != NULL){
			free(p);
			p = pNext;
			if(pNext != NULL) pNext = p->next;
		}
	}
	free(liste);
}

void print_list(linked_list_int *liste) {
	cell_int *p = liste->first;
	//printf("\n");
	while(p != NULL){
		printf("%d -> ", p->value);
		p = p->next;
	}
	printf("NULL");
}
