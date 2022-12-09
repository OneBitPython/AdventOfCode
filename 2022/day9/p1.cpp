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

bool same(int hx, int hy, int tx, int ty){
    // check if they are in the same row or column
    if(hx==tx || hy == ty)return 1;
    return 0;
}
int dist(int hx, int hy, int tx, int ty){
    return abs(hx-tx)+abs(hy-ty);
}
void move(int &x, int &y, char c){
    if(c=='U')y++;
    else if(c=='D')y--;
    else if(c=='L')x--;
    else x++;
    
}
void solve()
{
    int hx = 0, hy = 0, tx = 0, ty = 0;
    map<pair<int,int>,bool>visited;
    int n = 2000;
    for(int i = 0;i<n;++i){
        char x;
        cin >> x;
        int c;
        cin >> c;
        for(int i = 0;i<c;++i){
            move(hx,hy,x);
            int d = dist(hx, hy, tx, ty);
            if(same(hx,hy,tx,ty)){
                if(d >= 2){
                    move(tx,ty,x);
                }
            }else{
                if(d>2){
                    // move tx,ty diagonally
                    if(hx > tx && hy < ty)tx++,ty--;
                    else if(hx > tx && hy > ty)tx++,ty++;
                    else if(hx < tx && hy > ty)tx--,ty++;
                    else if(hx < tx && hy < ty)tx--,ty--;
                }
            }
            visited[{tx,ty}] = 1;
        }
    }
    int res = 0;
    for(auto x : visited){
        if(x.second)res++;
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