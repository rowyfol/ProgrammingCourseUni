#include <iostream>

using namespace std;

int main()
{ 
  int num;
  int flag = 0;
  do {
    int pow = 1;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;
    if (num % 7 == 0)
    {
      flag = 1;
    } else {
      int i = 1;
      while (i <= 8)
        {
          pow = pow * num;
          i++;
        }
        cout << "The number " << num << " raised to the power of 8 is " << pow << endl;
    }
  }
  while (flag == 0);
  return 0;
}
