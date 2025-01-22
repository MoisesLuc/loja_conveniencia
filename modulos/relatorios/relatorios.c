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
                rltr_nome_clientes();
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
                rltr_todos_produtos();
                break;
            // case '2':
            //     rltr_marca_produtos();
            //     break;
            // case '3': 
            //     rltr_prec_produtos();
            //     break;
        }
    } while (opcao != '0');
}

void modulo_rltr_vendas(void) {
    char opcao;

    do {
        opcao = menu_rltr_vendas();
        switch (opcao) {
            case '1':
                rltr_todos_vendas();
                break;
            // case '2':
            //     rltr_valor_vendas();
            //     break;
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
    printf("    2 - Filtrar por Nome\n");
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

void rltr_nome_clientes(void) {
    FILE* fp;
    Cliente* cliente = (Cliente*) malloc (sizeof(Cliente));
    int encontrado = 0;
    char nome[22];

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("\nInforme o nome do cliente: ");
    scanf(" %22[^\n]", nome);
    getchar();

    printf("Relatório de Clientes (Filtrado por Nome: %s):\n", nome);
    printf("-------------------------\n");

    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente->nome, nome) == 0 && cliente->status != 'd') {
            encontrado = 1;
            printf("Nome: %s\n", cliente->nome);
            printf("CPF: %s\n", cliente->cpf);
            printf("Email: %s\n", cliente->email);
            printf("Celular: %s\n", cliente->celular);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o nome: %s\n", nome);
    }

    printf("Tecle enter para continuar...\n");
    getchar();

    free(cliente);
    fclose(fp);
}



char menu_rltr_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n============ Relatório dos Produtos =============\n");
    printf("    1 - Ver Tudo\n");
    printf("    2 - Marca   \n");
    printf("    3 - Preço   \n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void rltr_todos_produtos(void) {
    FILE* fp;
    Produto* produto = (Produto*) malloc (sizeof(Produto));

    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(produto);
    }

    while (fread(produto, sizeof(Produto), 1, fp)) {
        if (produto != NULL) {
            exibe_produto(produto);
        }
    }
    printf("Tecle enter para continuar...");
    getchar();

    free(produto);
    fclose(fp);
} 

// void rltr_produtos_por_marca(const char* marcaFiltro) {
//     FILE* arquivo;
//     Produto entrada;
//     int encontrado = 0;

//     arquivo = fopen("produtos.dat", "rb");
//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo para leitura.\n");
//         return;
//     }

//     printf("Relatório de Produtos (Filtrado por Marca: %s):\n", marcaFiltro);
//     printf("-------------------------\n");

//     while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
//         if (strcmp(entrada.marca, marcaFiltro) == 0) {
//             encontrado = 1;
//             printf("ID Código: %d\n", entrada.id_codigo);
//             printf("Nome: %s\n", entrada.nomep);
//             printf("Marca: %s\n", entrada.marca);
//             printf("Quantidade em Estoque: %d\n", entrada.codigop);
//             printf("Valor: %s\n", entrada.preco);
//             printf("-------------------------\n");
//         }
//     }

//     if (!encontrado) {
//         printf("Nenhum produto encontrado com a marca: %s\n", marcaFiltro);
//     }

//     fclose(arquivo);
// }

// void rltr_produtos_por_prec(const char* precoFiltro) {
//     FILE* arquivo;
//     Produto entrada;
//     int encontrado = 0;

//     arquivo = fopen("produtos.dat", "rb");
//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo para leitura.\n");
//         return;
//     }

//     printf("Relatório de Produtos (Filtrado por Valor: %s):\n", precoFiltro);
//     printf("-------------------------\n");

//     while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
//         if (strcmp(entrada->preco, precoFiltro) == 0) {
//             encontrado = 1;
//             printf("ID Código: %d\n", entrada->id_codigo);
//             printf("Nome: %s\n", entrada.nomep);
//             printf("Código: %s\n", entrada.codigop);
//             printf("Marca: %s\n", entrada.marca);
//             printf("Preço: %s\n", entrada.preco);
//             printf("-------------------------\n");
//         }
//     }

//     if (!encontrado) {
//         printf("Nenhum produto encontrado com o valor: %s\n", precoFiltro);
//     }

//     fclose(arquivo);
// }



char menu_rltr_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n============ Relatório de Vendas =============\n");
    printf("    1 - Ver Tudo\n");
    printf("    2 - Cupom Fisc  \n");
    printf("    3 - Valor   \n");
    printf("    0 - Sair\n");
    printf("    Escolha uma opção: ");
    scanf(" %c", &op);
    getchar();
    return op;
}

void rltr_todos_vendas(void) {
    FILE* fp;
    Venda* venda = (Venda*) malloc (sizeof(Venda));

    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        free(venda);
    }

    while (fread(venda, sizeof(Venda), 1, fp)) {
        if (venda != NULL) {
            exibe_venda(venda);
        }
    }
    printf("Tecle enter para continuar...");
    getchar();

    free(venda);
    fclose(fp);
}

// void rltr_vendas_por_valor(float valorFiltro) {
//     FILE* arquivo;
//     Venda entrada;
//     int encontrado = 0;

//     arquivo = fopen("vendas.dat", "rb");
//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo para leitura.\n");
//         return;
//     }

//     printf("Relatório de Vendas (Filtrado por Valor Total: %.2f):\n", valorFiltro);
//     printf("-------------------------\n");

//     while (fread(&entrada, sizeof(Venda), 1, arquivo)) {
//         if (entrada.valor == valorFiltro) {
//             encontrado = 1;
//             printf("Cupom Fiscal: %d\n", entrada.cupom);
//             printf("Nome dos Produtos: %s\n", entrada.pv);
//             printf("Valor: %.2f\n", entrada.valor);
//             printf("-------------------------\n");
//         }
//     }

//     if (!encontrado) {
//         printf("Nenhuma venda encontrada com o valor total: %.2f\n", valorFiltro);
//     }

//     fclose(arquivo);

// }

