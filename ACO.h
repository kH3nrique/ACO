#ifndef ACO_H
#define ACO_H

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

    void showUp(int **mat, int T){
        for (int i = 0; i < T ; i++){
            for (int j = 0; j < T; j++){
                cout << mat[i][j] << " ";
            }
            cout <<endl;
        }
    }

public:
    void makeGraf(int **mat, int T){
        //Fill(mat, T);
        showUp(mat, T);
    }
};

#endif