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
            case '3':
            rltr_cpf_clientes();
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
            case '2':
            rltr_marca_produtos();
                break;
            case '3': 
            rltr_prec_produtos();
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
                rltr_todos_vendas();
                break;
            case '2':
            rltr_cupfisc_vendas();
                break;
            case '3':
            rltr_valor_vendas();
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
    printf("    2 - Nome    \n");
    printf("    3 - CPF     \n");
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

typedef struct Clie nte {
    char nome[55];
    char cpf[12];
    char email[55];
    char celular[12];
} Cliente;

void rltr_clientes_por_marca(const char* marcaFiltro) {
    FILE* arquivo;
    Cliente entrada;
    int encontrado = 0;

    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Clientes (Filtrado por Marca: %s):\n", marcaFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Cliente), 1, arquivo)) {
        if (strcmp(entrada.email, marcaFiltro) == 0) {
            encontrado = 1;
            printf("Nome: %s\n", entrada.nome);
            printf("CPF: %s\n", entrada.cpf);
            printf("Email: %s\n", entrada.email);
            printf("Celular: %s\n", entrada.celular);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com a marca: %s\n", marcaFiltro);
    }

    fclose(arquivo);
}

int main() {
    char marcaFiltro[55];

    printf("Digite a marca para filtrar os clientes: ");
    scanf("%54s", marcaFiltro);

    rltr_clientes_por_marca(marcaFiltro);

    return 0;
}


void rltr_clientes_por_cpf(const char* cpfFiltro) {
    FILE* arquivo;
    Cliente entrada;
    int encontrado = 0;

    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Clientes (Filtrado por CPF: %s):\n", cpfFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Cliente), 1, arquivo)) {
        if (strcmp(entrada.cpf, cpfFiltro) == 0) {
            encontrado = 1;
            printf("Nome: %s\n", entrada.nome);
            printf("CPF: %s\n", entrada.cpf);
            printf("Email: %s\n", entrada.email);
            printf("Celular: %s\n", entrada.celular);
            printf("Status: %c\n", entrada.status);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o CPF: %s\n", cpfFiltro);
    }

    fclose(arquivo);
}

int main() {
    char cpfFiltro[12];

    printf("Digite o CPF para filtrar os clientes: ");
    scanf("%11s", cpfFiltro);

    rltr_clientes_por_cpf(cpfFiltro);

    return 0;
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



typedef struct {
    int id_codigo;
    char nomep[55];
    char codigop[6];
    char marca[20];
    char preco[20];
} Produto;

void rltr_produtos_por_marca(const char* marcaFiltro) {
    FILE* arquivo;
    Produto entrada;
    int encontrado = 0;

    arquivo = fopen("produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Produtos (Filtrado por Marca: %s):\n", marcaFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strcmp(entrada.marca, marcaFiltro) == 0) {
            encontrado = 1;
            printf("ID Código: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nomep);
            printf("Marca: %s\n", entrada.marca);
            printf("Quantidade em Estoque: %d\n", entrada.codigop);
            printf("Valor: %s\n", entrada.preco);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com a marca: %s\n", marcaFiltro);
    }

    fclose(arquivo);
}

int main() {
    char filtro[20];

    printf("Digite a marca para filtrar os produtos: ");
    scanf("%19s", filtro);

    rltr_produtos_por_marca(filtro);

    return 0;
}


void rltr_produtos_por_prec(const char* precoFiltro) {
    FILE* arquivo;
    Produto entrada;
    int encontrado = 0;

    arquivo = fopen("produtos.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Produtos (Filtrado por Valor: %s):\n", precoFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strcmp(entrada.preco, precoFiltro) == 0) {
            encontrado = 1;
            printf("ID Código: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nomep);
            printf("Código: %s\n", entrada.codigop);
            printf("Marca: %s\n", entrada.marca);
            printf("Preço: %s\n", entrada.preco);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o valor: %s\n", precoFiltro);
    }

    fclose(arquivo);
}

int main() {
    char precoFiltro[20];

    printf("Digite o valor para filtrar os produtos: ");
    scanf("%19s", precoFiltro);

    rltr_produtos_por_prec(precoFiltro);

    return 0;
}




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



typedef struct {
    char cupom[5];
    char pv[100];
    char valor[5];
} Venda;

void rltr_vendas_por_cupom(const char* cupomFiltro) {
    FILE* arquivo;
    Venda entrada;
    int encontrado = 0;

    arquivo = fopen("vendas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Vendas (Filtrado por Cupom Fiscal: %s):\n", cupomFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Venda), 1, arquivo)) {
        if (strcmp(entrada.cupom, cupomFiltro) == 0) {
            encontrado = 1;
            printf("Cupom Fiscal: %d\n", entrada.cupom);
            printf("Nome dos Produtos: %s\n", entrada.pv);
            printf("Valor: %.2f\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhuma venda encontrada com o cupom fiscal: %s\n", cupomFiltro);
    }

    fclose(arquivo);
}

int main() {
    char filtro[30];

    printf("Digite o cupom fiscal para filtrar as vendas: ");
    scanf("%4s", filtro);

    rltr_vendas_por_cupom(filtro);

    return 0;
}


void rltr_vendas_por_valor(float valorFiltro) {
    FILE* arquivo;
    Venda entrada;
    int encontrado = 0;

    arquivo = fopen("vendas.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Relatório de Vendas (Filtrado por Valor Total: %.2f):\n", valorFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Venda), 1, arquivo)) {
        if (entrada.valor == valorFiltro) {
            encontrado = 1;
            printf("Cupom Fiscal: %d\n", entrada.cupom);
            printf("Nome dos Produtos: %s\n", entrada.pv);
            printf("Valor: %.2f\n", entrada.valor);
            printf("-------------------------\n");
        }
        }
    }

    if (!encontrado) {
        printf("Nenhuma venda encontrada com o valor total: %.2f\n", valorFiltro);
    }

    fclose(arquivo);

}

