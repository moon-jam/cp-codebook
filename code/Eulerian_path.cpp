int n, m, odd=1, ed=1, cnt_odd = 0;
int deg[100005];
vi g[100005], ans;
bool vis[100005];
map<pii, bool> evis;

void dfs(int rt){
    vis[rt] = 1;
    while(!g[rt].empty()){
        int cur = g[rt].back();
        g[rt].pob();
        if(evis[{rt, cur}]) continue;
        evis[{rt, cur}] = 1, evis[{cur, rt}] = 1, dfs(cur);
        ans.eb(rt);
    }
}

signed main() {
    ios;
    cin >> n >> m;
    si cg;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].eb(b), g[b].eb(a);
        deg[a]++, deg[b]++;
        cg.insert(a), cg.insert(b);
    }
    rep(i, 1, n) if(deg[i]&1) ed = odd, odd = i, cnt_odd++;
    if(cnt_odd!=0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(odd);
    for(int i : cg) if(!vis[i]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    cout << ed << '\n';
    return 0;
}