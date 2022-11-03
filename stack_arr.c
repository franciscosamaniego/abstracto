#include <stdio.h>
#include <stdlib.h>
#define N 300

//globales
int a[N];
int tos = -1;

void push(int val) {
  system("clear");
  tos++;
  a[tos] = val;
}


int isempty(void) {
  return(tos == -1 ? 1 : 0);
}

int pop() {
    system("clear");
  return a[tos--];
}

void print_stack(int a[], int tos) {
  printf("Stack de %d items: (", tos+1);
  for(int i = 0; i <= tos; i++) {
    printf("%d ", a[i]);
  }
  printf(")\n");
  printf("%s\n", isempty() ? "Esta vacia" : "No esta vacia");
}

int main(int argc, char *argv[]) {
  int choice;
  int n;
  while(1) {
    printf("Que queres hacer?\n");
    printf("1) Agregar\n");
    printf("2)Sacar\n");
    printf("3)Ver\n");
    printf("4)Salir\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
      printf("Que numero agregas?\n");
      scanf("%d", &n);
      push(n);
      break;
      case 2:
      pop();
      break;
      case 3:
      print_stack(a,tos);
      break;
      case 4:
      exit(0);
      default:
      printf("Elija una opcion valida\n");
      break;
    }

  }
  return 0;
}
