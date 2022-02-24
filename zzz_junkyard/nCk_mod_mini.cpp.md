---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: nCk (mod2/mod3)
    links: []
  bundledCode: "#line 1 \"zzz_junkyard/nCk_mod_mini.cpp\"\nlong nCk_mod2(long n, long\
    \ k){\n    if(n < 0) return 0;\n    if(k < 0 || n < k) return 0;\n    if(n < 2)\
    \ return 1;\n    if(k > n-k) k = n-k;\n    long j = n;\n    long r = 1;\n    while(j){\n\
    \        j >>= 1;\n        r <<= 1;\n    }\n    r >>= 1;\n    if(k >= n-r+1) return\
    \ 0;\n    else return nCk_mod2(n-r, k);\n}\n\nlong nCk_mod3(long n, long k){\n\
    \    if(n < 0) return 0;\n    if(k < 0 || n < k) return 0;\n    if(n < 2) return\
    \ 1;\n    if(n == 2){\n        if(k == 1) return 2;\n        else return 1;\n\
    \    }\n    if(k > n-k) k = n-k;\n    long j = n;\n    long r = 1;\n    while(j){\n\
    \        j /= 3;\n        r *= 3;\n    }\n    r /= 3;\n    if(n < 2 * r) return\
    \ nCk_mod3(n-r, k);\n    else{\n        if(k < r){\n            return nCk_mod3(n-2*r,\
    \ k);\n        }else{\n            return (nCk_mod3(n-2*r, k-r) * 2) % 3;\n  \
    \      }\n    }\n}\n/**\n * @brief nCk (mod2/mod3)\n */\n"
  code: "long nCk_mod2(long n, long k){\n    if(n < 0) return 0;\n    if(k < 0 ||\
    \ n < k) return 0;\n    if(n < 2) return 1;\n    if(k > n-k) k = n-k;\n    long\
    \ j = n;\n    long r = 1;\n    while(j){\n        j >>= 1;\n        r <<= 1;\n\
    \    }\n    r >>= 1;\n    if(k >= n-r+1) return 0;\n    else return nCk_mod2(n-r,\
    \ k);\n}\n\nlong nCk_mod3(long n, long k){\n    if(n < 0) return 0;\n    if(k\
    \ < 0 || n < k) return 0;\n    if(n < 2) return 1;\n    if(n == 2){\n        if(k\
    \ == 1) return 2;\n        else return 1;\n    }\n    if(k > n-k) k = n-k;\n \
    \   long j = n;\n    long r = 1;\n    while(j){\n        j /= 3;\n        r *=\
    \ 3;\n    }\n    r /= 3;\n    if(n < 2 * r) return nCk_mod3(n-r, k);\n    else{\n\
    \        if(k < r){\n            return nCk_mod3(n-2*r, k);\n        }else{\n\
    \            return (nCk_mod3(n-2*r, k-r) * 2) % 3;\n        }\n    }\n}\n/**\n\
    \ * @brief nCk (mod2/mod3)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: zzz_junkyard/nCk_mod_mini.cpp
  requiredBy: []
  timestamp: '2022-02-24 10:55:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: zzz_junkyard/nCk_mod_mini.cpp
layout: document
redirect_from:
- /library/zzz_junkyard/nCk_mod_mini.cpp
- /library/zzz_junkyard/nCk_mod_mini.cpp.html
title: nCk (mod2/mod3)
---
