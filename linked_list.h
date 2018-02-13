#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

	#include <stdio.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <assert.h>

	#define NDEBUG 1

	typedef struct cell  cell;
	typedef struct list list;
	typedef struct element elt;

	struct element{
        int value;
    };

	struct cell {
		elt data;
		cell *next;
	};

	struct list{
		cell *first;
	};

	list* nil();    //Create empty list
	void cons(list *liste, elt e);      //append e to liste
	int size(list *liste);
	bool is_empty(list *liste);
	elt get_element(list *liste, int n);
	void insert_element(list *liste, elt e, int place);     //Start counting at 1
	void remove_element(list *liste, int place);    //Start counting at 1
	void deallocate_list(list *liste);
	void print_list(list *liste);

#endif // LINKED_LIST_H_INCLUDED
