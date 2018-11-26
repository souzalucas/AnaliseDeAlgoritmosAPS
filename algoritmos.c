#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "leitor.h"

typedef long int LLI;

void imprime(LLI *vet, LLI tam){
    printf("\n\n");
	LLI i;
    for(i = 0; i < tam; i++){
        printf(" %ld",vet[i]);
    }
    printf("\n");

}



void troca(LLI* a, LLI* b){
	LLI aux = *a;
	*a = *b;
	*b = aux;
}

void bubble(LLI* v, LLI n, LLI *execucao){
	LLI i, j;

	for(i = 0; i < n; i++){
		for(j = 1; j < n; j++)
		{
			*execucao += 1;
			if(v[j-1] > v[j])
				troca(&v[j-1], &v[j]);
		}
	}
}



void bubbleOtimizado(LLI* v, LLI n, LLI* execucao){
	LLI i, j;
	for(i = 0; i < n; i++){
		int hTroca = 0;
		for(j = 1; j < n-i; j++)
		{
			*execucao += 1;
			if(v[j-1] > v[j]){
                troca(&v[j-1], &v[j]);
				hTroca = 1;
			}
		}
		if(hTroca == 0)
			return;
	}
}

void insertion(LLI* v, LLI n, LLI* execucao){
	LLI i, j, aux;

	for(i = 0; i < n; i++){
		aux = v[i];
		j = i-1;
		while(aux < v[j] && j >= 0){
			*execucao +=1;
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
}

void selection(LLI* v, LLI n, LLI *execucao){
	LLI i, j;

	for(i = 0; i < n; i++){
		LLI menor = i;
		for(j = i+1; j < n; j++)
		{	
			*execucao +=1;
			if(v[j] < v[menor])
				menor = j;
		}
		troca(&v[i], &v[menor]);
	}
}

void merge(LLI* v, LLI p, LLI m, LLI r){
	LLI n1 = m-p+1, n2 = r-m;
	LLI i, j, k;
	LLI v1[n1], v2[n2];

	for(i = 0; i < n1; i++)
		v1[i] = v[p+i];
	for(j = 0; j < n2; j++)
		v2[j] = v[m+1+j];

	i = 0;
	j = 0; 
	k = p;
	while(i < n1 && j < n2){
		if(v1[i] <= v2[j]){
			v[k] = v1[i];
			i++;
		} else {
			v[k] = v2[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		v[k] = v1[i];
		i++;
		k++;
	}

	while(j < n2){
		v[k] = v2[j];
		j++;
		k++;
	}
}

void mergeSort(LLI* v, LLI p, LLI r, LLI *execucao){
	LLI m;
	if(p < r){
		m = p+(r-p)/2;

		*execucao +=1;
	
		mergeSort(v, p, m,execucao);
		mergeSort(v, m+1, r,execucao);
		merge(v, p, m, r);
	}
}

LLI BuscaBinaria(LLI* v, LLI x, LLI e, LLI d, LLI* execucao){
	LLI m = (e + d)/2;
	if(v[m] == x)
		return m;
	if(e >= d)
		return -1;
	else{
		if(v[m] < x){
			*execucao +=1;
			return BuscaBinaria(v, x, m+1, d, execucao);
		}else{
			*execucao +=1;
			return BuscaBinaria(v, x, e, m-1, execucao);
		}
	}
}

void levaTopo(LLI* v, LLI n, LLI p){
    LLI d = 2*p + 1;
    LLI e = 2*p + 2;
    LLI maior = p; 

    if(d < n && v[d] > v[maior]) 
        maior = d; 
  
    if(e < n && v[e] > v[maior]) 
        maior = e; 
  
    if(maior != p) { 
        troca(&v[p], &v[maior]); 
        levaTopo(v, n, maior); 
    } 
}

void heapSort(LLI* v, LLI n, LLI *execucao){
	LLI i, tam;

	for(i = n/2 -1; i >= 0; i--){
        levaTopo(v, n, i);
	}
    for(i = n-1; i >= 0; i--){
		*execucao +=1;
        troca(&v[0], &v[i]);
        levaTopo(v, i, 0);
    }
}


void Find_MAX_sub_vetor_KADANE(LLI *vetor, LLI tam, LLI *inicio, LLI *fim , LLI *max_total, LLI *execucao){
    LLI max_atual;
    LLI xtemp;
    LLI i;
    max_atual = 0;
    *max_total = -1;
    xtemp = 0;

    LLI verif = vetor[0];
    for(i = 1; i < tam; i++){
		*execucao +=1;
        if(vetor[i] > verif){
            verif = vetor[i];
            *inicio = *fim = i;
        }
    }


    if(verif > 0){
		
    
        for(i=0; i < tam; i++){

			*execucao +=1;
        
            max_atual = max_atual + vetor[i];

            if(max_atual < 0) { 
                max_atual = 0;
                xtemp = i+1;
            }

            if(max_atual > *max_total){
                *max_total = max_atual;
                *inicio = xtemp;
                *fim = i;
            }
        }
    }else{
        *max_total = verif;
    }
    
}


LLI partition(LLI *vetor, LLI left, LLI right){

    LLI pivo = vetor[right];
    LLI i = (left - 1);
	LLI j;
    for(j = left; j <= right-1; j++){
        if(vetor[j] <= pivo){
            i = i + 1;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i+1], &vetor[right]);
    return (i+1);
}

/*PARA TESTAR O QUICKSORT, DEVE MANDAR TAMANHO -1 !!*/
void quicksort(LLI *vetor, LLI left, LLI right, LLI *execucao){
    if(left < right){
        LLI q = partition(vetor, left, right);
        
		*execucao +=1;
        quicksort(vetor, left, q-1, execucao);
        quicksort(vetor, q+1,right, execucao);
    }
}

void verifica_ordenacao(LLI *vetor, LLI tam){
	for(LLI i = 1; i < tam; i++)
	{
		if(vetor[i-1] > vetor[i])
		{
			printf("\n\n  vetor nao esta ordenado! \n\n");
			printf("  posicao: %ld   ---  valor no vetor[%ld] = %ld \n\n", i,i, vetor[i]);
			printf("  posicao: %ld   ---  valor no vetor[%ld] = %ld \n\n", i-1,i-1, vetor[i-1]);
			return ;
		}
	}
	printf("vetor ordenado!\n");
}




/*##########################################################################################################################*/
/*											PARTE DE CONTROLE DOS ALGORITMOS                     							*/

int cmp(const void* a,const void* b)
{
	return *(LLI*)a - *(LLI*)b;
}

LLI algoritmo_busca(LLI *vetor, LLI tam, char* nome_arquivo){

	__clock_t inicio;
	__clock_t fim;
	double tempo ;
	LLI quantidade_loop = 0;

	LLI inicioSubVetor;
	LLI fimSubVetor;
	LLI SomaTotal = 0;

	FILE *arquivo;

    arquivo = fopen(nome_arquivo, "w+");

	/* Análise do algoritmo de busca subvetor*/
	quantidade_loop = 0;
	inicio = clock();
	Find_MAX_sub_vetor_KADANE(vetor,tam, &inicioSubVetor, &fimSubVetor, &SomaTotal, &quantidade_loop);
	fim = clock();

	printf("Find Subvetor Maximo: Vetor[%ld] ate Vetor[%ld] =>  SOMA = %ld		( sem vetor ordenado! )\n", inicioSubVetor, fimSubVetor, SomaTotal);
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "Find_Max_vetor,%g,%ld\n", tempo, quantidade_loop);
	

	qsort(vetor, tam, sizeof(LLI), &cmp);


	/* Análise do algoritmo de busca binária*/
	quantidade_loop = 0;
	LLI valor_buscar = vetor[fimSubVetor];
	inicio = clock();
	LLI encontrado = BuscaBinaria(vetor, valor_buscar, 0,tam, &quantidade_loop);
	fim = clock();

	printf("Busca Binaria: Valor buscado = %ld		( com vetor ordenado! )\n", encontrado);
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);	
	fprintf(arquivo, "BuscaBinária,%g,%ld\n", tempo, quantidade_loop);
	
	fclose(arquivo);
}

void algoritmos_ordenacao(LLI *vetor, LLI tam, char* nome_arquivo){


	FILE *arquivo;
	
	arquivo = fopen(nome_arquivo, "w+");

	clock_t inicio;
	clock_t fim;
	double tempo ;
	int quant = 7;


	LLI quantidade_loop = 0;
	LLI *vetorBubble = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorBubbleOtimizado = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorInsertion = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorSelection = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorMerge = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorHeap = (LLI*)calloc(tam,sizeof(LLI));
	LLI *vetorQuick = (LLI*)calloc(tam,sizeof(LLI));


	for(LLI i = 0; i < tam; i++){
		
		vetorBubble[i] = vetor[i];
		vetorBubbleOtimizado[i] = vetor[i];
		vetorInsertion[i] = vetor[i];
		vetorSelection[i] = vetor[i];
		vetorMerge[i] = vetor[i];
		vetorHeap[i] = vetor[i];
		vetorQuick[i] = vetor[i];
	}


	

	
	
	/*analise do bublleSort*/
	
	quantidade_loop = 0;
	inicio = clock();
	bubble(vetorBubble,tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "BubbleSort,%g,%ld\n", tempo, quantidade_loop);


	printf("BubbleSort: ");
	verifica_ordenacao(vetorBubble, tam);
	
	/*analise do bublleSort Otimizado*/
	quantidade_loop = 0;
	inicio = clock();
	bubbleOtimizado(vetorBubbleOtimizado,tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "BubbleSort Otimizado,%g,%ld\n", tempo, quantidade_loop);

	printf("BubbleSortOtimizado: ");
	verifica_ordenacao(vetorBubbleOtimizado, tam);
	

	/*analise do insertion */
	quantidade_loop = 0;
	inicio = clock();
	insertion(vetorInsertion, tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "InsertionSort,%g,%ld\n", tempo, quantidade_loop);

	printf("Insertion: ");
	verifica_ordenacao(vetorInsertion, tam);
	

	/* análise do selection */
	quantidade_loop = 0;
	inicio = clock();
	selection(vetorSelection, tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "SelectionSort,%g,%ld\n", tempo, quantidade_loop);
	
	printf("selection: ");
	verifica_ordenacao(vetorSelection, tam);



	/* análise do mergeSort*/
	quantidade_loop = 0;
	inicio = clock();
	mergeSort(vetorMerge,0,tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "MergeSort,%g,%ld\n", tempo, quantidade_loop);
	
	printf("mergesort: ");
	verifica_ordenacao(vetorMerge, tam);
	
	/* análise do heapSort */
	
	quantidade_loop = 0;
	inicio = clock();
	heapSort(vetorHeap, tam, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "HeapSort,%g,%ld\n", tempo, quantidade_loop);
	
	printf("heap: ");
	verifica_ordenacao(vetorHeap, tam);



	/* análise do quickSort */
	quantidade_loop = 0;
	inicio = clock();
	quicksort(vetorQuick,0,tam-1, &quantidade_loop);
	fim = clock();
	tempo = ((double)(fim - inicio) / CLOCKS_PER_SEC);
	fprintf(arquivo, "QuickSort,%g,%ld\n", tempo, quantidade_loop);
	
	printf("quicksort: ");
	verifica_ordenacao(vetorQuick, tam);


	fclose(arquivo);

	free(vetorBubble);
	free(vetorBubbleOtimizado);
	free(vetorInsertion);
	free(vetorSelection);
	free(vetorMerge);
	free(vetorHeap);
	free(vetorQuick);

	
}




void controlador(char* nome){

	LLI tam = 0;

	LLI* vetor = leitor(nome, &tam);

	printf("\n		EXECUTANDO O ARQUIVO COM %lld VALORES \n\n",tam);

	char nome_ordenacao[50] = {"graficoOrdenação"};
	char* nome_arquivo = strdup(strcat(nome_ordenacao, nome));
	algoritmos_ordenacao(vetor, tam, nome_arquivo);
	free(nome_arquivo);

	char nome_busca[50] = {"graficoBusca"};
	nome_arquivo = strdup(strcat(nome_busca, nome));
	algoritmo_busca(vetor, tam, nome_arquivo);
	free(nome_arquivo);

}






int main(){
	
	char nome_arquivo[] = {"file-1000"};
	/* O controlador toma conta de toda a análize */
	controlador("file-1000");	
	controlador("file-10000");
	controlador("file-100000");
	return 0;
}


