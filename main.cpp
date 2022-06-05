#include "Task5.h"

using namespace std;

void Task(Base *b)
{
    b->input();
    b->process();
    b->output();
}

int main()
{
    Base *b;
    /*
    Task1 task1;
    b = &task1;
    task(b);

    Task2 task2;
    b = &task2;
    task(b);

    Task3 task3;
    b = &task3;
    task(b);
    */

    Task5 task5;
    b = &task5;
    Task(b);

    return 0;
}
