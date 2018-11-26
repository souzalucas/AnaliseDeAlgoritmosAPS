#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef long int LLI;


LLI* leitor(char* file, LLI *tam){

    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    LLI num;
    LLI i;
    if(strcmp(file,"file-1000") == 0){
		

        LLI *vetor = (LLI*)calloc(1000,sizeof(LLI));

        pont_arq = fopen(file, "r");

        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 1000;
	    for(i = 0; i < 1000; i++){
		    fscanf(pont_arq, "%ld,", &num);
		    vetor[i] = num;
	    }
        return vetor;


	}else if(strcmp(file, "file-10000") == 0){
		
        LLI *vetor = (LLI*)calloc(10000,sizeof(LLI));

        pont_arq = fopen(file, "r");

        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 10000;
	    for(i = 0; i < 10000; i++){
		    fscanf(pont_arq, "%ld,", &num);
		    vetor[i] = num;
	    }
        return vetor;

        

	}else if(strcmp(file, "file-100000") == 0){
		
        LLI *vetor = (LLI*)calloc(100000,sizeof(LLI));

        pont_arq = fopen(file, "r");
        
        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 100000;
	    for(i = 0; i < 100000; i++){
		    fscanf(pont_arq, "%ld,", &num);
		    vetor[i] = num;
	    }
        return vetor;

	}
	else{
		printf(" parametro invalido!");

    }

}