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

bool limit(int x, int y, int rows, int cols);
void propagateFire(vector<vector<int>>& matrix, int rows, int cols);
bool isFireExtinguished(const vector<vector<int>>& matrix);
bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos);