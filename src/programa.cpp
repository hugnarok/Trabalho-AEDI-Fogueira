#include "include/arquivos.hpp"
#include "include/programa.hpp"
#include "include/algoritimics.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void printMatrix(const vector<vector<int>>& matrix) {
    cout << "\n Matriz atual:\n" << endl;
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

pair<int, int> getRowsAndCols(ifstream &file) {
    int rows, cols;
    file >> rows >> cols;
    return {rows, cols};
}

pair<int, int> getAnimalPosition(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 9) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; 
}

vector<vector<int>> createMatrix() {  

    ifstream file("/home/hugo/Área de trabalho/AEDi/Trabalho_01/Trabalho-AEDI-Fogueira/src/input.dat");
    int rows, cols, fireX, fireY;

    if (!file){
        cerr << "Arquivo naao encontrado" << endl;
        return {};
    }

    vector<vector<int>> matrix = getMatrix(file, rows, cols, fireX, fireY);

    return matrix;
}


//execução
void executeProgram() {

    ifstream archive("/home/hugo/Área de trabalho/AEDi/Trabalho_01/Trabalho-AEDI-Fogueira/src/input.dat");

    pair<int, int> rowsAndCols = getRowsAndCols(archive);
    int rows = rowsAndCols.first;
    int cols = rowsAndCols.second;
    vector<vector<int>> floresta = createMatrix();
    pair<int, int> animalPos = getAnimalPosition(floresta, rows, cols);

    while (!isFireExtinguished(floresta)) {
        printMatrix(floresta);
        if (!runAnimal(floresta, rows, cols, animalPos)) {
            cout << "O animal nao pode mais se mover!" << endl;
        }
        propagateFire(floresta, rows, cols);
    }
    
    cout << "Nao ha mais arvores para queimar!" << endl;

}

