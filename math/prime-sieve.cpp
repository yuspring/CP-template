vector<int> prime;
vector<int> p;

void sieve(int n){
    prime.resize(n + 1, 1);
    for (int i = 2; i <= n; i++){
        if (prime[i] == 1){
            p.push_back(i);
            prime[i] = i;
        }
        for (int x : p){
            if (x * i > n) break;
            prime[x * i] = x;
            if (x == prime[i]) break;
        }
    }
}