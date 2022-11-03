#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
} node;

node *stack = NULL;

void push(int item) {
  node *t = stack;
  stack = malloc(sizeof(node));
  stack->value = item;
  stack->next = t;
}

int pop(void) {
  int val = stack->value;
  node *t = stack;
  stack = stack->next;
  free(t);
  return val;
}

void isempty(void) {
  return stack == NULL ? true : false;
}

void printstack(void) {
  for(node *x = stack; x != NULL; x = x->next) {
    printf("%d ", x->value);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  push(5);
  push(1);
  push(2);
  push(3);
  push(4);
  printstack();
  pop();
  printstack();
  pop();
  pop();
  printstack();
  return 0;
}
