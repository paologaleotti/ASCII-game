class Memory {
    private:
        struct map_mem {
            int map[20][20];
            map_mem *prec;
            map_mem *next;
        };
        
    public:
    typedef map_mem *p_map_mem;
	p_map_mem head;
	p_map_mem active;

	Memory();
	void push_map(int map[20][20]);
	void modify_node(p_map_mem *act, int mapToPush[20][20]);
};