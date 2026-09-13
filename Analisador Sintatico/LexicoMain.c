#include <stdio.h>
#include <string.h>
#include "Lexico.h"
 
int main(void){
    char linha[TAM_MAX_ENTRADA];
 
    printf("Digite a expressao: ");
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        return 1;
    }
 
    /* remove o '\n' final que o fgets deixa */
    linha[strcspn(linha, "\n")] = '\0';
 
    analisador_sintatico(linha);
 
    return 0;
}