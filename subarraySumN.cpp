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
int n, k, arr[20];
set<vector<int>> ans;
vector<int> v;
void rec(int indx, int curRem)
{
    if (curRem == 0)
    {
        ans.insert(v);
    }
    if (indx >= n)
        return;
    rec(indx + 1, curRem);
    v.push_back(arr[indx]);
    rec(indx + 1, curRem - arr[indx]);
    v.pop_back();
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    rec(0, k);
    if (ans.size() == 0)
    {
        cout << "NONE" << endl
             << endl;
        
        return;
    }
    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << ' ';
        cout << endl;
    }
    cout << endl;
    v.clear();
    ans.clear();
}

int main()
{
    fastIO();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
