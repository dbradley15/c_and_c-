/* CS261- Assignment 1 - Pointer Function Practice*/
/* Name: Dan Bradley
 * Date: 12.11.18
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 10
#define ID_RANGE 10
#define SCORE_RANGE 101

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     
     
     struct student * list = malloc(sizeof(struct student) * SIZE);
     
     /*return the pointer*/
     return list;
}


void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     
     int idArr[SIZE] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int scoreArr[SIZE] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

	idArr[0] = (rand() % SIZE) + 1;


	/*This loop will assign a random ID number from 1-10 inside the ID Array. It will scan all earlier contents of the array
	to make sure there are no repeat numbers. If a repeat number is discovered, it will continue assigning a new ID for that
	index until a unique # is finally found*/

	for (int i = 1; i < SIZE; i++) {

		int flag;

		do {
			flag = 0;
			idArr[i] = (rand() % SIZE) + 1;
			
			for (int j = 0; j < i; j++) {
				if (idArr[i] == idArr[j])
					flag = 1;
			}
		} while (flag == 1);
	}

	scoreArr[0] = rand() % SCORE_RANGE;

	/*This loop will assign a random score number from 0-100 inside the Score Array. It will scan all earlier contents of the array
	to make sure there are no repeat numbers. If a repeat number is discovered, it will continue assigning a new Score for that
	index until a unique # is finally found*/

	for (int k = 1; k < SIZE; k++) {

		int flag2;

		do {
			flag2 = 0;
			scoreArr[k] = rand() % SCORE_RANGE;
			
			for (int l = 0; l < k; l++) {
				if (scoreArr[k] == scoreArr[l])
					flag2 = 1;
			}
		} while (flag2 == 1);
	}

	//Assign the random scores and IDs to each student
	for (int m = 0; m < SIZE; m++) {

		students[m].id = idArr[m];
		students[m].score = scoreArr[m];
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < SIZE; i++) {
        printf("ID: %d  Score: %d\n", students[i].id, students[i].score);
    }
    
    printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
     int total = students[0].score;
     int min = students[0].score;
     int max = students[0].score;
     
     for(int i = 1; i < SIZE; i++) {
         total += students[i].score;
         
         if(min > students[i].score) {
            min = students[i].score;
         }
         
         if(max < students[i].score) {
             max = students[i].score;
         }
     }
     
     double avg = total / SIZE;
     printf("The average score is: %g\nThe highest score was: %d\nThe lowest score was: %d\n", avg, max, min);
     
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     
     if(stud != NULL) {
         free(stud);
     }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
