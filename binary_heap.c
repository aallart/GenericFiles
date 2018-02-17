#include <stdio.h>
#include <stdlib.h>

#include "binary_heap.h"


heap* nil_heap(){
    heap* p_heap = NULL;
    p_heap = malloc(sizeof(*p_heap));
    if (p_heap == NULL) exit(EXIT_FAILURE);
	p_heap->root = NULL; p_heap->size = 0;
	return p_heap;
}

bool is_heap_empty(heap *p_heap){
	return p_heap->root == NULL;
}

void insert_heap(heap *p_heap, elt e){
		//append node in the end
	node *father = father_node(p_heap, p_heap->size + 1);
	node *p_new = NULL;
	node *son = NULL;
	elt temp;
	p_new = malloc(sizeof(*p_new));
	if (p_new == NULL) exit(EXIT_FAILURE);
	p_new->right = NULL;
	p_new->left = NULL;
	p_new->data = e;
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
		while(father != NULL && comp_elt(father->data, son->data)==1){
			temp = father->data;
			father->data = son->data;
			son->data = temp;
			father = father->father;
			son = son->father;
		}
	}
	p_heap->size++;
}

elt extract_min(heap *p_heap){
            //find min and free the memory
	node *father = father_node(p_heap, p_heap->size), *p_last = NULL;
	node *p;
	elt min = p_heap->root->data, temp;
	if(father->left == NULL){ //No need to resort the heap, it will be empty empty!
        free(father);
		p_heap->root = NULL;
    }
	else{
		if(father->right == NULL) p_last = father->left;
		else p_last = father->right;
		p_heap->root->data = p_last->data;
		if(father->right == p_last) father->right = NULL;
		else father->left = NULL;
		free(p_last);
			//resort the heap
		p = p_heap->root;
		while(p->left != NULL && comp_elt(p->left->data, p->data) == -1 || p->right != NULL && comp_elt(p->right->data, p->data) == -1){
                    //move value to left down
			if(p->right == NULL || (p->right != NULL && comp_elt(p->right->data, p->left->data) == 1)){
				temp = p->left->data;
				p->left->data = p->data;
				p->data = temp;
				p = p->left;
			}       //Move it to right down
			else{
				temp = p->right->data;
				p->right->data = p->data;
				p->data = temp;
				p = p->right;
			}
		}
	}
	p_heap->size--;
	return min;
}

void print_elt(elt e){
    printf("%d", e.value);
}

void print_level(node *p_node, int level) {
    int i;
    for (i = 0; i < level - 1; i++) {
        printf("   ");
    }

    if (p_node == NULL) {
        printf("%snil\n", level == 0 ? "" : " +-");
        return;
    }

    printf("%s(", level == 0 ? "" : " +-");print_elt(p_node->data);printf(")\n");
    print_level(p_node->left, level + 1);
    print_level(p_node->right, level + 1);
}

void print_heap(heap *p_heap){
	if (p_heap != NULL)
		print_level(p_heap->root, 0);
}

int comp_elt(elt a, elt b){
    if (a.value < b.value) return -1;
    else if (a.value == b.value) return 0;
    return 1;
}

node *father_node(heap *p_heap, int n) {
    char carray[sizeof(int)*8+1];
    node *p_father = p_heap->root;
    int level = 0, i;
    while (n != 0){
		carray[level] = (n&1)==1?'r':'l';
		level++;
		n = n >> 1;
	}
	for(i = level-2; i >= 1; i--){
		if (carray[i] == 'l')
			p_father = p_father->left;
		else
			p_father = p_father->right;
	}
    return p_father;
}

void deallocate_node_rec(node *p){
	if(p->left != NULL) deallocate_node_rec(p->left);
	if(p->right != NULL) deallocate_node_rec(p->right);
	free(p);
}

void deallocate_heap(heap *p_heap){
	deallocate_node_rec(p_heap->root);
	free(p_heap);
}
