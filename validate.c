#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  char value;
  struct node *next;
} node;

node *stack = NULL;

void push(char item) {
  node *t = stack;
  stack = malloc(sizeof(node));
  stack->value = item;
  stack->next = t;
}

char pop(void) {
  char val = stack->value;
  node *t = stack;
  stack = stack->next;
  free(t);
  return val;
}

bool isempty(void) {
  return stack == NULL ? true : false;
}

void printstack(void) {
  for(node *x = stack; x != NULL; x = x->next) {
    printf("%c ", x->value);
  }
  printf("\n");
}

bool esta_balanceado(char *s) {
  int i = 0;
  while (s[i] != 0) {
    if(s[i] == ')') {
      if (pop() != '(') return false;
    } else {
      push(s[i]);
    }
    i++;
  }
  if(!isempty()) return false;
  return true;
}

int main(int argc, char *argv[]) {
  printf("%s\n", esta_balanceado(argv[1]) ? "Si esta" : "No no esta");
  return 0;
}
