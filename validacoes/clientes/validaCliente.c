#include <stdio.h>
#include <string.h>
#include <ctype.h>



int valida_cpf(const char *cpf){
    if (strlen(cpf) != 11){
        return 0;
}
    for(int i=0; i<11; i++){
        if(!isdigit(cpf[1])){
            return 0;
        }
}
    int iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) {
        return 0;
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int primeiroDigito = (soma * 10) % 11;
    if (primeiroDigito == 10) {
        primeiroDigito = 0;
    }

    
    if (primeiroDigito != (cpf[9] - '0')) {
        return 0;
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int segundoDigito = (soma * 10) % 11;
    if (segundoDigito == 10) {
        segundoDigito = 0;
    }

    if (segundoDigito != (cpf[10] - '0')) {
        return 0;
    }

    return 1;  
}
// Função para validar CPF, a função foi tirada do chatGPT.

int valida_email(const char *email){

    const char *arr = strchr(email, '@');

    if(arr == NULL || arr == email || arr == email + strlen(email) - 1){
        return 0;
    }

    const char *pont = strchr(arr + 1, '.');
    if (pont == NULL || pont == arr + 1 || pont == email + strlen(email) - 1) {
        return 0;
    }

    for (const char *p = email; *p; p++) {
        if (!isalnum(*p) && *p != '.' && *p != '@' && *p != '-' && *p != '_') {
            return 0;
        }
    }

    return 1;

}
//Função para valiadr E-mail, inpirada num código do chatGPT!

int valida_celular(const char *celular) {
    
    if (strlen(celular) != 11) {
        return 0;
    }

    
    for (int i = 0; i < 11; i++) {
        if (!isdigit(celular[i])) {
            return 0;
        }
    }

    
    if (celular[2] != '9') {
        return 0;
    }

    return 1;  
}
//Função para validar o número do celular, adaptada do chatGPT