---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 1 \"Combinatorics/binomial.cpp\"\ntemplate<class M>\nclass binomial{\n\
    \    //M\u306Fmodint\u3092\u60F3\u5B9A\u3057\u3066\u3044\u307E\u3059\npublic:\n\
    \    vector<M> fac, caf;\n    binomial(long MAX = 510000){\n        fac.resize(MAX);\n\
    \        caf.resize(MAX);\n        fac[0] = 1; caf[0] = 1;\n        fac[1] = 1;\
    \ caf[1] = 1;\n        for(long i = 2; i < MAX; i++) fac[i] = fac[i-1] * i;\n\
    \        caf[MAX-1] = M(1) / fac[MAX-1];\n        for(long i = MAX-2; i >= 2;\
    \ i--) caf[i] = caf[i+1] * (i+1);\n    }\n    M nCk(long n, long k){\n       \
    \ if (n < k) return 0;\n        if (n < 0 || k < 0) return 0;\n        return\
    \ fac[n] * caf[k] * caf[n-k];\n    }\n};\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\
    \n */\n"
  code: "template<class M>\nclass binomial{\n    //M\u306Fmodint\u3092\u60F3\u5B9A\
    \u3057\u3066\u3044\u307E\u3059\npublic:\n    vector<M> fac, caf;\n    binomial(long\
    \ MAX = 510000){\n        fac.resize(MAX);\n        caf.resize(MAX);\n       \
    \ fac[0] = 1; caf[0] = 1;\n        fac[1] = 1; caf[1] = 1;\n        for(long i\
    \ = 2; i < MAX; i++) fac[i] = fac[i-1] * i;\n        caf[MAX-1] = M(1) / fac[MAX-1];\n\
    \        for(long i = MAX-2; i >= 2; i--) caf[i] = caf[i+1] * (i+1);\n    }\n\
    \    M nCk(long n, long k){\n        if (n < k) return 0;\n        if (n < 0 ||\
    \ k < 0) return 0;\n        return fac[n] * caf[k] * caf[n-k];\n    }\n};\n/**\n\
    \ * @brief \u4E8C\u9805\u4FC2\u6570\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: Combinatorics/binomial.cpp
  requiredBy: []
  timestamp: '2022-02-22 17:37:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Combinatorics/binomial.cpp
layout: document
redirect_from:
- /library/Combinatorics/binomial.cpp
- /library/Combinatorics/binomial.cpp.html
title: "\u4E8C\u9805\u4FC2\u6570"
---
