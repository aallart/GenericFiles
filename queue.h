#ifndef QUEUE_INT_H
#define QUEUE_INT_H

	#include "double_linked_list.h"

	typedef dlist queue;

	queue* nil_queue();
	bool is_queue_empty(queue* p_queue);
	elt dequeue(queue* p_queue);
	void enqueue(queue* p_queue, elt e);
	void print_queue(queue* p_queue);
	void deallocate_queue(queue* p_queue);

#endif
