/**
 * @file double_linked_list.h
 *
 * @brief Simple definition of double linked list containing generic values
 *
 * This is a simple definition of a double linked list containing `int`
 * values implemented using cells linked by pointers. Warning: the cells
 * pointers should not be shared as deallocation of a double linked list
 * deallocates the memory space reserved for the cells!
 *
 * The API of the linked list is defined as follows:
 *
 * - a function to create an empty list
 * - a function to append an element at the beginning of the list
 * - a function to append an element at the end of the list
 * - a function to return the size of a list
 * - a function to check if a list is empty or not
 * - a function to get the element at a specified position
 * - a function to insert an element at a specified position in
 *   the list
 * - a function to remove an element at a specified position
 *   in the list
 * - a function to deallocate a list
 * - a function to print a list
 */

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdbool.h>

/**
 * @brief An alias for the structure representing the cells
 */
typedef struct cell cell;

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
 * @brief The structure representing the cells of the list
 */
struct cell {
    /** the data in the cell */
    elt data;
    /** the next cell in the list */
    cell *next;
    /** the previous cell in the list */
    cell *previous;
};

/**
 * @brief An alias for the structure representing the
 *        double linked list
 */
typedef struct dlist dlist;

/**
 * @brief The structure representing a double linked list
 */
struct dlist {
    /** the size of the list */
    int      size;
    /** the first cell in the list */
    cell *first;
    /** the last cell in the list */
    cell *last;
};

/**
 * @brief print the basic elt data type
 *
 * @param e is the element to be printed
 */
void print_elt(elt e);

/**
 * @brief Creates an empty list
 *
 * @post return a pointer to an empty dlist
 */
dlist* nil();

/**
 * @brief Append an element at the beginning of a list
 *
 * @param p_list  a pointer to the list to be modified
 * @param data   the value to be added in the list
 *
 * @post The first cell of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new first cell has the previously first cell for
 *       next cell.
 */
void cons(dlist *p_list, elt data);

/**
 * @brief Append an element at the end of a list
 *
 * @param p_list  a pointer to the list to be modified
 * @param data   the value to be added in the list
 *
 * @post The last cell of the list is now a new cell
 *       containing the value passed as parameter. The
 *       other cells of the list are not modified and the
 *       new last cell has the previously last cell for
 *       previous cell.
 */
void snoc(dlist *p_list, elt data);

/**
 * @brief The length of a list
 *
 * @param p_list  a pointer to the list whose length is wanted
 *
 * @return the length of the list (i.e. the number of distinct cells
 *         in the list)
 */
int size(const dlist *p_list);

/**
 * @brief Is the list empty?
 *
 * @param p_list  a pointer to the list
 *
 * @return true is the list is empty, false else
 */
bool is_empty(const dlist *p_list);

/**
 * @brief Get an element in the list at a specified position
 *
 * @param p_list  a pointer to the list to be queried
 * @param pos     the position of the wanted element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list (excluded)
 *
 * @return the value stored at position `pos`
 */
elt get_element(const dlist *p_list, int pos);

/**
 * @brief Insert an element in the list at a specified position
 *
 * @param p_list  a pointer to the list in which the element is inserted
 * @param pos     the position of the wanted element
 * @param data   the value of the new element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list
 *
 * @post Consider a call `insert_element(p_l, pos, value)`
 *       and let us suppose that the list before the call is
 *       represented by `old_list` and `length` represents the length of
 *       the list after call then:
 *       - \f$\forall i \in [0, ..., pos - 1]\f$ `get_element(*p_l, i) ==
 *       get_element(old_list, i)`
 *       - `get_element(*p_l, pos) == value`
 *       - \f$\forall i \in [pos + 1, ..., length]\f$
 *       `get_element(*p_l, i) == get_element(old_list, i - 1)`
 */
void insert_element(dlist *p_list, int pos, elt data);

/**
 * @brief Remove an element in the list at a specified position
 *
 * @param p_list  a pointer to the list from which the element is to be removed
 * @param pos     the position of the element
 * @pre   `pos` should be comprised between 0 and the length of
 *         the list (excluded)
 *
 * @post Consider a call `insert_element(p_l, pos, value)` and
 *       let us suppose that the list before the call is represented
 *       by `old_list` and `length` represents the length of
 *       the list after call, then:
 *       - \f$\forall i \in [0, ..., pos - 1]\f$ `get_element(*p_l, i) ==
 *       get_element(old_list, i)`
 *       - \f$\forall i \in [pos, ..., length - 1]\f$
 *       `get_element(*p_l, i) == get_element(old_list, i + 1)`
 */
void remove_element(dlist *p_list, int pos);

/**
 * @brief Deallocate a list
 *
 * @param p_list  a pointer to the list to be deallocated
 *
 * @post After the call to `deallocate_list`, all cells composing `list`
 *       are deallocated AND the structure representing the list is also
 *       deallocated. `p_list` is `NULL` after the call.
 */
void deallocate_list(dlist *p_list);

/**
 * @brief Print a list
 *
 * @param p_list  a pointer to the list to be printed
 *
 * @post After the call to `print_list`, the list is printed on the console
 *       in classical format using `[]`.
 */
void print_list(const dlist *p_list);

#endif
