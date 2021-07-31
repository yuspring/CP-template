struct line{
    int a, b;

    int operator() (int x){
        return a * x + b;
    }
};

deque<line> dq;

bool dot(line a, line b, line c){
    return (b.a - a.a) * (c.b - b.b) >= (b.b - a.b) * (c.a - b.a);
}

void insert(line a){
    while (sz(dq) >= 2 && dot(dq[sz(dq) - 2], dq[sz(dq) - 1], a))
        dq.pob();

    dq.pb(a);
}

int query(int x){
    while (sz(dq) >= 2 && dq[0](x) <= dq[1](x))
        dq.pof();
    return dq[0].a * x + dq[0].b;
}

int query2(int x){
    int l = -1, r = sz(dq);
    while (r - l > 1){
        int m = (l + r) >> 1;
        if (dq[m](x) <= dq[m + 1](x)) l = m;
        else r = m;
    }
    return dq[r](x);
}