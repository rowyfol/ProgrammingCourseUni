#include <iostream>

using namespace std;

int main()
{
	int loop_n;
	cout<<"Enter loop_n: "<<endl;
	cin>>loop_n;

	int a,b, max, min;

	cout<<"Enter the first number:"<<endl;
	cin>>b;

	cout<<"Enter the second number:"<<endl;
	cin>>a;

	if (a>=b) {
		max = a;
	} else {
		min = a;
	}


	int input_n;

	for (int i=0; i<loop_n;i++)
	{
		cout<<"Enter the number: "<<endl;
		cin>>input_n;

		if (input_n>max)
		{
			max = input_n;
		}
		if (input_n<min)
		{
			min =input_n;
		}
	}

	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;


	return 0;
}
