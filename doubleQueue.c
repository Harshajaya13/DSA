
#include <stdio.h>
#define MAX 30

int cq[MAX];
int f = -1, r = -1;

// --- Helper functions for clarity ---
int isFull() { return ((r + 1) % MAX == f); }

int isEmpty() { return (f == -1); }

// --- Deque Operations ---

// Same as your original enqueue
void insertRear(int x) {
  if (isFull()) {
    printf("Queue is overflow\n");
    return;
  }
  if (isEmpty()) {
    f = r = 0;
  } else {
    r = (r + 1) % MAX;
  }
  cq[r] = x;
}

// NEW FUNCTION: Insert at the front
void insertFront(int x) {
  if (isFull()) {
    printf("Queue is overflow\n");
    return;
  }
  if (isEmpty()) {
    f = r = 0;
  } else {
    // Move front backward, wrapping around if needed
    f = (f - 1 + MAX) % MAX;
  }
  cq[f] = x;
}

// Same as your original dequeue
int deleteFront() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }
  int x = cq[f];
  if (f == r) { // Only one element
    f = r = -1;
  } else {
    f = (f + 1) % MAX;
  }
  return x;
}

// NEW FUNCTION: Delete from the rear
int deleteRear() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }
  int x = cq[r];
  if (f == r) { // Only one element
    f = r = -1;
  } else {
    // Move rear backward, wrapping around if needed
    r = (r - 1 + MAX) % MAX;
  }
  return x;
}

void display() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  int i = f;
  while (1) {
    printf("%d ", cq[i]);
    if (i == r)
      break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main() {
  // You can modify the main function to test the new operations
  // e.g., add options for insertFront and deleteRear
  insertRear(10);
  insertRear(20);
  insertFront(5); // Queue: 5, 10, 20
  display();
  deleteRear(); // Queue: 5, 10
  display();
  deleteFront(); // Queue: 10
  display();

  return 0;
}
