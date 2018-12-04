from random import randint

name = "file"

def gerar_arquivo_aleatorio(nome, quantidade):
    with open(name + "-{}".format(quantidade), "w+") as file:
        for i in range(quantidade):
            file.write("%d," % (randint(-quantidade + 1, quantidade)))

gerar_arquivo_aleatorio(name, 1000)
gerar_arquivo_aleatorio(name, 10000)
gerar_arquivo_aleatorio(name, 100000)
