#include <iostream>
#include "stack.hpp"
#include "plates.hpp"
#pragma once



class Stack_of_plates: public Stack
{
    public:
        int maxlength;
        int length1;
        int length2;
        int length3;
        Plate *aray1;
        Plate *aray2;
        Plate *aray3;
        //int top1;
       // int top1;
       /* int top2;
        int top3;*/



        void sorting()
        {
            for(int i=0;i<maxlength;i++)
            {
                for(int j=i+1;j<maxlength;j++)
                {
                    if(aray1[i].diameter>aray1[j].diameter)
                    {
                        int gg;
                        gg=aray1[i].diameter;
                        aray1[i].diameter=aray1[j].diameter;
                        aray1[j].diameter=gg;
                    }
                }
            }

             for(int i=0;i<maxlength;i++)
            {
                for(int j=i+1;j<maxlength;j++)
                {
                    if(aray2[i].diameter>aray2[j].diameter)
                    {
                        int gg;
                        gg=aray2[i].diameter;
                        aray2[i].diameter=aray2[j].diameter;
                        aray2[j].diameter=gg;
                    }
                }
            }

             for(int i=0;i<maxlength;i++)
            {
                for(int j=i+1;j<maxlength;j++)
                {
                    if(aray3[i].diameter>aray3[j].diameter)
                    {
                        int gg;
                        gg=aray3[i].diameter;
                        aray3[i].diameter=aray3[j].diameter;
                        aray3[j].diameter=gg;
                    }
                }
            }
        }

        int if_you_won()
        {
            for(int i=0;i<maxlength;i++)
            {
                if(aray1[i].diameter!=0)
                {

                    return 3;
                }

                if(aray2[i].diameter!=0)
                {

                    return 3;

                }
            }


                return 10;
        }

        Stack_of_plates(int sizee)
        {
            maxlength=sizee;
            srand(time(0));
            length1=sizee;
            length2=0;
            length3=0;
            aray1=new Plate[maxlength];

            for(int i=0;i<maxlength;i++)
            {
                aray1[i].diameter=rand()%100+1;
            }



            aray2=new Plate[maxlength];

            for(int i=0;i<maxlength;i++)
            {
                aray2[i].diameter=0;
            }

            aray3=new Plate[maxlength];

            for(int i=0;i<maxlength;i++)
            {
                aray3[i].diameter=0;
            }

            sorting();
        }

        ~Stack_of_plates()
        {
            delete [] aray1;
            delete [] aray2;
            delete [] aray3;
        }

        void show()
        {
            std::cout<<"FIRST STACK" <<std::endl;

            for(int i=0;i<maxlength;i++)
            {
                if(aray1[i].diameter!=0)
                    std::cout<<aray1[i].diameter<<std::endl;
            }
            std::cout<<std::endl <<std::endl;

            std::cout<<"SECOND STACK" <<std::endl;

            for(int i=0;i<maxlength;i++)
            {
                if(aray2[i].diameter!=0)
                    std::cout<<aray2[i].diameter<<std::endl;
            }

            std::cout<<std::endl <<std::endl;

            std::cout<<"THIRD STACK" <<std::endl;

            for(int i=0;i<maxlength;i++)
            {
                 if(aray3[i].diameter!=0)
                    std::cout<<aray3[i].diameter<<std::endl;
            }

            std::cout<<std::endl <<std::endl;
        }

