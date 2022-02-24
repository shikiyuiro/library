class binomial_arbitrary_mod{
public:
    binomial_arbitrary_mod(long mod) : MOD(mod){
        long mod_tmp = mod;
        for(long i = 2; i * i <= mod_tmp; i++){
            while(mod_tmp % i == 0){
                mod_tmp /= i;
                primes[i]++;
            }
        }
        if(mod_tmp != 1) primes[mod_tmp] = 1;
        for(auto [p, q] : primes){
            bpp.push_back(binomial_primepower(p, q));
            long pp = 1;
            while(q--) pp *= p;
            primepowers.push_back(pp);
        }
        
    }
    long nCk(long n, long k){
        vector<long> b, m;
        for(long i = 0; i < bpp.size(); i++){
            b.push_back(bpp[i].nCk(n, k));
            m.push_back(primepowers[i]);
        }
        CRT crt(MOD);
        return crt.Garner(b, m);
    }
private:
    long MOD;
    vector<long> primepowers;
    map<long,long> primes;
    struct binomial_primepower{
        long p, q;
        long mod = 1;//p^q
        vector<long> fact_no_p, tcaf_no_p;
        binomial_primepower(long p, long q) : p(p), q(q){
            for(long i = 0; i < q; i++) mod *= p;
            fact_no_p.resize(mod);
            tcaf_no_p.resize(mod);
            fact_no_p[0] = 1;
            for(long i = 1; i < mod; i++) fact_no_p[i] = (i % p) ? fact_no_p[i-1] * i % mod : fact_no_p[i-1];
            tcaf_no_p[mod-1] = 1;
            long rhs = fact_no_p[mod-1];
            long exp = mod - 2;
            while (exp) {
                if(exp % 2) tcaf_no_p[mod-1] = tcaf_no_p[mod-1] * rhs % mod;
                rhs = rhs * rhs % mod;
                exp /= 2;
            }
            for(long i = mod-2; i >= 0; i--) tcaf_no_p[i] = ((i+1) % p) ? tcaf_no_p[i+1] * (i+1) % mod : tcaf_no_p[i+1];
        }
        long nCk(long n, long k){
            long res = 1;
            long r = n - k;
            long Lg0 = 0, Lgm = 0;
            for(long u = n/p; u > 0; u /= p) Lg0 += u;
            for(long u = k/p; u > 0; u /= p) Lg0 -= u;
            for(long u = r/p; u > 0; u /= p) Lg0 -= u;
            for(long u = n/mod; u > 0; u /= p) Lgm += u;
            for(long u = k/mod; u > 0; u /= p) Lgm -= u;
            for(long u = r/mod; u > 0; u /= p) Lgm -= u;
            while(n > 0){
                res = res * fact_no_p[n % mod] % mod * tcaf_no_p[k % mod] % mod * tcaf_no_p[r % mod] % mod;
                n /= p; k /= p; r /= p;
            }
            while(Lg0--) res = res * p % mod;
            if((not (p == 2 and q >= 3)) and (Lgm & 1) and res) res = mod - res;
            return res;
        }
    };
    struct CRT{
        long MOD;
        CRT(long mod) : MOD(mod){}
        inline long mod(long a, long m) {
            long res = a % m;
            if (res < 0) res += m;
            return res;
        }

        long extGCD(long a, long b, long &p, long &q) {
            if (b == 0) { p = 1; q = 0; return a; }
            long d = extGCD(b, a%b, q, p);
            q -= a/b * p;
            return d;
        }

        long modinv(long a, long m) {
            long x, y;
            extGCD(a, m, x, y);
            return mod(x, m);
        }

        long Garner(vector<long> b, vector<long> m) {
            m.push_back(MOD); // banpei
            vector<long> coeffs((int)m.size(), 1);
            vector<long> constants((int)m.size(), 0);
            for (int k = 0; k < (int)b.size(); ++k) {
                long t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
                for (int i = k+1; i < (int)m.size(); ++i) {
                    (constants[i] += t * coeffs[i]) %= m[i];
                    (coeffs[i] *= m[k]) %= m[i];
                }
            }
            return constants.back();
        }
    };
    vector<binomial_primepower> bpp;
};
/**
 * @brief 二項係数( 任意mod )
 */
