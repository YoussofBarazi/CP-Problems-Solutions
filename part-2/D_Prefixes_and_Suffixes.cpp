#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
using namespace std;

const int N = 200009;

vector <int> KMP(string s)
{
    int n = s.size();
    vector <int> pi(n);

    for (int i = 1 ; i < n ; i ++)
    {
        int j = pi[i - 1];
  
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j ++;

        pi[i] = j;
    }

    return pi;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    vector <int> PF = KMP(s);
    vector <int> freq(n + 1 , 0);
    
    for (int i = 0 ; i < n ; i ++)
    {
        freq[PF[i]] ++;
    }

    for (int i = n - 1 ; i >= 1 ; i --)
            freq[PF[i - 1]] += freq[i];
    
    vector <int> ans;

    while (n > 0)
        ans.pb(n) , n = PF[n - 1];

    cout << ans.size() << endl;

    sort(all(ans));

    for (auto &x : ans)
        cout << x << " " << freq[x] + 1 << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}

void IO(string name = "") {

	cin.tie(0)->sync_with_stdio(0);
	if (name.size()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}

}