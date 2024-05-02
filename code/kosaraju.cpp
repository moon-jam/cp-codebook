int id = 0;
int n, m;
vi g[100005], rg[100005], ord;
int idx[100005];
bool vis[100005], rvis[100005];

void dfs(int rt){
    if(vis[rt]) return;
    vis[rt] = 1;
    for(int i : g[rt]) dfs(i);
    ord.eb(rt);
}

void rdfs(int rt){
    if(rvis[rt]) return;
    rvis[rt] = 1;
    for(int i : rg[rt]) rdfs(i);
    idx[rt] = id;
}

signed main() {
    ios;
    cin >> n >> m;
    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        g[a].eb(b);
        rg[b].eb(a);
    }
    rep(i, 1, n) dfs(i);
    reverse(all(ord));
    for(int i : ord) if(!rvis[i]) id++,rdfs(i);
    cout << id << '\n';
    rep(i, 1, n) cout << idx[i] << ' ';
    return 0;
}
