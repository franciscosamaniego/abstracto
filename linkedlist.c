#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char value;
  struct node *next;
} node;

int main(int argc, char *argv[]) {
  node *first = NULL;
  //memory allocate
  first = malloc(sizeof(node));
  first->value = 'T';
  node *second = malloc(sizeof(node));
  second->value = 'E';
  node *third = malloc(sizeof(node));
  third->value = 'H';
  node *fourth = malloc(sizeof(node));
  fourth->value = 'U';
  node *fifth = malloc(sizeof(node));
  fifth->value = 'E';
  node *sixth = malloc(sizeof(node));
  sixth->value = 'L';
  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = NULL;
  for(node *x = first; x != NULL; x = x->next) {
    printf("%c ", x->value);
  }
  printf("\n");
  return 0;
}
