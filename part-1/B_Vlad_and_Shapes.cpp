#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
char a[N][N];
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int s = 0;
        bool k = false;

        for (int i = 0; i < n; ++i)
        {
            string a;
            cin >> a;
            if (k)
            {

                continue;
            }
            int sum = 0;

            for (int j = 0; j < n; ++j)
            {
                if (a[j] == '1')
                {
                    ++sum;
                }
            }

            if (s == 0)
            {
                s = sum;
            }
            else
            {
                if (sum != s)
                {
                    k = true;
                }
            }
        }

        if (!k)
        {
            cout << "SQUARE" << endl;
        }
        else 
        {
            
            cout << "TRIANGLE" << endl;
        }
    }
}