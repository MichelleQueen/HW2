class AI: public Model{
    public:
        void initial();
        void update(std::list<Object*> object_list);
};