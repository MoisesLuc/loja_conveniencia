#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "modulos/gerais/gerais.h"
#include "modulos/produtos/produtos.h"
#include "modulos/clientes/clientes.h"
#include "modulos/vendas/vendas.h"
#include "modulos/relatorios/relatorios.h"

int main(void) {
    char  op;

    do {
        op = menu_principal();
        if (op == '1') {
            modulo_produtos();
        } else if(op == '2') {
            modulo_clientes();
        } else if (op == '3') {
            modulo_vendas();
        } else if (op == '4') {
            modulo_relatorios();
        } else if (op == '5') {
            informacoes_gerais();
        } else if (op == '6') {
            informacoes_da_equipe();
        } else {
            printf("Opção inválida!");
        }
    } while(op != '0');

    return 0;
}



