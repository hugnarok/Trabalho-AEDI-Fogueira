#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;
class Agua{
    protected:
        int x, y;
        bool vazia;

    public:
        Agua(int x, int y);
        pair<int, int> getPositionAgua();
        bool getVazia();

};