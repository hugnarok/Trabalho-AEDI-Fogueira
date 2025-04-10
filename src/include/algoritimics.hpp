#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include "./programa.hpp"

using namespace std;
static bool animalAlive = true;
static vector<pair<int, int>> newFirePositions;
static set<pair<int, int>> lastPositionsAnimal;

bool limit(int x, int y, int rows, int cols);
void propagateFire(vector<vector<int>>& matrix, int rows, int cols);
bool isFireExtinguished(const vector<vector<int>>& matrix);
bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos);