#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente Cliente;
struct cliente {
    char nome[55];
    char cpf[12];
    char email[55];
    char celular[11];
    char status;
};

int modulo_clientes(void);
Cliente* cadastrar_cliente(void);
void grava_cliente(Cliente*);
void exibe_cliente(Cliente*);
Cliente* busca_cliente(void);
void alterar_cliente(void);
void lista_cliente(void);
void excluir_cliente(Cliente*);

int main(void) {
    Cliente* x;
    int opcao;
    do {
        opcao = modulo_clientes();
        switch (opcao) {
            case 1:
                x = cadastrar_cliente();
                grava_cliente(x);
                free(x);
                break;
            case 2:
                x = busca_cliente();
                if (x != NULL) {
                    exibe_cliente(x);
                    free(x);
                } else {
                    printf("Cliente não encontrado!\n");
                }
                break;
            case 3:
                printf("Função de alteração ainda não implementada.\n");
                break;
            case 4:
                printf("Função de exclusão ainda não implementada.\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
    return 0;
}

int modulo_clientes(void) {
    int op;
    printf("\n============ Módulo Clientes =============\n");
    printf("    1 - Cadastrar cliente\n");
    printf("    2 - Pesquisar cliente\n");
    printf("    3 - Alterar cliente\n");
    printf("    4 - Excluir cliente\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf("%d", &op);
    getchar();
    return op;
}

Cliente* cadastrar_cliente(void) {
    Cliente* cln = (Cliente*) malloc(sizeof(Cliente));
    printf("\n=============== Cadastrar Clientes ==============\n");
    printf("\n");
    printf("    Informe o nome do cliente: ");
    scanf(" %54[^\n]", cln->nome);
    printf("    Informe o CPF do cliente: ");
    scanf(" %11[^\n]", cln->cpf);
    printf("    Informe o e-mail do cliente: ");
    scanf(" %54[^\n]", cln->email);
    printf("    Informe o celular do cliente: ");
    scanf(" %10[^\n]", cln->celular);
    cln->status = 'c';
    return cln;
}

void exibe_cliente(Cliente* cl) {
    if (cl == NULL || cl->status == 'x') {
        printf("Cliente não encontrado ou excluído.\n");
    } else {
        printf("\n==============   Exibir cliente   ==============\n");
        printf("\n");
        printf("\n= = = = = = =  Cliente Cadastrado  = = = = = = =\n");
        printf("    Nome: %s\n", cl->nome);
        printf("    CPF: %s\n", cl->cpf);
        printf("    E-mail: %s\n", cl->email);
        printf("    Celular: %s\n", cl->celular);
        printf("    Situação: %s\n", (cl->status == 'c') ? "Cadastrado" : "Desconhecida");
    }
}

void grava_cliente(Cliente* cln) {
    FILE* fp = fopen("clientes.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        exit(1);
    }
    fwrite(cln, sizeof(Cliente), 1, fp);
    fclose(fp);
}

Cliente* busca_cliente(void) {
    FILE* fp = fopen("clientes.dat", "rb");
    Cliente* cln = (Cliente*) malloc(sizeof(Cliente));
    char cpff[12];

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(cln);
        return NULL;
    }

    printf("\nInforme o CPF do cliente: ");
    scanf(" %11[^\n]", cpff);

    while (fread(cln, sizeof(Cliente), 1, fp)) {
        if (strcmp(cln->cpf, cpff) == 0 && cln->status != 'x') {
            fclose(fp);
            return cln;
        }
    }

    fclose(fp);
    free(cln);
    return NULL;
}