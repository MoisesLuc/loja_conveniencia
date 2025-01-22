#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendas.h"
#include "../produtos/produtos.h"

void modulo_vendas(void) {
    char opcao;
    Venda* vd;

    do {
        opcao = menu_vendas();
        switch(opcao) {
            case '1':
                vd = cadastrar_venda();
                grava_venda(vd);
                free(vd);
                break;
            case '2':
                vd = busca_venda();
                exibe_venda(vd);
                free(vd);
                break;
            case '3':
                atualiza_venda(); 
                free(vd);
                break;
            case '4':
                vd = busca_venda();
                exclui_venda(vd);
                free(vd);
                break;
            }
    } while (opcao != '0');
}

char menu_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("\n============ Módulo Venda =============\n");
    printf("    1 - Cadastrar venda\n");
    printf("    2 - Pesquisar venda\n");
    printf("    3 - Alterar venda\n");
    printf("    4 - Excluir venda\n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

Venda *cadastrar_venda(void) {
    Venda *vnd = (Venda *)malloc(sizeof(Venda));
    printf("\n");
    printf("\n=============== Cadastrar Venda ==============\n");
    printf("\n");
    printf("    Informe o cumpom fiscal: ");
    scanf(" %4[^\n]", vnd->cupom);
    printf("    Informe o código do produto vendido: ");
    scanf(" %5[^\n]", vnd->cod_prodt);
    printf("    Informe o valor da compra: ");
    scanf(" %4[^\n]", vnd->valor);
    printf("    Informe a forma de pagamento: ");
    scanf(" %19[^\n]", vnd->pagamento);
    vnd->status = 'c';
    return vnd;
}

void grava_venda(Venda *vnd) {
    FILE *fp = fopen("vendas.dat", "ab");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para gravação.\n");
        exit(1);
    }
    fwrite(vnd, sizeof(Venda), 1, fp);
    fclose(fp);
}

Venda *busca_venda(void) {
    FILE *fp = fopen("vendas.dat", "rb");
    Venda *vnd = (Venda *)malloc(sizeof(Venda));
    char cupom[5];

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(vnd);
        return NULL;
    }

    printf("\nInforme o cumpom fiscal: ");
    scanf(" %4[^\n]", cupom);
    getchar();

    while (fread(vnd, sizeof(Venda), 1, fp))
    {
        if (strcmp(vnd->cupom, cupom) == 0 && vnd->status != 'd')
        {
            fclose(fp);
            return vnd;
        }
    }

    fclose(fp);
    free(vnd);
    return NULL;
}

void exibe_venda(Venda *vnd) {
    if (vnd == NULL)
    {
        printf("\n= = = = = = = Venda Inexistente  = = = = = = =\n");
    }
    else
    {
        printf("\n= = = = = = =  Venda Cadastrada  = = = = = = =\n");
        printf("    Cupom: %s\n", vnd->cupom);
        printf("    Produtos vendidos: %s\n", vnd->cod_prodt);
        printf("    Total: %s\n", vnd->valor);
        printf("    Forma de pagamento: %s\n", vnd->pagamento);
        printf("    Situação: %s\n", (vnd->status == 'c') ? "Cadastrada" : "Desconhecida");
        printf("\n= = = = = = = = = = = = = = = = = = = = = = = =\n");
    }
    printf("\n");
    printf("Tecle enter para continuar...");
    getchar();

}

void exclui_venda(Venda *vndLido) {
    FILE *fp;
    Venda *vndArq;

    int achou = 0;
    if (vndLido == NULL)
    {
        printf("A venda informada não existe!\n");
    }
    else
    {
        vndArq = (Venda *)malloc(sizeof(Venda));
        fp = fopen("vendas.dat", "r+b");
        if (fp == NULL)
        {
            printf("Ops! Erro abertura do arquivo!\n");
            printf("Não é possível continuar...\n");
            exit(1);
        }

        while (!feof(fp))
        {
            fread(vndArq, sizeof(Venda), 1, fp);
            if ((strcmp(vndArq->cupom, vndLido->cupom) == 0) && (vndArq->status != 'd'))
            {
                achou = 1;
                vndArq->status = 'd';
                fseek(fp, -1 * sizeof(Venda), SEEK_CUR);
                fwrite(vndArq, sizeof(Venda), 1, fp);
                printf("\nVenda excluída!\n");
            }
        }
        if (!achou)
        {
            printf("\nVenda não encontrada!\n");
        }
        fclose(fp);
    }

    printf("\n");
    printf("Tecle enter para continuar...");
    getchar();
}

void regrava_venda(Venda *vnd) {
    int achou;
    FILE *fp;
    Venda *vndLido;

    vndLido = (Venda *)malloc(sizeof(Venda));
    fp = fopen("venda.dat", "r+b");
    if (fp == NULL)
    {
        printf("\nVenda não encontrada!\n");
    }
    while (!feof(fp))
    {
        achou = 0;
        while (fread(vndLido, sizeof(Venda), 1, fp) && !achou)
        {
            fread(vndLido, sizeof(Venda), 1, fp);
            if (strcmp(vndLido->cupom, vnd->cupom) == 0)
            {
                achou = 1;
                fseek(fp, -1 * sizeof(Venda), SEEK_CUR);
                fwrite(vnd, sizeof(Venda), 1, fp);
                break;
            }
        }
        fclose(fp);
        free(vndLido);
    }
}

void atualiza_venda(void) {
    Venda *vnd;
    char *cupom = (char *)malloc(100 * sizeof(char));

    vnd = busca_venda();
    if (vnd == NULL)
    {
        printf("\n\nVenda não encontrada!\n\n");
    }
    else
    {
        vnd = cadastrar_venda();
        strcpy(vnd->cupom, cupom);
        regrava_venda(vnd);
        free(vnd);
    }
    free(cupom);
}