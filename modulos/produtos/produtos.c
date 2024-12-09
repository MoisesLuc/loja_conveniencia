#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"

char tela_modulo_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Módulo Produtos         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      1 - Cadastrar Produto                                     ||\n");
    printf("||      2 - Verificar Produto                                     ||\n");
    printf("||      3 - Alterar Produto                                       ||\n");
    printf("||      4 - Excluir Produto                                       ||\n");
    printf("||      0 - Sair                                                  ||\n");
    printf("||                                                                ||\n");    
    printf("||    => Escolha a opção desejada: ");
    scanf(" %c", &op); 
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}

void tela_cadastrar_produto(void) {
    char nome[20], codigo[10], marca[15], preco[8];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Cadastrar Produto       = = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Nome do produto: ");
    fgets(nome, 20, stdin);
    strtok(nome, "\n"); 
    printf("||      => Código do produto: ");
    fgets(codigo, 10, stdin);
    strtok(codigo, "\n");
    printf("||      => Marca do produto: ");
    fgets(marca, 15, stdin);
    strtok(marca, "\n");
    printf("||      => Preço do produto: ");
    fgets(preco, 8, stdin);
    strtok(preco, "\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_verificar_produto(void) {
    char codigo[10];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Verificar Produto       = = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código do produto: ");
    fgets(codigo, 10, stdin);
    strtok(codigo, "\n");
    printf("||\n");
    printf("||      => Nome do produto: XXXXXXXX\n");
    printf("||      => Código do produto: XXXXXXXX\n");
    printf("||      => Marca do produto: XXXXXXXX\n");
    printf("||      => Preço do produto: XXXXXXXX\n");
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_produto(void) {
    char nome[20], codigo[10], marca[15], preco[8];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Alterar Produto       = = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código do produto: ");
    fgets(codigo, 10, stdin);
    strtok(codigo, "\n");
    printf("\n");
    printf("|| ______________________________________________________________ \n");
    printf("||\n");
    printf("||      => Nome do produto: ");
    fgets(nome, 20, stdin);
    strtok(nome, "\n");
    printf("||      => Marca do produto: ");
    fgets(marca, 15, stdin);
    strtok(marca, "\n");
    printf("||      => Preço do produto: ");
    fgets(preco, 8, stdin);
    strtok(preco, "\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_produto(void) {
    char codigo[10];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Excluir Produto       = = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código do produto: ");
    fgets(codigo, 10, stdin);
    strtok(codigo, "\n");
    printf("||                                                                ||\n");
    printf("||      => Produto excluído!                                      ||\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}