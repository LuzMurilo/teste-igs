//---------------------------------------------------------------------------------------------------------
/*
* @4
* Desenvolva a função a qual recebe dois valores de inteiros e que faça a todas as operacoes de ‘Bitwise’ e devolva o maior resultado
* entre eles.
*/
//---------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calcular_maximum_bitwise(int v1, int v2) {
    if (v1 < 0 || v2 < 0) {
        printf("Os numeros nao podem ser negativos!\n");
        return -1;
    }
    int maior = v1 & v2;    // AND

    if (v1 | v2 > maior)    // OR
        maior = v1 | v2;
    if (v1 ^ v2 > maior)    // XOR
        maior = v1 ^ v2;
    if (v1 << v2 > maior)   // Left Shift
        maior = v1 << v2;
    if (v1 >> v2 > maior)   // Right Shift
        maior = v1 >> v2;
    if (~v1 > maior)        // NOT v1
        maior = ~v1;
    if (~v2 > maior)        // NOT v2
        maior = ~v2;
        
    return maior;
}

int main() {
int valor_1, valor_2, maior_valor;
printf("Informe os valores.\n");
scanf("%d %d", &valor_1, &valor_2);
maior_valor = calcular_maximum_bitwise(valor_1, valor_2);
printf("O maior valor e: %d .\n", maior_valor);
return 0;
}