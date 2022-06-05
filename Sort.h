#include<iostream>
#include<vector>
#include "Degree.h"

class Sort
{
    public:
        Sort();
        Sort(std::vector<Degree> Arr);

        std::vector<Degree> Sorting();

    private:
        std::vector<Degree> arr;


};