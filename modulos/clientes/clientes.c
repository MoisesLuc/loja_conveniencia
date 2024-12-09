#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

char modulo_clientes(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("\n============ Módulo Clientes =============\n");
    printf("    1 - Cadastrar cliente\n");
    printf("    2 - Pesquisar cliente\n");
    printf("    3 - Alterar cliente\n");
    printf("    4 - Excluir cliente\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf("%c", &op);
    getchar();
    return op;
}

Cliente* cadastrar_cliente(void) {
    Cliente* cln = (Cliente*) malloc(sizeof(Cliente));
    printf("\n");
    printf("\n=============== Cadastrar Clientes ==============\n");
    printf("\n");
    printf("    Informe o nome do cliente: ");
    scanf(" %54[^\n]", cln->nome);
    printf("    Informe o CPF do cliente: ");
    scanf(" %10[^\n]", cln->cpf);
    printf("    Informe o e-mail do cliente: ");
    scanf(" %54[^\n]", cln->email);
    printf("    Informe o celular do cliente: ");
    scanf(" %10[^\n]", cln->celular);
    cln->status = 'c';
    return cln;
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

void exibe_cliente(Cliente* cl) {
    if (cl == NULL || cl->status == 'd') {
        printf("Cliente não encontrado ou excluído.\n");
    } else {
        system("clear||cls");
        printf("\n");
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

void exclui_cliente(Cliente* clnLido) {
    FILE* fp;
    Cliente* clnArq;
    
    int achou = 0;
    if (clnLido == NULL) {
        printf("O Cliente informado não existe!\n");
 }
    else {
        clnArq = (Cliente*) malloc(sizeof(Cliente));
        fp = fopen("cliente.dat", "r+b");
        if (fp == NULL) {
            printf("Ops! Erro abertura do arquivo!\n");
            printf("Não é possível continuar...\n");
            exit(1);
 }

        while(!feof(fp)) {
            fread(clnArq, sizeof(Cliente), 1, fp);
            if ((clnArq->cpf == clnLido->cpf) && (clnArq->status != 'x')) {
                achou = 1;
                clnArq->status = 'x';
                fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
                fwrite(clnArq, sizeof(Cliente), 1, fp);
                printf("\nCliente excluído!\n");
 }
 }
        if (!achou) {
            printf("\nCliente não encontrado!\n");
 }
    fclose(fp);
 }
}

void regrava_cliente(Cliente* cln) {
	int achou;
	FILE* fp;
	Cliente* clnLido;

	clnLido = (Cliente*) malloc(sizeof(Cliente));
	fp = fopen("cliente.dat", "r+b");
	if (fp == NULL) {
		printf("\nCliente não encontrado!\n");
	}
	while(!feof(fp)) {
	achou = 0;
	while(fread(clnLido, sizeof(Cliente), 1, fp) && !achou) {
		fread(clnLido, sizeof(Cliente), 1, fp);
		if (strcmp(clnLido->cpf, cln->cpf) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
        	fwrite(cln, sizeof(Cliente), 1, fp);
			break;
		}
	}
	fclose(fp);
	free(clnLido);
}
}