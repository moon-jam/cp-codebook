// from 1 to n
int n, m, deg[100005];
vi g[100005], ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = g[rt].back();
        g[rt].pob();
        dfs(cur);
    }
    ans.eb(rt);
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        deg[a]++, deg[b]++;
    }
    rep(i, 1+1, n-1) if(deg[i]&1){
        cout << "IMPOSSIBLE\n";
        return 0;
    } 
    if(!((deg[1]&1) && (deg[n]&1))){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(1);
    rep(i, 1, n) if(!g[i].empty()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    return 0;
}