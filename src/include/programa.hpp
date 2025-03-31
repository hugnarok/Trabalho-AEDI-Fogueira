#pragma once 

#include <iostream>
#include <vector>

using namespace std;

// função para criar a matriz a partir do arquivo
void printMatrix(const vector<vector<int>>& matrix);
vector<vector<int>> createMatrix();
pair<int, int> getRowsAndCols(ifstream &file);
pair<int, int> getAnimalPosition(const vector<vector<int>>& matrix , int rows, int cols);
void executeProgram();



