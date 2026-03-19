//doubly linked list operations
/*
1.insert beg, intert end, delete first, delete last.
2.insert any,delete any.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  struct node *prev;
  int value;
  struct node *next;
};

void insert_beg(struct node **,struct node **);
void insert_end(struct node **,struct node **);

void delete_first(struct node **,struct node **);
void delete_last(struct node **,struct node **);

void display(struct node **,struct node **);

void f_caller(struct node **,struct node **);

void menu_list();



int main(){
  struct node *head=NULL;
  struct node *tail=NULL;

  f_caller(&head,&tail);

  return 0;
}

void f_caller(struct node **head,struct node **tail){
  int choise;
  void (*f_pointer[6])(struct node **,struct node **) = {
    display,
    insert_beg,
    insert_end,
    delete_first,
    delete_last
  };
  menu_list();
  while (1)
  {
    printf("\nEnter choise : ");
    scanf("%d",&choise);

    if (choise == -1){
      puts("Exit Succesfully..");
      exit(0);
    }else if(choise == 0){
      menu_list();
    }else if (1<=choise && choise<=5){
      f_pointer[choise-1](head,tail);
    }else{
      puts("Invalid choise!");
    }
  }
  
}

void menu_list(){
  printf("\n--Operation--\n"

        "\n-1.Exit."
        "\n0.MENU_list"
        "\n1.Display"
        "\n2.Insert Begining"
        "\n3.Insert End"
        "\n4.Delete First."
        "\n5.Delete Last"
        "\n"
      );
}

void insert_beg(struct node **head,struct node **tail){
  int element;
  printf("Enter Element : ");
  scanf("%d",&element);

  struct node *newnode = malloc(sizeof(struct node));
  newnode -> value = element;
  newnode->prev = NULL;

  if (!*head){
    *head = newnode;
    *tail = newnode;
    newnode->next = NULL;
  }else{
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode; 
  } 
}

void insert_end(struct node **head,struct node **tail){
  int element;
  printf("Enter Element : ");
  scanf("%d",&element);

  struct node *newnode = malloc(sizeof(struct node));
  newnode->value = element;
  newnode ->next = NULL;

  if (!*head){
    *head = newnode;
    *tail = newnode;
    newnode ->prev = NULL;
  }else{
    newnode->prev = *tail;
    (*tail)->next = newnode;
    *tail = newnode;
  }
}

void delete_first(struct node **head,struct node **tail){return;}
void delete_last(struct node **head,struct node **tail){return;}

void display(struct node **head,struct node **tail){
  (void)*tail;
  if (!*head){
    puts("Empty list");
    return;
  }
  struct node *p = *head;

  printf("HEAD -> ");
  while (p != NULL)
  {
    printf("%d -> ",p->value);
    p=p->next;
  }
  puts("NULL");
}