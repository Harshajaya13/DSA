#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
  };struct node *start = NULL;

  void insert() {
  int opt,pos,i=1,data;
  printf("Enter where to insert: 1.start \t 2.end \t 3.position: ");
  scanf("%d",&opt);
  printf("enter the data:");
  scanf("%d",&data);
     struct node *new_node = (struct node *)malloc(sizeof(struct node)),*temp= start;
     new_node ->next = NULL;
    new_node->data = data;

  if(start == NULL) {
    start = new_node;
    return;
  } else {
  switch(opt) {
    case 1:
          new_node->next = start;
          start = new_node;
          break;

    case 2:
            temp = start;
          while(temp ->next != NULL) {
          temp = temp->next;
        }
         temp ->next = new_node;
          new_node ->next = NULL;
         break;

    case 3 :

       printf("enter the position you want to insert");
       scanf("%d",&pos);
      if(pos == 1) {
          new_node->next = start;
          start = new_node;
          return;
        } else {
          temp = start;
          while(temp->next != NULL && i<pos-1) {
            temp = temp->next;
            i++;
          }
          if(temp == NULL) {
            printf("invalid position");
          } else {
            new_node ->next = temp->next;
            temp->next = new_node;
          }
        }
          break;
      default: printf("Invalid choice");
              break;
      }
      }
    }

     void deletenode() {
      struct node *temp = start,*extra = start;
      int opt,pos,i=1;
    printf("Enter where to delete the node: 1.start \t 2.end \t3.position : ");
    scanf("%d",&pos);
    if(start == NULL) {
    printf("list is empty");

  } else {
        switch(opt){
        case 1:
            temp = start;
          start = start->next;
          free(temp);
            break;

      case 2:
            temp = start;
          if(start->next == NULL) {
          free(start);
          start = NULL;
        } else {
            while(temp->next->next != NULL) {
            temp = temp->next;
          }
          extra = temp->next;
          temp->next = NULL;
          free(extra);
        }
          break;

      case 3:
        scanf("%d",&opt);
        if(pos ==1 ) {
          temp = start;
          start = start->next;
          free(temp);
        } else {
          while(i<pos-1 && temp!= NULL) {
            temp = temp->next;
            i++;
          }
          if(temp == NULL || temp->next == NULL) {
            printf("invalid position");
          }
          else {
            extra = temp->next;
            temp->next = extra->next;
            free(extra);
          }
        }
       break;
      default : printf("exit");
               break;

        }
    }
  }

 void traverse() {
  struct node *temp = start;
  if(start == NULL) {
    printf("list is empty");
  }
  while(temp != NULL) {
    printf("%d ->",temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

  void search() {
  int pos,i=1,key;
  printf("enter the data");
  scanf("%d",&key);
   struct node *temp = start;
  if(start == NULL) {
    printf("list is empty");
  }
  else {
    while(temp!= NULL) {
      if(temp->data == key) {
        printf("found");
        return;
      }
      temp = temp->next;
      i++;
    }
  }
  printf("not found");
}

int main() {
  int data,opt;
  do {
  printf("enter the operation : \n1.insert \n 2.delete\n3.display\n4.search\n5.exit");
  scanf("%d",&opt);
  switch(opt) {
    case 1:
           insert();
           break;
    case 2:
           deletenode();
           break;
    case 3: traverse();
            break;
    case 4: search();
            break;
    case 5: printf("exit");
            break;
    default: printf("invalid choice");
            break;
  }
  }
  while(opt!=5);
  return 0;
}
