constexpr int MOD = 1e9 + 7;

inline int mod_fibonnacci (int n) {

    long long X[2] = {1, 1};
    
    long long mat[2][2] = {{1, 1}, {1, 0}};
    
    while (n) {
    
        if (n & 1) {
            
            long long X_[2];
            
            X_[0] = (mat[0][0] * X[0] + mat[0][1] * X[1]) % MOD;
            X_[1] = (mat[1][0] * X[0] + mat[1][1] * X[1]) % MOD;
            
            X[0] = X_[0]; x[1] = X_[1];
        }
        
        long long mat_temp[2][2];
        memset (mat_temp, 0, sizeof (mat_temp);
        
        rep (i, 0, 1)
            rep (j, 0, 1)
                mat_temp[i][j] = (mat[i][0] * mat[0][j] + mat[i][1] * mat[1][j])
                                % MOD;
                                
        n >>= 1;
    }
        
    return X[1];
}