import os # biblioteca pra usar o método de limpar a tela
import threading
import time

import numpy as np

def geradorGrafico1(dados, titulo='', labelx='', labely=''):
    import matplotlib.pyplot as plt
    import seaborn as sns
    import pandas as pd
    sns.set()
    
    colors = ['#2300A8', '#00A658', "#5eb293"]
    
    print(*dados, sep="\n")

    dados[2] = list(map(int, dados[2]))

    x = dados[0]
    plt.xticks(range(len(x)), x)
    plt.bar(range(len(dados[2])), dados[2], align='center', color=colors)

    plt.title(titulo)
    plt.xlabel(labelx) 
    plt.ylabel(labely) 

    plt.show()
    
def geradorGrafico2(dados, titulo='', labelx='', labely=''):
    import matplotlib.pyplot as plt
    import seaborn as sns
    import pandas as pd
    sns.set()
    
    colors = ['#2300A8', '#00A658']
    
    print(*dados, sep="\n")

    dados[1] = list(map(lambda x: int(float(x)*1e3), dados[1]))

    x = dados[0]
    plt.xticks(range(len(x)), x)
    plt.bar(range(len(dados[1])), dados[1], align='center', color=colors)

    plt.title(titulo)
    plt.xlabel(labelx) 
    plt.ylabel(labely) 

    plt.show()


def leitor(file_name):
    file_reader = open(file_name, 'r')
    
    file_list = file_reader.readlines()
    file_list = [ i.replace('\n', '') for i in file_list]
    file_list = [ i.split(' ') for i in file_list]
    
    
    file_reader.close()

    return file_list


def matrix_transposta(matrix):
    return list(zip(*matrix))



def main():
    
    for i in [1e3, 1e4, 1e5]:
        fila_dados = matrix_transposta(leitor("graficoOrdenaçãofile-{}".format(int(i))))
        geradorGrafico1(
            fila_dados,
            "Relação entre a quantidade de iteração de cada algoritmo para um tamanho de [{}]".format(int(i)),
            "Algoritmos de Ordenação",
            "Quantidade de iteração")
        geradorGrafico2(
            fila_dados,
            "Relação entre a quantidade de tempo de cada algoritmo para um tamanho de [{}]".format(int(i)),
            "Algoritmo de Ordenação",
            "Tempo em milisegundos"
            )


    for i in [1e3, 1e4, 1e5]:
            fila_dados = matrix_transposta(leitor("graficoBuscafile-{}".format(int(i))))
            geradorGrafico1(
                fila_dados,
                "Relação entre a quantidade de iteração de cada algoritmo para um tamanho de [{}]".format(int(i)),
                "Algoritmos de Busca",
                "Quantidade de iteração")
            geradorGrafico2(
                fila_dados,
                "Relação entre a quantidade de tempo de cada algoritmo para um tamanho de [{}]".format(int(i)),
                "Algoritmo de Busca",
                "Tempo em milisegundos"
                )
    # limpa a tela no Windows ou Linux
    # os.system('cls' if os.name == 'nt' else 'clear')

    

if __name__ == '__main__':
	main()