#define MOD(x)  ((x % mod) + mod) % mod;

struct matrix{

    ll m[2][2];
    
    matrix(){ 
        memset(m,0,sizeof(m));
    }

    matrix operator*(matrix a){
        matrix res;
        for (int i = 0;i < 2;i++){
            for (int j = 0;j < 2;j++){
                for (int k = 0;k < 2;k++){
                    res.m[i][j] = MOD( MOD(res.m[i][j]) + MOD( MOD(m[i][k]) * MOD(a.m[k][j]) ) ) ;
                }
            }
        }
        return res;
    }
};

matrix power(matrix a, int b){
    matrix res;
    res.m[0][0] = 1;
    res.m[1][1] = 1;
    while (b){
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}