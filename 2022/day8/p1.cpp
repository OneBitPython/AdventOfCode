#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif



void solve()
{
    int n =99;
    int m = n;
    vector<vector<int>>a(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;++i){
        string s;
        cin >> s;
        for(int j = 1;j<=m;++j){
            int x = s[j-1]-'0';
            a[i][j] = x;
        }
    }
    int res = (m+m)+(n-2)+(n-2);
    for(int i = 2;i<n;++i){
        for(int j = 2;j<m;++j){
            int mx = 0;
            for(int k = i-1;k>=1;--k){
                mx = max(mx, a[k][j]);
            }
            bool got = 0;
            if(mx < a[i][j])res++,got=1;
            mx = 0;
            for(int k = i+1;k<=n;++k){
                mx = max(mx, a[k][j]);
            }
            if(mx < a[i][j] && !got)res++,got=1;
            mx = 0;
            for(int k = j-1;k>=1;--k){
                mx = max(mx, a[i][k]);
            }
            if(mx < a[i][j] && !got)res++,got=1;
            mx = 0;
            for(int k = j+1;k<=m;++k){
                mx = max(mx, a[i][k]);
            }
            if(mx < a[i][j] && !got)res++;
        }
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}