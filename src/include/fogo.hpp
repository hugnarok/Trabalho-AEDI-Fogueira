#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;

class Fogo {
    protected:
        int x, y;

    public:
        Fogo(int x, int y);
        pair<int, int> getPosition();

};