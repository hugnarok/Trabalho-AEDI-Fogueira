#include "include/algoritimics.hpp"


vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool limit(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}


void propagateFire(vector<vector<int>>& matrix, int rows, int cols) {
    vector<pair<int, int>> firePositions;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 2) {
                firePositions.push_back({i, j});
            }
        }
    }

    while (!firePositions.empty()) {
        pair<int, int> firePos = firePositions.back();
        firePositions.pop_back();

        for (auto d : directions){
            int dierctioX = firePos.first + d.first;
            int directionY = firePos.second + d.second;

            if (limit(dierctioX, directionY, rows, cols) && matrix[dierctioX][directionY] == 1) {
                matrix[dierctioX][directionY] = 2; 
            }
            matrix[firePos.first][firePos.second] = 3;
        }
    }
}

bool isFireExtinguished(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            if (cell == 2) {
                return false;
            }
        }
    }
    return true;
}

//animal
bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos) {

    for (auto d : directions){
        int dierctioX = animalPos.first + d.first;
        int directionY = animalPos.second + d.second;

        if (limit(dierctioX, directionY, rows, cols) && matrix[dierctioX][directionY] == 1) {
            matrix[animalPos.first][animalPos.second] = 1;
            matrix[dierctioX][directionY] = 9;
            animalPos = {dierctioX, directionY};
            return true;
        }else if(limit(dierctioX, directionY, rows, cols) && matrix[dierctioX][directionY] == 4){
            for (auto d : directions) {
                int newX = animalPos.first + d.first;
                int newY = animalPos.second + d.second;

                if (limit(newX, newY, rows, cols)) {
                    matrix[newX][newY] = 1;
                }
            }
            matrix[dierctioX][directionY] = 9;
            return true;
        }
    }                

    return false; 
}