#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "modulos/gerais/gerais.h"
#include "modulos/produtos/produtos.h"
#include "modulos/clientes/clientes.h"
#include "modulos/vendas/vendas.h"
#include "modulos/entregas/entregas.h"

int main(void){
    char op;

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
            char op_clientes = tela_modulo_clientes();
            if(op_clientes == '1'){
                tela_cadastrar_cliente();
            }else if(op_clientes == '2'){
                tela_verificar_cliente();
            }else if(op_clientes == '3'){
                tela_alterar_cliente();    
            }else if(op_clientes == '4'){
                tela_excluir_cliente();
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
            char op_entregas = tela_entregas();
            if(op_entregas == '1'){
                tela_entregas_pendentes();
            }else if(op_entregas == '2'){
                tela_confirmcancel_entregas();
            }
        }else if(op == '5'){
            system("clear||cls");
            printf("\n");
            printf("Menu em construção\n");
            printf("| Tecle <ENTER> para continuar...\n");
            getchar();
        }else if(op == '6'){
            informacoes_gerais();
        }else if(op == '7'){
            informacoes_da_equipe();
        }else if(op == '0'){
            printf("fim\n");
        }else{
            printf("Opção inválida!");
        }
    }while(op != '0');

    return 0;
}
