#ifndef POWERUPS_HPP
#define POWERUPS_HPP

#include "../room/Room.hpp"

class Pickups {
    private:
        struct pickup_prop {
            int type;
            int y;
            int x;
        };

        struct pickup_list {
            pickup_prop pickup;
            pickup_list *next;
        };
        
    public:

    typedef pickup_list *p_pickup_list;
    p_pickup_list head;

    void pickup_obj_assign(Room *room);
    void pickup_destroy(int x, int y);
    void check_if_exist(Room *room);

};

#endif