struct matrix{

    ll m[2][2];
    
    matrix(){ 
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                m[i][j] = 0;
            }
        }
    }

    matrix operator*(matrix a){
        matrix res;
        for (int i = 0;i < 2;i++){
            for (int j = 0;j < 2;j++){
                for (int k = 0;k < 2;k++){
                    res.m[i][j] = ( (res.m[i][j] % mod) + ( (m[i][k] % mod) * (a.m[k][j] % mod) ) % mod) % mod;
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