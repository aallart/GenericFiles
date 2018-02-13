#include "linked_list.h"

int main(void) {
	linked_list_int *liste = nil();
	//print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s\n", (is_empty(liste))?"yes":"no");
	cons(liste, 3); cons(liste, 7); cons(liste, -2); cons(liste, 4);
	printf("\n\n");
	print_list(liste);printf(" => size = %d", size(liste));printf(" => empty = %s", (is_empty(liste))?"yes":"no");
	printf("; 2nd element = %d\n", get_element(liste, 2));
	printf("Inserted 11 in third position => \t");
	insert_element(liste, 11, 3);print_list(liste);printf("\n");
	printf("Inserted 16 in 6th position => \t");
	insert_element(liste, 16, 6);print_list(liste);printf("\n");
	printf("removing 7 (4th position) => \t");
	remove_element(liste, 3);print_list(liste);printf("\n");
	deallocate_list(liste);
    return 0;
}
