int n, q, s;
struct qu {
    int l, r, id;
    bool operator<(const qu &B) const {
        if (l / s != B.l / s) return l < B.l;
        return (l / s & 1) ? r < B.r : r > B.r;
    }
};

signed main() {
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    s = sqrt(n);

    cin >> q;
    vector<qu> qus(q);
    for (int i = 0; i < q; i++) 
        cin >> qus[i].l >> qus[i].r, qus[i].id=i;
    sort(qus.begin(), qus.end());

    int l = 1, r = 1, p = 0;
    set<pair<int, int>> ans;
    vector<int> cur(n + 1);
    cur[arr[1]] = 1;
    for (qu i : qus) {
        while (i.r > r) {
            r++;
            if (cur[arr[r]] & 1) p++;
            cur[arr[r]]++;
        }
        while (i.l > l) {
            cur[arr[l]]--;
            if (cur[arr[l]] & 1) p--;
            l++;
        }
        while (i.r < r) {
            cur[arr[r]]--;
            if (cur[arr[r]] & 1) p--;
            r--;
        }
        while (i.l < l) {
            l--;
            if (cur[arr[l]] & 1) p++;
            cur[arr[l]]++;
        }
        ans.insert({i.id, p});
    }
    for (auto i : ans) cout << i.second << '\n';
    return 0;
}