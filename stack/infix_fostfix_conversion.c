//infix to postfix conversion using stack

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void push(char* arr,int* top,char element){
  (*top)++;
  arr[*top] = element;
}

int checkELement(char element){
  if((element >= 'a' && element<= 'z') ||
            (element>='A' && element<='Z')){
    return 0;
  }
  else if (element == '(' ||
           element == '^' ||
           element == '*' ||
           element == '/' ||
           element == '+' ||
           element == '-')
  {
    return 1;
  }else if (element == ')'){
    return 2;
  }else{
    printf("problem!checkElement_fun(%c)",element);
    exit(1);
  }
}
char pop(char* arr,int* top){
  char x = arr[*top];
  --(*top);
  return x;
}
int precedence(char element){
  if (element == '^'){
    return 3;
  }else if(element == '*' || element == '/'){
    return 2;
  }else if(element == '+' || element == '-'){
    return 1;
  }else if (element == '('){
    return 0;
  }else{
    printf("problem!precendence_fun(%c)",element);
    exit(1);
  }
}


int main(){
  char expression[50];
  printf("Enter Expreession : ");
  scanf("%s",expression);
  int len = strlen(expression);

  char stack[50],postfix[50];
  int stack_top=-1,post_top=-1;

  int x;

  for (int i = 0; i < len; i++){
    x = checkELement(expression[i]);

    //OPERAND
    if (x == 0){
      push(postfix,&post_top,expression[i]);
    } //OPERATOR or (
    else if (x==1){
      if (expression[i]=='('){
        push(stack,&stack_top,expression[i]);
      }else{
        while (stack_top!=-1 && precedence(stack[stack_top]) >= precedence(expression[i])){
         push(postfix,&post_top,pop(stack,&stack_top));
        }
        push(stack,&stack_top,expression[i]);
      }
      
    }
    else if(x==2){
      while (stack[stack_top] != '(')
      {
        push(postfix,&post_top,pop(stack,&stack_top));
      }
      pop(stack,&stack_top);
    }
  }
  
  while (stack_top != -1)
  {
    push(postfix,&post_top,pop(stack,&stack_top));
  }
  postfix[++post_top] = '\0';
  printf("%s",postfix);
  
  return 0;
}