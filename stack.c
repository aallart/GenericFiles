#include "stack.h"

stack* nil_stack(){
	return nil();
}

bool is_stack_empty(stack* p_stack){
	return is_empty(p_stack);
}

elt pop(stack* p_stack){
	elt e = get_element(p_stack, 0);
	remove_element(p_stack, 0);
	return e;
}

void push(stack* p_stack, elt e){
	insert_element(p_stack, e, 0);
}

void print_stack(stack* p_stack){
	print_list(p_stack);
}

void deallocate_stack(stack* p_stack){
	deallocate_list(p_stack);
}
