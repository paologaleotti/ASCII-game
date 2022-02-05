class Memory {
    private:
<<<<<<< HEAD
        struct map_mem {
            int map[20][20];
            map_mem *prec;
            map_mem *next;
        };
        
    public: 
    typedef map_mem *p_map_mem;
};
=======
        struct mem {
            int map[20][20];
            mem *prec;
            mem *next;
        };
        
    public:
    typedef mem *p_mem;
	p_mem last;
	p_mem active;

	Memory();
    void fill_map(p_mem *ptr, int map[20][20]);
	void push_map(int mapToPush[20][20]);
	void modify_node(int mapToPush[20][20]);
};
>>>>>>> origin/pollo
