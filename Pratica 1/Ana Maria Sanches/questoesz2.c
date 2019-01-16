#include <stdio.h>
#include <stdlib.h>

#define PI   3.14159

double op1, op2;

double mult_cpy (double val){
  val *= PI;
  printf ("Depois da operacao: %lf\n", op1);
  return val;
}

void mult_ref (double *val){
  *val *= PI;
  printf("Depois da operacao: %lf\n", op2);

}

int main(){

  scanf("%lf %lf", &op1, &op2);
  printf("Por valor: \n Antes da funcao: %lf\n", op1);
  op1 = mult_cpy(op1);
  printf("Depois da funcao: %lf\n", op1);

  printf("Por referencia: \n Antes da funcao: %lf\n", op2);
  mult_ref(&op2);
  printf("Depois da funcao: %lf\n", op2);

}




