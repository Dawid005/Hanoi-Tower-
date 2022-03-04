#include <iostream>

#include "Stack_of_plates.hpp"

using namespace std;

int main()
{

    Stack_of_plates a(9);

    a.show();

    while(a.if_you_won()==3)
    {
        int choice;
        int choice2;
        int value;
        int gg;
        int abc;

        cout<<"From which stack do you want get your plate, give me number: "<<endl;
        cin>>choice;

        cout<<"Where do you want to put this";
        cin>> choice2;

        a.push(choice2,a.pop(choice),choice);

        a.show();

    }
    cout<<"Congratulations, You have won!!!!"<<endl;

    return 0;
}
