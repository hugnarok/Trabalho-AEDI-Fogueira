#include "include/algoritimics.hpp"
#include "include/config.hpp"

static bool animalAlive = true;

bool limit(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

static vector<pair<int, int>> newFirePositions;

void propagateFire(vector<vector<int>>& matrix, int rows, int cols) {
    vector<pair<int, int>> firePositions;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 2) {
                firePositions.push_back({i, j});
            }
        }
    }

    while (!newFirePositions.empty()){
        pair<int, int> firePos = newFirePositions.back();
        newFirePositions.pop_back();

        if (limit(firePos.first, firePos.second, rows, cols)){
            matrix[firePos.first][firePos.second] = 3;
        }
    }
    
    while (!firePositions.empty()) { 
        pair<int, int> firePos = firePositions.back();
        firePositions.pop_back();
        if (limit(firePos.first, firePos.second, rows, cols)){
            newFirePositions.push_back(firePos);
        }
        

        for (auto d : directionsFire) {
            int directionX = firePos.first + d.first;
            int directionY = firePos.second + d.second;

            if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == 9) {
                matrix[directionX][directionY] = 2;
                animalAlive = false;
            }
            
            if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == 1) {
                matrix[directionX][directionY] = 2;
            }
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

//anim!al
static set<pair<int, int>> lastPositionsAnimal;

bool runAnimal(vector<vector<int>>& matrix, int rows, int cols, pair<int, int> &animalPos) {
    if(!animalAlive) return false;

    vector<int> priorities {4, 0, 1};

    for (int priority : priorities) {
        for (auto d : directions) {
            int directionX = animalPos.first + d.first;
            int directionY = animalPos.second + d.second;

            if (limit(directionX, directionY, rows, cols) && matrix[directionX][directionY] == priority) {

                if(lastPositionsAnimal.find({directionX, directionY}) == lastPositionsAnimal.end()){

                    if (matrix[directionX][directionY] == 4){
                        for(auto d2 : directions){
                            int directionX2 = directionX + d2.first;
                            int directionY2 = directionY + d2.second;
                            
                            if (limit(directionX2, directionY2, rows, cols)){
                                if (matrix[directionX2][directionY2] == 4){
                                    matrix[directionX2][directionY2] = 4;
                                }else{
                                    matrix[directionX2][directionY2] = 1;
                                }
                                
                            }
                        }
                    }

                    matrix[animalPos.first][animalPos.second] = 1;
                    matrix[directionX][directionY] = 9;
                    animalPos = {directionX, directionY};
                    lastPositionsAnimal.insert(animalPos);
                    return true;
                    
                }
            }
        }
    }

    return false;
}