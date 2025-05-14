
int main()
{
  int num;
  int size;
  cout << "Enter a number: ";
  cin >> num;
  cout << "Enter the size of number: ";
  cin >> size;

  int array[size];
  int r;
  for (int i = 0; i < size; i++)
  {
    r = num%10;
    array[i] = r;
    cout << array[i];
    num /= 10;
  }
  cout << endl;
  return 0;
}
