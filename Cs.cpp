
int main()
{
  int array[5];
  for ( int i = 0; i< 5 ; i++)
  {
    cout << "Enter a number: ";
    cin >> array[i];
    cout << endl;
  }

  for ( int j = 0; j < 5; j++)
  {
    int result = array[j];
    for ( int k = 1; k <= 2; k++)
    {
        result = result * result;
    }
    cout << "array[" << j << "] ^ 2 :" << result << endl;
  }
  return 0;
}
