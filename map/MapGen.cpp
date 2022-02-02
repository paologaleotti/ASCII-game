#include "MapGen.hpp"
#include <stdlib.h>
#include <time.h>

void MapGen::gen_map() {
    srand(time(NULL));
    int m = rand()%3;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            int temp = MapGen::map_lib[m][y][x];
            this->map[y][x] = temp;
        }
    }
}