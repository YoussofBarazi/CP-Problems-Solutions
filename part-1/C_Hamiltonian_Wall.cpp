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
string s[2];
int mem[2][N];
int n;

int dp (int i , int j , pi lst)
{
    if ((i == 2 && j == n) || s[i][j] == 'W')
    {
        return 0;
    }
    if (mem[i][j] != 0) 
    {
        return mem[i][j];
    }

    int ans1 = 1 , ans2 = 1;
    if (j + 1 < n) ans1 += dp(i , j + 1 , {i , j});
    if (lst != make_pair(int(!i) , j)) ans2 += dp(!i , j , {i , j});

    mem[i][j] = max(ans1 , ans2);
    
    return max(ans1 , ans2);
}

void solve()
{
    cin >> n;

    cin >> s[0] >> s[1];

    for (size_t i = 0; i < n; i++)
    {
        mem[0][i] = mem[1][i] = 0;
    }
    
    int cnt = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (s[0][i] == 'B') cnt ++;
        if (s[1][i] == 'B') cnt ++;
    }

    if (dp(0 , 0 ,{}) == cnt)
    {
        cout << "YES" << endl;
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        mem[0][i] = mem[1][i] = 0;
    }
    
    if (dp(1 , 0 , {}) == cnt)
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
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