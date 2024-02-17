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
ll func(int indx, ll sumB, ll sumC, int n, vector<ll> &v)
{
    if (indx >= n)
    {
        return abs((sumB * sumB) - (sumC * sumC));
    }
    ll ans = INT_MAX;
    ans = min(ans, func(indx + 1, sumB + v[indx], sumC, n, v));
    ans = min(ans, func(indx + 1, sumB, sumC + v[indx], n, v));
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    cout << func(0, 0, 0, n, v) << endl;
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
