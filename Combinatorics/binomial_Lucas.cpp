class binomial_Lucas{
public:
    long p;
    vector<vector<long>> table;
    binomial_Lucas(long p) : p(p){
        table.resize(p, vector<long>(p));
        table[0][0] = 1;
        for(long i = 1; i < p; i++) table[i][0] = 1;
        for(long i = 1; i < p; i++) table[i][i] = 1;
        for(long i = 2; i < p; i++) for(long j = 1; j < i; j++){
            table[i][j] = table[i-1][j-1] + table[i-1][j];
            if(table[i][j] >= p) table[i][j] %= p;
        }
    }
    long nCk(long n, long k){
        if(n < 0) return 0;
        if(k < 0 || n < k) return 0;
        long res = 1;
        while(n){
            res *= table[n % p][k % p];
            res %= p;
            n /= p; k /= p;
        }
        return res;
    }
};
/**
 * @brief 二項係数( Lucas )
 */
