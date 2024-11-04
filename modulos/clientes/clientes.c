#include<stdio.h>
#include<stdlib.h>

char tela_modulo_clientes(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Módulo Clientes         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      1 - Cadastrar Cliente                                     ||\n");
    printf("||      2 - Verificar Cliente                                     ||\n");
    printf("||      3 - Alterar Cliente                                       ||\n");
    printf("||      4 - Excluir Cliente                                       ||\n");
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

void tela_cadastrar_cliente(void){
    char cpf[12], nomec[52], celular[15], email[52];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Cadastrar Cliente         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => CPF do cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("||      => Nome do Cliente: ");
    scanf("%s", nomec);
    fgets(nomec, 52, stdin);
    printf("||      => Celular do cliente: ");
    scanf("%s", celular);
    fgets(celular, 15, stdin);
    printf("||      => E-mail do cliente: ");
    scanf("%s", email);
    fgets(email, 52, stdin);
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_verificar_cliente(void){
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        verificar cliente         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => CPF do cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("||\n");
    printf("||      => Nome do Cliente: XXXXXXXX\n");
    printf("||      => CPF do Cliente: XXXXXXXX\n");
    printf("||      => Celular do Cliente: XXXXXXXX\n");
    printf("||      => E-mail do Cliente: XXXXXXXX\n");
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_cliente(void){
    
    char cpf[12], nomec[52], celular[15], email[52];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Alterar Cliente         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => CPF dop cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("\n");
    printf("|| ______________________________________________________________ \n");
    printf("||\n");
    printf("||      => (novo) Nome do cliente: ");
    scanf("%s", nomec);
    fgets(nomec, 52, stdin);
    printf("||      => (novo) Celular do cliente: ");
    scanf("%s", celular);
    fgets(celular, 15, stdin);
    printf("||      => (novo) E-mail do cliente: ");
    scanf("%s", email);
    fgets(email, 52, stdin);
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_cliente(void){
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =          Excluir Cliente         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => CPF do cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("||                                                                ||\n");
    printf("||      => Cliente excluído!                                      ||\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}