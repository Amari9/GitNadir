#include <stdio.h>
#include <stdlib.h>
#include "questoesz.h"

int main(){

    double n[3], p[3], resultado;
    lerEntrada(&n, &p);
    resultado = medP(n, p);
    salvarResultados(n, p, resultado);

    return 0;

}
