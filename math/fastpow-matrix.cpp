struct matrix{

    ll m[10][10];

    matrix operator*(matrix a){
        matrix res;
        for (int i = 0;i < 2;i++){
            for (int j = 0;j < 2;j++){
                res.m[i][j] = 0;
            }
        }

        for (int i = 0;i < 2;i++){
            for (int j = 0;j < 2;j++){
                for (int k = 0;k < 2;k++){
                    res.m[i][j] = (res.m[i][j] + ((m[i][k] % mod) * (a.m[k][j] % mod)) % mod) % mod;
                }
            }
        }
        return res;
    }
}mat;