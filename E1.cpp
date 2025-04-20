#include <iostream>

using namespace std;

void space()
{
        cout<<endl;
}

int main()
{
        int loop_n;
        cout<<"Enter loop_n: ";
        cin>>loop_n;
        space();

        int a, b, max, min;

        cout<<"Enter the first number:";
        cin>>b;
        space();

        cout<<"Enter the second number:";
        cin>>a;
        space();

        if (a >= b) {
                max = a;
                min = b;

        } else {
                min = a;
                max = b;
        }

        int input_n;

        for (int i=0; i<loop_n;i++)
        {
                cout<<"Enter the number: ";
                cin>>input_n;
                space();

                if (input_n > max)
                {
                        max = input_n;
                }
                if (input_n < min)
                {
                        min =input_n;
                }
        }

        cout<<"Max: "<<max<<endl;
        cout<<"Min: "<<min<<endl;


        return 0;
}
