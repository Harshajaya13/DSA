#include<stdio.h>
#include<ctype.h>
#define MAX 30

int top = -1;
int stack[MAX];

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    return stack[top--];
}

int main() {
    char postfix[30];
    char e;
    int i = 0, op1, op2, result;

    printf("Enter postfix expression (only digits & +,-,*,/,%%): ");
    scanf("%s", postfix);
    while (postfix[i] != '\0') {
        e = postfix[i];

        if (isdigit(e)) {
            push(e - '0');  // convert char '5' → int 5
        } else {
            op2 = pop();
            op1 = pop();

            switch (e) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                default:
                    printf("Invalid operator %c\n", e);
                    return 1;
            }

            push(result);
        }
        i++;
    }
    printf("Result = %d\n", pop());
    return 0;
}

