#include <stdio.h>

#define IDENT       1
#define NUMERO      2
#define MAIS        3
#define MULT        4
#define POTENCIA    5
#define ABRE_PAR    6
#define FECHA_PAR   7
#define FIM         8
#define ERRO_LEXICO 9

#define TAM_MAX_ENTRADA 256

int  simbolo_lido;
int  ocorreu_erro;
char entrada[TAM_MAX_ENTRADA];
int  pos_char;

int proximo_token(void){

    while (entrada[pos_char] == ' '  ||
           entrada[pos_char] == '\t' ||
           entrada[pos_char] == '\n' ||
           entrada[pos_char] == '\r') {
        pos_char++;
    }

    char c = entrada[pos_char];

    if (c == '\0') {
        return FIM;
    }

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        pos_char++;
        while ((entrada[pos_char] >= 'a' && entrada[pos_char] <= 'z') ||
               (entrada[pos_char] >= 'A' && entrada[pos_char] <= 'Z') ||
               (entrada[pos_char] >= '0' && entrada[pos_char] <= '9')) {
            pos_char++;
        }
        return IDENT;
    }

    if (c >= '0' && c <= '9') {
        pos_char++;
        while (entrada[pos_char] >= '0' && entrada[pos_char] <= '9') {
            pos_char++;
        }
        return NUMERO;
    }

    if (c == '+') {
        pos_char++;
        return MAIS;
    }

    if (c == '*') {
        pos_char++;
        if (entrada[pos_char] == '*') {
            pos_char++;
            return POTENCIA;
        }
        return MULT;
    }

    if (c == '(') {
        pos_char++;
        return ABRE_PAR;
    }

    if (c == ')') {
        pos_char++;
        return FECHA_PAR;
    }

    pos_char++;
    ocorreu_erro = 1;
    printf("ERRO LEXICO: caractere invalido '%c'\n", c);
    return ERRO_LEXICO;
}

void obtenha_simbolo(void){
    simbolo_lido = proximo_token();
}

void erro(const char *mensagem){
    printf("ERRO: %s\n", mensagem);
    ocorreu_erro = 1;
}

void expr(void);
void termo(void);
void fator(void);
void primario(void);

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

int analisador_sintatico(const char *texto_fonte){
    int i = 0;

    while (texto_fonte[i] != '\0' && i < TAM_MAX_ENTRADA - 1) {
        entrada[i] = texto_fonte[i];
        i++;
    }
    entrada[i] = '\0';

    pos_char = 0;
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

int main(void){
    char linha[TAM_MAX_ENTRADA];
    int i;

    printf("Digite a expressao: ");
    if (fgets(linha, sizeof(linha), stdin) == NULL) {
        return 1;
    }

    i = 0;
    while (linha[i] != '\0') {
        if (linha[i] == '\n') {
            linha[i] = '\0';
            break;
        }
        i++;
    }

    analisador_sintatico(linha);

    return 0;
}