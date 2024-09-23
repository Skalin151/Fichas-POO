#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

class Ordenacao
{
    private:
        static void lixo()
        {

        }
    public:
        static int Aleatorio(int min, int max)
        {
            return min + rand() % (max - min + 1);
        }
        static int *AlocarVector(int N)
        {
            int *V = new int[N];
            return V;
        }
        static void DesalocarVector(int *V)
        {
            delete []V;
        }
        static void LerVector(int *V, int N)
        {
            for (int i = 0; i < N; i++)
            {
                cout << "V[" << i << "]= ";
                cin >> V[i];
            }
        }
        static void GerarPreencherVector(int *V, int N)
        {
            for (int i = 0; i < N; i++)
            {
                V[i] = Aleatorio(1, 10);
            }
        }
        static void EscreverVector(int *V, int N)
        {
            cout << "[";
            for (int i = 0; i < N; i++)
                cout << V[i] << ",";
            cout << "]" << endl;

        }
        static void BubbleSort(int *V, int N, string fich_tempos)
        {
            int NTrocas = 0;
            clock_t T0 = clock();
            // Codigo da ordenacao do vector
            int i, j, temp;

            // Percorre todo o vetor
            for (i = 0; i < N - 1; i++) {
                    // A cada iteração, a maior parte dos elementos não ordenados será empurrada para o final
                for (j = 0; j < N - i - 1; j++) {
                        // Se o elemento atual for maior que o próximo, eles são trocados
                    if (V[j] > V[j + 1]) {
                            // Troca de elementos
                        temp = V[j];
                        V[j] = V[j + 1];
                        V[j + 1] = temp;
                        NTrocas++;
                    }
                }
            }
            clock_t T1 = clock();
            // Calcula a duração em segundos
            double Dt = (double)(T1 - T0) / CLOCKS_PER_SEC;
            ofstream F(fich_tempos, ios::app);
            F << __FUNCTION__ << ";" << N << ";" << NTrocas << ";" << Dt << endl;
            F.close();
        }
        static void QuickSort(int *V, int N, string fich_tempos)
        {
            int NTrocas = 0;
            clock_t T0 = clock();
            // Codigo da ordenacao do vector


            clock_t T1 = clock();
            // Calcula a duração em segundos
            double Dt = (double)(T1 - T0) / CLOCKS_PER_SEC;
            ofstream F(fich_tempos, ios::app);
            F << __FUNCTION__ << ";" << N << ";" << NTrocas << ";" << Dt << endl;
            F.close();
        }
};

#endif // ORDENACAO_H
