#ifndef STACK_INT_H
#define STACK_INT_H

	#include "linked_list.h"

	list* nil_stack();
	bool is_stack_empty(list* stack);
	int pop(list* stack);
	void push(list *stack, elt e);
	void print_stack(list *stack);
	void deallocate_stack(list *stack);

#endif