        int pop(int number)
        {
            int g;

            if(number==1)
            {
                if(length1>0)
                {

                    g=aray1[maxlength-length1].diameter;
                    aray1[maxlength-length1].diameter=0;
                    length1=length1-1;

                    sorting();

                    return g;
                }

                else
                {
                    std::cout<<"There is no value to give"<<std::endl;
                    return 0;
                }
            }

            else if(number==2)
            {

                if(length2>0)
                {
                    sorting ();
                    g=aray2[maxlength-length2].diameter;
                    aray2[maxlength-length2].diameter=0;
                    length2=length2-1;

                    sorting();

                    return g;
                }

                else
                {
                    std::cout<<"There is no value to give"<<std::endl;
                    return 0;
                }
            }

            else if(number==3)
            {
                if(length3>0)
                {
                    g=aray3[maxlength-length3].diameter;
                    aray3[maxlength-length3].diameter=0;
                    length3=length3-1;

                    sorting();

                    return g;
                }

                else
                {
                    std::cout<<"There is no value to give"<<std::endl;
                    return 0;
                }
            }

            else
            {
                std::cout<<"There is no array with this number!!!!";
            }

            sorting();

            return g;
        }

        int control_push(int number, int element)
        {
             if(number==1)
            {
                if(length1<maxlength)
                {
                    if(aray1[0].diameter>=element || aray1[0].diameter==0)
                    {

                        return 0;
                    }

                    else
                    {
                        return 10;
                    }
                }
                else
                {
                    return 10;
                }

            }

            else if(number==2)
            {
                if(aray2[0].diameter>=element || aray2[0].diameter==0)
                {
                    if(aray2[length2-1].diameter>=element)
                    {
                        return 0;
                    }

                    else
                    {
                        return 10;
                    }
                }
                else
                {
                    return 10;
                }
            }

               else if(number==3)
               {
                    if(length3<maxlength)
                    {
                        if(aray3[0].diameter>=element || aray3[0].diameter==0)
                        {
                            return 10;
                        }

                        else
                        {
                            return 10;
                        }
                    }

                    else
                    {
                        return 10;
                    }
                }

                else
                {
                    return 10;
                }

        }

        void push(int number, int element, int before)
        {

            if(number==1)
            {
                if(length1<maxlength)
                {
                    if(aray1[maxlength-length1].diameter>=element || aray1[maxlength-1].diameter==0)
                    {

                        aray1[0].diameter=element;

                        length1=length1+1;

                        sorting();

                        return ;
                    }

                    else
                    {
                        std::cout<<"You can not put this value here!!!!"<<std::endl;

                        push(before,element,number);

                        return ;
                    }
                }

                else
                {
                    std::cout<<"It would be too many elements in this array. You can not do this!!!"<<std::endl;

                    push(before,element,number);

                    return ;
                }

            }

            else if(number==2)
            {
                if(length2<maxlength)
                {
                    if(aray2[maxlength-length2].diameter>=element || aray2[maxlength-1].diameter==0)
                    {

                        aray2[0].diameter=element;

                        length2=length2+1;

                        sorting();

                        return ;
                    }

                    else
                    {

                        push(before,element,number);

                        std::cout<<"You can not put this value here!!!!"<<std::endl;

                        return ;
                    }
                }
                else
                {
                    std::cout<<"It would be too many elements in this array. You can not do this!!!"<<std::endl;

                    push(before,element,number);

                    return ;
                }
            }

               else if(number==3)
               {
                    if(length3<maxlength)
                    {
                        if(aray3[maxlength-length3].diameter>=element || aray3[maxlength-1].diameter==0)
                        {

                            aray3[0].diameter=element;

                            length3=length3+1;

                            sorting();

                            return ;
                        }

                        else
                        {
                            std::cout<<"You can not put this value here!!!!"<<std::endl;

                            push(before,element,number);

                            return ;
                        }
                    }

                    else
                    {
                        std::cout<<"It would be too many elements in this array. You can not do this!!!"<<std::endl;

                        push(before,element,number);

                        return ;
                    }
                }

                else
                {
                    std::cout<<"There is no this array"<<std::endl;


                        if(before==1)
                        {
                            push(1,element,before);
                        }

                        else if(before==2)
                        {
                            push(2,element,before);
                        }

                        else if(before==3)
                        {
                            push(3,element,before);
                        }

                    return ;
                }
        }
};
