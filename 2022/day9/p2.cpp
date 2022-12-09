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
    map<pair<int,int>,bool>visited;
    int n = 2000;
    vector<pair<int,int>>pos(10);
    for(int i = 0;i<n;++i){
        char x;
        cin >> x;
        int c;
        cin >> c;
        for(int i = 0;i<c;++i){
            int hx = pos[0].first, hy = pos[0].second;
            move(hx,hy,x);
            pos[0].first = hx;
            pos[0].second = hy;
            for(int j = 1;j<=9;++j){
                int hx = pos[j-1].first, hy = pos[j-1].second;
                int tx = pos[j].first, ty = pos[j].second;
                int d = dist(hx, hy, tx, ty);
                if(abs(hx-tx)>=2 && abs(hy-ty)>=2){
                    if(hx > tx)tx = hx-1;
                    else tx = hx+1;
                    if(hy > ty)ty = hy-1;
                    else ty = hy+1;
                }else if(abs(hx-tx)>=2){
                    if(hx > tx)tx = hx-1;
                    else tx = hx+1;
                    ty = hy;
                }else if(abs(hy-ty)>=2){
                    tx = hx;
                    if(hy > ty)ty = hy-1;
                    else ty = hy+1;
                }   
                pos[j] = {tx,ty};
            }
            visited[pos[9]] = 1;
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