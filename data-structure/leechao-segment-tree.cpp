const int MAXN = 5e5 + 5;

#define L idx<<1
#define R idx<<1|1

struct Line{
    int a, b;
    int operator()(int x){
        return a * x + b;
    }
};

Line tr[MAXN << 2];

void insert(Line seg, int idx, int l, int r){
    if (l == r){
        if (seg(l) > tr[idx](l)){
            tr[idx] = seg;
        }
        return;
    }

    int m = (l + r) >> 1;
    if (tr[idx].a > seg.a) swap(tr[idx], seg);
    if (tr[idx](m) < seg(m)) swap(tr[idx], seg), insert(seg, L, l, m);
    else insert(seg, R, m + 1, r);
}

int query(int x, int idx, int l, int r){
    if (l == r) return tr[idx](x);
    int m = (l + r) >> 1;
    if (x <= m) return max(tr[idx](x), query(x, L, l, m));
    else return max(tr[idx](x), query(x, R, m + 1, r));
}