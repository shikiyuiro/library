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
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Data Structure/SparseTable.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\nclass SparseTable{\nprivate:\n\
    \    function<long(long, long)> opera;\npublic:\n    vector<vector<long>> table;\n\
    \    vector<long> cf;\n    \n    SparseTable(vector<long>& v, long e, function<long(long,\
    \ long)> operation) {\n        opera = operation;\n        long isiz = v.size();\n\
    \        long jsiz = 0;\n        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz,\
    \ vector<long>(jsiz, e));\n        for(long i = 0; i < isiz; i++)table[i][0] =\
    \ v[i];\n        for(long j = 1; j < jsiz; j++){\n            for(long i = 0;\
    \ i + (1 << (j - 1)) < isiz; i++){\n                table[i][j] = opera(table[i][j\
    \ - 1], table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n       \
    \ cf.resize(isiz + 1);\n        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >>\
    \ 1] + 1;\n    }\n    \n    long query(long l, long r/*\u534A\u958B\u533A\u9593\
    */){\n        assert(l < r);\n        long b = cf[r - l];\n        return opera(table[l][b],\
    \ table[r - (1 << b)][b]);\n    }\n};\n\nint main(){\n    long N, Q; cin >> N\
    \ >> Q;\n    vector<long> A(N);\n    for(long i = 0; i < N; i++) cin >> A[i];\n\
    \    \n    SparseTable STA(A, INT_MAX, [](long a, long b){return min(a, b);});\n\
    \    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << STA.query(u,\
    \ v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\nclass SparseTable{\nprivate:\n    function<long(long,\
    \ long)> opera;\npublic:\n    vector<vector<long>> table;\n    vector<long> cf;\n\
    \    \n    SparseTable(vector<long>& v, long e, function<long(long, long)> operation)\
    \ {\n        opera = operation;\n        long isiz = v.size();\n        long jsiz\
    \ = 0;\n        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz,\
    \ vector<long>(jsiz, e));\n        for(long i = 0; i < isiz; i++)table[i][0] =\
    \ v[i];\n        for(long j = 1; j < jsiz; j++){\n            for(long i = 0;\
    \ i + (1 << (j - 1)) < isiz; i++){\n                table[i][j] = opera(table[i][j\
    \ - 1], table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n       \
    \ cf.resize(isiz + 1);\n        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >>\
    \ 1] + 1;\n    }\n    \n    long query(long l, long r/*\u534A\u958B\u533A\u9593\
    */){\n        assert(l < r);\n        long b = cf[r - l];\n        return opera(table[l][b],\
    \ table[r - (1 << b)][b]);\n    }\n};\n\nint main(){\n    long N, Q; cin >> N\
    \ >> Q;\n    vector<long> A(N);\n    for(long i = 0; i < N; i++) cin >> A[i];\n\
    \    \n    SparseTable STA(A, INT_MAX, [](long a, long b){return min(a, b);});\n\
    \    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << STA.query(u,\
    \ v) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Data Structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2021-10-24 23:50:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data Structure/SparseTable.cpp
layout: document
redirect_from:
- /library/Data Structure/SparseTable.cpp
- /library/Data Structure/SparseTable.cpp.html
title: Data Structure/SparseTable.cpp
---