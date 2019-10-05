/*
 ============================================================================
 Name        : Main.c
 Author      : Aman Verma
 Version     : 1.1 - 05/10/2019
 Description : Implementation of Conway's Game of Life in C using arrays, functions and conditional statements.
 ============================================================================
 */

#include<stdio.h>

//Global variables to store the neighboring cell values
int upLeft = 0;
int up = 0;
int upRight = 0;
int right = 0;
int left = 0;
int downLeft = 0;
int down = 0;
int downRight = 0;

//To count the number of alive cells
int count = 0, genNum = 1;

//A 2D array of original generation
int arr[8][8] = { { 0, 1, 0, 0, 1, 0, 0, 1 }, { 0, 0, 0, 1, 0, 1, 0, 0 }, { 0,
		0, 1, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 1, 0, 0, 0,
		0, 0 }, { 0, 1, 0, 0, 0, 1, 0, 0 }, { 1, 0, 0, 1, 0, 0, 0, 1 }, { 1, 0,
		0, 0, 0, 0, 0, 0 }, };

//A 2D array to store next generations
int gen[8][8];

int main() {

	//Variables for loops
	int i, j, num;

	//Function declaration
	void nextGen(int, int);

	//Printing original generation
	printf("Original:\n");
	fflush(stdout);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d ", arr[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}

	//Prompt to input number of generations required
	printf("\nEnter number of generations: ");
	fflush(stdout);
	scanf("%d", &genNum);

	if (genNum < 1) {
		genNum = 1;
	}

	for (num = 1; num <= genNum; num++) {

		//Making the duplicate of array
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				gen[i][j] = arr[i][j];
			}
		}

		//Logic for next generation
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				count = 0;

				//Assigning values of neighboring cells
				upLeft = arr[i - 1][j - 1];
				up = arr[i - 1][j];
				upRight = arr[i - 1][j + 1];
				left = arr[i][j - 1];
				right = arr[i][j + 1];
				downLeft = arr[i + 1][j - 1];
				down = arr[i + 1][j];
				downRight = arr[i + 1][j + 1];

				//The above variables may contain garbage values due to array index out of bound
				//So the cells containing the garbage value or 0 is considered as dead

				//Applying CGOL rules for cell at row i and column j.
				nextGen(i, j);

			}

		}
		printf("\nGeneration %d:\n", num);
		fflush(stdout);
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				printf("%d ", gen[i][j]);
				fflush(stdout);
			}
			printf("\n");
			fflush(stdout);
		}

		//Making original array equal to changed array
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				arr[i][j] = gen[i][j];
			}
		}

	}

	return 0;

}

//Function definition
void nextGen(int i, int j) {

	//Counting number of alive cells
	if (upLeft == 1) {
		count++;
	}

	if (up == 1) {
		count++;
	}

	if (upRight == 1) {
		count++;
	}

	if (left == 1) {
		count++;
	}

	if (right == 1) {
		count++;
	}

	if (downLeft == 1) {
		count++;
	}

	if (down == 1) {
		count++;
	}

	if (downRight == 1) {
		count++;
	}

	// Under-population - Cell dies if there are less than 2 alive neighboring cells
	if (count < 2)
		gen[i][j] = 0;

	//Over-population - Cell dies if there are more than 3 alive neighboring cells
	else if (count > 3)
		gen[i][j] = 0;

	//Alive - Cell becomes alive if there are 3 alive neighboring cells
	else if (count == 3)
		gen[i][j] = 1;

	//Else the cell remain unchanged
	else
		gen[i][j] = arr[i][j];

}

