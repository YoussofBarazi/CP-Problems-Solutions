#include <iostream>

using namespace std;

int main ()
{
    int n ;
    cin >> n;

    int cnt = 0;

    for (int a = 1 ; a <= n ; a ++)
    {
        for (int b = a ; b <= n ; b ++)
        {
            int XOR = a ^ b;

            if (a + b > XOR && b < XOR && XOR <= n)
                cnt ++;
        }
    }

    cout << cnt << endl;
}