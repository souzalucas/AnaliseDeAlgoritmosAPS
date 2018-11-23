#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubble(int* v, int n){
	int i, j , aux;

	for(i = 0; i < n; i++){
		for(j = 0; j < n-1; j++){
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}
}

void bubbleOtimizado(int* v, int n){
	int i, j, aux;

	for(i = 1; i < n; i++){
		int troca = 0;
		for(j = 0; j < n-i-1; j++){
			if(v[j] > v[j+1]){
				aux = v[j+1];
				v[j+1] = v[j];
				v[j] = aux;
				troca = 1;
			}
		}
		if(troca == 0)
			return;
	}	
}

void insertion(int* v, int n){
	int i, j, aux;

	for(i = 0; i < n; i++){
		aux = v[i];
		j = i-1;
		while(aux < v[j] && j >= 0){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = aux;
	}
}

void selection(int* v, int n){
	int i, j, aux;

	for(i = 0; i < n; i++){
		int menor = i;
		for(j = i+1; j < n; j++){
			if(v[j] < v[menor])
				menor = j;
		}
		aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;	
	}
}

void merge(int* v, int p, int m, int r){
	int n1 = m-p+1, n2 = r-m;
	int i, j, k;
	int v1[n1], v2[n2];

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

void mergeSort(int* v, int p, int r){
	int m;
	if(p < r){
		m = p+(r-p)/2;

		mergeSort(v, p, m);
		mergeSort(v, m+1, r);
		merge(v, p, m, r);
	}
}

int BuscaBinaria (int x, int v[], int e, int d){
	int m = (e + d)/2;
	if (v[m] == x)
		return m;
	if (e >= d)
		return -1;
	else
		if (v[m] < x)
			return BuscaBinaria(x, v, m+1, d);
		else
			return BuscaBinaria(x, v, e, m-1);
}

void fmcs(int* v, int e, int m, int d, int* retorno){
  int i, j;

  int leftSum;
  int rightSum;
  int maxLeft;
  int maxRight;
  int sum = 0;

  for(i = m; i >= e; i--){
    sum += sum;
    if(sum > leftSum){
      leftSum = sum;
      maxLeft = i;
    }
  }
  sum = 0;
  for(i = m+1; i <= d; i++){
    sum += sum;
    if(sum > rightSum){
      rightSum = sum;
      maxRight = i;
    }
  }

  retorno[0] = maxLeft;
  retorno[1] = maxRight;
  retorno[2] = leftSum+rightSum;
}



void main(){
	int v[] = {3,6,7,5,0,2,10,1};
	mergeSort(v, 0, 7);

	int i = 0;
	
	for(i = 0; i < 8; i++)
		printf("%d ", v[i]);
}