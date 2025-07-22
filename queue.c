#include <stdio.h>
#define MAX 10
int r = -1, f = -1, top = -1;
int que[MAX];

void enqueue(int x) {
  if (r == MAX - 1) {
    printf("queue is overflow");
  } else {
    if (f == -1)
      f = 0;
    que[++r] = x;
  }
}

int dequeue() {
  int x;
  if (f == -1) {
    printf("queue is underflow");
  } else {
    x = que[f++];
    return x;
  }
}

void display() {
  if (f == -1) {
    printf("queue is empty");
    return;
  } else {
    int i;
    printf("queue is: ");
    for (i = f; i <= r; i++) {
      printf("%d ", que[i]);
    }
  }
}

void search() {
  int key;
  printf("enter the element to search: ");
  scanf("%d", &key);
  for (int i = f; i <= r; i++) {
    if (que[i] == key) {
      printf("found");
      return;
    }
  }
  printf("not found");
}

int main() {
  int x, opt;
  do {
    printf(
        "\n enter an option:\n 1.insert \n 2.delete \n 3.display \n 4.search "
        "\n 5.exit\n");
    scanf("%d", &opt);
    switch (opt) {
    case 1:
      printf("enter a number: ");
      scanf("%d", &x);
      enqueue(x);
      break;
    case 2:
      x = dequeue();
      printf("deleted element is : %d", x);
      break;
    case 3:
      display();
      break;
    case 4:
      search();
      break;
    case 5:
      printf("exiting...");
      break;
    default:
      printf("enter a correct number ");
      break;
    }
  } while (opt != 5);
  return 0;
}
