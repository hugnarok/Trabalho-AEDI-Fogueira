#include "include/arquivos.hpp"

vector<vector<int>> getMatrix(ifstream &file, int& rows, int& cols, int& fireX, int& fireY) {
    file >> rows >> cols >> fireX >> fireY;
    
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
        }
    }

    return matrix;

    cout << "rodou";
}