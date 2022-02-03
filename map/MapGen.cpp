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

    srand(time(NULL));
    m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = tr_lib[m][y][x];
            this->map[y][x+10] = temp;
        }
    }

    srand(time(NULL));
    m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = bl_lib[m][y][x];
            this->map[y+10][x] = temp;
        }
    }

    srand(time(NULL));
    m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = br_lib[m][y][x];
            this->map[y+10][x+10] = temp;
        }
    }
}