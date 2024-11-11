#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validaEndereco(const char *rua, const char *bairro, const char *numero) {
    
    if (rua == NULL || strlen(rua) == 0 || bairro == NULL || strlen(bairro) == 0) {
        return 0; 
    }

    
    if (numero == NULL || strlen(numero) == 0) {
        return 0; 
    }

    
    for (int i = 0; i < strlen(numero); i++) {
        if (!isdigit(numero[i])) {
            return 0; 
        }
    }

    return 1; 
}

//Inspirada em uma função do chatGPT