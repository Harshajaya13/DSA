#include<stdio.h>
#define MAX 10
int stack[MAX];
int top = -1,value;

void push(int value) {
    if(top == MAX-1) {
        printf("stack is overflow");
      }
      else {
          top++;
          stack[top] = value;
          printf("%d is pushed to the list",stack[top]);
        }
  }
  void pop() {
      if(top == -1) {
          printf("the list is underflow");
        }
        else {
           printf("%d  is popped from the list",stack[top]);
            top--;

          }
    }
    void display() {
        for(int i =0;i<=top;i++) {
            printf("%d -> ",stack[i]);
          }
        printf("top");
      }

    void search() {
        int key;
        printf("enter the value of the element");
        scanf("%d",&key);
        for(int i =0;i<=top;i++) {
            if(stack[i] == key) {
                printf("element is found");
                return;
              }
          }
          printf("element is not found");
      }

      int main() {
        int opt;
        do {
        printf("\nselect the option: \n1.push\n2.pop\n3.display\n4.search\n5.exit\n");
        scanf("%d",&opt);
        switch(opt) {
        case 1: 
                printf("enter the value of the element:");
                scanf("%d",&value);
                push(value);
                break;
        case 2: pop();
                break;
      
       case 3: display();
               break;

       case 4: 
              search();
              break;
       case 5: printf("exit");
                break;
      default :
              printf("enter the correct number");
      }
  }
        while(opt!=5);
        return 0;
}
