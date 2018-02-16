#include <stdio.h>
#include <stdlib.h>

#include "heap_int.h"

void deallocate_node_rec(heap_int_node *p);

// auxiliary functions
void print_level(heap_int_node *p_node, int level) {
    for (int i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (p_node == NULL) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(%d)\n", level == 0 ? "" : " +-", p_node->value);
    print_level(p_node->left, level + 1);
    print_level(p_node->right, level + 1);
}

// gives a pointer to the heap node pointer representing the father
// of node number n in the heap
heap_int_node *go_to_father_node(heap_int *p_heap, int n) {
    char carray[sizeof(int)*8+1];
    heap_int_node *p_father_node = p_heap->root;
    int level = 0, i;
    while (n != 0){
		carray[level] = (n&1)==1?'r':'l';
		level++;
		n = n >> 1;
	}
	for(i = level-2; i >= 1; i--){
		if (carray[i] == 'l')
			p_father_node = p_father_node->left;
		else
			p_father_node = p_father_node->right;
	}
    return p_father_node;
}


// functions from the signature
heap_int nil(){
	heap_int heap = {NULL, 0};
	return heap;
}

bool is_empty(heap_int *p_heap){
	return p_heap->root == NULL;
}

void insert(heap_int *p_heap, int value){
		//append node in the end
	heap_int_node *father = go_to_father_node(p_heap, p_heap->size + 1);
	heap_int_node *p_new = NULL;
	heap_int_node *son = NULL;
	p_new = malloc(sizeof(*p_new));
	int temp;
	if (p_new == NULL) exit(EXIT_FAILURE);
	p_new->right = NULL;
	p_new->left = NULL;
	p_new->value = value;
		//make the heap be sorted again
	if(father == NULL){
		p_heap->root = p_new;
		p_new->father = NULL;
	}
	else{
		p_new->father = father;
		if(father->left == NULL) father->left = p_new;
		else father->right = p_new;
		son = p_new;
		while(father != NULL && father->value > son->value){
			temp = father->value;
			father->value = son->value;
			son->value = temp;
			father = father->father;
			son = son->father;
		}
	}
	p_heap->size++;
}

void print_heap(heap_int *p_heap){
	if (p_heap != NULL)
		print_level(p_heap->root, 0);
}

int extract_min(heap_int *p_heap){
		//find min and free the memory
	heap_int_node *father = go_to_father_node(p_heap, p_heap->size), *p_last = NULL;
	heap_int_node *p;
	int min = p_heap->root->value, temp;
	if(father->left == NULL){
		free(p_last);
		p_heap->root = NULL;
	}
	else{
		if(father->right == NULL) p_last = father->left;
		else p_last = father->right;
		p_heap->root->value = p_last->value;
		if(father->right == p_last) father->right = NULL;
		else father->left = NULL;
		free(p_last);
		p_heap->size--;
			//resort the heap	
		p = p_heap->root;
		while((p->left != NULL) && (p->left->value < p->value || (p->right != NULL && p->right-> value < p->value))){
			if(p->right == NULL || (p->right != NULL && p->right->value > p->left->value)){
				temp = p->left->value;
				p->left->value = p->value;
				p->value = temp;
				p = p->left;
			}
			else{
				temp = p->right->value;
				p->right->value = p->value;
				p->value = temp;
				p = p->right;
			}
		}
	}
	return min;
}

void deallocate_node_rec(heap_int_node *p){
	if(p->left != NULL) deallocate_node_rec(p->left);
	if(p->right != NULL) deallocate_node_rec(p->right);
	free(p);
}

void deallocate_heap(heap_int *p_heap){
	deallocate_node_rec(p_heap->root);
}
