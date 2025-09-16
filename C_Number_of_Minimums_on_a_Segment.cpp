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

const int N = 100009;

int n;

struct Node {
    int val , cnt;

    Node () {   
        val = 1e9 , cnt = 0;
    } 

    Node (int x , int c) {
        val = x , cnt = c;
    }
};


struct ST {
    
    #define lc (id << 1)
    #define rc ((id << 1) | 1)
    #define mid ((r + l) >> 1)

    vector <Node> seg;

    ST ()
    {
        seg.resize(4 * N);
    }    

    void merge(int id)
    {
        seg[id] = ans(seg[id * 2] , seg[id * 2 + 1]);
    }

    Node ans (Node a , Node b)
    {
        Node ANS;

        if (a.val < b.val)
            return a;
        else if (a.val > b.val)
            return b;
        else 
            return Node(a.val , a.cnt + b.cnt);
    }

    void update(int ndx , int val , int id = 1 , int l = 1 , int r = n)
    {
        if (l == r)
        {
            seg[id] = Node (val , 1);
            return ;
        }

        if (ndx <= mid)
            update(ndx , val , lc , l , mid);
        else 
            update(ndx , val , rc , mid + 1 , r);

        merge(id);
    }

    Node query(int L , int R , int id = 1 , int l = 1 , int r = n)
    {
        if (L <= l && r <= R)
            return seg[id];
        
        if (l > R || L > r)
            return Node();
        
        return ans(query(L , R , lc , l , mid) , query(L , R , rc , mid + 1 , r));
    }
};

void solve()
{
    int q;

    cin >> n >> q;

    ST st;

    for (int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >> x;

        st.update(i + 1 , x);
    }

    while (q --)
    {
        int type;
        cin >> type ;

        if (type == 1)
        {
            int i , v;
            cin >> i >> v;
            
            i ++;

            st.update(i , v);
        }
        else 
        {
            int l , r;
            cin >> l >> r;
            
            l ++;
            
            Node ans = st.query(l , r);
            cout << ans.val << " " << ans.cnt << endl;
        }
    }
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