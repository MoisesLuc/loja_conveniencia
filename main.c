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
    Cliente* cl;
    do{
        op = menu_principal();
        if(op == '1'){
            char op_produto = tela_modulo_produtos();
            if(op_produto == '1'){
                tela_cadastrar_produto();
            }else if(op_produto == '2'){
                tela_verificar_produto();
            }else if(op_produto == '3'){
                tela_alterar_produto();
            }else if(op_produto == '4'){
                tela_excluir_produto();
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
                cl = busca_cliente();
                regrava_cliente(cl);  
                free(cl);  
            }else if(op_clientes == '4'){
                cl = busca_cliente();
                exclui_cliente(cl);
                free(cl);
            }
        }else if(op == '3'){
            char op_vendas = tela_modulo_vendas();
            if(op_vendas == '1'){
                tela_cadastrar_venda();
            }else if(op_vendas == '2'){
                tela_alterar_venda();
            }else if(op_vendas == '3'){
                tela_excluir_venda();
            }else if(op_vendas == '4'){
                tela_exibir_venda();
            }
        
        }else if(op == '4'){
            system("clear||cls");
            printf("\n");
            printf("Menu em construção\n");
            printf("| Tecle <ENTER> para continuar...\n");
            getchar();
        }else if(op == '5'){
            informacoes_gerais();
        }else if(op == '6'){
            informacoes_da_equipe();
        }else if(op == '0'){
            printf("fim\n");
        }else{
            printf("Opção inválida!");
        }
    }while(op != '0');

    return 0;
}



