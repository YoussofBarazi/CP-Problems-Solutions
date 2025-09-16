#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;



void solve()
{
    int n;
    cin >> n;

    
    for (int i = 1 ; i <= n ; i ++)
    {
        bool t1 = i % 2 , t2 = i % 2;
        for (int j = 1 ; j <= n ; j ++)
        {
            if (t1)
                cout << "##" ;
            else 
                cout << ".." ; 
            t1 = !t1;
        }
        cout <<"\n";
        for (int j = 1 ; j <= n ; j ++)
        {
            if (t2)
                cout << "##" ;
            else 
                cout << ".."; 
            t2 = !t2;
        }
        cout <<"\n";
    }
}

int main()
{
    IOS;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}