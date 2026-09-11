#include <stdlib.h>
#include <stdio.h>
#include "Sintatico.h"

int main(void){
    
    int t1[]  = { IDENT, FIM };
    int t2[]  = { IDENT, MAIS, NUMERO, FIM };
    int t3[]  = { IDENT, MULT, NUMERO, FIM };
    int t4[]  = { IDENT, POTENCIA, NUMERO, FIM };
    int t5[]  = { ABRE_PAR, IDENT, MAIS, NUMERO, FECHA_PAR, FIM };
    int t6[]  = { IDENT, MAIS, NUMERO, MULT, IDENT, FIM };
    int t7[]  = { IDENT, MAIS, FIM };
    int t8[]  = { ABRE_PAR, IDENT, MAIS, NUMERO, FIM };
    int t9[]  = { IDENT, MULT, MAIS, NUMERO, FIM };
    int t10[] = { MAIS, IDENT, FIM };

    int *testes[] = { t1, t2, t3, t4, t5, t6, t7, t8, t9, t10 };
    int n = sizeof(testes) / sizeof(testes[0]);

    for (int i = 0; i < n; i++) {
        printf("Teste %d: ", i + 1);
        analisador_sintatico(testes[i]);
    }

    return 0;
}