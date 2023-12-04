#include <iostream>
#include <vector>

using namespace std;

// Classe Plate representa uma placa com comprimento, largura e preço.
class Plate {
private:
    int length, width, price;

public:
    // Construtor para inicializar a placa com valores específicos.
    Plate(int l, int w, int p) : length(l), width(w), price(p) {}

    // Métodos para obter as propriedades da placa.
    int getPrice() const { return price; }
    int getWidth() const { return width; }
    int getLength() const { return length; }
};

// Função principal do algoritmo que calcula o preço máximo possível.
int algorithm(const vector<Plate>& plateList, int maxWidth, int maxLength) {
    // Tabela de programação dinâmica para armazenar os preços máximos.
    vector<vector<int>> dp(maxWidth + 1, vector<int>(maxLength + 1, 0));

    // Pré-processamento para estabelecer os preços máximos para cada tamanho de placa.
    for (const auto& plate : plateList) {
        if (plate.getWidth() <= maxWidth && plate.getLength() <= maxLength) {
            dp[plate.getWidth()][plate.getLength()] = max(dp[plate.getWidth()][plate.getLength()], plate.getPrice());
        }
        if (plate.getWidth() != plate.getLength() && plate.getLength() <= maxWidth && plate.getWidth() <= maxLength) {
            dp[plate.getLength()][plate.getWidth()] = max(dp[plate.getLength()][plate.getWidth()], plate.getPrice());
        }
    }

    // Preenchimento da tabela DP, considerando todos os cortes possíveis.
    for (int w = 1; w <= maxWidth; ++w) {
        for (int l = 1; l <= maxLength; ++l) {
            for (int cut = 1; cut < w; ++cut) {
                dp[w][l] = max(dp[w][l], dp[cut][l] + dp[w - cut][l]);
            }
            for (int cut = 1; cut < l; ++cut) {
                dp[w][l] = max(dp[w][l], dp[w][cut] + dp[w][l - cut]);
            }
        }
    }

    return dp[maxWidth][maxLength]; // Retorna o preço máximo obtido.
}

// Função principal que lê os dados de entrada e executa o algoritmo.
int main() {
    int plateWidth, plateLength, numberPlates;
    cin >> plateWidth >> plateLength >> numberPlates;

    vector<Plate> vecPlateList;
    for (int i = 0; i < numberPlates; ++i) {
        int length, width, price;
        cin >> length >> width >> price;
        vecPlateList.emplace_back(length, width, price);
    }

    int price = algorithm(vecPlateList, plateWidth, plateLength);
    cout << price << "\n"; // Exibe o preço máximo.
    return 0;
}



/*
Complexidade das Funções:

● Plate::Plate(int, int, int): O(1) - Inicialização direta dos membros.
● Plate::getPrice, getWidth, getLength: O(1) - Acesso direto a um membro.
● algorithm(...):
    ○ O(N * maxWidth * maxLength) - Onde N é o número de placas.
    ○ Cada placa é processada uma vez, e para cada placa, a tabela DP é atualizada com base em suas dimensões.
    ○ O preenchimento da tabela DP é feito com dois loops aninhados, cada um dependendo de maxWidth e maxLength.
● main(): Depende da entrada, mas principalmente dominado pela chamada de algorithm(...), portanto, tem a mesma complexidade dessa função.


Comentário Geral sobre o Projeto e sua Complexidade:

Este projeto implementa um algoritmo para calcular o preço máximo que pode ser obtido cortando placas de diferentes tamanhos e preços. 
Utiliza a abordagem de programação dinâmica para otimizar o cálculo, estruturando-se em torno da classe Plate e da função algorithm. 
A função main lê os dados das placas, armazena-os num vetor de objetos Plate e invoca o algoritmo para calcular o preço máximo.

A complexidade total do projeto é O(N * maxWidth * maxLength), onde N é o número de tipos de placas, e maxWidth e maxLength são as dimensões máximas consideradas. 
Esta complexidade é principalmente devido ao preenchimento da tabela de programação dinâmica, que considera todos os tamanhos possíveis e as combinações de cortes para maximizar o preço.

*/