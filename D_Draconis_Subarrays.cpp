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

vector<int> KMP(vector<ll> s)
{
    int n = s.size();
    vector<int> pi(n , 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    return pi;
}

void solve()
{
    int m , n;
    cin >> m >> n;

    vector <ll> M(m + 2 , 0) , N(n + 2 , 0);
    vector <ll> all;
    
    for (int i = 1 ; i <= m ; i ++)
    {
        cin >> M[i];
        
        if (i > 1)
            all.push_back(M[i] - M[i - 1]);
    }

    all.push_back(-1e9);

    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> N[i];

        if (i > 1)
            all.push_back(N[i] - N[i - 1]);
    }

    vector <int> kmp = KMP(all);

    int cnt = 0;

    for (int i = 0 ; i <= all.size() ; i ++)
    {
        cnt += (kmp[i] == (m - 1));
    }

    cout << cnt << endl;
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