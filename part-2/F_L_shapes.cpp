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

int dx[] = {-1 , 0 , 1 , 0 , 1 , 1 , -1 , -1};
int dy[] = {0 , 1 , 0 , -1 , 1 , -1 , 1 , -1};

const int N = 200009;

int parent[N];

int find(int id)
{
    return parent[id] = (id == parent[id])? id : find(parent[id]); 
}

void join(int id1 , int id2)
{
    id1 = find(id1);
    id2 = find(id2);

    if (id1 == id2) 
        return ;

    parent[id1] = id2;
}

void solve()
{
    int n , m;
    cin >> n >> m;

    vector <string> s(n + 2 , string(m + 2 , '.'));
    for (int i = 1 ; i <= n ; i ++)
        for (int j = 1 ; j <= m ; j ++)
            cin >> s[i][j];

    vector <vi> id(n + 2);
    vector <vector <bool>> ok(n + 2);

    //cout << "KKKKKKKKKKKKKKKK" << endl;
    int t = 0;

    for (int i = 0 ; i < n + 2 ; i ++)
        for (int j = 0 ; j < m + 2 ; j ++)
            id[i].push_back(t ++) , ok[i].push_back(false);

    for (int id = 0 ; id < t ; id ++)
        parent[id] = id;

    for (int i = 1 ; i <= n ; i ++)
    {        
        for (int j = 1 ; j <= m ; j ++)
        {
            if (s[i][j] == '*' && !ok[i][j])
            {
                if (s[i + 1][j] == '*' && s[i + 1][j + 1] == '*' && !ok[i + 1][j] && !ok[i + 1][j + 1])
                {
                    join(id[i][j] , id[i + 1][j]);
                    join(id[i][j] , id[i + 1][j + 1]);

                    ok[i + 1][j] = true;
                    ok[i + 1][j + 1] = true;
                }
                else if (s[i + 1][j] == '*' && s[i][j + 1] == '*' && !ok[i + 1][j] && !ok[i][j + 1])
                {
                    join(id[i][j] , id[i + 1][j]);
                    join(id[i][j] , id[i][j + 1]);

                    ok[i + 1][j] = true;
                    ok[i][j + 1] = true;
                }
                else if (s[i][j + 1] == '*' && s[i + 1][j + 1] == '*' && !ok[i][j + 1] && !ok[i + 1][j + 1])
                {
                    join(id[i][j] , id[i][j + 1]);
                    join(id[i][j] , id[i + 1][j + 1]);

                    ok[i][j + 1] = true;
                    ok[i + 1][j + 1] = true;
                }
                else if (s[i + 1][j] == '*' && s[i + 1][j - 1] == '*' && !ok[i + 1][j] && !ok[i + 1][j - 1])
                {
                    join(id[i][j] , id[i + 1][j]);
                    join(id[i][j] , id[i + 1][j - 1]);

                    ok[i + 1][j] = true;
                    ok[i + 1][j - 1] = true;
                }
                else 
                {
                    // cout << i << " " << j << endl;
                    cout << "NO" << endl;
                    return ;
                }

                ok[i][j] = true;
            }

            if (ok[i][j] && s[i][j] == '*')
            {
                for (int t = 0 ; t < 8 ; t ++)
                {
                    int I = i + dx[t] , J = j + dy[t];

                    if (s[I][J] == '*' && find(id[I][J]) != find(id[i][j]))
                    {
                        // cout << i << " " << j << " " << I << " " << j << endl;
                        cout << "NO" << endl;
                        return ;
                    }
                }
            }
        }
    }

    cout << "YES" << endl;
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