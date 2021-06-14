vector<pii> g[MAXV];
int N;

int dijkstra(int s, int e){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> dis(N, -1);
    vector<bool> vis(N);
    pq.push({0,s});
    dis[s] = 0;
    
    while(!pq.empty()){
        int d = pq.top().F, v = pq.top().S;
        pq.pop();
        if(v == e) break;
        if(vis[v]) continue;
        vis[v] = true;
        for(pii p : g[v]){
            if(vis[p.S]) continue;
            if(dis[p.S] == -1 || d+ p.F < dis[p.S]){
                dis[p.S] = d + p.F;
                pq.push({dis[p.S], p.S});
            }
        }
    }
    return dis[e];
}

