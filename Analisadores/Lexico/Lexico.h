#ifndef LEXICO_H
#define LEXICO_H
 
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
 
/* ---- Estado do Analisador Sintatico (ja existia) ---- */
extern int  simbolo_lido;
extern int  ocorreu_erro;
 
/* ---- Estado do Analisador Lexico (novo) ---- */
extern char entrada[TAM_MAX_ENTRADA]; /* buffer com a string bruta digitada */
extern int  pos_char;                 /* posicao atual de leitura na string */
 
/* ---- Funcoes do Analisador Lexico ---- */
int  proximo_token(void);
 
/* ---- Funcoes do Analisador Sintatico ---- */
void obtenha_simbolo(void);
void erro(const char *mensagem);
void expr(void);
void termo(void);
void fator(void);
void primario(void);
int  analisador_sintatico(const char *texto_fonte);
 
#endif