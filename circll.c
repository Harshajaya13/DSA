#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
  };struct node *head = NULL,*tail = NULL;
  
  void insert(){
      struct node *new_node = (struct node *)malloc(sizeof(struct node));
          printf("Enter the data to insert: ");
           scanf("%d", &new_node->data);
        if(head == NULL) {
          head = tail = new_node;
          new_node -> next = head;
          return;
        }
          int opt, pos, i = 1;
      printf("Enter the option to perform the opeartion \n 1.Start \n 2.End \n 3.Position\n: ");
      scanf("%d",&opt);
         
      switch(opt) {
          case 1:
                  new_node -> next = head;
                  head = new_node;
                  tail->next = new_node;
                  break;

          case 2:
                  tail->next = new_node;
                  tail = new_node;
                  tail->next = head;
                  break;

         case 3:
                  printf("Enter the position: ");
                  scanf("%d",&pos);
                  if(pos ==1) {
                      new_node -> next = head;
                      head = new_node;
                      tail->next = new_node;
                    }
                  else {
                      struct node *temp = head;
                      while(temp->next != head && i<pos-1) {
                          temp = temp->next;
                          i++;
                        }
                        if(i != pos-1) {
                            printf("enter the valid position");
                            free(new_node);
                            return;
                          }
                        new_node ->next = temp->next;
                        temp -> next = new_node;
                        if(temp == tail) {
                        tail = new_node;
                         }
                    }
                    break;
          default : printf("enter a valid number");
          break;
        }
    }

         void deletenode() {
             struct node *temp = head,*prev= NULL;
              int opt,pos,i=1;
              if(head == NULL) {
              printf("list is empty");
              return;
              }
             printf("enter the operation you want to perfrom \n 1.start \n 2.end \n 3.position: ");
            scanf("%d",&opt);
            switch(opt) {
             case 1:  
                    if(head == tail) {
                      free(head);
                      head = tail = NULL;
                     }
                     else {
                      temp = head;
                      head = head->next;
                      tail->next = head;
                      free(temp);
                       }
                       break;
              
            case 2: 
                      if(head == tail) {
                      free(head);
                      head = tail = NULL;
                     }
                      else {
                        temp = head;
                        while(temp->next != head)
                        {
                          prev = temp;
                          temp = temp->next;
                         }
                         free(temp);
                        prev ->next = head;
                        tail = prev;
                       }
                        break;

            case 3: 
                    printf("enter the position: ");
                    scanf("%d",&pos);
                    if(pos ==1 ) {
                        if(head == tail) {
                       free(head);
                        head = tail = NULL;
                         return;
                      }
                    else {
                        temp = head;
                        head = head->next;
                        tail->next = head;
                        free(temp);
                       }
                    
                    }
                     else {
                      temp = head;
                      while(i<pos-1 && temp->next != head) {
                      temp = temp->next;
                      i++;
                     }  
                      if(temp ->next == head && i!=pos-1) {
                      printf("invalid position");
                      return;
                       }
                    struct node *extra = temp->next;
                    temp->next = extra->next;
                    if(extra == tail){
                      tail = temp;
                    }
                  }
                      break;
              default :
                        printf("enter a valid number");

            }
         }

        void traverse() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    printf("%d -> ", temp->data); // print head
    temp = temp->next;

    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("(head)\n");
}
      void search() {
        int data,pos,i=1;
        struct node *temp = head;
        printf("enter the data");
        scanf("%d",&data);
      if(head == NULL) {
      printf("List is empty");
  } else {
    while(temp ->next != head) {
        if(temp->data == data) {
        printf("found");
        return;
      }
        temp = temp->next;
        i++;
    }
  }
  printf("not found");
}
 int main()
{
   int opt;
    do {
     printf("\nChoose an operation to perform:\n1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Exit\n");
        scanf("%d", &opt);
     switch(opt) {
      case 1:
                insert();
                break;
            case 2:
                deletenode();
                break;
            case 3:
                traverse();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (opt != 5);
  return 0;
 }






















