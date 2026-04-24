//insertion Sort time complexity O(n^2)

#include<stdio.h>

void display(int *,int);
void insertionSort(int *,int);

int main(){
  int arr[] = {2,7,4,5,9,3,1};
  int len = sizeof(arr)/sizeof(arr[0]);

  insertionSort(arr,len);
  display(arr,len);

  return 0;
}

void display(int *arr,int len){
  for(int i=0;i<len;i++){
    printf("%d , ",arr[i]);
  }
}

void insertionSort(int arr[],int len){
  if(len<=1) return;
  int key,j;

  for(int i = 1; i < len; i++){
    key = arr[i];
    for (j = i; j > 0; j--)
    {
      if (key < arr[j-1])
        arr[j] = arr[j-1];
      else
        break;
    }
    arr[j] = key;
  }
}