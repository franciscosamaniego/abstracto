#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isempty(void) {
  return first == NULL ? true : false;
}

void enqueue(int item){
  node *t = last;
  last = malloc(sizeof(node));
  last->value = item;
  last->next = NULL;
  if(isempty()) first = last;
  else t->next = last;
}

int deque(void) {
  int val = first->value;
  node *t = first;
  first = first->next;
  if(isempty()) last = NULL;
  free(t);
  return val;
}
