#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(void) {
  List *list1 = createList();
  List *list2 = createList();

  // lê entrada
  char *input;
  size_t length = 0;
  ssize_t read;

  printf("enter number: ");
  read = getline(&input, &length, stdin);
  
  storeInputInList(list1, input);
  printReverse(list1);

  // printf("enter number: ");
  // scanf("%d", &input);
  // storeInputInList(list2, input);
  // printReverse(list2);

  // List *result = multiply(list1, list2);
  // print(result);
// printf("%d", list->length);
  return 0;
}