vector<pair<pii, int>> edge;

int kruskal(){
    int res = 0;
    for (auto &v : edge){
        int a = v.F.F, b = v.F.S;
        if (find(a) == find(b)) continue;
        unite(a, b);
        res += v.S;
    }
    return res;
}
