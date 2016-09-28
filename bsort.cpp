#include "Header.h"
link bsort(link ptr) {
	link firstptr, p0, p1, p2, p3;
	firstptr = ptr;
	int swapcount, passcnt;
	passcnt = 0;
	do {
		ptr = firstptr;
		swapcount = 0;
		do {
			if (ptr->time > ptr->next->time) {
				p0 = ptr->last;
				p1 = ptr;
				p2 = ptr->next;
				p3 = p2->next;
				if (p1 == firstptr) {
					p2->last = NULL;
					p2->next = p1;
					p1->last = p2;
					p1->next = p3;
					p3->last = p1;
					firstptr = p2;
				}
				else if (p3 == NULL) {
					p0->next = p2;
					p2->last = p0;
					p2->next = p1;
					p1->last = p2;
					p1->next = NULL;
				}
				else {
					p0->next = p2;
					p2->last = p0;
					p2->next = p1;
					p1->last = p2;
					p1->next = p3;
					p3->last = p1;
				}
				swapcount++;
			}
			else ptr = ptr->next;
		} while (ptr->next != NULL);
	} while (swapcount > 0);
	return firstptr;
}