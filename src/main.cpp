#include <iostream>
#include "include/arquivos.hpp"

using namespace std;

int main() {

    ifstream file("/home/hugo/Área de trabalho/AEDi/Trabalho_01/Trabalho-AEDI-Fogueira/src/input.dat");
    int rows, cols, fireX, fireY;

    if (!file){
        cerr << "Arquivo não encontrado" << endl;
        return -1;
    }
    
    vector<vector<int>> matrix = getMatrix(file, rows, cols, fireX, fireY);
    file.close();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}