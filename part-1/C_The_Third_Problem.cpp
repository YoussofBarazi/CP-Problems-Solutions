// problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=759

#include <bits/stdc++.h>

using namespace std;

// a rectangle such that the lower-left corner is (x1 , y1)
// and the upper-right corner is (x2 , y2)
struct Rectangle
{
    int x1, y1, x2, y2;

    Rectangle() {}
    Rectangle(int _x1, int _y1, int _x2, int _y2)
    {
        x1 = _x1;
        y1 = _y1;
        x2 = _x2;
        y2 = _y2;
    }

    int area()
    {
        if (x2 < x1 || y2 < y1)
            return 0;
        return (x2 - x1) * (y2 - y1);
    }
};

// return the intersection between two rectangles
Rectangle rectangleIntersection(Rectangle r1, Rectangle r2)
{
    return Rectangle(max(r1.x1, r2.x1), max(r1.y1, r2.y1), min(r1.x2, r2.x2), min(r1.y2, r2.y2));
}

// reads a rectangle
Rectangle getRectangle()
{
    Rectangle r;
    scanf("%d %d %d %d", &r.x1, &r.y1, &r.x2, &r.y2);
    return r;
}

void solve()
{
    Rectangle A, B, C;
    A = getRectangle();
    B = getRectangle();
    C = getRectangle();

    printf("%d\n", A.area() - rectangleIntersection(A, C).area() + B.area() - rectangleIntersection(B, C).area());
}

int main()
{

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    solve();

    return 0;
}