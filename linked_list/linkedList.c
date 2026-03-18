// linkedList in c programming.
/*
This file include basic linked list operations in c language.
learning DSA in c language.
*/

#include<stdio.h>
#include<stdlib.h>

//defining function pointer length
#define len 12

struct node
{
  int value;
  struct node *next;
};

int value_input(){
  int element;
  printf("Enter Element : ");
  scanf("%d",&element);
  return element;
}

//Function prototyping 
void f_caller(struct node **);
void menu(struct node **);

void display(struct node **);

void insert_begining(struct node **);
void insert_end(struct node **);

void insert_before(struct node **);
void insert_after(struct node **);

void delete_beg(struct node **);
void delete_end(struct node **);

void delete_any(struct node **);
void delete_mid(struct node **);

void reverse_display(struct node **);
void physically_reverse(struct node **);

//array of function pointer
void (*f_pointer[len])(struct node **) = {
  menu,
  display,
  insert_begining,
  insert_end,
  insert_before,
  insert_after,
  delete_beg,
  delete_end,
  delete_mid,
  delete_any,
  reverse_display,
  physically_reverse
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

        "\n4.Insert Before an Element."
        "\n5.Insert After an Element."
        
        "\n6.Delete Begining."
        "\n7.Delete End."

        "\n8.Delete Mid."
        "\n9.Delete any."
        
        "\n10.Reverse Display."
        "\n11.Physically Reverse List."
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

void insert_before(struct node **head){
  if (!*head){
    puts("Empty List!");
    return;
  }
  
  int key;
  printf("Enter key:");
  scanf("%d",&key);
  int element=value_input();

  struct node *p = *head;

  struct node *newnode = malloc(sizeof(struct node));
  newnode -> value = element;
  if (p->value==key)
  {
    newnode->next=p;
    *head = newnode;
  }else{
    while (p->next != NULL)
    {
      if (p->next->value==key)
      {
        newnode->next=p->next;
        p->next = newnode;
        return;
      }
      p=p->next;
    }
  }
  puts("Not Found!");
  free(newnode);
  return;
}
void insert_after(struct node **head){
  if (!*head){
    puts("Empty list!");
    return;
  }
  
  int element = value_input();
  int key;
  printf("Enter key : ");
  scanf("%d",&key);

  struct node *p = *head;

  while (p!=NULL)
  {
    if (p->value == key)
    {
      struct node *newnode = malloc(sizeof(struct node));
      newnode->value=element;
      newnode->next = p->next;
      p->next = newnode;
      return;
    }
    p=p->next;
  }
  puts("Not Found key!");
}

void delete_beg(struct node **head){
  if (!*head){
    puts("Empty List");
    return;
  }
  struct node*p = *head;

  *head = p->next;
  free(p);
}
void delete_end(struct node **head){
  if (!*head){
    puts("Empty list!");
    return;
  }
  if ((*head)->next == NULL){
    free(*head);
    *head = NULL;
    return;
  }
  
  struct node *p = *head;
  while (p->next->next != NULL){
    p=p->next;
  }

  free(p->next);
  p->next = NULL;
  
}

void delete_any(struct node **head){

  if (!*head){
    puts("Empty List!");
    return;
  }
  int element;
  printf("Enter Node value to delete : ");
  scanf("%d",&element);

  struct node *forward = *head;
  struct node *prev = NULL;
  
  while (forward!=NULL)
  {
    if (forward -> value == element)
    {
      if (prev == NULL)
      {
        *head = forward->next;
      }else{
        prev ->next = forward->next;
      }
      free(forward);
      return;
    }
    prev = forward;
    forward = forward->next;
  }
  puts("Not Found!");
}
void delete_mid(struct node **head)
{
    if(!*head)
    {
        puts("Empty list!");
        return;
    }

    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *slow = *head;
    struct node *fast = *head;
    struct node *prev = NULL;

    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    free(slow);
}

void reverse_display(struct node **head){
  if (!*head){
    return;
  }

  reverse_display(&(*head) -> next);
  printf("%d -> ",(*head) -> value);
}

void physically_reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *curr = *head;
    struct node *next = NULL;

    while(curr != NULL)
    {
        next = curr->next;   
        curr->next = prev;   

        prev = curr;         
        curr = next;         
    }

    *head = prev;            
}