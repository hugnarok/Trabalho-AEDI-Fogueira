#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <utility> 

using namespace std;

class Arvore {
    protected:
        int x, y, situacao;
        bool chmas;

    public:
        Arvore(int x, int y, int situacao);
        pair<int, int> getPositionArvore();
        int getSituacao();
        bool getChmas();
        void setChmas(bool chmas);
        void setSituacao(int situacao);
};