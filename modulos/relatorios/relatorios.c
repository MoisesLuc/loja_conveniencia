#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "../produtos/produtos.h"
#include "../clientes/clientes.h"
#include "../vendas/vendas.h"

void modulo_relatorios(void) {
    char opcao;

    do {
        opcao = menu_relatorios();
        switch(opcao) {
            case '1':
                modulo_rltr_clientes();
                break;
            case '2':
                modulo_rltr_produtos();
                break;
            case '3':
                modulo_rltr_vendas();
                break;
        }
    } while (opcao != '0');
}

void modulo_rltr_clientes(void) {
    char opcao;

    do {
        opcao = menu_rltr_clientes();
        switch (opcao) {
            case '1':
                rltr_todos_clientes();
                break;
            case '2':
                break;
            case '3':
                break;
        }
    } while (opcao != '0');
}

void modulo_rltr_produtos(void) {
    char opcao;

    do {
        opcao = menu_rltr_produtos();
        switch (opcao) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
        }
    } while (opcao != '0');
}

void modulo_rltr_vendas(void) {
    char opcao;

    do {
        opcao = menu_rltr_vendas();
        switch (opcao) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
        }
    } while (opcao != '0');
}

/////////////////// MENUS ////////////////////

char menu_relatorios(void) {
    char op;
    system("clear||cls");
    printf("\n============ Módulo Relatórios =============\n");
    printf("    1 - Relatórios de Clientes\n");
    printf("    2 - Relatórios de Produtos\n");
    printf("    3 - Relatórios de Vendas\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}



char menu_rltr_clientes(void) {
    char op;
    system("clear||cls");
    printf("\n============ Relatório dos Clientes =============\n");
    printf("    1 - Ver Tudo\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void rltr_todos_clientes(void) {
    FILE* fp;
    Cliente* cliente = (Cliente*) malloc (sizeof(Cliente));

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(cliente);
    }

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (cliente != NULL) {
            exibe_cliente(cliente);
        }
    }
    printf("Tecle enter para continuar...\n");
    getchar();

    free(cliente);
    fclose(fp);
}



char menu_rltr_produtos(void) {
    char op = '0';
    system("clear||cls");
    printf("\n============ Relatório dos Produtos =============\n");
    getchar();
    return op;
}

char menu_rltr_vendas(void) {
    char op = '0';
    system("clear||cls");
    printf("\n============ Relatório das Vendas =============\n");
    getchar();
    return op;
}