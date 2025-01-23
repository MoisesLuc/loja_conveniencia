#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

void modulo_produtos(void) {
    char opcao;
    Produto* pd;

    do {
        opcao = menu_produtos();
        switch(opcao) {
            case '1':
                pd = cadastrar_produto();
                grava_produto(pd);
                free(pd);
                break;
            case '2':
                pd = busca_produto();
                exibe_produto(pd);
                printf("Tecle enter para continuar...\n");
                getchar();
                free(pd);
                break;
            case '3':
                atualiza_produto(); 
                free(pd); 
                break; 
            case '4':
                pd = busca_produto();
                exclui_produto(pd);
                free(pd);
                break;
            }
    } while (opcao != '0');
}

char menu_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("\n============ Módulo Produtos =============\n");
    printf("    1 - Cadastrar produto\n");
    printf("    2 - Pesquisar produto\n");
    printf("    3 - Alterar produto\n");
    printf("    4 - Excluir produto\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Produto *cadastrar_produto(void) {
    Produto *pdt = (Produto *)malloc(sizeof(Produto));
    printf("\n");
    printf("\n=============== Cadastrar Produto ==============\n");
    printf("\n");
    printf("    Informe o nome do produto: ");
    scanf(" %54[^\n]", pdt->nome);
    getchar();
    printf("    Informe o código do produto: ");
    scanf(" %5[^\n]", pdt->codigo);
    getchar();
    printf("    Informe a marca do produto: ");
    scanf(" %19[^\n]", pdt->marca);
    getchar();
    printf("    Informe o preço do produto: ");
    scanf(" %5[^\n]", pdt->preco);
    getchar();
    pdt->status = 'c';
    printf("\n");
    printf("Produto cadastrado com sucesso!\n");
    printf("\n");
    printf("Tecle enter para continuar...\n");
    getchar();
    return pdt;
}

void grava_produto(Produto *pdt) {
    FILE *fp = fopen("produtos.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        exit(1);
    }

    fwrite(pdt, sizeof(Produto), 1, fp);
    fclose(fp);
}

Produto *busca_produto(void) {
    FILE *fp = fopen("produtos.dat", "rb");
    Produto *pdt = (Produto *)malloc(sizeof(Produto));
    char codigo[5];

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(pdt);
        return NULL;
    }

    printf("\nInforme o código do produto: ");
    scanf(" %5[^\n]", codigo);
    getchar();

    while (fread(pdt, sizeof(Produto), 1, fp)) {
        if (strcmp(pdt->codigo, codigo) == 0 && pdt->status != 'd') {
            fclose(fp);
            return pdt;
        }
    }

    fclose(fp);
    free(pdt);
    return NULL;
}

void exibe_produto(Produto *pdt) {
    if (pdt == NULL) {
        printf("\n= = = = = = = Produto Inexistente  = = = = = = =\n");
    }
    else {
        printf("\n= = = = = = =  Produto Cadastrado  = = = = = = =\n");
        printf("    Nome: %s\n", pdt->nome);
        printf("    Código: %s\n", pdt->codigo);
        printf("    Marca: %s\n", pdt->marca);
        printf("    Preço: %s\n", pdt->preco);
        printf("    Situação: %s\n", (pdt->status == 'c') ? "Cadastrado" : "Desconhecida");
        printf("\n= = = = = = = = = = = = = = = = = = = = = = = =\n");
    }
    printf("\n");
}

void exclui_produto(Produto *pdtLido) {
    FILE *fp;
    Produto *pdtArq;

    int achou = 0;
    if (pdtLido == NULL) {
        printf("O produto informado não existe!\n");
    } else {
        pdtArq = (Produto *)malloc(sizeof(Produto));
        fp = fopen("produtos.dat", "r+b");
        if (fp == NULL) {
            printf("Ops! Erro abertura do arquivo!\n");
            printf("Não é possível continuar...\n");
            exit(1);
        }

        while (!feof(fp)) {
            fread(pdtArq, sizeof(Produto), 1, fp);
            if ((strcmp(pdtArq->codigo, pdtLido->codigo) == 0) && (pdtArq->status != 'd')) {
                achou = 1;
                pdtArq->status = 'd';
                fseek(fp, -1 * sizeof(Produto), SEEK_CUR);
                fwrite(pdtArq, sizeof(Produto), 1, fp);
                printf("\nProduto excluído!\n");
                
            }
        }
        if (!achou) {
            printf("\nProduto não encontrado!\n");
        }

        fclose(fp);
    }

    printf("\n");
    printf("Tecle enter para continuar...");
    getchar();
}

void regrava_produto(Produto *pdt) {
    int achou;
    FILE *fp;
    Produto *pdtLido;

    pdtLido = (Produto *)malloc(sizeof(Produto));
    fp = fopen("produto.dat", "r+b");
    if (fp == NULL) {
        printf("\nProduto não encontrado!\n");
    }
    while (!feof(fp)) {
        achou = 0;
        while (fread(pdtLido, sizeof(Produto), 1, fp) && !achou) {
            fread(pdtLido, sizeof(Produto), 1, fp);
            if (strcmp(pdtLido->codigo, pdt->codigo) == 0) {
                achou = 1;
                fseek(fp, -1 * sizeof(Produto), SEEK_CUR);
                fwrite(pdt, sizeof(Produto), 1, fp);
                break;
            }
        }
        fclose(fp);
        free(pdtLido);
    }
}

void atualiza_produto(void) {
    Produto *pdt;

    pdt = busca_produto();
    if (pdt == NULL) {
        printf("\n\nProduto não encontrado!\n\n");
    } else {
        Produto *novo_pdt = cadastrar_produto();
        strcpy(novo_pdt->codigo, "12345");
        regrava_produto(novo_pdt);
        free(novo_pdt);
    }
}
