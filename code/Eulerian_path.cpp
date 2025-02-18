int n, m, st=1, ed=1, cnt_odd = 0;
si g[100005];
vi ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = *g[rt].begin();
        g[rt].erase(g[rt].begin());
        g[cur].erase(rt);
        dfs(cur);
    }
    ans.eb(rt);
}

signed main() {
    ios;
    cin >> n >> m;
    si cg;
    rep(i, 1, m){
        int a, b;
        cin >> a >> b;
        g[a].insert(b), g[b].insert(a);
    }
    rep(i, 1, n) if(g[i].size()&1) ed = st, st = i, cnt_odd++;
    if(cnt_odd!=0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(st);
    rep(i, 1, n) if(!g[i].empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(all(ans));
    for(int i : ans) cout << i << ' ';
    return 0;
}