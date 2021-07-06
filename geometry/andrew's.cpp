template<typename T>
pair<T, T> operator-(pair<T, T> a, pair<T, T> b){
    return mp(a.F - b.F, a.S - b.S);
}

template<typename T>
T cross(pair<T, T> a, pair<T, T> b){
    return a.F * b.S - a.S * b.F;
}

template<typename T>
vector<pair<T, T>> getConvexHull(vector<pair<T, T>>& pnts){

    int n = pnts.size();
    sort(iter(pnts));

    vector<pair<T, T>> hull;
    hull.reserve(n);

    for(int i = 0; i < 2; i++){
        int t = sz(hull);
        for(pair<T, T> pnt : pnts){
            while(sz(hull) - t >= 2 && cross(hull.back() - hull[sz(hull) - 2], pnt - hull[sz(hull) - 2]) <= 0){
                hull.pop_back();
            }
            hull.pb(pnt);
        }
        hull.pop_back();
        reverse(iter(pnts));
    }

    return hull;
}