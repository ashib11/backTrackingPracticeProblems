#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
#define ll long long
#define pi acos(-1.0)
#define ull unsigned long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// find_by_order();
// order_of_key();
bool isSafe(vector<vector<int>> &v, int x, int y, int n)
{
    if (x < 0 || x >= n || y < 0 || y >= n || v[x][y] == false)
        return false;
    return true;
}
bool rainMaze(vector<vector<int>> &v, int x, int y, int n, vector<vector<bool>> &bt)
{
    if (x == n - 1 and y == n - 1)
    {
        bt[x][y] = true;
        return true;
    }
    if (isSafe(v, x, y, n))
    {
        bt[x][y] = true;
        if (rainMaze(v, x + 1, y, n, bt))
        {
            return true;
        }
        if (rainMaze(v, x, y + 1, n, bt))
        {
            return true;
        }
    }
    bt[x][y] = false;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> v[i][j];
    vector<vector<bool>> bt(n, vector<bool>(n, false));
    if (rainMaze(v, 0, 0, n, bt))
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << bt[i][j] << ' ';
            cout << endl;
        }
    }
    else
        cout << "NO" << endl;
}

int main()
{
    fastIO();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
