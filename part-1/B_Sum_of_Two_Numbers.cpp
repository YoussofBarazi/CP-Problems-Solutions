#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define oo INT_MAX
#define OO LONG_MAX
#define pb push_back
#define F first
#define S second
#define Sort(a) sort(a.begin(), a.end())
#define Rsort(a) sort(a.rbegin(), a.rend())
#define UB(a, t) upper_bound(a.begin(), a.end(), t) - a.begin()
#define LB(a, t) lower_bound(a.begin(), a.end(), t) - a.begin()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    string n;
    cin >> n;

    string a , b;
    a = b = "";
    bool tx = true;
    int x , y;

    for (size_t i = 0; i < n.size(); i++)
    {
        int t = n[i] - '0';
        if (tx)
        {
            x = (t + 1) / 2;
        }
        else 
        {
            x = t / 2;
        }
        
        if (t % 2) tx = !tx;

        y = t - x;
        a += x + '0';
        b += y + '0';
    }
    
    x = stoi(a) , y = stoi(b);

    cout << x << " " << y << endl;
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