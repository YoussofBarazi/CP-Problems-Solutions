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

const int N = 5001;

int choose[N][N] , mod = 1e9 + 7;

void bascal_triangle(int n, int k, int p)
{
    for (int i = 0; i <= n; i++)
    {

        choose[i][0] = 1;

        if (i <= k)
        {
            choose[i][i] = 1;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            if (i != j)
            {
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % p;
            }
        }
    }
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve()
{
    int n , q;
    string s;
    cin >> n >> q >> s;
    
    vector <vector<bool>> vis(n , vector <bool> (n , false));
    vector <ll> ans(n + 5 , 0);
    vector <int> cnt(2 * n , 0);

    for (int i = 0 ; i < n ; i ++)
    {
        string t = s.substr(i);
        vector <int> z = z_function(t) , freq(n + 1 , 0);

        for (int j = 0 ; j < z.size() ; j ++)
        {   
            freq[0] ++;
            freq[z[j] + 1] --;
        }
        for (int i = 1 ; i <= t.size() ; i ++)
        {
            freq[i] += freq[i - 1];
            cout << freq[i]+1 << " " ;
            cnt[freq[i] + 1] ++;
        }

        cout << endl;
    }    

    for (int i = 1 ; i <= n ; i ++)
    {
        for (int j = 1 ; j <= i ; j ++)
        {
            ans[j] += choose[i][j] * cnt[i] % mod;
        }
    }

    while (q --)
    {
        int k;
        cin >> k;

        if (k >= ans.size())
            cout << 0 << endl;
        else 
            cout << ans[k] % mod << endl;
    }
}

int main()
{
    IOS;

    bascal_triangle(N - 1 , N - 1 , mod);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}