---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Testcode/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
  isVerificationFile: true
  path: Testcode/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-10-25 16:40:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Testcode/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/Testcode/UnionFind.test.cpp
- /verify/Testcode/UnionFind.test.cpp.html
title: Testcode/UnionFind.test.cpp
---