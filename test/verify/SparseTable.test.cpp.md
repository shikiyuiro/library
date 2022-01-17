---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/verify/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 4 \"test/verify/SparseTable.test.cpp\"\n\n#line 1 \"DataStructure/SparseTable.cpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n  \
    \  vector<vector<S>> table;\n    vector<long> cf;\n    \n    explicit SparseTable()\
    \ = default;\n    \n    SparseTable(vector<S>& v){\n        long isiz = v.size();\n\
    \        long jsiz = 0;\n        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz,\
    \ vector<S>(jsiz, e()));\n        for(long i = 0; i < isiz; i++) table[i][0] =\
    \ v[i];\n        for(long j = 1; j < jsiz; j++){\n            for(long i = 0;\
    \ i + (1 << (j - 1)) < isiz; i++){\n                table[i][j] = op(table[i][j\
    \ - 1], table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n       \
    \ cf.resize(isiz + 1);\n        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >>\
    \ 1] + 1;\n    }\n    \n    S query(long l, long r/*\u534A\u958B\u533A\u9593*/){\n\
    \        if(l == r) return e();\n        long b = cf[r - l];\n        return op(table[l][b],\
    \ table[r - (1 << b)][b]);\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\
    \u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n#line\
    \ 6 \"test/verify/SparseTable.test.cpp\"\n\nint main(){\n    long N, Q; cin >>\
    \ N >> Q;\n    vector<long> A(N);\n    for(long i = 0; i < N; i++) cin >> A[i];\n\
    \    \n    SparseTable<long> STA(A, LONG_MAX, [](long a, long b){return min(a,\
    \ b);});\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout <<\
    \ STA.query(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../template/template.cpp\"\n\n#include \"../../DataStructure/SparseTable.cpp\"\
    \n\nint main(){\n    long N, Q; cin >> N >> Q;\n    vector<long> A(N);\n    for(long\
    \ i = 0; i < N; i++) cin >> A[i];\n    \n    SparseTable<long> STA(A, LONG_MAX,\
    \ [](long a, long b){return min(a, b);});\n    while(Q--){\n        long u, v;\
    \ cin >> u >> v;\n        cout << STA.query(u, v) << endl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: test/verify/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2022-01-17 10:14:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/verify/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/verify/SparseTable.test.cpp
- /verify/test/verify/SparseTable.test.cpp.html
title: test/verify/SparseTable.test.cpp
---
