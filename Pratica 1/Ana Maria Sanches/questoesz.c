#include "questoesz.h"
#include <stdio.h>
#include <stdlib.h>
/*
    Biblioteca de medias com as funcoes utilizadas nas questoes 1, 3, 4 e 5
*/

double soma(double a, double b, double c){
  return a + b + c;
}

double mult(double a, double b, double c){
  return a * b * c;
}

double divi(double a, double b){
  if(b==0) return 0;
  return a/b;
}

double medP(double n[3], double p[3]){

    double med = divi((soma(n[0] * p[0], n[1] * p[1], n[2] * p[2])),(soma(p[0],p[1],p[2])));
    salvarResultados(n, p, med);
    return med;

}

int salvarResultados(double n[3], double p[3], double result){

    FILE *fp;
    if ((fp = fopen("resultados.txt", "r+")) == NULL) {
        printf ("Nao foi possivel abrir o arquivo\n");
        return -1;
    }
    fprintf (fp, "Operacao: (%.2lf * %.2lf + %.2lf * %.2lf + %.2lf * %.2lf)/(%.2lf + %.2lf + %.2lf) = %.2lf\n", n[0], p[0], n[1],p[1], n[2], p[2], n[0], n[1], n[2]);
    fclose(fp);
    return 0;

}

int lerEntrada(double *n[3], double *p[3]){

    FILE *fp;

    if ((fp = fopen("resultados.txt", "r+")) == NULL) {
        printf ("Nao foi possivel abrir o arquivo\n");
        return -1;
    }
    fscanf(fp, "%lf %lf %lf %lf %lf %lf", n[0], n[1], n[2], p[0], p[1], p[2]);
    fclose(fp);

    return 0;

}
