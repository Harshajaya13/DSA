/*suppose f is at the 2
r is at the 0
then it is like starts from f where it is the f = 2 and goes to the i !=( r+1) %
max then the 1 is missing not to print as the i != 1 when r is 0 so how can the
as it only prints the presnet elements not deleted ones so i!= (r+1%)max works
as it skips the deleted one unlike the search
even in search when we use the r+1 condition it is like if the f is 3 and r is 0
then it will skip the 1 2 indexs to search for
memory means the slots
like in the music player
when we play the ,music in the circular queue when we delete one item that means
there is  slot free and then we can add a song to fill that space,but we cant
retain that same song because here the slots are retaining not the data ?/
*/

#include <stdio.h>
#define MAX 30
int cq[MAX], r = -1, f = -1, i, x;

void enqueue(int x) {
  if ((r + 1) % MAX == f) {
    printf("queue is oevrflow");
    return;
  }
  if (f == -1) {
    f = r = 0;
    cq[r] = x;
  } else {
    r = (r + 1) % MAX;
    cq[r] = x;
  }
}

int dequeue() {
  if (f == -1) {
    printf("queue is empty");
    return 0;
  }
  int x = cq[f];

  if (f == r) {
    f = r = -1;
  } else {
    f = (f + 1) % MAX;
  }
  return x;
}

void display() {
  if (f == -1) {
    printf("Queue is empty.\n");
    return;
  }

  printf("Queue elements (front to rear): ");
  int i = f;
  while (1) {
    printf("%d ", cq[i]);
    if (i == r) {
      break;
    }
    i = (i + 1) % MAX;
  }
  printf("\n");
}

void search() {
  int key, found = 0;

  if (f == -1) {
    printf("Queue is empty, cannot search.\n");
    return;
  }

  printf("Enter the element to search for: ");
  scanf("%d", &key);

  int i = f;
  int pos_count = 1;

  while (1) {
    if (cq[i] == key) {

      printf("Element %d found at index %d (position %d in queue).\n", key, i,
             pos_count);
      found = 1;
      break;
    }
    if (i == r) {
      break;
    }
    i = (i + 1) % MAX;
    pos_count++;
  }

  if (!found) {
    printf("Element %d not found in the queue.\n", key);
  }
}
int main() {
  int opt;
  do {
    printf("\nenter the operation "
           "\n1.enqueue\n2.dequeue\n3.display\n4.search\n5.exit");
    scanf("%d", &opt);
    switch (opt) {

    case 1:
      printf("Enter value to enqueue: ");
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
    }
  } while (opt != 5);
  return 0;
}
