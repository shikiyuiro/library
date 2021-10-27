---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/UnionFind.cpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)"
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/verify/UnionFind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#line 4 \"test/verify/UnionFind.test.cpp\"\n\n#line 1 \"DataStructure/UnionFind.cpp\"\
    \nclass UnionFind{\nprivate:\n    vector<long> Root;\n    vector<long> Size;\n\
    public:\n    UnionFind(long size){ Root.resize(size); iota(Root.begin(), Root.end(),\
    \ 0); Size.resize(size, 1);}\n    long find(long x){ return (Root[x] == x) ? x:\
    \ Root[x] = find(Root[x]); }\n    void unite(long x, long y){ if(Size[find(x)]\
    \ < Size[find(y)]) swap(x, y); Root[find(y)] = find(x); Size[find(x)] += Size[find(y)];}\n\
    \    bool same(long x, long y){ return find(x) == find(y);}\n    long size(long\
    \ x){ return Size[find(x)];}\n};\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020(Union Find)\n * @docs docs/DataStructure/UnionFind.md\n */\n\
    #line 6 \"test/verify/UnionFind.test.cpp\"\n\nint main(){\n    long N, Q; cin\
    \ >> N >> Q;\n    Unionind uf(N);\n    long t, u, v;\n    while(Q--){\n      \
    \  cin >> t >> u >> v;\n        if(t == 0) uf.unite(u, v);\n        if(t == 1)\
    \ cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../DataStructure/UnionFind.cpp\"\
    \n\nint main(){\n    long N, Q; cin >> N >> Q;\n    Unionind uf(N);\n    long\
    \ t, u, v;\n    while(Q--){\n        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u,\
    \ v);\n        if(t == 1) cout << (uf.same(u, v) ? 1 : 0) << endl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/UnionFind.cpp
  isVerificationFile: true
  path: test/verify/UnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-10-27 10:20:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/UnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/verify/UnionFind.test.cpp
- /verify/test/verify/UnionFind.test.cpp.html
title: test/verify/UnionFind.test.cpp
---
