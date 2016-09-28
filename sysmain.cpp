#include "Header.h"
void main(void) {
	link ptr, firstptr, lastptr;
	int write_flag;
	char sel;
	while (true) {
		printf("\nSelect option:\n");
		printf("(1) Enter new database\n");
		printf("(2)Read database from disk\n");
		printf("(3)Insert new flight into database\n");
		printf("(4)Delete flight from database\n");
		printf("(5)Modify entry in database");
		printf("(6)Time sort database\n");
		printf("(7) Save current database to disk\n");
		printf("(8)Display current database to disk\n");
		printf("(9)Exit the database\n");
		sel = getch();//Get user numerical input for switching
		switch (sel) {
		case '1':
			firstptr = NULL;
			lastptr = NULL;
			while (true) {
				if ((ptr = newflt2()) == NULL) {//Null ptr means database entry is finished
					free(ptr);
					break;
				}
				if (!firstptr) firstptr = ptr;

				else lastptr->next = ptr;

				ptr->last = lastptr;
				lastptr = ptr;



			}
			dispdb(firstptr);
			write_flag = writedb(firstptr);
			break;
		case '2':
			firstptr = readdb();
			if (firstptr == NULL) {
				printf("\nThe specified file does not exist. Try again\n");
				break;
			}
			firstptr = bsort(firstptr);
			dispdb(firstptr);
			break;
		case '3':
			insert(firstptr);
			firstptr = bsort(firstptr);
			dispdb(firstptr);
			break;
		case '4':
			firstptr = delflt(firstptr);
			dispdb(firstptr);
			break;
		case '5':
			modflt(firstptr);
			break;
		case '6':
			firstptr = bsort(firstptr);
		case '7':
			write_flag = writedb(firstptr);
		case '8':
			dispdb(firstptr);
			break;
		case '9':
			exit(0);
		default:
			printf("This was an invalid option. Try again");
		}
	}
}


			

