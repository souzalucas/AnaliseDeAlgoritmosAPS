#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int* leitor(char* file, int *tam){

    // criando a variável ponteiro para o arquivo
    FILE *pont_arq;
    int num;
    int i;
    if(strcmp(file,"file-1000") == 0){
		

        int *vetor = (int*)calloc(1000,sizeof(int));

        pont_arq = fopen(file, "r");

        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 1000;
	    for(i = 0; i < 1000; i++){
		    fscanf(pont_arq, "%d,", &num);
		    vetor[i] = num;
	    }
        return vetor;


	}else if(strcmp(file, "file-10000") == 0){
		
        int *vetor = (int*)calloc(10000,sizeof(int));

        pont_arq = fopen(file, "r");

        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 10000;
	    for(i = 0; i < 10000; i++){
		    fscanf(pont_arq, "%d,", &num);
		    vetor[i] = num;
	    }
        return vetor;

        

	}else if(strcmp(file, "file-100000") == 0){
		
        int *vetor = (int*)calloc(100000,sizeof(int));

        pont_arq = fopen(file, "r");
        
        if(!pont_arq){
            printf("\n\n    Erro ao abrir o arquivo!\n\n ");
            exit(0);
        }

        *tam = 100000;
	    for(i = 0; i < 100000; i++){
		    fscanf(pont_arq, "%d,", &num);
		    vetor[i] = num;
	    }
        return vetor;

	}
	else{
		printf(" parametro invalido!");

    }

}