#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int grid[1000][1000];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int rows_alternate = 0, cols_alternate = 0;

    for (int i = 0; i < n; i++)
    {
        int sum[] = {0, 0};

        for (int j = 0; j < n; j++)
        {

            sum[j % 2] += grid[i][j];
        }

        rows_alternate += max(sum[0], sum[1]);
    }

    for (int i = 0; i < n; i++)
    {
        int sum[] = {0, 0};

        for (int j = 0; j < n; j++)
        {
            sum[j % 2] += grid[j][i];
        }

        cols_alternate += max(sum[0], sum[1]);
    }

    cout << max(rows_alternate, cols_alternate) << endl;

    return 0;
}