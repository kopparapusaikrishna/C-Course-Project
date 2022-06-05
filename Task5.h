#ifndef TASK5_H_
#define TASK5_H_

#include "Base.h"
#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include "Edge.h"
#include "Sort.h"

// Implements base class.
class Task5: public Base{

public:
    void input() override;
    void process() override;
    void output() override;

private:
    std::vector<std::string> inputLines; //Each line of input is stored here in order.
    std::vector<std::string> outputLines; //Each line of output is stored here for writing in output file.
    int n;



};

#endif //TASK5_H
