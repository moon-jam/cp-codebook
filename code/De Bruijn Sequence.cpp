int n;
vi g[100005], ans;

void dfs(int rt){
    while(!g[rt].empty()){
        int cur = g[rt].back();
        g[rt].pob();
        dfs(cur);
        ans.eb(rt&1);
    }
}

signed main() {
    ios;
    cin >> n;
    rev(i, (1<<(n-1))-1, 0){
        int nxt = (i<<1) & ((1<<(n-1))-1);
        g[i].eb(nxt);
        g[i].eb(nxt+1);
    }
    dfs(0);
    reverse(all(ans));
    rep(i,1,n-1) cout << 0;
    if(n==1) cout << "01";
    else for(int i : ans) cout << i;
    return 0;
}