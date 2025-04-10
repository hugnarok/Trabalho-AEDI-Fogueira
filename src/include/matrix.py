import random

def gerar_matriz(linhas, colunas):
    return [[random.choices([0, 1, 4], weights=[1, 3, 1])[0] for _ in range(colunas)] for _ in range(linhas)]

def imprimir_matriz(matriz):
    for linha in matriz:
        print(" ".join(map(str, linha)))

if __name__ == "__main__":
    linhas = int(input("Digite o número de linhas: "))
    colunas = int(input("Digite o número de colunas: "))
    matriz = gerar_matriz(linhas, colunas)
    imprimir_matriz(matriz)
