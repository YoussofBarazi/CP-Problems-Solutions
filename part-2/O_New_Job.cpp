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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;

int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};

const int N = 69;

template <typename T>
struct TPoint
{
    T x;
    T y;
    int id;

    TPoint() : x(0), y(0), id(-1) {}
    TPoint(const T &x_, const T &y_) : x(x_), y(y_), id(-1) {}
    TPoint(const T &x_, const T &y_, int id_) : x(x_), y(y_), id(id_) {}

    static constexpr T eps = static_cast<T>(1e-9);

    inline TPoint operator+(const TPoint &rhs) const { return TPoint(x + rhs.x, y + rhs.y); }
    inline TPoint operator-(const TPoint &rhs) const { return TPoint(x - rhs.x, y - rhs.y); }
    inline TPoint operator*(const T &rhs) const { return TPoint(x * rhs, y * rhs); }
    inline TPoint operator/(const T &rhs) const { return TPoint(x / rhs, y / rhs); }

    friend T dot(const TPoint &a, const TPoint &b)
    { // Dot Product
        return a.x * b.x + a.y * b.y;
    }

    friend T cross(const TPoint &a, const TPoint &b)
    { // Cross Product
        return a.x * b.y - a.y * b.x;
    }

    inline T abs2() const
    {
        return x * x + y * y;
    }

    inline bool operator<(const TPoint &rhs) const
    {
        return (y < rhs.y || (y == rhs.y && x < rhs.x));
        // return (x < rhs.x || (x == rhs.x && y < rhs.y));
    }

    inline bool operator==(const TPoint &rhs) const
    {
        return (y == rhs.y && x == rhs.x);
    }

    inline bool is_upper() const
    {
        return (y > eps || (abs(y) <= eps && x > eps));
    }

    inline int cmp_polar(const TPoint &rhs) const
    {
        assert(abs(x) > eps || abs(y) > eps);
        assert(abs(rhs.x) > eps || abs(rhs.y) > eps);
        bool a = is_upper();
        bool b = rhs.is_upper();
        if (a != b)
        {
            return (a ? -1 : 1);
        }
        long long v = x * rhs.y - y * rhs.x;
        return (v > eps ? -1 : (v < -eps ? 1 : 0));
    }

    friend bool inside_rect(TPoint A, TPoint B, TPoint P)
    {
        return (min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y));
    };
};

using point = TPoint<long long>;
// using point = TPoint<long double>;

template <typename T>
string to_string(const TPoint<T> &p)
{
    return "(" + to_string(p.x) + ", " + to_string(p.y) + ")";
}

vector<point> convex_hull(vector<point> &points) {
    vector <point> hull;

	sort(points.begin(), points.end());

	points.erase(unique(points.begin(), points.end()), points.end());
	int n = points.size();

	if (n < 3) {
		hull = points;
		return hull;
	}

	for (int i = 0; i < n; i++) {
		while (hull.size() > 1 && cross(hull.back() - hull[hull.size() - 2] , points[i] - hull[hull.size() - 2]) < 0)
			hull.pop_back();
		hull.push_back(points[i]);
	}

	auto lower_hull_length = hull.size();

	for (int i = n - 2; i >= 0; i--) {
		while (hull.size() > lower_hull_length && cross(hull.back() - hull[hull.size() - 2] , points[i] - hull[hull.size() - 2]) < 0)
			hull.pop_back();

		hull.push_back(points[i]);
	}
	hull.pop_back();
    return hull;
}

vector <point> p;
ll dp[N][N][N];
int n, k, c;

ll sol(int i, int cnt, int first, int last) {
    if (i == first) {
        return abs(cross(p[last] - p[i], p[first] - p[i]));
    } if (cnt == k) {
        return 0;
    }

    ll &ret = dp[i][cnt][last];
    if (ret != -1) {
        return ret;
    }

    ret = sol((i + 1) % n, cnt, first, last);
    ret = max(ret, sol((i + 1) % n, cnt + 1, first, i) + abs(cross(p[i] - p[first], p[last] - p[first])));
    
    return ret;
}

vector <point> ans;

void dfs(int i, int cnt, int first, int last) {
    if (i == first) {
        return ;
    }

    ll t = sol(i, cnt, first, last);

    if (t - abs(cross(p[last] - p[first], p[i] - p[first])) == sol((i + 1) % n, cnt + 1, first, i)) {
        ans.push_back(p[i]);
        dfs((i + 1) % n, cnt + 1, first, i);
    } else {
        dfs((i + 1) % n, cnt, first, last);
    }
}

void solve()
{
    cin >> n >> k >> c;

    p.resize(n);

    for (int i = 0 ; i < n ; i ++) {
        cin >> p[i].x >> p[i].y;
    }

    p = convex_hull(p);
    n = p.size();
    k = min(k , n);

    // for (auto [x , y , id] : p) {
    //     cout << x << " " << y << endl;
    // }

    pair <ll, int> mx = {-1, -1};

    for (int i = 0 ; i < n ; i++) {
        memset(dp, -1, sizeof dp);
        mx = max(mx, {sol((i + 1) % n , 1, i, i), i});
    }

    ans.push_back(p[mx.S]);
    memset(dp, -1, sizeof dp);
    dfs((mx.S + 1) % n, 1, mx.S, mx.S);

    cout << mx.F * c / 2 << ((mx.F * c % 2)? ".5" : ".0") << endl;
    cout << ans.size() << endl;
    for (auto [x, y, id] : ans) {
        cout << x << " " << y << endl;
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