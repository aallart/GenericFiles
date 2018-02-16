 /**
 * @file binary_heap.h
 *
 * @brief Simple definition of a binary heap containing generic values
 *
 * @author Christophe Garion
 *
 * This is a simple definition of a binary heap containing generic
 * values implemented using a binary tree. Warning: the cells
 * pointers should not be shared as deallocation of a BST
 * deallocates the memory space reserved for the cells!
 *
 * Inserting a value and extracting the minimum value are guaranteed
 * to have a worst-case complexity in $O(\log n)$ where $n$ is the
 * size of the heap.
 *
 * The API of the binary heap is defined as follows:
 *
 * - a function to create an empty heap
 * - a function to check if the heap is empty
 * - a function to insert a new value in the heap
 * - a function to get the minimum value in the heap
 * - a function to print the binary heap
 * - a function to deallocate the binary heap
 */

#ifndef HEAP_INT_H
#define HEAP_INT_H

#include <stdbool.h>


/**
 * @brief An alias for the structure representing the data in the cells
 */
typedef struct element elt;

/**
 * @brief The structure representing the data in the cells
 */
struct element {
    /** the value in the cell (can be modified) */
    int value;
};

/**
 * @brief An alias to the structure representing the nodes of the
 *        binary heap.
 */
typedef struct node node;

/**
 * @brief The structure representing the nodes of the binary heap.
 */
struct node {
    /** The value in the node */
    elt data;
    /** A pointer to the left child node */
    node *left;
    /** A pointer to the right child node */
    node *right;
    /** A pointer to the father node */
    node *father;
};

/**
 * @brief An alias to the structure representing a binary heap.
 */
typedef struct heap heap;

/**
 * @brief The structure representing the binary heap.
 */
struct heap {
    /** The root of the binary heap. May be `NULL` */
    node *root;
    /** The size of the binary heap */
    int size;
};

/**
 * @brief print the basic elt data type
 *
 * @param e is the element to be printed
 */
void print_elt(elt e);

/**
 * @brief print the heap starting from given level
 *
 * @param p_node is a pointer to the first node
 * @param level to be defined
 */
void print_level(node *p_node, int level);

/**
 * @brief compare two elements
 *
 * @param a is the first element
 * @param b is the second one
 *
 * @return -1 if a<b, 0 if a=b and 1 if a>b
 */
int comp_elt(elt a, elt b);

/**
 * @brief Create a nil binary heap.
 *
 * @return a pointer to a new empty binary heap
 */
heap* nil_heap();

/**
 * @brief Is the binary heap empty?
 *
 * @param p_heap a pointer to the heap you want to
 *               check the emptiness
 *
 * @return `true` is `p_heap` is empty, `false` else
 *
 * @pre `p_heap` is not `NULL`
 */
bool is_heap_empty(heap *p_heap);

node *father_node(heap *p_heap, int n);

/**
 * @brief Insert a new value in the binary heap. The
 *        worst-case execution time of this function
 *        is guaranteed to be in \f$\log n\f$ where
 *        \f$n\f$ is the size of the binary heap.
 *
 * @param p_heap a pointer to the heap in which the value is
 *               to be inserted
 * @param e the value to be inserted
 *
 * @pre `p_heap` is not `NULL`
 *
 * @post After the call, `p_heap` will point to a binary heap
 *       in which the value `value` has been inserted according
 *       to the algorithm presented in the lab session.
 */
void insert_heap(heap *p_heap, elt e);

/**
 * @brief Extract the minimum value in the binary heap. The
 *        worst-case execution time of this function
 *        is guaranteed to be in \f$\log n\f$ where \f$n\f$ is
 *        the size of the binary heap.
 *
 * @param p_heap a pointer to the heap from which the value is
 *               to be extracted
 *
 * @return the minimum value in the binary heap
 *
 * @pre `p_heap` is not `NULL` and the binary heap is not empty
 */
elt extract_min(heap *p_heap);

/**
 * @brief Prints the binary heap.
 *
 * @param p_heap a pointer to the binary heap to be printed
 *
 * @pre `p_heap` is not `NULL`
 *
 * @post After the call, the binary heap is printed.
 */
void print_heap(heap *p_heap);

/**
 * @brief Deallocate the binary heap.
 *
 * @param p_heap  a pointer to the binary heap to be deallocated
 *
 * @pre `p_heap` is not `NULL`
 *
 * @post After the call, all memory regions used for the nodes
 *       are deallocated.
 */
void deallocate_heap(heap *p_heap);

#endif
