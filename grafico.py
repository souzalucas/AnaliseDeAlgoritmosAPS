#!/usr/bin/python3
import os # biblioteca pra usar o método de limpar a tela
import threading
import time


def geradorGrafico(dados, titulo='', labelx='', labely=''):
    import matplotlib.pyplot as plt
    import seaborn as sns
    import pandas as pd
    sns.set()
    
    colors = ['#2300A8', '#00A658']

    x = dados[0]
    plt.xticks(range(len(x)), x)

    for i in range(0, len(dados)):
        plt.bar(range(len(dados[i])), dados[i], align='center', color=colors)

    plt.title(titulo)
    plt.xlabel(labelx) 
    plt.ylabel(labely) 

    plt.show()
    



def leitor(file_name):
    file_reader = open(file_name, 'r');
    
    file_list = file_reader.readlines()
    file_list = [ i.replace('\n', '') for i in file_list]
    file_list = [ i.split(' ') for i in file_list]
    
    
    file_reader.close()

    return file_list


def matrix_transposta(matrix):
    return list(zip(*matrix))



def main():
   
    fila_dados = leitor("arquivo")

    print(fila_dados)

    geradorGrafico(matrix_transposta(fila_dados), "tempo gasto", "lableX", "lableY")
    
    #geradorGrafico(dados,'tempo gasto', 'labsdsleX', 'labsdsdsely')

    # limpa a tela no Windows ou Linux
    os.system('cls' if os.name == 'nt' else 'clear')

    

if __name__ == '__main__':
	main()