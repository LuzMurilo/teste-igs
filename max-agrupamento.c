//-------------------------------------------------------------------------------------------------------
/*
*@3
*Desenvolva a função a qual recebe três parâmetros:
* ‘valor_ref’: Valor de referencia
* ‘array’: array de inteiros
* ‘tamanho_array’: quantidade de elementos no array
*Esta função deve devolver a maior quantidade de elementos do array que somados resulta em um valor menor ou igual ao
*parâmetro 'valor_ref'
*
*Ex.: arr [4,2,3,1,5,6]
* valor_ref = 7
* retorno = 3; (representado pelos elementos do array [2,3,1] => 2+3+1 = 6 que é menor que 'valor_ref')
*/
//-------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTOS 128 //Define o numero maximo de elementos (global)

//função auxiliar para preencher nosso array de inteiros.
//arry_int sera preenchido com os valores inseridos
//max_elementos quantidade maxima de elementos que o array_int pode receber
//retorna a quantidade de elementos inteiros maiores que zero foram inseridos
int criar_array(int *array_int, int max_elementos){
    int idx = 0;
    char array_str[128];
    char valor[16];
    char *posicao_inicio = NULL;
    char *posicao_fim = NULL;
    printf ("Informe os valores do tipo inteiros, separados por virgula\n");
    scanf ("%s", array_str);
    if (strlen (array_str) > 0){
        posicao_inicio = array_str;
        do {
            posicao_fim = strchr (posicao_inicio, ',');
            memset(valor,0, sizeof(valor));
            if(posicao_fim != NULL) {
                memcpy(valor, posicao_inicio,(int) (posicao_fim - posicao_inicio) );
                posicao_inicio = (posicao_fim + 1 );
            }
            else if(posicao_inicio != NULL){
                memcpy(valor, posicao_inicio,(int) strlen(posicao_inicio) );
            }
            if(strlen(valor)) {
                array_int[idx++] = atoi(valor);
            }
        } while (posicao_fim != NULL && idx < max_elementos);
    }
    printf ("ARRAY -> [" );
    for(int i=0; i<idx; ++i){
        printf ("%d", array_int[i]);
        if(i+1 < idx){
            printf(",");
        }
    }
    printf ("] \n");
    return idx;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    const int n1 = m - l + 1;
    const int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int maximo_elementos(int valor_ref, int* array, int tamanho_array) {
    if (sizeof(array) <= 0)
        return 0;
    
    int qtd = 0, soma = 0;
    printf("Array size: %d\n", tamanho_array);

    // Utiliza merge sort para organizar o array de forma crescente
    int sorted_array[tamanho_array];
    for (int i = 0; i < tamanho_array; i++) {     
        sorted_array[i] = array[i];     
    }
    mergeSort(sorted_array, 0, tamanho_array - 1);

    // Soma os itens do array até atingir o valor de referencia
    if (sorted_array[0] <= valor_ref) {
        soma = sorted_array[0];
        qtd = 1;
        while (soma <= valor_ref && qtd < tamanho_array) {
            soma += sorted_array[qtd];
            if (soma <= valor_ref)
                qtd ++;
        }
    }

    return qtd;
}

int main () {
    int array_int[MAX_ELEMENTOS] ;
    int qtd_elementos = 0;
    int tamanho_array = 0;
    int valor_ref = 0;
    tamanho_array = criar_array(array_int, MAX_ELEMENTOS);
    printf("Informe o valor para agrupamento.\n");
    scanf ("%d", &valor_ref);
    qtd_elementos = maximo_elementos(valor_ref, array_int, tamanho_array);
    printf("O numero maximo de agrupamente e [%d].\n", qtd_elementos);
    return 0;
}