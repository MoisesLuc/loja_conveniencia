#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char tela_entregas(void){
    char op_entregas; 
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =           Menú entregas          = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      1- Verificar entregas pendentes                           ||\n");
    printf("||      2- Confirmar entregas ou cancelar entrega                 ||\n");
    printf("||      0- Sair                                                   ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("||    => Escolha a opção desejada: ");
    scanf("%c", &op_entregas);
    getchar();
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
    return op_entregas;
}

void tela_entregas_pendentes(void){
    char entregas[60];
    strcpy(entregas,"Chico das melancia, rua maledo, 701");
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Entrgas pendêntes         = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||      1- %s                                                     ||\n", entregas);
    printf("||      2- %s                                                     ||\n", entregas);
    printf("||      3- %s                                                     ||\n", entregas);
    printf("||      4- %s                                                     ||\n", entregas);
    printf("||      5- %s                                                     ||\n", entregas);
    printf("||                                                                ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("\n");
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}

void tela_confirmcancel_entregas(void){
    char resp; 
    char num[4];
    system("clear||cls");
    printf("\n");
    printf("|| ______________________________________________________________ ||\n");
    printf("||                                                                ||\n");
    printf("|| = = = = = = = =        Confirmar/cancelar        = = = = = = = ||\n");
    printf("||                                                                ||\n");
    printf("||       Digite o número da entrega: ");
    scanf("%s", num);
    getchar();
    printf("||       Deseja confirmar a entrega?                              ||\n");
    printf("||                                                                ||\n");
    printf("||       obs: 's' para confirmar e 'n' para cancelar              ||\n");
    printf("|| = = = = = = = = = = = = = = = = = = = = = = = =  = = = = = = = ||\n");
    printf("     => Digite a opção desejada(s/n): ");
    scanf("%c", &resp);
    getchar();
    printf("\n");
    if(resp == 's'){
        printf("| Entrega confirmada!\n");
    }else{
        printf("| Entrega cancelada!\n");
    }
    printf("| Tecle <ENTER> para continuar...\n");
    getchar();
}
