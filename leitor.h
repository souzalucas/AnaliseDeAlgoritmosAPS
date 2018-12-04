#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long int LLI;


LLI* leitor(char* file, LLI *tam){

    // criando a variável ponteiro para o arquivo
    if(strcmp(file,"file-1000") == 0){
		*tam = 1000;
	}else if(strcmp(file, "file-10000") == 0){
		*tam = 10000;
   	}else if(strcmp(file, "file-100000") == 0){
		*tam = 100000;
	}
	else{
		printf(" parametro invalido!");
    }
    LLI *vetor = (LLI*)calloc(*tam,sizeof(LLI));

    FILE *pont_arq;
    pont_arq = fopen(file, "r");
    if(!pont_arq){
        printf("\n\n    Erro ao abrir o arquivo!\n\n ");
        exit(0);
    }

    LLI num, i;
    for(i = 0; i < *tam; i++){
        fscanf(pont_arq, "%ld,", &num);
        vetor[i] = num;
    }
    return vetor;
}