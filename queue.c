#include "queue.h"

queue* nil_queue(){
	return nil();
}

bool is_queue_empty(queue* p_queue){
	return is_empty(p_queue);
}

elt dequeue(queue* p_queue){
    elt e = get_element(p_queue, size(p_queue)-1);
	remove_element(p_queue, size(p_queue)-1);
	return e;
}

void enqueue(queue* p_queue, elt e){
	insert_element(p_queue, 0, e);
}

void print_queue(queue* p_queue){
	print_list(p_queue);
}

void deallocate_queue(queue* p_queue){
	deallocate_list(p_queue);
}
