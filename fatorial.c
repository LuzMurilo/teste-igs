//-------------------------------------------------------------------------------------------------------
/*
* @2
* Desenvolva a função que retorna o valor fatorial no parâmetro 'valor_ft'
*
*/
//-------------------------------------------------------------------------------------------------------

#include <stdio.h>

void calc_fatorial(int *valor_ft, int valor_n){
    int fatorial;
    if (valor_n > 12 || valor_n < 0)
    {
        printf("Só é possível calcular números positivos\n");
        printf("Números maiores que 12 não são possíveis calcular usando 'int'\n");
        return;
    }
    
    for (fatorial = 1; valor_n > 1; valor_n--)
        fatorial *= valor_n;

    *valor_ft = fatorial;
}

int main() {
int v, vf = 0;
int *pv = &v;
scanf("%d", &v);
calc_fatorial(&vf, *pv); //Corrigido erro de ponteiro na passagem das variaveis
printf("Valor fatorial de: [%d] é [%d]", v, vf);
return 0;
}