//Implementation of Circular queue
//Time Complexity = O(1)[for both insertion and deletion]

#include<stdio.h>

void enqueue(int*,int*,int*,int*);
void dequeue(int*,int*,int*,int*);
void display(int*,int*,int*,int*);

int main(){
  int max;
  printf("Enter Length of Queue : ");
  scanf("%d",&max);

  int arr[max],choise,front=-1,rear=-1;
  void (*f_pointer[3])(int*,int*,int*,int*)={enqueue,dequeue,display};

  while (1){
    printf("\n---Operations---"
    "\n1.Enqueue"
    "\n2.Dequeue"
    "\n3.Display"
    "\n4.Exit\nEnter choise : ");
    scanf("%d",&choise);

    if(choise>=1 && choise<=3){
      f_pointer[choise-1](arr,&front,&rear,&max);
    }else if (choise == 4){
      printf("Succesfully EXIT..");
      break;
    }else{
      printf("Invalid Choise!");
    }
  }
  return 0;
}

void enqueue(int* a,int* front,int* rear,int* max){
  if (*front == (*rear + 1) % *max){
    printf("Queue full!\n");
    return;
  }

  int x;
  printf("Enter Element : ");
  scanf("%d",&x);

  if(*front == -1 && *rear == -1){
    *front = *rear = 0;
  }else{
    *rear = (*rear + 1) % *max;
  }
  a[*rear] = x;

}
void dequeue(int* a,int* front,int* rear,int* max){
  if (*front==-1){
    printf("Empty Queue!\n");
    return;
  }
  printf("%d Dequeue..\n",a[*front]);

  if(*front == *rear){
    *front = *rear = -1;
  }else
  {
    *front = (*front + 1) % *max;
  }
}

void display(int* a,int* front,int* rear,int* max){
  if (*front == -1){
    printf("Empty Queue!\n");
    return;
  }

  int x = *front;

  while (1)
  {
    printf("%d ",a[x]);
    if (x == *rear){
     break;
    }
    x = (x+1) % *max;
  }
  printf("\n");
  
}