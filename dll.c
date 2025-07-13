#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *previous,*next;
};
struct node *start= NULL,*end = NULL;

void insert()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)),*temp = start;
    int data,opt,pos,i=1;
    new_node ->next = NULL;
    new_node ->previous = NULL;
    if(start == NULL) {
        printf("Enter data: ");
        scanf("%d",&new_node->data);
        start = new_node;
        end = new_node;
        return;
    }
    else{
        printf("which position you want to insert the data \n1.start \n2.end \n3.pos\n");
        scanf("%d",&opt);
        printf("Enter data: ");
        scanf("%d",&new_node->data);

        
        switch(opt)
        {
            case 1: 
                new_node->next = start;
                start->previous = new_node;
                start = new_node;
                break;

            case 2:
                end->next = new_node;
                new_node->previous = end;
                end = new_node;
                break;


            case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            if(pos ==1) {
                new_node -> next = start;
                start->previous = new_node;
                start = new_node;   
            }
            else {
                temp = start;
                while( temp != NULL && i<pos-1) {
                    temp = temp->next;
                    i++;
                }
                if(temp == NULL) {
                    printf("Invalid position\n");
                    free(new_node);
                    return;
                } else {
                    new_node->next = temp->next;
                    if(temp->next != NULL) {
                        temp->next->previous = new_node;
                    }
                    temp->next = new_node;
                    new_node->previous = temp;  
            }
            
          }
            break;
            default:
                printf("Invalid choice\n");
                free(new_node);
                return;
               
       }
    }
}

void deletenode() {
    struct node *temp = start, *extra;
    int opt, pos, i = 1;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    else {
        printf("Delete from what position?\n1.start 2.end 3.pos\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1 :
                temp = start;
                start = start->next;
                if (start != NULL) {
                    start->previous = NULL;
                }
                free(temp);
                break;

            case 2 : 
                if(start ->next == NULL) {
                    free(start);
                    start = NULL;
                    end = NULL;
                } else {
                    while(temp->next->next != NULL) {
                        temp = temp->next;
                    }
                    extra = temp->next;
                    end = temp; 
                    temp->next = NULL;
                    free(extra);
                }
                break;
            
            case 3 : 
            printf("Enter position: ");
            scanf("%d", &pos);
            if(pos == 1) {
                temp = start;
                start = start->next;
                if (start != NULL) {
                    start->previous = NULL;
                }
                free(temp);
            } else {
                while(temp != NULL && i < pos - 1) {
                    temp = temp->next;
                    i++;
                }
                if(temp == NULL || temp->next == NULL) {
                    printf("Invalid position\n");
                } else {
                    extra = temp->next;
                    temp->next = extra->next;
                    if (extra->next != NULL) {
                        extra->next->previous = temp;
                    }
                    free(extra);
                }
            }
        }

    }
}
void traverse() {
    struct node *temp = start;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void search() {
  struct node *temp = start;
    int data;
    if(start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter data to search: ");
    scanf("%d", &data);
    int pos,i= 1;
    while(temp != NULL) {
        if(temp->data == data) {
            printf("Data %d found at position %d\n", data, i);
            return;
        }   
        temp = temp->next;
        i++;  
    }
    printf("Data %d not found in the list\n", data);
}
int main() {
    int opt;
   do {
        printf("choose an operation to perform \n1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Exit\n");
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
    } while(opt != 5);
    return 0;
}
        