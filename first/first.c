#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _GNU_SOURCE

int createEven(int* data, int* even, int size);
int createOdd(int* data, int* odd, int size);

int main(int argc, char** argv) {
     FILE *file = fopen(argv[1], "r");
     int size, evenSize, oddSize = 0;
     int data[20], odd[20], even[20];

     if(file == NULL){
         printf("error\n");
         return 0;
     }
     //get the size
     fscanf(file, "%d", &size);
     
     //store the array
     for(int i = 0; i<size; i++){
        fscanf(file, "%d", &data[i]);
     }

    evenSize = createEven(data, even, size);
    oddSize = createOdd(data, odd, size);

    for(int i = 0; i<evenSize; i++){
        printf("%d\t", even[i]);
    }
    for(int i = 0; i<oddSize; i++){
        if(i+1==oddSize)
            printf("%d", odd[i]);
        else
            printf("%d\t", odd[i]);
    }
    return 0;
}

//creates the even number array and sorts them in ascending order
int createEven(int* data, int* even, int size){
  int evenCounter = 0;
  for(int i = 0; i<size; i++){
      if(data[i]%2==0){
          even[evenCounter] = data[i];
          evenCounter++;
      }
  }
  for(int i = 0; i<evenCounter-1; i++){
      for(int j = i+1; j<evenCounter; j++){
          if(even[i] > even[j]){
              int temp = even[i];
              even[i] = even[j];
              even[j] = temp;
          }
      }
  }
  return evenCounter;
}

//creates the odd number array and sorts them in descending order
int createOdd(int* data, int* odd, int size){
  int oddCounter = 0;
  for(int i = 0; i<size; i++){
      if(data[i]%2!=0){
          odd[oddCounter] = data[i];
          oddCounter++;
      }
  }
  for(int i = 0; i<oddCounter-1; i++){
      for(int j = i+1; j<oddCounter; j++){
          if(odd[i] < odd[j]){
              int temp = odd[i];
              odd[i] = odd[j];
              odd[j] = temp;

          }
      }
  }
  return oddCounter;
}







