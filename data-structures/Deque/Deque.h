// Deque.h

typedef int element;

// Node 구조체 정의
typedef struct DequeNode {
  element data;
  struct DequeNode *prev;
  struct DequeNode *next;
} DequeNode;

// Deque 구조체 정의
typedef struct Deque {
  DequeNode *front;
  DequeNode *rear;
} Deque;

// Function Prototypes
Deque *createDeque();

void insertFront(Deque *DQ, element x);
void insertRear(Deque *DQ, element x);

element deleteFront(Deque *DQ);
element deleteRear(Deque *DQ);

element getFront(Deque *DQ);
element getRear(Deque *DQ);

int isEmpty(Deque *DQ);
int isFull(Deque *DQ);
