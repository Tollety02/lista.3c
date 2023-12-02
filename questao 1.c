#include <stdio.h>
#include <string.h>

int romanoParaDecimal(char romano){
    switch(romano){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

void decimalParaBinario(int decimalFuncao) {
    if(decimalFuncao == 0){
        printf("0");
        return;
    }

    int binario[32];
    int j = 0;

    while(decimalFuncao > 0){
        binario[j] = decimalFuncao % 2;
        decimalFuncao /= 2;
        j++;
    }


    for(j--; j >= 0; j--){
        printf("%d", binario[j]);
    }
}

void decimalParaHexadecimal(int decimalFuncao){
    if(decimalFuncao == 0){
        printf("0");
        return;
    }

    char hexadecimal[20];
    int x = 0, resto;

    while(decimalFuncao > 0){
        resto = decimalFuncao % 16;
        if(resto < 10){
            hexadecimal[x] = resto + '0';
        }else{
            hexadecimal[x] = resto - 10 + 'a';
        }
        decimalFuncao = decimalFuncao / 16;
        x++;
    }

    for(x--; x >= 0; x--){
        printf("%c", hexadecimal[x]);
    }
}

int main(){
    char romano[13];
    int decimal = 0, tamanho, i, atual, proximo;
    int decimalDoBinario, decimalDoHexadecimal;

    scanf("%s", romano);

    tamanho = strlen(romano);

    for(i = 0; i < tamanho; i++){
        atual = romanoParaDecimal(romano[i]);
        if(i < tamanho - 1){
            proximo = romanoParaDecimal(romano[i + 1]);
        }else{
            proximo = 0;
        }

        if(atual >= proximo){
            decimal = decimal + atual;
        }else{
            decimal = decimal + (proximo - atual);
            i++;
        }
    }
    decimalDoBinario = decimal;
    decimalDoHexadecimal = decimal;

    printf("%s na base 2: ", romano);
    decimalParaBinario(decimalDoBinario);
    printf("\n");
    printf("%s na base 10: %d\n", romano, decimal);
    printf("%s na base 16: ", romano);
    decimalParaHexadecimal(decimalDoHexadecimal);
    printf("\n");

    return 0;
}