---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570( Lucas )"
    links: []
  bundledCode: "#line 1 \"Combinatorics/binomial_Lucas.cpp\"\nclass binomial_Lucas{\n\
    public:\n    long p;\n    vector<vector<long>> table;\n    binomial_Lucas(long\
    \ p) : p(p){\n        table.resize(p, vector<long>(p));\n        table[0][0] =\
    \ 1;\n        for(long i = 1; i < p; i++) table[i][0] = 1;\n        for(long i\
    \ = 1; i < p; i++) table[i][i] = 1;\n        for(long i = 2; i < p; i++) for(long\
    \ j = 1; j < i; j++){\n            table[i][j] = table[i-1][j-1] + table[i-1][j];\n\
    \            if(table[i][j] >= p) table[i][j] %= p;\n        }\n    }\n    long\
    \ nCk(long n, long k){\n        if(n < 0) return 0;\n        if(k < 0 || n < k)\
    \ return 0;\n        long res = 1;\n        while(n){\n            res *= table[n\
    \ % p][k % p];\n            res %= p;\n            n /= p; k /= p;\n        }\n\
    \        return res;\n    }\n};\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570( Lucas\
    \ )\n */\n"
  code: "class binomial_Lucas{\npublic:\n    long p;\n    vector<vector<long>> table;\n\
    \    binomial_Lucas(long p) : p(p){\n        table.resize(p, vector<long>(p));\n\
    \        table[0][0] = 1;\n        for(long i = 1; i < p; i++) table[i][0] = 1;\n\
    \        for(long i = 1; i < p; i++) table[i][i] = 1;\n        for(long i = 2;\
    \ i < p; i++) for(long j = 1; j < i; j++){\n            table[i][j] = table[i-1][j-1]\
    \ + table[i-1][j];\n            if(table[i][j] >= p) table[i][j] %= p;\n     \
    \   }\n    }\n    long nCk(long n, long k){\n        if(n < 0) return 0;\n   \
    \     if(k < 0 || n < k) return 0;\n        long res = 1;\n        while(n){\n\
    \            res *= table[n % p][k % p];\n            res %= p;\n            n\
    \ /= p; k /= p;\n        }\n        return res;\n    }\n};\n/**\n * @brief \u4E8C\
    \u9805\u4FC2\u6570( Lucas )\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: Combinatorics/binomial_Lucas.cpp
  requiredBy: []
  timestamp: '2022-02-24 12:22:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Combinatorics/binomial_Lucas.cpp
layout: document
redirect_from:
- /library/Combinatorics/binomial_Lucas.cpp
- /library/Combinatorics/binomial_Lucas.cpp.html
title: "\u4E8C\u9805\u4FC2\u6570( Lucas )"
---
