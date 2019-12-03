#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "linked_list.h"

void printAll(p_list_t list) {
	for (int i = 0; i < noOfItems(list); i++) {
		void* str = getElement(list, i);
		printf("Element no.%d is %s\n", i + 1, str);
	}
	printf("\n");
}

main(void) {
		p_list_t student_list = linked_list_create();
		p_list_t teacher_list = linked_list_create();

		char str[] = "NAYA 273461";

		addItem(student_list, str);
		addItem(teacher_list, "IB HAVN");
		addItem(student_list, "ALICJA 274451");
		addItem(teacher_list, "IB HAVNOOOO");
		addItem(student_list, "MARIA 273377");
		addItem(teacher_list, "IB HAVNIIII");

		addItem(teacher_list, "KASPER");
		
		printAll(student_list);
		printAll(teacher_list);

		removeItem(student_list, str);
		removeItem(student_list, str);

		printAll(student_list);

		p_list_t empty_list = linked_list_create();

		removeItem(empty_list, str);

		linked_list_destroy(teacher_list);
		linked_list_destroy(student_list);
		linked_list_destroy(empty_list);


		
}