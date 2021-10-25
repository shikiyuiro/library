---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Data Structure/UnionFind.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\nclass Union_find{\npublic:\n\
    \    vector<long> par;\n    Union_find(long size){ par.resize(size); for(long\
    \ i = 0; i < size; i++) par[i] = i; }\n    long root(long x){ return (par[x] ==\
    \ x) ? x: par[x] = root(par[x]); }\n    void unite(long x, long y){ par[root(x)]\
    \ = root(y); }\n    bool same(long x, long y){ return root(x) == root(y); }\n\
    };\n\nint main(){\n    long N, Q; cin >> N >> Q;\n    Union_find uf(N);\n    long\
    \ t, u, v;\n    while(Q--){\n        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u,\
    \ v);\n        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nclass Union_find{\npublic:\n    vector<long> par;\n  \
    \  Union_find(long size){ par.resize(size); for(long i = 0; i < size; i++) par[i]\
    \ = i; }\n    long root(long x){ return (par[x] == x) ? x: par[x] = root(par[x]);\
    \ }\n    void unite(long x, long y){ par[root(x)] = root(y); }\n    bool same(long\
    \ x, long y){ return root(x) == root(y); }\n};\n\nint main(){\n    long N, Q;\
    \ cin >> N >> Q;\n    Union_find uf(N);\n    long t, u, v;\n    while(Q--){\n\
    \        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u, v);\n        if(t\
    \ == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Data Structure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-10-25 11:01:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/UnionFind.cpp
layout: document
redirect_from:
- /library/Data Structure/UnionFind.cpp
- /library/Data Structure/UnionFind.cpp.html
title: Data Structure/UnionFind.cpp
---
