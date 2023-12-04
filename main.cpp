#include "ACO.h"

int main(){
    ACO acess;
    vector<Alimento> alimentos = {
        {0, 0},
        {2, 1},
        {4, 2},
        {1, 3},
        {3, 4}
    };

    acess.algoritmo_alimento_formigas(alimentos, 10, 10);

    return 0;
}