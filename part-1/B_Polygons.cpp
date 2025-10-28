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
        // return (y < rhs.y || (y == rhs.y && x < rhs.x));
        return (x < rhs.x || (x == rhs.x && y < rhs.y));
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

int lower_hull_length;

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
	lower_hull_length = hull.size();

	for (int i = n - 2; i >= 0; i--) {
		while (hull.size() > lower_hull_length && cross(hull.back() - hull[hull.size() - 2] , points[i] - hull[hull.size() - 2]) < 0)
			hull.pop_back();
		hull.push_back(points[i]);
	}
	hull.pop_back();
    return hull;
}

bool inside(point p, vector <point> &uh, vector <point> &lh) { // check a point is it inside/outside a polygon
    auto t1 = lower_bound(all(uh), p);
    if (t1 == uh.begin() || t1 == uh.end()) {
        return false;
    }
    auto t2 = t1 - 1;

    if (cross(*t1 - *t2, p - *t2) >= 0) {
        return false;
    }

    t1 = lower_bound(all(lh), p);
    if (t1 == lh.begin() || t1 == lh.end()) {
        return false;
    }
    t2 = t1 - 1;
    
    if (cross(*t1 - *t2, p - *t2) <= 0) {
        return false;
    }

    return true;
}

void solve()
{
    int n, m;
    cin >> n;

    vector <point> a(n);
    for (auto& [x, y, i] : a) {
        cin >> x >> y;
    }

    a = convex_hull(a);

    vector <point> lh, uh;
    for (int i = 0 ; i < lower_hull_length ; i ++) {
        lh.push_back(a[i]);
    } for (int i = lower_hull_length - 1 ; i < a.size() ; i ++) {
        uh.push_back(a[i]);
    }
    uh.push_back(a[0]);
    reverse(all(uh));

    cin >> m;
    bool ok = true;

    while (m --) {
        int x, y;
        cin >> x >> y;

        if (!inside(point(x, y), uh, lh)) {
            ok = false;
        }
    }

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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