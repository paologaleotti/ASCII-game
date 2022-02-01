#include "Entity.hpp"
class Player : public Entity{
    public:
	int score;

	Player(int hp, int dmg, bool isDead=false, int x=0, int y=0, int score=0);
	void mv_left();
    void mv_right();
    void mv_up();
    void mv_down();
	void pickup_artifact();
};