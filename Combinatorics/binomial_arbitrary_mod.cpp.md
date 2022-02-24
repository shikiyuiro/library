---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570( \u4EFB\u610Fmod )"
    links: []
  bundledCode: "#line 1 \"Combinatorics/binomial_arbitrary_mod.cpp\"\nclass binomial_arbitrary_mod{\n\
    public:\n    binomial_arbitrary_mod(long mod) : MOD(mod){\n        long mod_tmp\
    \ = mod;\n        for(long i = 2; i * i <= mod_tmp; i++){\n            while(mod_tmp\
    \ % i == 0){\n                mod_tmp /= i;\n                primes[i]++;\n  \
    \          }\n        }\n        if(mod_tmp != 1) primes[mod_tmp] = 1;\n     \
    \   for(auto [p, q] : primes){\n            bpp.push_back(binomial_primepower(p,\
    \ q));\n            long pp = 1;\n            while(q--) pp *= p;\n          \
    \  primepowers.push_back(pp);\n        }\n        \n    }\n    long nCk(long n,\
    \ long k){\n        vector<long> b, m;\n        for(long i = 0; i < bpp.size();\
    \ i++){\n            b.push_back(bpp[i].nCk(n, k));\n            m.push_back(primepowers[i]);\n\
    \        }\n        CRT crt(MOD);\n        return crt.Garner(b, m);\n    }\nprivate:\n\
    \    long MOD;\n    vector<long> primepowers;\n    map<long,long> primes;\n  \
    \  struct binomial_primepower{\n        long p, q;\n        long mod = 1;//p^q\n\
    \        vector<long> fact_no_p, tcaf_no_p;\n        binomial_primepower(long\
    \ p, long q) : p(p), q(q){\n            for(long i = 0; i < q; i++) mod *= p;\n\
    \            fact_no_p.resize(mod);\n            tcaf_no_p.resize(mod);\n    \
    \        fact_no_p[0] = 1;\n            for(long i = 1; i < mod; i++) fact_no_p[i]\
    \ = (i % p) ? fact_no_p[i-1] * i % mod : fact_no_p[i-1];\n            tcaf_no_p[mod-1]\
    \ = 1;\n            long rhs = fact_no_p[mod-1];\n            long exp = mod -\
    \ 2;\n            while (exp) {\n                if(exp % 2) tcaf_no_p[mod-1]\
    \ = tcaf_no_p[mod-1] * rhs % mod;\n                rhs = rhs * rhs % mod;\n  \
    \              exp /= 2;\n            }\n            for(long i = mod-2; i >=\
    \ 0; i--) tcaf_no_p[i] = ((i+1) % p) ? tcaf_no_p[i+1] * (i+1) % mod : tcaf_no_p[i+1];\n\
    \        }\n        long nCk(long n, long k){\n            long res = 1;\n   \
    \         long r = n - k;\n            long Lg0 = 0, Lgm = 0;\n            for(long\
    \ u = n/p; u > 0; u /= p) Lg0 += u;\n            for(long u = k/p; u > 0; u /=\
    \ p) Lg0 -= u;\n            for(long u = r/p; u > 0; u /= p) Lg0 -= u;\n     \
    \       for(long u = n/mod; u > 0; u /= p) Lgm += u;\n            for(long u =\
    \ k/mod; u > 0; u /= p) Lgm -= u;\n            for(long u = r/mod; u > 0; u /=\
    \ p) Lgm -= u;\n            while(n > 0){\n                res = res * fact_no_p[n\
    \ % mod] % mod * tcaf_no_p[k % mod] % mod * tcaf_no_p[r % mod] % mod;\n      \
    \          n /= p; k /= p; r /= p;\n            }\n            while(Lg0--) res\
    \ = res * p % mod;\n            if((not (p == 2 and q >= 3)) and (Lgm & 1) and\
    \ res) res = mod - res;\n            return res;\n        }\n    };\n    struct\
    \ CRT{\n        long MOD;\n        CRT(long mod) : MOD(mod){}\n        inline\
    \ long mod(long a, long m) {\n            long res = a % m;\n            if (res\
    \ < 0) res += m;\n            return res;\n        }\n\n        long extGCD(long\
    \ a, long b, long &p, long &q) {\n            if (b == 0) { p = 1; q = 0; return\
    \ a; }\n            long d = extGCD(b, a%b, q, p);\n            q -= a/b * p;\n\
    \            return d;\n        }\n\n        long modinv(long a, long m) {\n \
    \           long x, y;\n            extGCD(a, m, x, y);\n            return mod(x,\
    \ m);\n        }\n\n        long Garner(vector<long> b, vector<long> m) {\n  \
    \          m.push_back(MOD); // banpei\n            vector<long> coeffs((int)m.size(),\
    \ 1);\n            vector<long> constants((int)m.size(), 0);\n            for\
    \ (int k = 0; k < (int)b.size(); ++k) {\n                long t = mod((b[k] -\
    \ constants[k]) * modinv(coeffs[k], m[k]), m[k]);\n                for (int i\
    \ = k+1; i < (int)m.size(); ++i) {\n                    (constants[i] += t * coeffs[i])\
    \ %= m[i];\n                    (coeffs[i] *= m[k]) %= m[i];\n               \
    \ }\n            }\n            return constants.back();\n        }\n    };\n\
    \    vector<binomial_primepower> bpp;\n};\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\
    ( \u4EFB\u610Fmod )\n */\n"
  code: "class binomial_arbitrary_mod{\npublic:\n    binomial_arbitrary_mod(long mod)\
    \ : MOD(mod){\n        long mod_tmp = mod;\n        for(long i = 2; i * i <= mod_tmp;\
    \ i++){\n            while(mod_tmp % i == 0){\n                mod_tmp /= i;\n\
    \                primes[i]++;\n            }\n        }\n        if(mod_tmp !=\
    \ 1) primes[mod_tmp] = 1;\n        for(auto [p, q] : primes){\n            bpp.push_back(binomial_primepower(p,\
    \ q));\n            long pp = 1;\n            while(q--) pp *= p;\n          \
    \  primepowers.push_back(pp);\n        }\n        \n    }\n    long nCk(long n,\
    \ long k){\n        vector<long> b, m;\n        for(long i = 0; i < bpp.size();\
    \ i++){\n            b.push_back(bpp[i].nCk(n, k));\n            m.push_back(primepowers[i]);\n\
    \        }\n        CRT crt(MOD);\n        return crt.Garner(b, m);\n    }\nprivate:\n\
    \    long MOD;\n    vector<long> primepowers;\n    map<long,long> primes;\n  \
    \  struct binomial_primepower{\n        long p, q;\n        long mod = 1;//p^q\n\
    \        vector<long> fact_no_p, tcaf_no_p;\n        binomial_primepower(long\
    \ p, long q) : p(p), q(q){\n            for(long i = 0; i < q; i++) mod *= p;\n\
    \            fact_no_p.resize(mod);\n            tcaf_no_p.resize(mod);\n    \
    \        fact_no_p[0] = 1;\n            for(long i = 1; i < mod; i++) fact_no_p[i]\
    \ = (i % p) ? fact_no_p[i-1] * i % mod : fact_no_p[i-1];\n            tcaf_no_p[mod-1]\
    \ = 1;\n            long rhs = fact_no_p[mod-1];\n            long exp = mod -\
    \ 2;\n            while (exp) {\n                if(exp % 2) tcaf_no_p[mod-1]\
    \ = tcaf_no_p[mod-1] * rhs % mod;\n                rhs = rhs * rhs % mod;\n  \
    \              exp /= 2;\n            }\n            for(long i = mod-2; i >=\
    \ 0; i--) tcaf_no_p[i] = ((i+1) % p) ? tcaf_no_p[i+1] * (i+1) % mod : tcaf_no_p[i+1];\n\
    \        }\n        long nCk(long n, long k){\n            long res = 1;\n   \
    \         long r = n - k;\n            long Lg0 = 0, Lgm = 0;\n            for(long\
    \ u = n/p; u > 0; u /= p) Lg0 += u;\n            for(long u = k/p; u > 0; u /=\
    \ p) Lg0 -= u;\n            for(long u = r/p; u > 0; u /= p) Lg0 -= u;\n     \
    \       for(long u = n/mod; u > 0; u /= p) Lgm += u;\n            for(long u =\
    \ k/mod; u > 0; u /= p) Lgm -= u;\n            for(long u = r/mod; u > 0; u /=\
    \ p) Lgm -= u;\n            while(n > 0){\n                res = res * fact_no_p[n\
    \ % mod] % mod * tcaf_no_p[k % mod] % mod * tcaf_no_p[r % mod] % mod;\n      \
    \          n /= p; k /= p; r /= p;\n            }\n            while(Lg0--) res\
    \ = res * p % mod;\n            if((not (p == 2 and q >= 3)) and (Lgm & 1) and\
    \ res) res = mod - res;\n            return res;\n        }\n    };\n    struct\
    \ CRT{\n        long MOD;\n        CRT(long mod) : MOD(mod){}\n        inline\
    \ long mod(long a, long m) {\n            long res = a % m;\n            if (res\
    \ < 0) res += m;\n            return res;\n        }\n\n        long extGCD(long\
    \ a, long b, long &p, long &q) {\n            if (b == 0) { p = 1; q = 0; return\
    \ a; }\n            long d = extGCD(b, a%b, q, p);\n            q -= a/b * p;\n\
    \            return d;\n        }\n\n        long modinv(long a, long m) {\n \
    \           long x, y;\n            extGCD(a, m, x, y);\n            return mod(x,\
    \ m);\n        }\n\n        long Garner(vector<long> b, vector<long> m) {\n  \
    \          m.push_back(MOD); // banpei\n            vector<long> coeffs((int)m.size(),\
    \ 1);\n            vector<long> constants((int)m.size(), 0);\n            for\
    \ (int k = 0; k < (int)b.size(); ++k) {\n                long t = mod((b[k] -\
    \ constants[k]) * modinv(coeffs[k], m[k]), m[k]);\n                for (int i\
    \ = k+1; i < (int)m.size(); ++i) {\n                    (constants[i] += t * coeffs[i])\
    \ %= m[i];\n                    (coeffs[i] *= m[k]) %= m[i];\n               \
    \ }\n            }\n            return constants.back();\n        }\n    };\n\
    \    vector<binomial_primepower> bpp;\n};\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\
    ( \u4EFB\u610Fmod )\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: Combinatorics/binomial_arbitrary_mod.cpp
  requiredBy: []
  timestamp: '2022-02-24 20:59:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Combinatorics/binomial_arbitrary_mod.cpp
layout: document
redirect_from:
- /library/Combinatorics/binomial_arbitrary_mod.cpp
- /library/Combinatorics/binomial_arbitrary_mod.cpp.html
title: "\u4E8C\u9805\u4FC2\u6570( \u4EFB\u610Fmod )"
---
