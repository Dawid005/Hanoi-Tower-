#include <iostream>
#pragma once




class Stack
{
    public:
        int *arrayy;
        int length;
        int top;

        Stack()
        {
            *arrayy=NULL;
            length=0;
            top=-1;
        }

        Stack(int *aray, int longg)
        {
            length=longg;
            top=length-1;
            arrayy=new int[length];

            for(int i=0;i<length;i++)
                arrayy[i]=aray[i];

        }

        Stack(int abc)
        {
            length=1;
            top=0;

            arrayy=new int[length];

            arrayy[0]=abc;
        }

        ~Stack()
        {
            delete [] arrayy;
            length=0;
            top=-1;
        }

        void push(int element)
        {
            length=length+1;
            top=length-1;
            int *aray=new int[length];

            for(int i=0;i<length-1;i++)
                aray[i]=arrayy[i];

            aray[length-1]=element;

            delete [] arrayy;

            arrayy= new int[length];

            for(int i=0;i<length;i++)
                arrayy[i]=aray[i];

            delete [] aray;
        }

        int pop()
        {
            if(length==0&&top==-1)
            {
                std::cout<<"Warning, Stack is empty!!!"<<std::endl;
                std::cout<<"Number of elements already is: ";

                return 0;
            }

            else
            {
                int gg=arrayy[length-1];
                length=length-1;
                top=length-1;
                int *aray=new int[length];

                for(int i=0;i<length;i++)
                    aray[i]=arrayy[i];

                delete [] arrayy;

                arrayy=new int[length];

                for(int i=0;i<length;i++)
                    arrayy[i]=aray[i];

                delete [] aray;

                return gg;
            }
        }

        void delet()
        {
            length=0;
            top=-1;
            delete [] arrayy;
        }

        void isempty()
        {
            if(length==0&&top==-1)
            {
                std::cout<<"Stack is empty";
                return ;
            }

            else
            {
                std::cout<<"Stack is not empty";
                return ;
            }
        }
        int How_many()
        {
            return length;
        }

        Stack(const Stack &pi)
        {
            length=pi.length;
            top=pi.top;

            for(int i=0;i<length;i++)
                arrayy[i]=pi.arrayy[i];
        }
};
