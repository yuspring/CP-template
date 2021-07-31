//adj and pq first is distance, second is vertex
vector<int> dis(N, INF);
vector<bool> vis(N);
priority_queue<pii, vector<pii>, greater<pii>> pq;


int dijkstra(int s, int e){
    dis[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty()){
        int d = pq.top().F, u = pq.top().S;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (pii v : adj[u]){
            if (vis[v.S]) continue;
            if (dis[v.S] > v.F + d){
                dis[v.S] = v.F + d;
                pq.push({ dis[v.S], v.S });
            }
        }
    }
    return dis[e];
}