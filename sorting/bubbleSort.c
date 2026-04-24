//Bubble sort using c programming
/*
Time complexity : O(n^2)
*/

#include<stdio.h>

void swap(int *,int *);
void bubble_sort(int *,int);

void display(int *,int);

int main(){
  int arr[] = {5,2,7,4,3,1};
  int len = sizeof(arr)/sizeof(arr[0]);

  bubble_sort(arr,len);
  display(arr,len);

}

void swap(int *x,int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


void bubble_sort(int *arr,int len){
  int temp,large = 0;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if(arr[j]>arr[j+1]){
        swap(&arr[j],&arr[j+1]);
      }
    } 
  }
}

void display(int *arr,int len){
  printf("\nArray : ");
  for (int i = 0; i < len; i++)
  {
    printf("%d  ",arr[i]);
  }
  puts("");
}

