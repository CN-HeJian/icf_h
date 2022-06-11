#pragma

extern int s_iFirst;
extern int s_iSecond;

class CHaveStaticDataMember{
    public:
        CHaveStaticDataMember(){};
        ~CHaveStaticDataMember() {};
    //private:
        static int m_iStaticInitial;
        static int m_iDynInitial;
};




