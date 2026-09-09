#include "analisador.h"

void obtenha_simbolo(void){
    simbolo_lido = sequencia[pos++];
}

void erro(const char *mensagem){
    printf("ERRO: %s\n", mensagem);
    ocorreu_erro = 1;
}

void expr(void){
    termo();
    if (ocorreu_erro) return;
    if (simbolo_lido == MAIS) {
        obtenha_simbolo();
        expr();
    }
}

void termo(void){
    fator();
    if (ocorreu_erro) return;
    if (simbolo_lido == MULT) {
        obtenha_simbolo();
        termo();
    }
}

void fator(void){
    primario();
    if (ocorreu_erro) return;
    if (simbolo_lido == POTENCIA) {
        obtenha_simbolo();
        fator();
    }
}

void primario(void){
    if (simbolo_lido == IDENT) {
        obtenha_simbolo();
    }
    else if (simbolo_lido == NUMERO) {
        obtenha_simbolo();
    }
    else if (simbolo_lido == ABRE_PAR) {
        obtenha_simbolo();
        expr();
        if (ocorreu_erro) return;
        if (simbolo_lido != FECHA_PAR)
            erro("falta ')'");
        else
            obtenha_simbolo();
    }
    else {
        erro("primario invalido");
    }
}

/* procedimento ANALISADOR_SINTATICO */
int analisador_sintatico(int *tokens){
    sequencia = tokens;
    pos = 0;
    ocorreu_erro = 0;

    obtenha_simbolo();
    expr();

    if (ocorreu_erro)
        return 0;

    if (simbolo_lido == FIM) {
        printf("Expressao valida\n");
        return 1;
    } else {
        erro("simbolo inesperado");
        return 0;
    }
}
