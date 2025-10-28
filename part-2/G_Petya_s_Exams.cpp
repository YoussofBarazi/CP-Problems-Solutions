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

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <array<int , 4>> exam;
    for (int i = 0 ; i < m ; i ++)
    {
        int s , d , c;
        cin >> s >> d >> c;

        exam.push_back({d , s , c , i + 1});
    }

    sort(all(exam));

    // for (auto x : exam)
    // {
    //     cout << x[3] << endl;
    // }

    vector <int> day(n + 1 , 0);

    for (auto x : exam)
    {
        int s = x[1] , d = x[0] , c = x[2] , i = x[3];

        for (int j = s ; j < d && 0 < c; j ++)
        {
            if (day[j])
                continue;
            
            c --;
            day[j] = i;
        }

        if (c)
        {
            cout << -1 << endl;
            return ;
        }
        
        day[d] = m + 1;
    }

    for (int i = 1 ; i <= n ; i ++)
        cout << day[i] << " " ;
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