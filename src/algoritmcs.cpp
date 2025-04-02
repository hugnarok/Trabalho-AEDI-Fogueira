#include "include/algoritimics.hpp"
#include "include/config.hpp"

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
            int directionX = firePos.first + d.first;
            int directionY = firePos.second + d.second;

            if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == 1) {
                matrix[directionX][directionY] = 2; 
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

    for (auto d : directions) {
        int directionX = animalPos.first + d.first;
        int directionY = animalPos.second + d.second;

        if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == 0) {
            matrix[animalPos.first][animalPos.second] = 1;
            matrix[directionX][directionY] = 9;
            animalPos = {directionX, directionY};
            return true;
        }
    }

    for (auto d : directions) {
        int directionX = animalPos.first + d.first;
        int directionY = animalPos.second + d.second;

        if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == 1) {
            matrix[animalPos.first][animalPos.second] = 1;
            matrix[directionX][directionY] = 9;
            animalPos = {directionX, directionY};
            return true;
        }
    }

    for (auto d : directions){
        int dierctionX = animalPos.first + d.first;
        int directionY = animalPos.second + d.second;

        if (limit(dierctionX, directionY, rows, cols) && matrix[dierctionX][directionY] != 2 && matrix[dierctionX][directionY] != 3) {
            if(matrix[dierctionX][directionY] == 4){
                for (auto d : directions) {
                    int newX = dierctionX + d.first;
                    int newY = directionY + d.second;

                    if (limit(newX, newY, rows, cols) && matrix[newX][newY] == 4) {
                        matrix[newX][newY] = 4;
                    }else{
                        matrix[newX][newY] = 1;
                    }
                }
                matrix[animalPos.first][animalPos.second] = 0;
                matrix[dierctionX][directionY] = 9;
                animalPos = {dierctionX, directionY};
                return true;
            }else{
                matrix[animalPos.first][animalPos.second] = 1;
                matrix[dierctionX][directionY] = 9;
                animalPos = {dierctionX, directionY};
                return true;
            }
        }
    }


    return false; 
}
