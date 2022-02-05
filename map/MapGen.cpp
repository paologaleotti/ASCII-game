#include "MapGen.hpp"
#include <stdlib.h>
#include <time.h>

void MapGen::gen_map() {
    srand(time(NULL));
    int m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = tl_lib[m][y][x];
            this->map[y][x] = temp;
        }
    }

    m = rand()%MapGen::n_sect;
    int cont = 2;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            int temp = tr_lib[m][y][x];
            if(temp == 0 && rand()%10 == 0 && cont > 0){
                this->map[y][x+10] = 3;
                cont--;
            }
            else this->map[y][x+10] = temp;
        }
    }

    m = rand()%MapGen::n_sect;
    cont = 2;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = bl_lib[m][y][x];
            if(temp == 0 && rand()%10 == 0 && cont > 0){
                this->map[y+10][x] = 3;
                cont--;
            }
            else this->map[y+10][x] = temp;
        }
    }

    m = rand()%MapGen::n_sect;
    cont = 2;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = br_lib[m][y][x];
            if(temp == 0 && rand()%10 == 0 && cont > 0){
                this->map[y+10][x+10] = 3;
                cont--;
            }
            else this->map[y+10][x+10] = temp;
        }
    }
}