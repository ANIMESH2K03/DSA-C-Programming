// implementation of linear queue
// TimeComplexity = O(1)[both insertion and delition]

#include<stdio.h>

void enqueue(int*,int*,int*,int*);
void dequeue(int*,int*,int*,int*);
void display(int*,int*,int*,int*);

int main(){
  int max;
  printf("Enter size of Queue :");
  scanf("%d",&max);
  int arr[max],rear=-1,front=0;
  int choise;

  void (*f_pointer[3])(int*,int*,int*,int*)={enqueue,dequeue,display};

  while(1){
    printf("\n---Operation---\n"
    "\n1.enqueue"
    "\n2.dequeue"
    "\n3.display"
    "\n4.exit\nEnter Choise : ");
    scanf("%d",&choise);

    if(choise>=1 && choise<=3){
      f_pointer[choise-1](arr,&rear,&front,&max);
    }else if (choise==4){
      printf("Exit Succesfully..\n");
      break;
    }else{
      printf("Invalid Choise!\n");
    }
  }

  return 0;
}

void enqueue(int* a,int* rear,int* front,int* max){
  if(*rear == *max - 1){
    printf("QUEUE Full!\n");
  }else{
    printf("Enter Element :");
    scanf("%d",&a[*rear+1]);
    (*rear)++;
  }
}
void dequeue(int* a,int* rear,int* front,int* max){
  if(*front > *rear){
    printf("Empty QUEUE!\n");
  }else{
    printf("%d dequeue succesful..",a[*front]);
    (*front)++;
  }
}
void display(int* a,int* rear,int* front,int* max){
  if(*front > *rear){
    printf("Empty Queue!\n");
  }else{
    printf("Queue : ");
    for (int i = *front; i <= *rear; i++){
      printf("%d ",a[i]);
    }
  }
}