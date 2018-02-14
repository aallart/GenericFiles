#include "stack_int.h"

list* create_empty_stack(){
	return nil();
}

bool is_stack_empty(list* stack){
	return is_empty(stack);
}

int pop(list* stack){
	int elt = get_element(stack, 0);
	remove_element(stack, 0);
	return elt;
}

void push(list *stack, elt e){
	insert_element(stack, e, 0);
}

void print_stack(list *stack){
	print_list(stack);
}

void deallocate_stack(list *stack){
	deallocate_list(stack);
}
