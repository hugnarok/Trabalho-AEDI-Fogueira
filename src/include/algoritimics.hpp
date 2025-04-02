#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool limit(int x, int y, int rows, int cols);
void propagateFire(vector<vector<int>>& matrix, int rows, int cols);
bool isFireExtinguished(const vector<vector<int>>& matrix);
bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos);