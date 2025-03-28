#pragma once

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getMatrix(ifstream &file, int& rows, int& cols, int& fireX, int& fireY); 