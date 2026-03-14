// linkedList in c programming.
/*
This file include basic linked list operations in c language.
learning DSA in c language.
*/

#include<stdio.h>
#include<stdlib.h>

//defining function pointer length
#define len 4

struct node
{
  int value;
  struct node *next;
};

int value_input(){
  int element;
  printf("Enter Element to Insert Begining : ");
  scanf("%d",&element);
  return element;
}

//Function prototyping 
void f_caller(struct node **);
void menu(struct node **);

void display(struct node **);

void insert_begining(struct node **);
void insert_end(struct node **);

//array of function pointer
void (*f_pointer[len])(struct node **) = {
  menu,
  display,
  insert_begining,
  insert_end
};

// main function

int main(){
  struct node *head = NULL;

  f_caller(&head);
  return 0;
}

void f_caller(struct node **head){
  int choise;

  // menu(&(*head));
  menu(head);

  while (1)
  {
    printf("\nEnter choise : ");
    scanf("%d",&choise);

    if (choise >=0 && choise<= len-1)
    {
      f_pointer[choise](head);
    }else if (choise == -1)
    {
      puts("Exit Succesfully!");
      break;
    }else{
      puts("Invalid Choise!");
    }
  }
}

void menu(struct node **head){
  (void)*head;
  printf("\n--LinkedList Operations--\n"

        "\n-1.EXIT."
        "\n0.MENU."
        "\n1.DISPLAY LIST."

        "\n2.Insert at Begining."
        "\n3.Insert at End."

        "\n"
        );
}

void display(struct node **head){
  if (!*head)
  {
    puts("Empty list!");
    return;
  }
  struct node *p = *head;
  printf("HEAD -> ");

  while (p != NULL){
    printf("%d -> ",p->value);
    p = p->next;
  }
  puts("NULL");
}

void insert_begining(struct node **head){
  int element = value_input();

  struct node *newnode = malloc(sizeof(struct node));
  newnode ->value = element;
  newnode ->next = *head;
  *head = newnode;
}

void insert_end(struct node **head){
  int element = value_input();

  struct node *newnode = malloc(sizeof(struct node));
  newnode ->value = element;
  newnode ->next = NULL;

  if (!*head){
    *head = newnode;
    return;
  }

  struct node *p = *head;

  while (p ->next !=NULL){
    p = p->next;
  }
  p-> next = newnode;
   
}
