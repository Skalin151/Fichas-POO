#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

// a) Declarar uma list de strings
list<string> palavras;

// b) Função para ler de um ficheiro de texto todas as palavras e colocar na lista
void LerFicheiroParaLista(const string& nomeFicheiro, list<string>& lista) {
    ifstream file(nomeFicheiro);
    if (!file) {
        cout << "Erro ao abrir o ficheiro: " << nomeFicheiro << endl;
        return;
    }
    string palavra;
    while (file >> palavra) {
        lista.push_back(palavra); // Adiciona cada palavra à lista
    }
    file.close();
}

// c) Contar todas as palavras
int ContarPalavras(const list<string>& lista) {
    return lista.size(); // Retorna o tamanho da lista
}

// d) Listar as palavras que estão na lista
void ListarPalavras(const list<string>& lista) {
    for (const auto& palavra : lista) {
        cout << palavra << endl;
    }
}

// e) Listar ao contrário o conteúdo da lista
void ListarPalavrasAoContrario(const list<string>& lista) {
    for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
        cout << *it << endl;
    }
}

// f) Eliminar uma palavra da lista (dada a palavra)
void EliminarPalavra(list<string>& lista, const string& palavra) {
    lista.remove(palavra); // Remove todas as ocorrências da palavra
}

// g) Eliminar uma palavra da lista (dada uma posição da lista)
void EliminarPalavraPorPosicao(list<string>& lista, int posicao) {
    if (posicao < 0 || posicao >= lista.size()) {
        cout << "Posição inválida." << endl;
        return;
    }
    auto it = lista.begin();
    advance(it, posicao); // Avança o iterador para a posição desejada
    lista.erase(it);      // Remove a palavra na posição
}

// h) Verificar se existem palavras repetidas
bool ExistemPalavrasRepetidas(const list<string>& lista) {
    list<string> palavrasUnicas(lista);
    palavrasUnicas.sort();   // Ordena a lista
    palavrasUnicas.unique(); // Remove palavras repetidas consecutivas
    return palavrasUnicas.size() != lista.size();
}

// i) Contar o número de palavras de tamanho inferior a 5
int ContarPalavrasComMenosDe5Caracteres(const list<string>& lista) {
    return count_if(lista.begin(), lista.end(), [](const string& palavra) {
        return palavra.size() < 5;
    });
}

// j) Passar todas as palavras da lista para maiúsculas
void ConverterParaMaiusculas(list<string>& lista) {
    for (auto& palavra : lista) {
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::toupper);
    }
}

// k) Gravar num ficheiro de texto as palavras de tamanho superior a 10
void GravarPalavrasComMaisDe10Caracteres(const list<string>& lista, const string& nomeFicheiro) {
    ofstream file(nomeFicheiro);
    if (!file) {
        cout << "Erro ao abrir o ficheiro: " << nomeFicheiro << endl;
        return;
    }
    for (const auto& palavra : lista) {
        if (palavra.size() > 10) {
            file << palavra << endl;
        }
    }
    file.close();
}

int main() {
    // a) Declarar uma list de strings
    list<string> palavras;

    // b) Ler de um ficheiro de texto todas as palavras e colocar na lista
    LerFicheiroParaLista("palavras.txt", palavras);

    // c) Contar todas as palavras
    cout << "Numero de palavras: " << ContarPalavras(palavras) << endl;

    // d) Listar as palavras que estão na lista
    cout << "Palavras na lista:" << endl;
    ListarPalavras(palavras);

    // e) Listar ao contrário o conteúdo da lista
    cout << "\nPalavras ao contrario:" << endl;
    ListarPalavrasAoContrario(palavras);

    // f) Eliminar uma palavra da lista (dada a palavra)
    EliminarPalavra(palavras, "exemplo"); // Suponha que "exemplo" é uma palavra da lista

    // g) Eliminar uma palavra da lista (dada uma posição da lista)
    EliminarPalavraPorPosicao(palavras, 2); // Elimina a palavra na posição 2 (terceira palavra)

    // h) Verificar se existem palavras repetidas
    if (ExistemPalavrasRepetidas(palavras)) {
        cout << "\nExistem palavras repetidas." << endl;
    } else {
        cout << "\nNao existem palavras repetidas." << endl;
    }

    // i) Contar o número de palavras de tamanho inferior a 5
    cout << "\nNumero de palavras com menos de 5 caracteres: " << ContarPalavrasComMenosDe5Caracteres(palavras) << endl;

    // j) Passar todas as palavras da lista para maiúsculas
    ConverterParaMaiusculas(palavras);
    cout << "\nPalavras convertidas para maiusculas:" << endl;
    ListarPalavras(palavras);

    // k) Gravar num ficheiro de texto as palavras de tamanho superior a 10
    GravarPalavrasComMaisDe10Caracteres(palavras, "palavras_maiores_que_10.txt");

    return 0;
}
