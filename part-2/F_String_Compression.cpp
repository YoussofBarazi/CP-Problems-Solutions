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

const int N = 8009;

vector <int> digits(N , 0);

void precalc()
{
    for (int i = 1 ; i < N ; i ++)
        digits[i] = to_string(i).size();
}

int DP[N];
int pi[N];

void KMP(string s)
{
    for (int i = 1 ; i < s.size() ; i ++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[j] == s[i])
            j ++;
        
        pi[i] = j;
    }
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    for (int i = 0 ; i < n ; i ++)
            DP[i] = 1e8;

    string t = s;
    reverse(all(t));

    for (int l = 0 ; l < n ; l ++)
    {
        string tmp = t;
        reverse(all(tmp));
        KMP(tmp);

        int last = l ? DP[l - 1] : 0;

        for (int r = l ; r < n ; r ++)
        {
            int len = r - l + 1;
            int sp = len - pi[r - l];

            if (len % sp == 0)
            {
                DP[r] = min(DP[r] , last + sp + digits[len / sp]);
            }
            else 
            {
                DP[r] = min(DP[r] , last + len + 1);
            }
        }

        t.pop_back();
    }

    cout << DP[n - 1] << endl;
}

int main()
{
    IOS;

    precalc();

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}