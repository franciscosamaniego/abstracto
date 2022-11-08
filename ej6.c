#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n = 0;
int size = 1;
int *stack;

void push(int item) {
  if(n == size) stack = realloc(stack, (size*=2)*sizeof(int));
  stack[n++] = item;
}

int pop(void) {
  int item = stack[--n];
  stack[n] = 0;
  if(n > 0 && n == size/4) stack = realloc(stack, (size/=2)*sizeof(int));
  return item;
}

int size(void) {
  return n;
}

bool isempty(void) {
  return (n == 0) ? true : false;
}

int main(int argc, char *argv[]) {
  stack = calloc(size, sizeof(int));
  return 0;
}
