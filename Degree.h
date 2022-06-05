#include<iostream>
#include<vector>

class Degree
{
    public:
        Degree();
        Degree(int prei, double deg);

        int getPrevIndex() { return prevIndex ; }
        void setPrevIndex(int prei) {  prevIndex = prei ; }

        double getDegree() { return degree ; }
        void set(double deg) {  degree = deg ; }

    private:
        int prevIndex;
        double degree;
};
