struct line{
    int a, b;
    int val(int x){
        return a * x + b;
    }
    int dot(line x){
        return (b - x.b) / (x.a - a);
    }
}

bool query(int x){
    return dq[0].val(x) >= dq[1].val(x);
}

bool insert(line x){
    return x.dot(dq.back()) <= dq.back().dot(dq[sz(dq)-2];
}
