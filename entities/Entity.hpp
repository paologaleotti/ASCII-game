
class Entity{
    public:
        int hp; // vita
        // possibile int DEF, difesa che va sottratta ai danni ricevuti
        int dmg; // danno
        int mvSpeed; // n di caratteri per cui si muove ad ogni tic
        bool isDead; // per segnare se è vivo o morto

    private:
        int x, y;  // coordinate su matrice

    public:

        void dmg_calc(int incDmg); //incoming damage calc
        void mv_left();
        void mv_right();
        void mv_up();
        void mv_down();


};