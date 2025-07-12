#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*start = NULL;

void insert(int data)  {
     struct node *new_node = (struct node *)malloc(sizeof(struct node)),*temp;
     new_node -> next = NULL;
     new_node -> data = data;
     int pos,i=1,opt;
        if(start == NULL){
            start = new_node;
        }
        else {
           printf(" which position you want to insert the above data\n1.start \n2.end \n3.pos\n");
            scanf("%d",&opt);
            switch(opt) {
                case 1: 
                new_node ->next = start;
                start = new_node;
                break;

                case 2:
                     temp = start;
                    while(temp ->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                    break;  
                 
                    case 3:
                    printf("enter position: ");
                    scanf("%d",&pos);
                    temp = start;
                    if(pos ==1) {
                        new_node->next = start;
                        start = new_node;
                    }
                    else {
                        temp = start;
                        while(temp!= NULL && i<pos-1){
                            temp = temp->next;
                            i++;
                        }
                        if(temp == NULL) {
                            printf("Invalid position\n");
                            free(new_node);
                        } else {     
                            new_node->next = temp->next;
                            temp->next = new_node;
                        }
                    }
                     break;

                    default:
                    printf("Invalid choice\n");
                    free(new_node);
                }
            }
 }

void deletenode(){
struct node *temp  = start,*extra;
int opt,pos,i=1;
scanf("%d",&opt);
if(start == NULL) {
    printf("List is Empty\n");
    return;     
}
else {
   printf("Delete from what position?\n1.start 2.end 3.pos\n");
    scanf("%d", &opt);
    switch (opt) {
        case 1:
            temp = start;
          start = start->next;
          free(temp);
          break;

          case 2:
            if(start->next == NULL) {
                free(start);
                start = NULL;
            }
            else {
                while(temp ->next->next != NULL) {
                    temp = temp->next;
                }
                extra = temp->next;
                temp->next = NULL;
                free(extra);
            }
            break;
            
            case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            if(pos == 1) {
                start = start->next;
                free(temp); 
            }
            else {
                while(temp != NULL && i < pos - 1) {
                    temp = temp->next;
                    i++;
                }
                if(temp == NULL || temp->next == NULL) {
                    printf("Invalid position\n");
                } else {
                    extra = temp->next;
                    temp->next = extra->next;
                    free(extra);
            }

}

                break;
}
}
}

void traverse(){
    struct node *temp = start;
    if(start == NULL) {
        printf("List is Empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void search(int data) {
    struct node *temp = start;
    int pos,i=1;
    if(start == NULL) {
        printf("List is Empty\n");
        return;
    }
    while(temp != NULL) {
        if(temp->data == data) {
            printf("Element %d found at position %d\n", data, i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Element %d not found in the list\n", data);
}   
 
int main()
{
   int data,opt;
  do{
    printf("\n1.insert\t2.delete\t3.display\t4.search\t5.exit\n");
        scanf("%d", &opt);
        switch(opt){
            case 1:
            printf("enter data: ");
            scanf("%d", &data);
            insert(data);
            break;
            case 2:
            deletenode();
            break;
            case 3:     
            traverse();
            break;  
            case 4:
            printf("enter data to search: ");
            scanf("%d", &data);
            search(data);
            break;
            case 5:
            printf("Exiting...\n");
            break;
            default:
            printf("Invalid choice\n");
        }
  }while(opt!=5);
    return 0;
}