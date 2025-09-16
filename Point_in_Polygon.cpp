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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

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
        return (y < rhs.y || (y == rhs.y && x < rhs.x));
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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<point> pts(n);

    for (auto &p : pts)
    {
        cin >> p.x >> p.y;
    }

    n++;
    pts.push_back(pts[0]);

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        point t(x, y);

        bool boundary = false;
        bool inside = false;

        point inf(x + 1 , 1e9 + 7);

        for (int i = 1 ; i < n ; i ++) {
            if (cross(t - pts[i - 1] , pts[i] - pts[i - 1]) == 0 && inside_rect(pts[i] , pts[i - 1] , t)) {
                boundary = true;
            }
            auto S = [&](ll w) { return (w > 0)? 1 : (w < 0) ? -1 : 0 ;};
            bool b1 = S(cross(t - pts[i - 1] , pts[i] - pts[i - 1])) * S(cross(inf - pts[i - 1] , pts[i] - pts[i - 1])) < 0;
            bool b2 = S(cross(pts[i - 1] - t , inf - t)) * S(cross(pts[i] - t , inf - t)) < 0;

            if (b1 && b2) {
                inside ^= 1;
            }
        }

        if (boundary) {
            cout << "BOUNDARY" << endl;
        } else if (inside) {
            cout << "INSIDE" << endl;
        } else {
            cout << "OUTSIDE" << endl;
        }
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