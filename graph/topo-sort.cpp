//before use this algorithm, must to compute the "in" number

queue<int> q;

for (int i = 0; i < n; i++){
    if (in[i] == 0) q.push(i);
}

vector<int> res;
while (!q.empty()){
    int u = q.front();
    q.pop();
    res.push_back(u);

    for (auto v : adj[u]){
        in[v]--;
        if (in[v] == 0) q.push(v);
    }
}