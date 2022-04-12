#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>

// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pr pair<int, int>
#define forn(i, a, b) for (int i = a; i <= b; i++)
#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>

#define prl pair<long long, long long>
#define mp make_pair
#define pb push_back
const long long mod = 998244353;

using namespace std;

ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void print(vl &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
        cout << arr[i] << " ";
    cout << '\n';
}
ll po(ll x, ll y)
{
    if (y < 0)
        return 0;
    ll ans = 1;
    while (y--)
    {
        ans *= x;
        ans %= mod;
    }

    return ans;
}
const ll INF = LLONG_MAX;
ll addINF(ll x, ll y)
{
    if (INF - x <= y)
        return INF;
    return x + y;
}
ll mulINF(ll x, ll y)
{
    if (INF / x < y)
        return INF;
    return x * y;
}
ll nCrMOD(ll n, ll x)
{
    ll ans = 1;
    for (int i = 1; i <= x; i++)
    {
        ans *= (n - i + 1);
        ans %= mod;
        ans *= inv(i);
        ans %= mod;
    }
    return ans;
}
bool comp(prl a, prl b)
{
    return a.second < b.second;
}

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool check(string &take){
    bool t = true;
        for (int k = 0; k < (int)take.length() / 2; k++)
        {
            if (take[k] != take[(int)take.length() - 1 - k])
            {
                t = false;
                break;
            }
        }
        if(t)
        {
            return false;
        }
        t = true;
        int len = take.length() - 1;
        for (int k = 0; k < len / 2; k++)
        {
            if (take[k] != take[len - 1 - k])
            {
                t = false;
                break;
            }
        }
        if(t)
        {
            return false;
        }
        t = true;
        len++;
        for (int k = 0; k < len / 2; k++)
        {
            if (k + 1 < len - 1 - k && take[k + 1] != take[len - 1 - k])
            {
                t = false;
                break;
            }
        }
        if(t)
        {
            return false;
        }
        return true;
}
void rec(string &str, int i, string take,vector<vector<string>> &str5)
{
    if(i == 6)
    {
        if(check(take))str5[5].pb(take.substr(1));
        return;
    }
    if (str[i] == '?')
    {
        rec(str, i + 1, take + '0',str5);
        rec(str, i + 1, take + '1',str5);
    }
    else
        rec(str, i + 1, take + str[i],str5);
}
void solve(int test)
{

    int n;
    string str;
    cin >> n >> str;
    vector<vector<string>> str5(n);
    if(n < 5)
    {
        cout << "Case #" << test << ": " << "POSSIBLE"<< '\n';
        return;
    }
    if(n == 5)
    {
        for(int i = 0; i < 5;i++)
        {
            if(i != 2 && str[i] == '?')
            {
                cout << "Case #" << test << ": " << "POSSIBLE"<< '\n';
                return;
            }
        }
        bool a = true;
        for(int i = 0;i < n / 2;i++)
        {
            if(str[i] != str[n - i - 1])
            {
                a = false;
                break;
            }
        }
        if(a)cout << "Case #" << test << ": " << "IMPOSSIBLE"<< '\n';
        else cout << "Case #" << test << ": " << "POSSIBLE"<< '\n';
        return;
    }
    rec(str,0,"",str5);
     if(str5[5].size() == 0)
        {
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << '\n';
            return;
        }
    for(int i = 6; i < n;i++)
    {
        for(int k = 0;k < str5[i - 1].size();k++)
        {
            if(str[i] != '?')
            {
                string g = str5[i - 1][k] + str[i]; 
                if(check(g))
                {
                    str5[i].pb(g.substr(1));
                }
                
            }
            else{
                string e = str5[i - 1][k] + '0';
                string g = str5[i - 1][k] + '1';
                if(check(e))
                {
                    str5[i].pb(e.substr(1));
                }
                if(check(g))
                {
                    str5[i].pb(g.substr(1));
                    
                }
            }
        }
        if(str5[i].size() == 0)
        {
            cout << "Case #" << test << ": " << "IMPOSSIBLE" << '\n';
            return;
        }
       
    }
     cout << "Case #" << test << ": " << "POSSIBLE" << '\n';
    
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve(i + 1);
    }
}
