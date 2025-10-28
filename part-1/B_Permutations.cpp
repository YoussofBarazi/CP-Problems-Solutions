#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n , k;
    cin >> n >> k;
    
    vector < string > a(n);

    for (auto &x : a)
        cin >> x;

    vector < int > ndx(k);

    iota(ndx.begin() , ndx.end() , 0);

    int ans = INT_MAX;

    do {

        int mn = INT_MAX , mx = 0;

        for (int i = 0 ; i < n ; i ++)
        {
            int num = 0 , pow = 1;

            for (int j = k - 1 ; j >= 0 ; j --)
            {
                num += pow * (a[i][ndx[j]] - '0');
                pow *= 10; 
            }

            mn = min(mn , num);
            mx = max(mx , num);
        }

        ans = min(mx - mn , ans);

    } while (next_permutation(ndx.begin() , ndx.end()));

    cout << ans << endl;
}