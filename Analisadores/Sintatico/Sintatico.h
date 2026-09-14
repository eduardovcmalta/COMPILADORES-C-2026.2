#define IDENT     1
#define NUMERO    2
#define MAIS      3
#define MULT      4
#define POTENCIA  5
#define ABRE_PAR  6
#define FECHA_PAR 7
#define FIM       8

int *sequencia;
int  pos;
int  simbolo_lido;
int  ocorreu_erro;


void obtenha_simbolo(void);
void erro(const char *mensagem);
void expr(void);
void termo(void);
void fator(void);
void primario(void);