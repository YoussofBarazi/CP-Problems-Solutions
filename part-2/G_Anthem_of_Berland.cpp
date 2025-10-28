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

vector<int> KMP(string s){
    int n = s.size();
    vector<int> pi(n);

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

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = KMP(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

vector <vi> kmp;
vector <vi> DP;
string s , t;

int dp(int i , int j)
{
    if (i >= s.size())
        return j == t.size();

    int &ret = DP[i][j];

    if (ret != -1)
        return ret;

    ret = 0;

    if (s[i] == '?')
        for (int c = 0 ; c < 26 ; c ++)
            ret = max(ret , dp(i + 1 , kmp[j][c]) + (t.size() == j));
    else 
        ret = dp(i + 1 , kmp[j][s[i] - 'a']) + (t.size() == j);
        
    return ret;
}

void solve()
{
    cin >> s >> t;

    compute_automaton(t , kmp);
    DP.resize(s.size() + 1 , vector <int>(t.size() + 1 , -1));

    cout << dp(0 , 0) << endl;
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