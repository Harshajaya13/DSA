#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *start = NULL;

void enqueue(int x) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node)), *temp;
  new_node->data = x;
  new_node->next = NULL;
  if (start == NULL) {
    start = new_node;
  } else {
    temp = start;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

void dequeue() {
  struct node *temp = start;
  if (start == NULL) {
    printf("queue is empty");
  } else {
    temp = start;
    start = start->next;
    free(temp);
  }
}

void display() {
  struct node *temp = start;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

void search() {
  struct node *temp = start;
  int key;
  printf("enter the element to search :");
  scanf("%d", &key);
  while (temp != NULL) {
    if (key == temp->data) {
      printf("data is found");
      return;
    }
    temp = temp->next;
  }
  printf("not found");
}

int main() {
  int opt, x;
  do {
    printf("select an option \n 1. insert \n 2.delete \n 3.display \n 4.search "
           "\n 5. exit \n");
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      printf("enter the data: ");
      scanf("%d", &x);
      enqueue(x);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      search();
      break;
    case 5:
      printf("exit...");
      break;
    default:
      printf("enter a valid number");
    }
  } while (opt != 5);
  return 0;
}
