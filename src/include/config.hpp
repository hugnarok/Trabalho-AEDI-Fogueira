#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int ESPACO_VAZIO = 0;
const int ARVORE_QUEIMADA = 3;
const int ARVORE_CHAMAS = 2;
const int POCA_AGUA = 4;
const int ANIMAL = 9;
const int ESPACO_SEGURO = 0;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};