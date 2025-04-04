#include "include/arquivos.hpp"
#include "include/programa.hpp"
#include "include/algoritimics.hpp"
#include "include/config.hpp"

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
    cout << endl;
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

    ifstream file("./src/input.dat");
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

    ifstream archive("./src/input.dat");
    pair<int, int> rowsAndCols = getRowsAndCols(archive);
    int cont = 1;
    vector<vector<int>> floresta = createMatrix();
    pair<int, int> animalPos = getAnimalPosition(floresta, rowsAndCols.first, rowsAndCols.second);


    freopen("./src/output.dat", "w", stdout);

    while (!isFireExtinguished(floresta) && (cont < numberOfIterations + 1)) {
        printMatrix(floresta);
        cout << "Iteracao: " << cont << " de " << numberOfIterations << endl;
        runAnimal(floresta, rowsAndCols.first, rowsAndCols.second, animalPos);
        propagateFire(floresta, rowsAndCols.first, rowsAndCols.second);
        

        cont++;
    }
    cout << "Nao ha mais arvores para queimar!" << endl;

    fclose(stdout);
}

