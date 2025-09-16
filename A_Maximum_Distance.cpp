#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector <int> x(n) , y(n);

    for (auto &a : x)
        cin >> a;

    for (auto &a : y)
        cin >> a;

    int ans = 0;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < n ; j ++)
        {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            
            ans = max(ans , dist);
        }
    }

    cout << ans << endl;
}