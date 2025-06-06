#include "include/config.hpp"

vector<pair<int, int>> whindDirections(int wind){
    vector<pair<int, int>> routes;
    //{rows, coluns}

    switch (wind){
        case 1: // direita e baixo
            routes = {{0, 1}, {1, 0}};
            break;
        case 2: // esquerda e baixo
            routes = {{0, -1}, {1, 0}};
            break;
        case 3: // direita e cima
            routes = {{0, 1}, {-1, 0}};
            break;
        case 4:  // Esquerda e cima
            routes = {{0, -1}, {-1, 0}};
            break;
        case 5:  // Cima e baixo
            routes = {{-1, 0}, {1, 0}};
            break;
        case 6:  // Esquerda e direita
            routes = {{0, -1}, {0, 1}};
            break;
        case 7:  // Direita, esquerda e cima
            routes = {{0, 1}, {0, -1}, {-1, 0}}; 
            break;
        case 8:  // Direita, esquerda e baixo
            routes = {{0, 1}, {0, -1}, {1, 0}};
            break;
        case 9:  // Direita, cima e baixo
            routes = {{0, 1}, {-1, 0}, {1, 0}};
            break;
        case 10: // Esquerda, cima e baixo
            routes = {{0, -1}, {-1, 0}, {1, 0}};
            break;
        case 11: // Direita
            routes = {{0, 1}};
            break;
        case 12: // Esquerda
            routes = {{0, -1}};
            break;
        case 13: // Cima
            routes = {{-1, 0}};
            break;
        case 14: // Baixo
            routes = {{1, 0}};
            break;
        case 0:
            routes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            break;
        default:
            routes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            break;
    }

    return routes;
};