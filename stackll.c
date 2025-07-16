#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};struct node *top = NULL;

void push(int value) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->next = NULL;
  new_node->data = value;
      new_node->next = top;
      top = new_node;
  printf("%d is pushed to the list",value);
}
 void pop() {
  struct node *temp = top;
  if(top == NULL) {
    printf("stack is empty");
    return; 
  }
    printf("%d is popped out of the list",top->data);
    top= top->next;
   free(temp);
}

void display() {
    struct node *temp = top;
    if(top == NULL) {
    printf("stack is empty");
    return;
  }
  else {
    printf("stack elememts are:\n");
    while(temp!=NULL) {
      printf("%d ->",temp->data);
      temp = temp->next;
    }
    printf("end\n");
  }
}

 void search() {
  int key;
  struct node *temp = top;
  printf("enter the value to search : \n");
  scanf("%d",&key);
  while(temp!=NULL) {
    if(key == temp->data) {
      printf("element is found");
      return;
    }
    temp = temp->next;
  }
  printf("element is not found\n");
}
int main() {
  int opt,value;
  do {
    printf("\nselect the operation you want to perfrom:\n1.push\n2.pop\n3.display\n4.search\n5.exit\n");
    scanf("%d",&opt);
    switch(opt) {
      case 1 :
            printf("enter the data you want to push :");
            scanf("%d",&value);
            push(value);
            break;
      case 2:
            pop();
            break;
      case 3:
             display();
            break;
      case 4: 
            search();
            break;
      case 5: 
            printf("exit");
           break;
      default :
            printf("enter the correct number");
    }
  }
   while(opt!=5);
  return 0;
}




