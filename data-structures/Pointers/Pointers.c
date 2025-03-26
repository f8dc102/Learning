#include <stdio.h>
#include <stdlib.h> // For malloc(), free() functions

// Function Prototypes
int Basic();
int arrayAndPointer();
int dynamicMemoryAllocation();
int dynamicMemoryAllocation();
int callByReference();

void swap(int *x, int *y);

// Entry Point
int main() {
  // Choose the function to run
  short choice;

  printf("Choose the function to run:\n");
  printf("1. Basic Pointer Example\n");
  printf("2. Array and Pointer Example\n");
  printf("3. Dynamic Memory Allocation Example\n");
  printf("4. Call by Reference Example\n");
  printf("\n");
  printf("Enter your choice: ");

  scanf("%hd", &choice);

  // Add Space
  printf("\n");

  switch (choice) {
  case 1:
    Basic();
    break;
  case 2:
    arrayAndPointer();
    break;
  case 3:
    dynamicMemoryAllocation();
    break;
  case 4:
    callByReference();
    break;
  default:
    printf("Invalid choice!\n");
  }

  return 0;
}

// Basic Pointer Example
int Basic() {
  int a = 10;  // �Ϲ� ����
  int *p = &a; // ������ ���� (p�� a�� �ּҸ� ����)

  printf("a�� ��: %d\n", a);                   // 10
  printf("a�� �ּ�: %p\n", &a);                // �޸� �ּ�
  printf("������ p�� ��(=a�� �ּ�): %p\n", p); // &a�� ����
  printf("������ p�� ����Ű�� ��: %d\n", *p);  // 10 (a�� ��)

  *p = 20; // �����͸� �̿��� a�� ���� ����
  printf("�����͸� ���� ����� a�� ��: %d\n", a); // 20

  return 0;
}

// Array and Pointer Example
int arrayAndPointer() {
  int arr[3] = {10, 20, 30};
  int *p = arr; // �迭 �̸��� ù ��° ������ �ּҸ� ����Ŵ

  printf("arr[0]�� ��: %d\n", *p);       // 10
  printf("arr[1]�� ��: %d\n", *(p + 1)); // 20
  printf("arr[2]�� ��: %d\n", *(p + 2)); // 30

  return 0;
}

// Dynamic Memory Allocation Example
int dynamicMemoryAllocation() {
  int *ptr = (int *)malloc(sizeof(int) * 3); // ���� 3���� ������ �޸� �Ҵ�

  // If memory cannot be allocated then malloc() returns NULL
  if (ptr == NULL) {
    printf("�޸� �Ҵ� ����!\n");

    return 1;
  }

  ptr[0] = 10;
  ptr[1] = 20;
  ptr[2] = 30;

  printf("���� �Ҵ�� �迭: %d, %d, %d\n", ptr[0], ptr[1], ptr[2]);

  free(ptr); // �Ҵ��� �޸� ����
  return 0;
}

// Call by Reference Example
int callByReference() {
  int a = 10, b = 20;
  printf("Before swap: a = %d, b = %d\n", a, b);

  swap(&a, &b); // �����ͷ� ������ �ּҸ� ����

  printf("After swap: a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
