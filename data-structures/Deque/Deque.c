#include "Deque.h"

#include <stdio.h>
#include <stdlib.h>

Deque *create() {
  // Creat a new instance of Deque
  Deque *DQ = (Deque *)malloc(sizeof(Deque));

  // Check if memory allocation was successful
  if (DQ == NULL) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  // Initialize the Deque
  DQ->front = NULL;
  DQ->rear = NULL;

  return DQ;
}

void insertFront(Deque *DQ, element x) {
  // Create a new node
  DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));

  // Check if memory allocation was successful
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  // Check if memory allocation was successful
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  // Set the data and pointers
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = DQ->front;

  // If the deque is empty, set both front and rear to the new node
  if (isEmpty(DQ)) {
    DQ->rear = newNode;
  } else {
    DQ->front->prev = newNode;
  }

  DQ->front = newNode;
}

void insertRear(Deque *DQ, element x) {
  // Create a new node
  DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
  if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
  }

  // Set the data and pointers
  newNode->data = x;
  newNode->prev = DQ->rear;
  newNode->next = NULL;

  // If the deque is empty, set both front and rear to the new node
  if (isEmpty(DQ)) {
    DQ->front = newNode;
  } else {
    DQ->rear->next = newNode;
  }

  DQ->rear = newNode;
}

element deleteFront(Deque *DQ) {
  // Check if the deque is empty
  if (isEmpty(DQ)) {
    printf("Deque is empty\n");
    return -1; // or some other error value
  }

  // Store the data to be returned
  element data = DQ->front->data;

  // Move the front pointer to the next node
  DequeNode *temp = DQ->front;
  DQ->front = DQ->front->next;

  // If the deque becomes empty, set rear to NULL
  if (DQ->front == NULL) {
    DQ->rear = NULL;
  } else {
    DQ->front->prev = NULL;
  }

  // Free the memory of the deleted DequeNode
  free(temp);

  return data;
}

element deleteRear(Deque *DQ) {
  // Check if the deque is empty
  if (isEmpty(DQ)) {
    printf("Deque is empty\n");
    return -1; // or some other error value
  }

  // Store the data to be returned
  element data = DQ->rear->data;

  // Move the rear pointer to the previous node
  DequeNode *temp = DQ->rear;

  // If the deque becomes empty, set front to NULL
  if (DQ->rear == DQ->front) {
    DQ->front = NULL;
  } else {
    DQ->rear->prev->next = NULL;
  }

  DQ->rear = DQ->rear->prev;

  // Free the memory of the deleted DequeNode
  free(temp);

  return data;
}

element getFront(Deque *DQ) {
  // Check if the deque is empty
  if (isEmpty(DQ)) {
    printf("Deque is empty\n");
    return -1; // or some other error value
  }

  // Return the data at the front of the deque
  return DQ->front->data;
}

element getRear(Deque *DQ) {
  // Check if the deque is empty
  if (isEmpty(DQ)) {
    printf("Deque is empty\n");
    return -1; // or some other error value
  }

  // Return the data at the rear of the deque
  return DQ->rear->data;
}

int isEmpty(Deque *DQ) { return DQ->front == NULL; }

int isFull(Deque *DQ) { return 0; }
