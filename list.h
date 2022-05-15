#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node *next;
  struct Node *previous;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
  int length;
} List;

List *createList() {
  List *list = (List *)malloc(sizeof(List));

  list->head = (Node *)malloc(sizeof(Node));
  list->tail = list->head;
  list->length = 0;

  return list;
}

Node *initializeNode(int value) {
  Node *node = (Node *)malloc(sizeof(Node));

  node->value = value;
  node->next = NULL;
  node->previous = NULL;

  return node;
}

int push(List *list, int value) {
  Node *tmp = list->head;

  Node *node = initializeNode(value);
  node->value = value;

  if (list->length == 0) {
    list->head = node;
  }

  while (tmp->next) {
    tmp = tmp->next;
  }

  node->next = tmp->next;
  node->previous = tmp;
  tmp->next = node;

  list->tail = node;
  list->length++;

  return list->length;
}

int pop(List *list) {
  if (list->length == 0) {
    return list->length;
  }

  Node *tmp = list->head;

  while (tmp->next) {
    tmp = tmp->next;
  }

  Node *newTail = tmp->previous;
  newTail->next = NULL;
  list->tail = newTail;
  free(tmp);

  list->length--;
  return list->length;
}

void print(List *list) {
  if (list->length == 0) {
    printf("ERROR: list is empty\n");
    exit(0);
  }
  Node *tmp = list->head;
  while (tmp) {
    printf("%d ", tmp->value);
    tmp = tmp->next;
  }

  printf("\n");
}

void printReverse(List *list) {
  if (list->length == 0) {
    printf("ERROR: list is empty\n");
    exit(0);
  }
  Node *tmp = list->tail;
  while (tmp->previous) {
    printf("%d ", tmp->value);
    tmp = tmp->previous;
  }

  printf("\n");
}

// void storeInputInList(List *list, int entrada) {
//   int digits = entrada;

//   while (digits) {
//     push(list, digits % 100);
//     digits = digits / 100;
//   }
//   printf("\n");
// }

void storeInputInList(List *list, char *input) {
  char *digits = input;
  int inputLength = strlen(digits);

  // inputLength - 3 para ignorar o \0 do final da string
  for(int i = inputLength - 3; i >= 0; i = i-2) {
    char lastDigits[2];
   
      strncpy(lastDigits, digits+i, 2);

    int intLastDigits = atoi(lastDigits);
    push(list, intLastDigits);
    // printf("%d ", intLastDigits);
  }

  if(inputLength % 2 == 0 ) {
    char lastDigits[2];
   
      strncpy(lastDigits, digits, 1);

    int intLastDigits = atoi(lastDigits);
    push(list, intLastDigits);
    // printf("%d ", intLastDigits);
  }

  // printf("\n");
}

List *multiply(List *list1, List *list2){
  Node *upperNumber = list1->tail;
  Node *lowerNumber = list2->tail;

  List *resultList = createList();
  List *remaining = createList();
  while(lowerNumber->previous) {
    
    while(upperNumber->previous) {
      int a = upperNumber->value;
      int b = lowerNumber->value;
      int result = a * b;

      int lastTwoDigits = result % 100;
      printf("%d\n", lastTwoDigits);
      int remainingDigits = result / 100;
      printf("%d\n", remainingDigits);

      push(remaining, remainingDigits);

      push(resultList, lastTwoDigits);
      upperNumber = upperNumber->previous;
    }
    lowerNumber = lowerNumber->previous;
  }

  print(remaining);

  return resultList;
}