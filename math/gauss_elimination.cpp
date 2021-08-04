typedef double Matrix[N][N];

void guauss_elimination(Matrix A, int n){
    int r;
    for (int i = 0; i < n; i++){
        r = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (r != i) for (int j = 0; j <= n; j++) swap(A[r][i], A[i][j]);

        for (int k = i + 1; k < n; k++){
            double f = A[k][i] / A[i][i];
            for (int j = i; j <= n; j++) A[k][j] -= f * A[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = i + 1; j < n; j++)
            A[i][n] -= A[j][n] * A[i][j];
        A[i][n] /= A[i][i];
    }
}
