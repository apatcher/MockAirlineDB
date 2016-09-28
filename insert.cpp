#include "Header.h"
void insert(link ptr) {
	link lastptr; //Get end of db
	while (true) {
		if (ptr->next == NULL)break;
		else ptr = ptr->next;
	}
	lastptr = ptr;
	ptr = newflt2();
	lastptr->next = ptr;
	ptr->last = lastptr;
	return;
}