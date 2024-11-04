#include <stdio.h>
#include <stdlib.h>

char tela_modulo_vendas(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________________________\n");    
    printf("||                                                                ||\n");    
    printf("| = = = = = Sistema de Gestão para uma loja de conveniencia  = = = |\n");    
    printf("||                                                                ||\n");    
    printf("||    1 - Cadastrar venda                                         ||\n");    
    printf("||    2 - alterar venda                                           ||\n");    
    printf("||    3 - Excluir venda                                           ||\n");    
    printf("||    4 - Exibir venda                                            ||\n");    
    printf("||    0 - sair                                                    ||\n");    
    printf("||                                                                ||\n");    
    printf("||    => Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("||                                                                ||\n");    
    printf("|==================================================================|\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}

void tela_cadastrar_venda(void){
    char cpf[12], produtos_vendidos[6], opcao_entrega[15], valor_total[9], codigo[11];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Cadastrar venda           = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => CPF do cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("||      => Produtos vendidos: ");
    scanf("%s", produtos_vendidos);
    fgets(produtos_vendidos, 6, stdin);
    printf("||      => Opção de entrega: ");
    scanf("%s", opcao_entrega);
    fgets(opcao_entrega, 15, stdin);
    printf("||      => Valor total: ");
    scanf("%s", valor_total);
    fgets(valor_total, 9, stdin);
    printf("||      => Código da venda: ");
    scanf("%s", codigo);
    fgets(codigo, 11, stdin);
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_alterar_venda(void){
    char cpf[12], produtos_vendidos[6], opcao_entrega[15], valor_total[9], codigo[11];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =         Alterar venda            = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código da venda: ");
    scanf("%s", codigo);
    fgets(codigo, 11, stdin);
    printf("||      => (Novo) CPF do cliente: ");
    scanf("%s", cpf);
    fgets(cpf, 12, stdin);
    printf("||      => (Novo) Produtos vendidos: ");
    scanf("%s", produtos_vendidos);
    fgets(produtos_vendidos, 6, stdin);
    printf("||      => (Novo) Opção de entrega: ");
    scanf("%s", opcao_entrega);
    fgets(opcao_entrega, 15, stdin);
    printf("||      => (Novo) Valor total: ");
    scanf("%s", valor_total);
    fgets(valor_total, 9, stdin);
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_excluir_venda(void){
    char codigo[11];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =           Excluir venda          = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código da venda: ");
    scanf("%s", codigo);
    fgets(codigo, 11, stdin);
    printf("||                                                                ||\n");
    printf("||      => Venda excluída!                                        ||\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_exibir_venda(void){
    char codigo[11];

    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =         verificar venda          = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      => Código da venda: ");
    scanf("%s", codigo);
    fgets(codigo, 11, stdin);
    printf("||\n");
    printf("||      => CPF do Cliente: XXXXXXXX\n");
    printf("||      => Produtos vendidos: XXXXXXXX\n");
    printf("||      => Opção de entrega: XXXXXXXX\n");
    printf("||      => Valor total: XXXXXXXX\n");
    printf("||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}