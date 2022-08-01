//-------------------------------------------------------------------------------------------------------
/*
* @1
* Desenvolver a função: ‘maior_valor’; que recebe quatro valores do tipo inteiro e retorna o maior valor.
*
*/
//-------------------------------------------------------------------------------------------------------

#include <stdio.h>

int maior_valor(int v1, int v2, int v3, int v4){
//complete...
    int maior = v1;
    if (v2 > maior)
        maior = v2;
    if (v3 > maior)
        maior = v3;
    if (v4 > maior)
        maior = v4;
    
    return maior;
}

int main() {
int a, b, c, d;
scanf("%d %d %d %d", &a, &b, &c, &d);
int valor = maior_valor(a, b, c, d);
printf("%d", valor);
return 0;
}