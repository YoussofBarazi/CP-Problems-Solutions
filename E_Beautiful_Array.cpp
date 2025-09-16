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

ll DP[N][2];
int n , k;

ll dp(int i , vector <int> &a , bool d)
{
    if (i >= a.size() - 1)
        return 0;
    
    ll &ret = DP[i][2];

    if (ret != -1)
        return ret;

    ret = dp(i + 2 , a , d) + (a[i + 1] - a[i]) / k;  
    
    if (!d)
    {
        ret = min(ret , dp(i + 1 , a , true));
    }

    return ret;
}  

void solve()
{
    cin >> n >> k;

    map <int , vector <int>> m;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        m[x % k].push_back(x);
    }

    ll mn = 0;
    bool one_odd = false;

    for (auto x : m)
    {
        sort(all(x.S));
        
        if (x.S.size() % 2)
        {
            if (one_odd)
            {
                cout << "-1\n";
                return ;
            }

            one_odd = true;

            for (int i = 0 ; i < x.S.size() ; i ++)
                DP[i][0] = DP[i][1] = -1;
            
            mn += dp(0 , x.S , 0);
        }
        else 
        {    
            for (int i = 1 ; i < x.S.size() ; i += 2)
            mn += (x.S[i] - x.S[i - 1]) / k;
        }
    }

    cout << mn << endl;
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