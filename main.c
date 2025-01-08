#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "modulos/gerais/gerais.h"
#include "modulos/produtos/produtos.h"
#include "modulos/clientes/clientes.h"
#include "modulos/vendas/vendas.h"

int main(void){
    char  op;
    Produto* pd;
    Cliente* cl;
    Venda* vd;

    do{
        op = menu_principal();
        if(op == '1'){
            char op_produtos = modulo_produtos();
            if(op_produtos == '1'){
                pd = cadastrar_produto();
                grava_produto(pd);
                free(pd);
            }else if(op_produtos == '2'){
                pd = busca_produto();
                exibe_produto(pd);
                free(pd);
            }else if(op_produtos == '3'){
                atualiza_produto(); 
                free(pd);  
            }else if(op_produtos == '4'){
                pd = busca_produto();
                exclui_produto(pd);
                free(pd);
            }
        }else if(op == '2'){
            char op_clientes = modulo_clientes();
            if(op_clientes == '1'){
                cl = cadastrar_cliente();
                grava_cliente(cl);
                free(cl);
            }else if(op_clientes == '2'){
                cl = busca_cliente();
                exibe_cliente(cl);
                free(cl);
            }else if(op_clientes == '3'){
                atualiza_cliente(); 
                free(cl);  
            }else if(op_clientes == '4'){
                cl = busca_cliente();
                exclui_cliente(cl);
                free(cl);
            }
        }else if(op == '3'){
            char op_vendas = modulo_vendas();
            if(op_vendas == '1'){
                vd = cadastrar_venda();
                grava_venda(vd);
                free(vd);
            }else if(op_vendas == '2'){
                vd = busca_venda();
                exibe_venda(vd);
                free(vd);
            }else if(op_vendas == '3'){
                atualiza_venda(); 
                free(vd);  
            }else if(op_vendas == '4'){
                vd = busca_venda();
                exclui_venda(vd);
                free(vd);
            }
        }else if(op == '5'){
            informacoes_gerais();
        }else if(op == '6'){
            informacoes_da_equipe();
        }else{
            printf("Opção inválida!");
        }
    }while(op != '0');

    return 0;
}



