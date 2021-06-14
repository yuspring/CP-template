vector<pair<pii, int>> e;

int kruskal(){
    initDSU();
    int res = 0;
    for (auto& i : e){
        int a = i.F.F, b = i.F.S;
        if (find(a) == find(b)) continue;
        unite(a, b);
        res += i.S;
    }
    return;
}
