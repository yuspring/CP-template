//adj first is vertex, second is distance

int SPFA(int s, int e){
    vector<int> dis(N, INF), cnt(N);
    vector<bool> inq(N);
    queue<int> q;

    dis[s] = 0;
    inq[s] = 1;
    q.push(s);

    while (!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (pii v : adj[u]){
            if (dis[v.F] != INF || dis[u] + v.S > dis[v.F]) continue;
            if (++cnt[v.F] >= N) return INF;
            dis[v.F] = dis[u] + v.S;
            if (!inq[v.F]){
                inq[v.F] = 1, q.push(v.F);
            }
        }
    }
    return dis[e];
}