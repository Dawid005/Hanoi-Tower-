#include <iostream>
#include <time.h>
#pragma once


class Plate
{
    public:

        int diameter;
        Plate ()
        {
            srand(time(0));
            diameter=rand()%100+1;
        }

        Plate (int abcd)
        {
            diameter= abcd;
        }

        Plate(const Plate &p1)
        {
            diameter=p1.diameter;
        }

        Show()
        {
            return diameter;
        }
};
