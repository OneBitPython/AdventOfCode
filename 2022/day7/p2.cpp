#include <bits/stdc++.h>
using namespace std;

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

map<string,int>subtree;
map<string,string>parent;
map<string,set<string>>adj;
set<string>dist;

void dfs(string u, string p){
    for(string v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
        subtree[u] += subtree[v];
    }
}
void solve()
{
    
    string curr;
    vector<string>path_so_far = {"/"};
    string s;
    while(getline(cin,s)){
        string got;
        vector<string>a;
        for(auto x : s){
            if(x == ' '){
                a.pb(got);
                got.clear();
            }else got+=x;
        }
        a.pb(got);
        string curr;
        for(auto x : path_so_far){
            curr+=x;
            curr+="/";
        }
        if(a[1] == "cd"){
            if(a[2] == ".."){
                curr = parent[curr];
                path_so_far.erase(--path_so_far.end());
            }else if(a[2] != "/"){
                path_so_far.pb(a[2]);
            }
        }else if(a[1] != "ls"){
            if(a[0] == "dir"){
                string nxt = curr+a[1]+"/";
                parent[nxt] = curr;
                adj[curr].insert(nxt);
                dist.insert(nxt);
            }else{
                int v = stoi(a[0]);
                subtree[curr]+=v;
            }
        }
    }
    string dontcollide = "dlfjaldjfldjafldaj";
    dfs("//",dontcollide);
    
    int free = 70000000 - subtree["//"];
    int remove = 30000000 - free;
    set<int>pos;
    for(auto x : subtree){
        if(x.second >= remove)pos.insert(x.second);
    }
    cout << *pos.begin() << endl;
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