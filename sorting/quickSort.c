#include<stdio.h>

void swap(int *,int *);
void quickSort(int *,int,int);
int partition(int *,int,int);
void display(int *,int ,int);

int main(){
  int arr[] = {2,7,5,9,3,1,4};
  int len = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr,0,len);
  display(arr,0,len);

  return 0;
}

void display(int *arr,int start,int end){
  for (int i = 0; i < end; i++)
    printf("%d ",arr[i]);
  
}

void swap(int *x,int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quickSort(int *arr,int start,int end){
  if (start >= end-1)
    return;

  int pivet = partition(arr,start,end);
  quickSort(arr,start,pivet);
  quickSort(arr,pivet+1,end);
}

int partition(int *arr,int start,int end){
  int pivet = arr[end-1];
  int i = start-1;

  for (int j = start; j < end - 1; j++){
    if (arr[j] <= pivet){
      swap(&arr[++i],&arr[j]);
    }
  }
  swap(&arr[++i],&arr[end-1]);
  return i;
}