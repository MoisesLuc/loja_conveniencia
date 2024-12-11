typedef struct cliente Cliente;

struct cliente {
    char nome[55];
    char cpf[12];
    char email[55];
    char celular[12];
    char status;
};

char modulo_clientes(void);
Cliente* cadastrar_cliente(void);
void grava_cliente(Cliente*);
void exibe_cliente(Cliente*);
Cliente* busca_cliente(void);
void alterar_cliente(void);
void lista_cliente(void);
void exclui_cliente(Cliente* clnLido);
void regrava_cliente(Cliente* cln);
void atualiza_cliente(void);


