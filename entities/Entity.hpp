
class Entity{
    public:
        int HP; // vita
        // possibile int DEF, difesa che va sottratta ai danni ricevuti
        int DMG; // danno
        int mvspeed; // n di caratteri per cui si muove ad ogni tic
        bool KO; // per segnare se è vivo o morto

    private:
        int xCor, yCor;  // coordinate su matrice

    public:

    void dmgCalc(int incDMG); //incoming damage calc
    void mvleft();
    void mvright();
    void mvup();
    void mvdown();


};