#include "MapGen.hpp"

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

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            int temp = tr_lib[m][y][x];
            this->map[y][x+10] = temp;
        }
    }

    m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = bl_lib[m][y][x];
            this->map[y+10][x] = temp;
        }
    }

    m = rand()%MapGen::n_sect;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) { 
            int temp = br_lib[m][y][x];
            this->map[y+10][x+10] = temp;
        }
    }
}

void MapGen::gen_enemy(int n) {
    srand(time(NULL));

    for (int y = 1; y < 19; y++) {
        int dist = (rand()%3)+4;
        for (int x = 1; x < 19; x++) {
            if(this->map[y][x] == 0 && rand()%20 == 0 && n > 0 && dist < 0) {
                this->map[y][x] = 3;
                n--;
                dist = (rand()%3)+4;
            } else {
                dist--;
            }
        }
    }
}

void MapGen::gen_artifacts() {
    srand(time(NULL));

    for (int y = 1; y < 19; y++) {
        for (int x = 1; x < 19; x++) { 
            if (this->map[y][x] == 7 && rand()%3 == 0) {
                this->map[y][x] = 0;
            }
        }
    }
}

void MapGen::gen_powerup() {
    srand(time(NULL));
    bool is_generated = false;

    for (int y = 1; y < 19; y++) {
        for (int x = 1; x < 19; x++) { 
            if (this->map[y][x] == 0 && rand()%450 == 0 && !is_generated) {
                this->map[y][x] = 8;
                is_generated = true;
            }
        }
    }
}