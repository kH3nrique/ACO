#include "ACO.h"

int main(){
    int n = 3;
    ACO acess;

    int** matriz = (int**)malloc(n * sizeof(int*)); //sera usada para armazenar ponteiros

    for (int i = 0; i < n; ++i) { //armazena n inteiros em cada linha
        matriz[i] = (int*)malloc(n * sizeof(int)); //conforme vai tendo linhas, vai alocando memoria
    }

    // Inicializa a matriz com INF
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = INF;
        }
    }

    acess.makeGraf(matriz, n);

    return 0;
}