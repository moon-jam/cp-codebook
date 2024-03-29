#define lc id * 2 + 1
#define rc id * 2 + 2
#define M ((L + R) >> 1)

struct Nodes {
    Info info;
    Tag tag;
} seg[N * 4];

void push(int L, int R, int id) {
    if (R > L + 1) {
        seg[lc].tag... seg[id].tag;
        seg[rc].tag... seg[id].tag;
    }
    seg[id].info = ... seg[id].tag;  // Update the info from tag
    seg[id].tag = NULL;              // clear seg[id].tag
}

void pull(int L, int R, int id) {
    push(L, M, lc), push(M, R, rc);
    // Update the info of id from lc and rc
    seg[id].info = seg[lc].info... seg[rc].info;
}

void modify(int l, int r, Tag tag, int L = 0, int R = n, int id = 0) {
    push(id);
    if (l == L && r == R) {
        seg[id].tag = tag;
    } else {
        if (l >= M)
            modify(l, r, tag, M, R, rc);
        else if (r = < M)
            modify(l, r, tag, L, M, lc);
        else
            modify(l, M, tag, L, M, lc), modify(M, r, tag, M, R, rc);
        pull(id);
    }
}

Info query(int l, int r, int L = 0, int R = n, int id = 0) {
    push(id);
    if (l == L && r == R) return id.info;
    if (l >= M) return query(l, r, M, R, rc);
    if (r <= M) return query(l, r, lc);
    // calculate answer from lc and rc
    return query(l, M, L, M, lc)... query(M, r, M, R, rc);
}
