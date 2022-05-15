#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List *getLongerNumber(List *list1, List *list2) {
  if (list1->length >= list2->length) {
    return list1;
  } else {
    return list2;
  }
}

List *getShorterNumber(List *list1, List *list2) {
  if (list1->length < list2->length) {
    return list1;
  } else {
    return list2;
  }
}

void multiply(List *list1, List *list2) {
  Node *a = list1->tail;
  Node *b = list2->tail;

  List *result = createList();
  List *resultUpperNumbers = createList();
  
  while (a->previous) {
    List *upperNumbers = createList();
    
  }
}