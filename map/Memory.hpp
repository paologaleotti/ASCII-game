class Memory {
    private:
        struct mem {
            int map[20][20];
			int level_id;
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
