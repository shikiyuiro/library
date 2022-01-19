---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable_Compact.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\
      \u30AF\u30A8\u30EA$\\mathrm{O}(1)$ )"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/verify/SparseTable_Compact.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n/**\n * @brief \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n */\n#line 4 \"test/verify/SparseTable_Compact.test.cpp\"\
    \n\n#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S, S),\
    \ S (*e)()>\nclass SparseTable{\npublic:\n    vector<vector<S>> table;\n    vector<long>\
    \ cf;\n    \n    explicit SparseTable() = default;\n    \n    SparseTable(vector<S>&\
    \ v){\n        long isiz = v.size();\n        long jsiz = 0;\n        while((1\
    \ << jsiz) <= isiz) jsiz++;\n        table.resize(isiz, vector<S>(jsiz, e()));\n\
    \        for(long i = 0; i < isiz; i++) table[i][0] = v[i];\n        for(long\
    \ j = 1; j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz;\
    \ i++){\n                table[i][j] = op(table[i][j - 1], table[i + (1 << (j\
    \ - 1))][j - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n  \
    \      for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n\
    \    S query(long l, long r/*\u534A\u958B\u533A\u9593*/){\n        if(l == r)\
    \ return e();\n        long b = cf[r - l];\n        return op(table[l][b], table[r\
    \ - (1 << b)][b]);\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n#line 2 \"DataStructure/SparseTable_Compact.cpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)()>\nclass Compact_Sparse_Table{\n\
    public:\n    long W = 8;\n    vector<S> A;\n    vector<S> Lfold, Rfold;\n    SparseTable<S,\
    \ op, e> st;\n    \n    explicit Compact_Sparse_Table() = default;\n    \n   \
    \ Compact_Sparse_Table(vector<S> &A) : A(A){\n        A.resize(A.size() + W -\
    \ ((A.size() - 1) % W + 1), e());\n        vector<long> BLOCK(A.size() / W, e());\n\
    \        Lfold.resize(A.size(), e());\n        Rfold.resize(A.size(), e());\n\
    \        for(long b = 0; b < BLOCK.size(); b++){\n            BLOCK[b] = A[W *\
    \ b];\n            Lfold[W * b] = A[W * b];\n            Rfold[W * (b + 1) - 1]\
    \ = A[W * (b + 1) - 1];\n            for(long i = 1; i < W; i++){\n          \
    \      BLOCK[b] = op(BLOCK[b], A[W * b + i]);\n                Lfold[W * b + i]\
    \ = op(Lfold[W * b + i - 1], A[W * b + i]);\n                Rfold[W * (b + 1)\
    \ - 1 - i] = op(Rfold[W * (b + 1) - i], A[W * (b + 1) - 1 - i]);\n           \
    \ }\n        }\n        st = SparseTable<S, op, e> (BLOCK);\n    }\n    S query(long\
    \ L, long R/*\u534A\u958B\u533A\u9593*/){\n        R--;\n        long lb = (L\
    \ - (L % W) + W) / W;\n        long rb = (R - (R % W)) / W;\n        if(rb > lb){\n\
    \            return op(st.query(lb, rb), op(Lfold[R],Rfold[L]));\n        }\n\
    \        if(rb == lb){\n            return op(Lfold[R],Rfold[L]);\n        }\n\
    \        S res = e();\n        for(long i = L; i <= R; i++) res = op(res, A[i]);\n\
    \        return res;\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\
    \u30FC\u30D6\u30EB( \u69CB\u7BC9$\\mathrm{O}(N)$\u30FB\u30AF\u30A8\u30EA$\\mathrm{O}(1)$\
    \ )\n * @docs docs/DataStructure/SparseTable_compact.md\n */\n#line 6 \"test/verify/SparseTable_Compact.test.cpp\"\
    \n\nlong op(long a, long b){ return min(a, b);}\nlong e() { return LONG_MAX;}\n\
    \nint main(){\n    long N, Q; cin >> N >> Q;\n    vector<long> A(N);\n    for(long\
    \ i = 0; i < N; i++) cin >> A[i];\n    \n    Compact_Sparse_Table<long, op, e>\
    \ STA(A);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout <<\
    \ STA.query(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../DataStructure/SparseTable_Compact.cpp\"\
    \n\nlong op(long a, long b){ return min(a, b);}\nlong e() { return LONG_MAX;}\n\
    \nint main(){\n    long N, Q; cin >> N >> Q;\n    vector<long> A(N);\n    for(long\
    \ i = 0; i < N; i++) cin >> A[i];\n    \n    Compact_Sparse_Table<long, op, e>\
    \ STA(A);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout <<\
    \ STA.query(u, v) << endl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/SparseTable_Compact.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: test/verify/SparseTable_Compact.test.cpp
  requiredBy: []
  timestamp: '2022-01-17 11:15:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/SparseTable_Compact.test.cpp
layout: document
redirect_from:
- /verify/test/verify/SparseTable_Compact.test.cpp
- /verify/test/verify/SparseTable_Compact.test.cpp.html
title: test/verify/SparseTable_Compact.test.cpp
---
