#include <stdio.h>
#include <stdlib.h>
#define N 100

char operands[N];
char ops[N];
int ops_tos = -1;
int operands_tos = -1;

void printops(void) {
  printf("stack de %d ops (", ops_tos+1);
  for(int i = 0; i <= ops_tos; i++) {
    printf("%c ", ops[i]);
  }
  printf(")\n");
}
void printoperands() {
  printf("stack de %d operandos (", operands_tos+1);
  for(int i = 0; i <= operands_tos; i++) {
    printf("%c ", operands[i]);
  }
  printf(")\n");
 }

void pushops(char val) {
  ops_tos++;
  ops[ops_tos] = val;
}
void pushoperands(char val) {
  operands_tos++;
  operands[operands_tos] = val;
}

int popops(void) {
  return ops[ops_tos--];
}
int popoperands(void) {
  return operands[operands_tos--];
}

int eval(char *expr) {
  int i = 0;
  while(i != 0) {
    if(expr[i] == '+' || expr[i] == '*') {
      pushops(expr[i]);
      i++;
    }else if(expr[i] >= '1' && expr[i] <= '9') {
      pushoperands(atoi(expr));
      while(expr[i] >= '0' && expr[i] <= '9') i++;
    }else if(expr[i] == ')') {
      char op = popops();
      if(op == '+') {
        int a = popoperands();
        int b = popoperands();
        int res = a+b;
        pushoperands(res);
      }
      i++;
    } else {
      i++;
    }
  }
  return popoperands();
}

int main(int argc, char  *argv[]) {
  char *expresion = "((2+2)+8)";
  int res = eval(expresion);
  printops();
  printoperands();
  printf("El resultado de %s es %d\n", expresion, res);
  return 0;
}
