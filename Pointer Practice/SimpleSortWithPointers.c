/* CS261- Assignment 1 - Simple Sort with Pointers*/
/* Name: Dan Bradley
 * Date: 12.11.18
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
     
     for(int i = 0; i < n; i++) {
         
         for(int j = i + 1; j < n; j++) {
             
             if(number[i] > number[j]) {
                 int temp = number[i];
                 number[i] = number[j];
                 number[j] = temp;
             }
         }
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int * arr = malloc(sizeof(int) * n);
    
    /*Fill this array with random numbers, using rand().*/
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    
    /*Print the contents of the array.*/
    for(int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
    
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr, n);
    
    /*Print the contents of the array.*/    
    for(int i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }    
    
    return 0;
}
