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

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 200009;

void solve()
{
    int n , m , k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    s = 'L' + s + 'L';

    int swim_count = 0;

    for (int i = 0 ; i <= n;)
    {
        bool done = false;

        if (s[i] == 'L')
            for (int j = m ; j > 0 ; j --)
            {
                if (s[min(i + j , n + 1)] == 'L')
                {
                    i += j;
                    done = true;
                    break;
                }
            }

        if (done)
            continue;
        
        if(s[i] == 'L')
            for (int j = m ; j > 0 ; j --)
            {
                if (s[min(i + j , n + 1)] == 'W')
                {
                    i += j;
                    done = true;
                    break;
                }
            }

        if (!done && s[i] == 'W' && s[i + 1] != 'C')
        {
            i ++;
            done = true;
            swim_count ++;
        }

        if (!done || swim_count > k)
        {
            cout << "NO" << endl;
            return ;
        }
    }

    cout << "YES" << endl;
}

int main()
{
    // IO("name");
    IOS;

    int t = 1;
    cin >> t;

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