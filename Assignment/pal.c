
#include "pal.h"
#include <stdlib.h>

//--------------------------------------------------
// is_pal
//--------------------------------------------------

int is_pal(int a[]) {
	int flag = 0;
	if ((a[0] == a[5]) && (a[1] == a[4]) &&  (a[2] == a[3])) {
		flag = 1;
	}
	return flag;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------

char ask_for_command() {
	char move = ' ';
	printf("\nNEW MOVEMENT: Enter a valid command by keyword:");
	printf("\nValid commands : a\td\tw\tx\n");
	while (move != 'a' && move != 'd' && move != 'w' && move != 'x') {
		move = my_get_char();
	}
	return move;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------

void process_movement(int a[], int** p, int* num_mov, char c) {
	if (c == 'a') {
		if (*p != a) {
			*num_mov = *num_mov+1;
			*p = (*p - 1);
		}
	}
	else if (c == 'd') {
		if (*p != a+5) {
			*num_mov = *num_mov+1;
			*p = (*p + 1);
		}
	}
	else if (c == 'x') {
		if (**p != 0) {
			*num_mov = *num_mov + 1;
			**p = (**p - 1);
		}
	}
	else if (c == 'w') {
		if (**p != 9) {
			*num_mov = *num_mov + 1;
			**p = (**p + 1);
		}
	}
}

//--------------------------------------------------
// print_arrow
//--------------------------------------------------

void print_arrow(int* p,int a[]) {
	if (p == a)
		printf("\n           ^");
	else if (p == a+1)
		printf("\n             ^");
	else if (p == a+2)
		printf("\n               ^");
	else if (p == a+3)
		printf("\n                 ^");
	else if (p == a+4)
		printf("\n                   ^");
	else if (p == a+5)
		printf("\n                     ^");
}

//--------------------------------------------------
// print_status
//--------------------------------------------------

void print_status(int a[], int* p, int num_mov) {
	printf("------ Game Status -------\n");
	printf("Number = { ");
	for (int i = 0; i < 6; i++)
		printf("%d ",a[i]);
	printf("}\n");
	print_arrow(p,a);
	printf("\nNumber of moves = %d", num_mov);
	printf("\n---------------------------\n");
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------

void user_game_palindrome(int pal_num) {
	srand(time(NULL));
	int a[6];
	int num_moves = 0;
	int index = gen_num(0,5);
	int* index_ptr = &a[index];
	//int** index_ptr_ptr = &index_ptr;
	
	//convert pal_num to array
	int rem = pal_num;
	for (int i = 5; i >= 0; i--) {
		a[i] = rem % 10;
		rem = rem / 10;
	}

	int bool = 0;
	while (bool!=1) {
		bool = is_pal(a);
		print_status(a, index_ptr, num_moves);
		if (bool == 1) {
			printf("----------SOLVED!----------\n");
			printf("---------------------------\n");
		}
		else {
			char c = ask_for_command();
			process_movement(a, &index_ptr, &num_moves, c);
		}
	}
}