class Empty{
    public:
        Empty(){}
        ~Empty(){}
        Empty(const Empty& h);
        Empty& operator=(const Empty& rhs);

        Empty* operator&();
        const Empty* operator&()const;

    private:

};