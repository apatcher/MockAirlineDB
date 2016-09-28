#include "Header.h"
link delflt(link ptr) {
	link firstptr;
	link PLAST, PTHIS, PNEXT;//Temporary pointer addresses
	int fltn;
	char temp[10];
	firstptr = ptr;
	printf("Which flight number should be removed? ");
	fltn = atoi(gets(temp));
	while (true) {
		if (ptr->flt == fltn)break;
		else ptr = ptr->next;
		if (ptr == NULL) {
			printf("\nThis flight is not in the database");
			return (firstptr);

		}

	}
	PLAST = ptr->last; 
	PTHIS = ptr;
	PNEXT = ptr->next;
	if (PTHIS == firstptr) {//If the deleted flight is the first flight in the DB, reassign firstptr.
		PNEXT->last = NULL;
		firstptr = PNEXT;
		free(PTHIS);
	}
	else if (PNEXT == NULL) {//If the deleleted flight is the last flight in the database, reassign NULL end pointer.
		PLAST->next = NULL;
		free(PTHIS);
	}
	else {
		PLAST->next = PNEXT;
		PNEXT->last = PLAST;
		free(PTHIS);
	}
	return(firstptr);
}