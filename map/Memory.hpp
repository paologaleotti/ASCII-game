class Memory {
    private:
        struct map_mem {
            int map[20][20];
            map_mem *prec;
            map_mem *next;
        };
        
    public:
    typedef map_mem *p_map_mem;

	Memory();
	void push_map(p_map_mem *head, int map[20][20]);
};