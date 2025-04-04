#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set> 

using namespace std;

const int ESPACO_VAZIO = 0;
const int ARVORE_QUEIMADA = 3;
const int ARVORE_CHAMAS = 2;
const int POCA_AGUA = 4;
const int ANIMAL = 9;
const int ESPACO_SEGURO = 0;


// direções: 
    // 1. direita e baixo = {{1,0}, {0,1}}
    // 2. esquerda e baixo = {{-1,0}, {0,1}}
    // 3. direita e cima = {{1,0}, {0,-1}}
    // 4. esquerda e cima = {{-1,0}, {0,-1}}
    // 5. cima e baixo = {{-1,0}, {1,0}}
    // 6. esquerda direita = {{0,-1}, {0,1}}
    // 7. direita, esquerda e cima = {{1,0}, {0,-1}, {0,1}}
    // 8. direita, esquerda e baixo = {{1,0}, {0,-1}, {0,1}}
    // 9. direita, cima e baixo = {{1,0}, {0,-1}, {0,1}}
    // 10. esquerda, cima e baixo = {{-1,0}, {0,-1}, {1,0}}
    // 11. direita = {{0,1}}
    // 12. esquerda = {{0,-1}}
    // 13. cima = {{-1,0}}
    // 14. baixo = {{1,0}}
const int wind = 0;

const int numberOfIterations = 10;

vector<pair<int, int>> whindDirections(int wind);

const vector<pair<int, int>> directionsFire = whindDirections(wind);
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


