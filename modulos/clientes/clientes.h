typedef struct cliente Cliente;

struct cliente {
    char nome[55];
    char cpf[11];
    char email[55];
    char celular[11];
    char status;
};

char modulo_clientes(void);
Cliente* cadastrar_cliente(void);
void grava_cliente(Cliente*);
void exibe_cliente(Cliente*);
Cliente* busca_cliente(void);
void alterar_cliente(void);
void lista_cliente(void);
void excluir_cliente(Cliente*);
void exclui_Cliente(Cliente* clnLido);

