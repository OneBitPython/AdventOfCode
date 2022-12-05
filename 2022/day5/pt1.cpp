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


/*
            [J] [Z] [G]            
            [Z] [T] [S] [P] [R]    
[R]         [Q] [V] [B] [G] [J]    
[W] [W]     [N] [L] [V] [W] [C]    
[F] [Q]     [T] [G] [C] [T] [T] [W]
[H] [D] [W] [W] [H] [T] [R] [M] [B]
[T] [G] [T] [R] [B] [P] [B] [G] [G]
[S] [S] [B] [D] [F] [L] [Z] [N] [L]
*/
void solve()
{
    vector<vector<char>>pos = {
        {'S','T', 'H', 'F', 'W', 'R'},
        {'S', 'G', 'D', 'Q', 'W'},
        {'B', 'T', 'W'},
        {'D','R','W','T','N','Q','Z','J'},
        {'F','B','H','G','L','V','T','Z'},
        {'L','P','T','C','V','B','S','G'},
        {'Z','B','R','T','W','G','P'},
        {'N','G','M','T','C','J','R'},
        {'L','G','B','W'}
    };
    // move 1 from 2 to 1
    for(int z = 0;z<502;++z){
        string s;
        getline(cin,s);
        dbg(s);
        string get;
        int m = s.size();
        int cnt = 0;
        int spaces = 0;
        int f = 0;
        for(int i = 0;i<m;++i){
            if(s[i] == ' '){
                if(spaces==1){
                    cnt = stoi(get);
                }
                if(spaces == 3){
                    
                    f = stoi(get);
                }
                get.clear();
                spaces++;
            }else get+=s[i];
        }
        int t = stoi(get);
        t--;
        f--;
        for(int j = 0;j<cnt;++j){
            int l = pos[f].back();
            pos[t].pb(l);
            pos[f].erase(--pos[f].end());

        }
    }
    string res;
    for(auto x : pos){
        if(!x.empty())res+=x.back();
    }
    cout << res << endl;
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