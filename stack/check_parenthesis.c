//check parenthesises are properly arrange or not


#include<stdio.h>
#include<stdlib.h>

void push(char* a,int* top,char element){
  (*top)++;
  a[*top]=element;
}

void pop(char* a,int* top,char element){
  if (*top == -1){
    printf("invalid");
    exit(0);
  }
  
  if ((element == ']' && a[*top]== '[') || 
      (element == '}' && a[*top] == '{') || 
      (element == ')' && a[*top] == '('))
      {
      (*top)--;
  }else{
    printf("invalid");
    exit(0);
  }
}

int main(){
  int max = 50;
  char arr[max];
  printf("Enter Expression : ");
  scanf("%49s",arr);

  char stack[max];int top = -1,i=0;
  while(1){
    if(arr[i] == '[' || arr[i] == '{' || arr[i] == '('){
      push(stack,&top,arr[i]);
    }else if (arr[i] == ']' || arr[i] == '}' || arr[i] == ')'){
      pop(stack,&top,arr[i]);
    }
    else if (arr[i] == '\0'){
      break;
    }
    i++;
  }

  (top == -1)?printf("valid"):printf("invalid");
  
  return 0;
}