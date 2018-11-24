def cria_arquivo(name):
    file = open(name, 'w')

    file.close()

    return file





def main():
    file = cria_arquivo("vetor.txt")





if __name__ == "__main__":
    main() 