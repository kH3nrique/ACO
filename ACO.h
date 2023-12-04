#ifndef ACO_H
#define ACO_H

#include "instancias.h"

struct Alimento {
    // Posição
    double x, y;
};

class ACO{
public:
    // Função para obter a letra correspondente a uma posição
    char obter_letra(int posicao) {
        return static_cast<char>('A' + posicao);
    }

    int calcular_distancia(const Alimento& alimento1, const Alimento& alimento2) {
        // módulo da distância
        int dx = abs(alimento2.x - alimento1.x);
        int dy = abs(alimento2.y - alimento1.y);
        return dx + dy; // posição do alimento
    }

    void atualizar_feromonio(vector<vector<double>>& feromonio, const vector<int>& caminho, double valor) {
        for (size_t i = 0; i < caminho.size() - 1; ++i) {
            feromonio[caminho[i]][caminho[i + 1]] += valor;
        }
    }

    vector<int> gerar_caminho_unico(int tamanho, int formiga) {
        vector<int> caminho(tamanho);
        for (int i = 0; i < tamanho; ++i) {
            caminho[i] = i;
        }
        random_shuffle(caminho.begin() + 1, caminho.end()); 
        return caminho;
    }

    void imprimir_caminho(const vector<int>& caminho, double distancia) {
        cout << "Caminho: ";
        for (int posicao : caminho) {
            cout << obter_letra(posicao) << ' ';
        }
        cout << " | Distancia: " << distancia << '\n';
    }

    void algoritmo_alimento_formigas(vector<Alimento>& alimentos, int num_formigas, int max_iteracoes) {

        vector<vector<double>> feromonio(alimentos.size(), vector<double>(alimentos.size(), 1.0));
        vector<int> melhor_caminho_global;

        double melhor_distancia_global = numeric_limits<double>::max();
        int iteracao = 0;
        int iteracoes_sem_melhora = 0;
        const int MAX_ITERACOES_SEM_MELHORA = 3;

        while (iteracao < max_iteracoes && iteracoes_sem_melhora < MAX_ITERACOES_SEM_MELHORA) {

            vector<vector<int>> resultados_formigas;
            vector<double> distancias_formigas;

            for (int formiga = 0; formiga < num_formigas; ++formiga) {

                vector<int> caminho = gerar_caminho_unico(alimentos.size(), formiga);
                caminho.push_back(caminho[0]);

                double distancia_total = 0.0;

                for (size_t i = 0; i < caminho.size() - 1; ++i)
                    distancia_total += calcular_distancia(alimentos[caminho[i]], alimentos[caminho[i + 1]]);

                resultados_formigas.push_back(caminho);
                distancias_formigas.push_back(distancia_total);

                imprimir_caminho(caminho, distancia_total);
            }

            int indice_melhor_formiga = min_element(distancias_formigas.begin(), distancias_formigas.end()) - distancias_formigas.begin();
            vector<int> melhor_caminho_formiga = resultados_formigas[indice_melhor_formiga];

            atualizar_feromonio(feromonio, melhor_caminho_formiga, 1.0 / distancias_formigas[indice_melhor_formiga]);

            if (distancias_formigas[indice_melhor_formiga] < melhor_distancia_global) {

                melhor_caminho_global = melhor_caminho_formiga;
                melhor_distancia_global = distancias_formigas[indice_melhor_formiga];
                iteracoes_sem_melhora = 0;

                if (melhor_distancia_global == 0) {
                    cout << "Melhor distancia global atingida: 0. Encerrando o algoritmo.\n";
                    break;
                }
            }
            else {
                iteracoes_sem_melhora++;
            }

            iteracao++;
            cout << "\n";
        }

        cout << "\nMelhor Caminho Global Encontrado: ";
        imprimir_caminho(melhor_caminho_global, melhor_distancia_global);

        cout << "\nParametros do Algoritmo:\n";
        cout << "Numero de Formigas: " << num_formigas << '\n';
        cout << "Numero Maximo de Iteracoes: " << max_iteracoes << '\n';

        cout << "\nEstatisticas de Desempenho:\n";
        cout << "Numero Total de Iteracoes: " << iteracao << '\n';
        cout << "Numero de Iteracoes sem Melhora: " << iteracoes_sem_melhora << '\n';
    }
};

#endif