---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.cpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)"
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
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
  bundledCode: "#line 1 \"test/verify/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#line 4 \"test/verify/UnionFind.test.cpp\"\n\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \nclass Union_find{\npublic:\n    vector<long> par;\n    Union_find(long size){\
    \ par.resize(size); for(long i = 0; i < size; i++) par[i] = i; }\n    long root(long\
    \ x){ return (par[x] == x) ? x: par[x] = root(par[x]); }\n    void unite(long\
    \ x, long y){ par[root(x)] = root(y); }\n    bool same(long x, long y){ return\
    \ root(x) == root(y); }\n};\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020(Union Find)\n * @docs docs/DataStructure/UnionFind.md\n */\n#line\
    \ 6 \"test/verify/UnionFind.test.cpp\"\n\nint main(){\n    long N, Q; cin >> N\
    \ >> Q;\n    Union_find uf(N);\n    long t, u, v;\n    while(Q--){\n        cin\
    \ >> t >> u >> v;\n        if(t == 0) uf.unite(u, v);\n        if(t == 1) cout\
    \ << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../DataStructure/UnionFind.cpp\"\
    \n\nint main(){\n    long N, Q; cin >> N >> Q;\n    Union_find uf(N);\n    long\
    \ t, u, v;\n    while(Q--){\n        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u,\
    \ v);\n        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/verify/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-10-26 17:33:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/verify/UnionFind.test.cpp
- /verify/test/verify/UnionFind.test.cpp.html
title: test/verify/UnionFind.test.cpp
---
