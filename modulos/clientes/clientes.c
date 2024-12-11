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
    scanf(" %55[^\n]", cln->nome);
    printf("    Informe o CPF do cliente: ");
    scanf(" %12[^\n]", cln->cpf);
    printf("    Informe o e-mail do cliente: ");
    scanf(" %55[^\n]", cln->email);
    printf("    Informe o celular do cliente: ");
    scanf(" %12[^\n]", cln->celular);
    cln->status = 'c';
    printf("Cliente cadastrado com sucesso!\n"); 
    printf("\n");
    printf("Tecle enter para continuar...\n");
    getchar();
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
    char cpf[11];

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(cln);
        return NULL;
    }

    printf("\nInforme o CPF do cliente: ");
    scanf(" %10[^\n]", cpf);

    while (fread(cln, sizeof(Cliente), 1, fp)) {
        if (strcmp(cln->cpf, cpf) == 0 && cln->status != 'd') {
            fclose(fp);
            return cln;
        }
    }

    fclose(fp);
    free(cln);
    return NULL;
}

void exibe_cliente(Cliente* cln) {
    if (cln == NULL) {
		printf("\n= = = = = = = Cliente Inexistente  = = = = = = =\n");
	} else {
        printf("\n= = = = = = =  Cliente Cadastrado  = = = = = = =\n");
        printf("    Nome: %s\n", cln->nome);
        printf("    CPF: %s\n", cln->cpf);
        printf("    E-mail: %s\n", cln->email);
        printf("    Celular: %s\n", cln->celular);
        printf("    Situação: %s\n", (cln->status == 'c') ? "Cadastrado" : "Desconhecida");
    }
    printf("Tecle enter para continuar...\n");
    getchar();
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
            if ((strcmp(clnArq->cpf, clnLido->cpf) == 0) && (clnArq->status != 'd')) {
                achou = 1;
                clnArq->status = 'd';
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

void atualiza_cliente(void) {
    Cliente* cln;
    char cpf[12];  

    cln = busca_cliente();
    if (cln == NULL) {
        printf("\n\nCliente não encontrado!\n\n");
    } else {
        printf("Informe o novo CPF (11 dígitos): ");
        cln = busca_cliente();

        cln = cadastrar_cliente();
        strcpy(cln->cpf, cpf);  
        regrava_cliente(cln);   
        free(cln);              
    }
}