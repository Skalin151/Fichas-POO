#include <iostream>
#include <string>

using namespace std;

void gerarHistograma(string digitos) {
    int colunas[digitos.size()];

    for (size_t i = 0; i < digitos.size(); i++) {
        colunas[i] = digitos[i] - '0';
    }

    int alturaMaxima = 0;
    for (size_t i = 0; i < digitos.size(); i++) {
        if (colunas[i] > alturaMaxima) {
            alturaMaxima = colunas[i];
        }
    }

    for (int linha = alturaMaxima; linha > 0; linha--) {
        for (size_t i = 0; i < digitos.size(); i++) {
            if (colunas[i] >= linha) {
                cout << "* ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }


    for (size_t i = 0; i < digitos.size(); i++) {
        cout << digitos[i] << " ";
    }
    cout << endl;
}

int main() {
    string digitos;
    cout << "Introduza uma sequencia de digitos: ";
    cin >> digitos;
    gerarHistograma(digitos);

    return 0;
}
