#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

char modulo_produtos(void) {
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
    scanf("%c", &op);
    getchar();
    return op;
}

Produto* cadastrar_produto(void) {
    Produto* pdt = (Produto*) malloc(sizeof(Produto));
    printf("\n");
    printf("\n=============== Cadastrar Produto ==============\n");
    printf("\n");
    printf("    Informe o nome do produto: ");
    scanf(" %54[^\n]", pdt->nomep);
    printf("    Informe o código do produto: ");
    scanf(" %3[^\n]", pdt->codigop);
    printf("    Informe a marca do produto: ");
    scanf(" %19[^\n]", pdt->marca);
    printf("    Informe o preço do produto: ");
    scanf("%f", &pdt->preco);
    pdt->status = 'c';
    return pdt;
}
void grava_produto(Produto* pdt) {
    FILE* fp = fopen("produtos.dat", "ab");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para gravação.\n");
        exit(1);
    }
    fwrite(pdt, sizeof(Produto), 1, fp);
    fclose(fp);
}

Produto* busca_produto(void) {
    FILE* fp = fopen("produtos.dat", "rb");
    Produto* pdt = (Produto*) malloc(sizeof(Produto));
    char codigop[5];

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(pdt);
        return NULL;
    }

    printf("\nInforme o código do produto: ");
    scanf(" %5[^\n]", codigop);

    while (fread(pdt, sizeof(Produto), 1, fp)) {
        if (strcmp(pdt->codigop, codigop) == 0 && pdt->status != 'd') {
            fclose(fp);
            return pdt;
        }
    }

    fclose(fp);
    free(pdt);
    return NULL;
}

void exibe_produto(Produto* pdt) {
    if (pdt == NULL) {
		printf("\n= = = = = = = Cliente Inexistente  = = = = = = =\n");
	} else {
        printf("\n= = = = = = =  Cliente Cadastrado  = = = = = = =\n");
        printf("    Nome: %s\n", pdt->nomep);
        printf("    Código: %s\n", pdt->codigop);
        printf("    Marca: %s\n", pdt->marca);
        printf("    Preço: %f\n", pdt->preco);
        printf("    Situação: %s\n", (pdt->status == 'c') ? "Cadastrado" : "Desconhecida");
    }
    printf("\n");
    printf("Tecle enter para continuar...");
    getchar();
}

void exclui_produto(Produto* pdtLido) {
    FILE* fp;
    Produto* pdtArq;

    int achou = 0;
    if (pdtLido == NULL) {
        printf("O produto informado não existe!\n");
 }
    else {
        pdtArq = (Produto*) malloc(sizeof(Produto));
        fp = fopen("produto.dat", "r+b");
        if (fp == NULL) {
            printf("Ops! Erro abertura do arquivo!\n");
            printf("Não é possível continuar...\n");
            exit(1);
 }

        while(!feof(fp)) {
            fread(pdtArq, sizeof(Produto), 1, fp);
            if ((strcmp(pdtArq->codigop, pdtLido->codigop) == 0) && (pdtArq->status != 'd')) {
                achou = 1;
                pdtArq->status = 'd';
                fseek(fp, -1*sizeof(Produto), SEEK_CUR);
                fwrite(pdtArq, sizeof(Produto), 1, fp);
                printf("\nProduto excluído!\n");
 }
 }
        if (!achou) {
            printf("\nProduto não encontrado!\n");
 }
    fclose(fp);
 }
}

void regrava_produto(Produto* pdt) {
	int achou;
	FILE* fp;
	Produto* pdtLido;

	pdtLido = (Produto*) malloc(sizeof(Produto));
	fp = fopen("produto.dat", "r+b");
	if (fp == NULL) {
		printf("\nProduto não encontrado!\n");
	}
	while(!feof(fp)) {
	achou = 0;
	while(fread(pdtLido, sizeof(Produto), 1, fp) && !achou) {
		fread(pdtLido, sizeof(Produto), 1, fp);
		if (strcmp(pdtLido->codigop, pdt->codigop) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Produto), SEEK_CUR);
        	fwrite(pdt, sizeof(Produto), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(pdtLido);
}
}

void atualiza_produto(void) {
    Produto* pdt;

    // Busca o produto no sistema
    pdt = busca_produto();  // Sem passar argumentos
    if (pdt == NULL) {
        printf("\n\nProduto não encontrado!\n\n");
    } else {
        Produto* novo_pdt = cadastrar_produto();

        // Atualiza o código do produto
        strcpy(novo_pdt->codigop, "12345");

        // Regrava o produto no sistema
        regrava_produto(novo_pdt);

        // Libera memória alocada
        free(novo_pdt);
    }
}

