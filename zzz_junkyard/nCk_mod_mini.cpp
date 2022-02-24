long nCk_mod2(long n, long k){
    if(n < 0) return 0;
    if(k < 0 || n < k) return 0;
    if(n < 2) return 1;
    if(k > n-k) k = n-k;
    long j = n;
    long r = 1;
    while(j){
        j >>= 1;
        r <<= 1;
    }
    r >>= 1;
    if(k >= n-r+1) return 0;
    else return nCk_mod2(n-r, k);
}

long nCk_mod3(long n, long k){
    if(n < 0) return 0;
    if(k < 0 || n < k) return 0;
    if(n < 2) return 1;
    if(n == 2){
        if(k == 1) return 2;
        else return 1;
    }
    if(k > n-k) k = n-k;
    long j = n;
    long r = 1;
    while(j){
        j /= 3;
        r *= 3;
    }
    r /= 3;
    if(n < 2 * r) return nCk_mod3(n-r, k);
    else{
        if(k < r){
            return nCk_mod3(n-2*r, k);
        }else{
            return (nCk_mod3(n-2*r, k-r) * 2) % 3;
        }
    }
}
/**
 * @brief nCk (mod2/mod3)
 */
