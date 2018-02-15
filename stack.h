#ifndef STACK_INT_H
#define STACK_INT_H

	#include "linked_list.h"

    typedef list stack;

	stack* nil_stack();
	bool is_stack_empty(stack* p_stack);
	elt pop(stack* p_stack);
	void push(stack *p_stack, elt e);
	void print_stack(stack *p_stack);
	void deallocate_stack(stack *p_stack);

#endif
