#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 30

char stack[30],x,opt;
int top =-1;

void push(char x){
    if(top == MAX-1) {
        printf("stack is overflow");
        return;
      }else {
          stack[++top] = x;
        }
  }
  char pop(){
      if(top == -1){
          printf("list is underflow");
          return 0;
        } else {
            return stack[top--];
          }
    }

    int precedence(char opt){
        if(opt == '^')return 3;
        if(opt == '*' || opt == '/' || opt == '%') return 2;
        if(opt == '+' || opt=='-') return 1;
        return 0;
      }

      int main(){ 
      int i=0,k=0;
      char infix[30],postfix[30],e;
      printf("enter the expression");
      scanf("%s",infix);
      while(infix[i] != '\0') {
        e = infix[i];
        if(isalpha(e)){
            postfix[k++] = e;
          }
        else if(e == '('){
            push(e);
          }
        else if(e == ')'){
            while(top != -1 && stack[top] != '(' ) {
                postfix[k++] = pop();
              }
              pop();
          }
          else {
              while(top != -1 && precedence(stack[top])>=precedence(e)){
                  postfix[k++] = pop();
                }
                push(e);
            }
            i++;
        }

        while(top != -1){
            postfix[k++] = pop();
          }
         postfix[k] = '\0';  
          printf("postfix: %s\n",postfix);
          return 0;
      }

