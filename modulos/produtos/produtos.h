typedef struct produto Produto;

struct produto {
    char nomep[55];
    char codigop[5];
    char marca[20];
    float preco;
    char status;
};

void modulo_produtos(void);
char menu_produtos(void);
Produto* cadastrar_produto(void);
void grava_produto(Produto*);
void exibe_produto(Produto*);
Produto* busca_produto(void);
void alterar_produto(void);
void lista_produto(void);
void exclui_produto(Produto* pdtLido);
void regrava_produto(Produto* pdt);
void atualiza_produto(void);


