struct BIT {
    vector<int> bit;
    int n;

    BIT(int _n) {
        n = _n;
        bit.resize(n + 1);
    }
    void modify(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }
    int query(int pos) {
        int ans = 0;
        for (; pos > 0; pos -= pos & (-pos)) ans += bit[pos];
        return ans;
    }
};