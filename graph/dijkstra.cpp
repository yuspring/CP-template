const int MAXV = 1e5 + 5;
vector<pii> adj[MAXV];
int N;

//adj and pq first is distance, second is vertex

int dijkstra(int s, int e){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(N, INF);
    vector<bool> vis(N);
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()){
        int d = pq.top().F, v = pq.top().S;
        pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (pii p : adj[v]){
            if (vis[p.S]) continue;
            if (d + p.F < dis[p.S]){
                dis[p.S] = d + p.F;
                pq.push({dis[p.S], p.S});
            }
        }
    }
    return dis[e];
}