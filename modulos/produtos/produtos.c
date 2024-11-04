#include<stdio.h>
#include<stdlib.h>

char tela_modulo_produtos(void){
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
    scanf("%c", &op);
    getchar();
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}

void tela_cadastrar_produto(void){
    char nome[20], codigo[10], marca[15], preco[8];
    

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        cadastrar produto         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Nome do produto: ");
    scanf("%s", nome);
    fgets(nome, 20, stdin);
    printf("||      => Codigo do produto: ");
    scanf("%s", codigo);
    fgets(codigo, 10, stdin);
    printf("||      => Marca do produto: ");
    scanf("%s", marca);
    fgets(marca, 15, stdin);
    printf("||      => Preço do produto: ");
    scanf("%s", preco);
    fgets(preco, 8, stdin);
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_verificar_produto(void){
    char codigo[10];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        verificar produto         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Codigo do produto: ");
    scanf("%s", codigo);
    fgets(codigo, 8, stdin);
    printf("||\n");
    printf("||      => Nome do produto: XXXXXXXX\n");
    printf("||      => Codigo do produto: XXXXXXXX\n");
    printf("||      => Marca do produto: XXXXXXXX\n");
    printf("||      => Preço do produto: XXXXXXXX\n");
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_produto(void){
    char nome[20], codigo[10], marca[15], preco[8];
    

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Alterar Produto         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Codigo do produto: ");
    scanf("%s", codigo);
    fgets(codigo, 8, stdin);
    printf("\n");
    printf("|| ______________________________________________________________ \n");
    printf("||\n");
    printf("||      => Nome do produto: ");
    scanf("%s", nome);
    fgets(nome, 20, stdin);
    printf("||      => Marca do produto: ");
    scanf("%s", marca);
    fgets(marca, 15, stdin);
    printf("||      => Preço do produto: ");
    scanf("%s", preco);
    fgets(preco, 8, stdin);
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();

}

void tela_excluir_produto(void){
    char codigo[10];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Excluir Produto         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Codigo do produto: ");
    scanf("%s", codigo);
    fgets(codigo, 10, stdin);
    printf("||                                                                ||\n");
    printf("||      => Produto excluído!                                      ||\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}
