#include "linked_list.h"

int main(void) {
    elt elements[] = {{3}, {7}, {-2}, {4}, {11}, {16}};
	list *liste = nil();
	//print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s\n", (is_empty(liste))?"yes":"no");
	cons(liste, elements[0]); cons(liste, elements[1]); cons(liste, elements[2]); cons(liste, elements[3]);
	printf("\n\n");
	print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s", (is_empty(liste))?"yes":"no");
	printf("; 2nd element = %d\n", get_element(liste, 2));
	printf("Inserted 11 in third position => \t");
	insert_element(liste, elements[4], 3);print_list(liste);printf("\n");
	printf("Inserted 16 in 6th position => \t");
	insert_element(liste, elements[5], 6);print_list(liste);printf("\n");
	printf("removing 7 (4th position) => \t");
	remove_element(liste, 4);print_list(liste);printf("\n");
	deallocate_list(liste);
    return 0;
}
