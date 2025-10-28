#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allrev(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

void solve()
{
    int a , b , c , m;
    cin >> a >> b >> c >> m;

    vector <int> USB , PS2;

    while (m --)
    {
        int price;
        string type;

        cin >> price >> type;

        if (type == "USB")
            USB.push_back(price);
        else 
            PS2.push_back(price);
    }

    sort(all(USB));
    sort(all(PS2));

    ll cost = 0 , cnt = 0;

    int i = 0 , j = 0;
    
    while (i < USB.size() && a > 0)
    {
        cnt ++;
        cost += USB[i ++];
        a --;
    }

    while (j < PS2.size() && b > 0)
    {
        cnt ++;
        cost += PS2[j ++];
        b --;
    }

    while (c > 0)
    {
        if (j < PS2.size() && i < USB.size())
        {
            if (PS2[j] < USB[i])
                cost += PS2[j ++];
            else 
                cost += USB[i ++];
        }
        
        else if (j < PS2.size())
            cost += PS2[j ++];
        
        else if(i < USB.size())
            cost += USB[i ++];
        
        else 
            break;
        
        cnt ++;
        c --;
    }

    cout << cnt << " " << cost << endl;
}   

int main()
{
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}