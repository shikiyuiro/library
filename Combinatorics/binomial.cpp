template<class M>
class binomial{
    //Mはmodintを想定しています
public:
    vector<M> fac, caf;
    binomial(long MAX = 510000){
        fac.resize(MAX);
        caf.resize(MAX);
        fac[0] = 1; caf[0] = 1;
        fac[1] = 1; caf[1] = 1;
        for(long i = 2; i < MAX; i++) fac[i] = fac[i-1] * i;
        caf[MAX-1] = M(1) / fac[MAX-1];
        for(long i = MAX-2; i >= 2; i--) caf[i] = caf[i+1] * (i+1);
    }
    M nCk(long n, long k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * caf[k] * caf[n-k];
    }
};
/**
 * @brief 二項係数
 */
