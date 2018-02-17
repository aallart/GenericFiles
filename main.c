#include <stdlib.h>
#include <stdio.h>
#include "binary_heap.h"

int main(void) {
    int i;
    elt elements[] = {{3}, {7}, {-2}, {4}, {11}, {16}};
//    //  linked_list tests
//	list *liste = nil();
//	//print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s\n", (is_empty(liste))?"yes":"no");
//	cons(liste, elements[0]); cons(liste, elements[1]); cons(liste, elements[2]); cons(liste, elements[3]);
//	printf("\n\n");
//	print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s", (is_empty(liste))?"yes":"no");
//	//printf("; 2nd element = %d\n", get_element(liste, 1));
//	printf("Inserted 11 in third position => \t");
//	insert_element(liste, elements[4], 0);print_list(liste);printf("\n");
//	printf("Inserted 16 in 6th position => \t");
//	insert_element(liste, elements[5], 0);print_list(liste);printf("\n");
//	//printf("removing 7 (4th position) => \t");
//	remove_element(liste, 6);print_list(liste);printf("\n");
//	deallocate_list(liste);

//      //double linked list tests
//    dlist *p_list = nil();
//    //print_list(p_list);printf(" => empty = %s\n", (is_empty(p_list))?"yes":"no");
//    cons(p_list, elements[0]);cons(p_list, elements[1]);cons(p_list, elements[2]);
//    snoc(p_list, elements[3]);
//    //print_list(p_list);//printf(" => empty = %s", (is_empty(p_list))?"yes":"no");
//    //for(i = 0; i < 4; i++) {printf("\n%dth element: ", i); print_elt(get_element(p_list, i));}
//    printf("\n");
//    insert_element(p_list, 3, elements[4]);print_list(p_list);
//    printf("\n");
//    //print_elt(p_list->last->previous->next->previous->data);
//    remove_element(p_list, 3);print_list(p_list);

//    //stack ADT tests
//    stack *p_stack = nil_stack();
//    printf("\n%d\n", is_stack_empty(p_stack));
//    push(p_stack, elements[0]);push(p_stack, elements[1]);push(p_stack, elements[2]);
//    print_stack(p_stack);
//    printf("\n%d\n", is_stack_empty(p_stack));
//    print_elt(pop(p_stack));print_stack(p_stack);

//    //queue ADT tests
//    queue* p_queue = nil_queue();
//    printf("\n%d\n", is_queue_empty(p_queue));
//    enqueue(p_queue, elements[0]);enqueue(p_queue, elements[1]);enqueue(p_queue, elements[2]);
//    printf("\n%d\n", is_queue_empty(p_queue));
//    print_queue(p_queue);
//    print_elt(dequeue(p_queue));print_queue(p_queue);


    //binary heap ADT tests
    heap* p_heap = nil_heap();
    //printf("empty = %s\n", (is_heap_empty(p_heap))?"yes":"no");
    insert_heap(p_heap, elements[0]);insert_heap(p_heap, elements[1]);insert_heap(p_heap, elements[2]);insert_heap(p_heap, elements[3]);
    print_heap(p_heap);
    while(p_heap->root != NULL) {
        //printf("\n Min in the heap = ");
        printf("\t");print_elt(extract_min(p_heap));
    } printf("\n");
    return 0;
}
