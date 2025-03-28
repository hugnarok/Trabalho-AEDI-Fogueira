#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;
class Animal {
    protected:
        int x, y;
        bool vida;

    public:
        Animal(int x, int y);
        pair<int, int> getPositionAnimal();
        bool getVida();
        void walk(int x, int y);

};