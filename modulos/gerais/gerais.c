#include<stdio.h>
#include<stdlib.h>

char menu_principal(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________________________\n");    
    printf("||                                                                ||\n");    
    printf("| = = = = = Sistema de Gestão para uma loja de conveniencia  = = = |\n");    
    printf("||                                                                ||\n");    
    printf("||    1 - Modulo de produtos                                      ||\n");    
    printf("||    2 - Modulo de clientes                                      ||\n");    
    printf("||    3 - Modulo de vendas                                        ||\n");    
    printf("||    4 - Modulo de Entregas                                      ||\n");
    printf("||    5 - Modulo de relatorios                                    ||\n");      
    printf("||    6 - Modulo de informações                                   ||\n");    
    printf("||    7 - Modulo de informações da equipe                         ||\n");    
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

void informacoes_gerais(void){
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________________________\n");    
    printf("||                                                                ||\n");    
    printf("|| = = = = = = = = = Menu de informacões gerais = = = = = = = = = ||\n");    
    printf("||                                                                ||\n");    
    printf("||           Universidade Federal do Rio Grande do Norte          ||\n");    
    printf("||              Centro de Ensino Superior do Seridó               ||\n");    
    printf("||            Departamento de Computação e Tecnologia             ||\n");    
    printf("||               Disciplina DCT1106 -- Programação                ||\n");    
    printf("||         Sistema de gestão para uma loja de conveniencia        ||\n");    
    printf("||                                                                ||\n");    
    printf("||================================================================||\n");   
    printf("||                                                                ||\n");    
    printf("||                                                                ||\n");    
    printf("||  Esse projeto trata do desenvolvimento de um sistema de gestão ||\n");    
    printf("||  para uma loja de conveniência, com o intuito de ser avaliado  ||\n");    
    printf("||  na disciplina DCT1106 - Programação.                          ||\n");    
    printf("||                                                                ||\n");    
    printf("||                                                                ||\n");    
    printf("|==================================================================|\n");    
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void informacoes_da_equipe(void){
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________________________\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =   Menu de informações da equipe  = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||   Projeto desenvolvido por:                                    ||\n");
    printf("||                                                                ||\n");
    printf("||     Eduardo Nascimento Santos                                  ||\n");
    printf("||     github: https://github.com/Eduardo-NSantos                 ||\n");
    printf("||                                                                ||\n");
    printf("||     Luiz Henrique Felix                                        ||\n");
    printf("||     github: https://github.com/LuizFelixDev                    ||\n");
    printf("||                                                                ||\n");
    printf("|==================================================================|\n");    
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}
