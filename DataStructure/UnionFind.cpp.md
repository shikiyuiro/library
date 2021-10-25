---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n\nclass Union_find{\npublic:\n\
    \    vector<long> par;\n    Union_find(long size){ par.resize(size); for(long\
    \ i = 0; i < size; i++) par[i] = i; }\n    long root(long x){ return (par[x] ==\
    \ x) ? x: par[x] = root(par[x]); }\n    void unite(long x, long y){ par[root(x)]\
    \ = root(y); }\n    bool same(long x, long y){ return root(x) == root(y); }\n\
    };\n"
  code: "\nclass Union_find{\npublic:\n    vector<long> par;\n    Union_find(long\
    \ size){ par.resize(size); for(long i = 0; i < size; i++) par[i] = i; }\n    long\
    \ root(long x){ return (par[x] == x) ? x: par[x] = root(par[x]); }\n    void unite(long\
    \ x, long y){ par[root(x)] = root(y); }\n    bool same(long x, long y){ return\
    \ root(x) == root(y); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-10-25 17:19:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
