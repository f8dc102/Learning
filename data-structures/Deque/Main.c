#include "Deque.c"
#include <stdio.h>

int main() {
  // Create a new Deque
  Deque *DQ = create();

  // Check if Deque creation was successful
  if (DQ == NULL) {
    printf("Failed to create Deque\n");
    return -1;
  } else {
    printf("Deque created successfully\n");
  }

  // Insert elements at the front and rear
  for (int i = 0; i < 5; i++) {
    insertFront(DQ, i);

    printf("Inserted at front: %d\n", i);
  }

  for (int i = 5; i < 10; i++) {
    insertRear(DQ, i);

    printf("Inserted at rear: %d\n", i);
  }

  // Print the front and rear elements
  printf("Front: %d\n", getFront(DQ));
  printf("Rear: %d\n", getRear(DQ));

  // Delete elements from the front and rear
  element front = deleteFront(DQ);
  element rear = deleteRear(DQ);

  // Print the deleted elements
  printf("Deleted from front: %d\n", front);
  printf("Deleted from rear: %d\n", rear);

  // Check if the deque is empty
  if (isEmpty(DQ)) {
    printf("Deque is empty\n");
  } else {
    printf("Deque is not empty\n");
    printf("Now Front: %d\n", getFront(DQ));
    printf("Now Rear: %d\n", getRear(DQ));
  }

  return 0;
}
