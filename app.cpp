#include <iostream>

using namespace std;

int main()
{
    int satr, soton;
    cout << "satr: ";
    cin >> satr;
    cout << "soton: ";
    cin >> soton;

    int matris_1[satr][soton];
    int matris_2[satr][soton];

    for (int i=0; i < satr; i++)
    {
        cout << "sater: " << i << endl;
        for ( int j =0; j < soton; j++)
        {
            cout << "i = " << i << ", j = " << j << endl;
            cin >> matris_1[i][j];
        }

    }

    for (int i=0; i < satr; i++)
    {
        cout << "sater: " << i << endl;
        for (int j =0; j < soton; j++)
        {
            cout << "i = " << i << ", j = " << j << endl;
            cin >> matris_2[i][j];
        }
    }


    int tarane_1[soton][satr];
    int tarane_2[soton][satr];

    for ( int i =0; i < soton; i++)
    {
        for (int j=0; i < satr; i++ )
        {
            tarane_1[i][j] = matris_1[j][i];
            tarane_2[i][j] = matris_2[j][i];
        }
    }

    int output[satr][soton];

    for (int i = 0; i < satr; i++)
    {
        for (int j =0; i < soton; j++)
        {
            output[i][j] = 0;
            for (int k = 0; k < soton; k++)
            {
                output[i][j] += tarane_1[i][k] * tarane_2[k][j];
            }
        }
    }

    for (int i = 0; i < satr; i++)
    {
        for (int j =0; j < soton; j++)
        {
            cout << output[i][j] << "\t";
        }
        cout << endl;
    }
    
    int a;
    cin >> a; 

    return 0;
}