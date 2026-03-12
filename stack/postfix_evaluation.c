//evaluate posfix expression using stack

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

void push(int*,int*,int);
int pop(int*,int*);

int main(){
  char expression[50];
  printf("Enter Postfix expression : ");
  scanf("%s",expression);
  int len = strlen(expression);

  int stack[10];
  int top=-1,op1,op2;


  for (int i = 0; i < len; i++){

    if(isdigit(expression[i])){
      push(stack,&top,expression[i]-'0');
    }else{
      op2 = pop(stack,&top);
      op1 = pop(stack,&top);

      switch (expression[i])
      {
        case '^':push(stack,&top,pow(op1,op2));break;
        case '*':push(stack,&top,op1*op2);break;
        case '/':push(stack,&top,op1/op2);break;
        case '+':push(stack,&top,op1+op2);break;
        case '-':push(stack,&top,op1-op2);break;
      }
    }
  }
  printf("\noutput %d",stack[top]);
  return 0;
}

void push(int* arr,int* top,int element){
  ++(*top);
  arr[*top] = element;
  // printf("push : %d\n",element);
}

int pop(int* arr,int* top){
  int x = arr[*top];
  (*top)--;
  // printf("pop %d\n",x);
  return x;
}