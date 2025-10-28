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

class SparseTable {
    int K , N;
    vector <vector<ll>> st;

    public :

    SparseTable(int k , int n , vector<ll> &arr) {
        K = k; 
        N = n; 
        st.assign(k + 1 , vector<ll>(n + 1 , LLONG_MAX));
        build(arr);
    }

    void build(vector<ll> &arr) {
        for (int i = 0 ; i < arr.size() ; i ++) {
            st[0][i] = arr[i];
        }
        
        for (int i = 1; i <= K; i++)
            for (int j = 0; j + (1 << i) <= N; j++)
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    ll f(ll &x , ll &y) {
        return min(x, y); 
    }

    int log2_floor(unsigned long long i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    
    ll query(int l , int r) {
        int i = log2_floor(r - l + 1);
        return f(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

void solve()
{
    int n;
    cin >> n;

    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    SparseTable sparse = SparseTable(floor(log2(n)) , n , a);

    int q;
    cin >> q;

    while (q --) {
        int l , r;
        cin >> l >> r;
        cout << sparse.query(l , r) << endl;
    }
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