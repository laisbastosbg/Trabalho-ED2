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

void sumRemaining(Node *currentUpperNumber, int remaining) {
  while (remaining > 0) {
    int currentRemaining = remaining % 100;
    int remaining = remaining / 100;

    currentUpperNumber->previous->value += currentRemaining;
  }
}

void multiply(List *list1, List *list2) {
  Node *lowerNumber = list2->head;

  List *finalResult = createList();
  List *resultRemaining = createList();

  while (lowerNumber) {
    Node *upperNumber = list1->head;
    printf("lowerNumber: %d\n", lowerNumber->value);
    List *remaining = createList();
    Node *remainingTmp = remaining->head;
    push(remaining, 0);
    List *resultList = createList();

    while (upperNumber) {
      int a = upperNumber->value;
      int b = lowerNumber->value;
      printf("a = %d\n", a);
      printf("b = %d\n", b);
      printf("c = %d\n", remaining->tail->value);
      int result = (a * b) + remaining->tail->value;
      printf("result = %d\n", result);

      int lastTwoDigits = result % 100;
      int remainingDigits = result / 100;

      if (remainingDigits > 0) {
        push(remaining, remainingDigits);
      } else {
        push(remaining, 0);
      }

      push(resultList, lastTwoDigits);
      remainingTmp = remainingTmp->next;
      upperNumber = upperNumber->next;
    }
    printf("c = %d\n", remaining->tail->value);

    /////
    if (remainingTmp->next) {
      push(resultList, remainingTmp->next->value);
    }
    /////
    printf("------\n");
    printReverse(remaining);
    printReverse(resultList);
    printf("------\n");
    lowerNumber = lowerNumber->next;

    Node *resultListTmp = resultList->head;
  Node *finalResultTmp = finalResult->head;
    List *finalRemaining = createList();
    Node *finalRemainingTmp = remaining->head;
    
    if (finalResult->length == 0) {
      copyList(finalResult, resultList);
    } else {
      while (finalResultTmp->next) {
        // printf("######\n");
        // printf("finalResultTmp->value: %d\n", finalResultTmp->value);
        finalResultTmp = finalResultTmp->next;

        int resultSum = finalResultTmp->value + resultListTmp->value + finalRemaining->tail->value;
        // printf("finalResultTmp->value: %d\n", finalResultTmp->value);
        // printf("-----> resultSum: %d\n", resultSum);
        resultListTmp = resultListTmp->next;
        printf("----> resultListTmp->value: %d\n", resultListTmp->value);

        int rsLastDigits = resultSum % 100;
        int rsRemainingDigits = resultSum / 100;
        printf("rsRemainingDigits: %d\n", rsRemainingDigits);

      if (rsRemainingDigits > 0) {
        push(finalRemaining, rsRemainingDigits);
      } else {
        push(finalRemaining, 0);
      }

        finalResultTmp->value = rsLastDigits;
        // printf("finalResultTmp: %d\n", finalResultTmp->value);
      }

      // if (resultListTmp) {
      // push(finalResult, resultListTmp->value);
      // }
    }

    printReverse(finalResult);

    // printf("limpando aq: ");
  }
}
