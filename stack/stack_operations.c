//Stack Operations using array
//Time Complexity : O(1)[both insertion and deletion]

#include<stdio.h>

void push(int* a,int* top,int* max){
  if(*top == *max - 1){
    printf("Stack Overflow!");
    return;
  }else{
    (*top)++;
    printf("Enter Element : ");
    scanf("%d",&a[*top]);
    printf("%d add to stack succesfully..",a[*top]);
  }
}

void pop(int* a,int* top,int* max){
  if(*top == -1){
    printf("Stack Underflow!");
    return;
  }
  printf("%d pop succesfully..",a[*top]);
  (*top)--;
}

void peek(int *a,int* top,int* max){
  (void)max;

  if(*top == -1){
    printf("Empty Stack!");
  }else{
    printf("Top element : %d",a[*top]);
  }
}

void display(int* a,int* top,int* max){
  (void)max;
  if(*top == -1){
    printf("Empty Stack!");
  }else{
    printf("Stack Elements : ");
    for (int i = *top; i >= 0; i--)
    {
      printf("%d ",a[i]);
    }
  }
}

int main(){
  int max;
  printf("Enter Stack Size(1 to n) : ");
  scanf("%d",&max);

  int arr[max],top=-1,x;
  void (*f_pointer[4])(int *,int *,int *) = {push,pop,peek,display};

  while(1){
    printf("\nEnter Stack Operations : \n"
    "1.push\n"
    "2.pop\n"
    "3.peek\n"
    "4.display\n"
    "5.Exit\nEnter choise : ");

    scanf("%d",&x);
    if(x>=1 && x<=4){
      f_pointer[x-1](arr,&top,&max);
    }else if (x == 5)
    {
      break;
    }else{
      printf("Invalid choise! try again..");
      continue;
    }
    printf("\n");
  }

  return 0;
}
