typedef struct venda Venda;

struct venda {
    char cupom[5]; // Cupom fiscal, trocar por código?
    char cod_prodt[5];
    char valor[5];
    char pagamento[20];
    char status;
};

void modulo_vendas(void);
char menu_vendas(void);
Venda* cadastrar_venda(void);
void grava_venda(Venda*);
void exibe_venda(Venda*);
Venda* busca_venda(void);
void alterar_venda(void);
void lista_venda(void);
void exclui_venda(Venda* vndLido);
void regrava_venda(Venda* vnd);
void atualiza_venda(void);
