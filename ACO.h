#include "instancias.h"

class ACO{
private:
    void Fill(int **mat, int T){
        for (int i = 0; i < T ; i++){
            for (int j = 0; j < T; j++){
                cin >> mat[i][j];
            }
        }
    }
public:
    void fill(int **mat, int T){
        Fill(mat, T);
    }
};