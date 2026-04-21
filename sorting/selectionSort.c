//Selection sort using c programming
/*
Time complexity : O(n^2)
*/

#include<stdio.h>

void display(int *,int);
void swap(int *,int *);
void selectionSort(int *,int);

int main(){
  int arr[] = {64, 7, 25, 12, 22, 11, 35};
  int len = sizeof(arr)/sizeof(arr[0]);

  selectionSort(arr,len);
  display(arr,len);

}

void display(int *arr,int len){

  for(int i=0;i<len;i++){
    printf("%d ,",arr[i]);
  }

}

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int *arr,int len){
  if(len <= 1) return;

  int min = 0;
  for(int i=0;i<len;i++){
    if (arr[min] > arr[i]){
      min = i;
    }
  }
  
  swap(&arr[min],&arr[0]);

  selectionSort(arr + 1,len-1);
}