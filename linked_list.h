#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>

	#define NDEBUG 1

	typedef struct cell_int  cell_int;
	typedef struct linked_list_int linked_list_int;
	typedef struct element elt;

	struct element{
        int value;
    };

	struct cell_int {
		int value;
		cell_int *next;
	};

	struct linked_list_int{
		cell_int *first;
	};

	linked_list_int* nil();
	void cons(linked_list_int *liste, int e);
	int size(linked_list_int *liste);
	bool is_empty(linked_list_int *liste);
	int get_element(linked_list_int *liste, int n);
	void insert_element(linked_list_int *liste, int e, int place);
	void remove_element(linked_list_int *liste, int place);
	void deallocate_list(linked_list_int *liste);
	void print_list(linked_list_int *liste);

#endif // LINKED_LIST_H_INCLUDED
