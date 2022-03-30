---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"verify/SparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 2 \"DataStructure/SparseTable.cpp\"\n\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SparseTable{\npublic:\n    explicit SparseTable() = default;\n\
    \    SparseTable(vector<S>& v){\n        isiz = v.size();\n        jsiz = 32 -\
    \ __builtin_clz(isiz);\n        table.resize(isiz * jsiz, e());\n        for(int32_t\
    \ i = 0; i < isiz; i++) table[i] = v[i];\n        for(int32_t j = 1; j < jsiz;\
    \ j++){\n            for(int32_t i = 0; i + (1 << (j - 1)) < isiz; i++){\n   \
    \             table[i + isiz * j] = op(table[i + isiz * (j - 1)], table[i + (1\
    \ << (j - 1)) + isiz * (j - 1)]);\n            }\n        }\n    }\n    S fold(int32_t\
    \ L, int32_t R){\n        if(L == R) return e();\n        int32_t b = 32 - __builtin_clz(R\
    \ - L) - 1;\n        return op(table[L + isiz * b], table[R - (1 << b) + isiz\
    \ * b]);\n    }\nprivate:\n    vector<S> table;\n    int32_t isiz;\n    int32_t\
    \ jsiz;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n\
    \ * @docs docs/DataStructure/SparseTable.md\n */\n#line 5 \"verify/SparseTable.test.cpp\"\
    \n\nint64_t op(int64_t a, int64_t b){\n    return min(a, b);\n}\n\nint64_t e(){\n\
    \    return INT64_MAX;\n}\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N, Q; cin >> N >> Q;\n    vector<int64_t> A(N);\n    for(int64_t\
    \ i = 0; i < N; i++) cin >> A[i];\n    SparseTable<int64_t, op, e> sp(A);\n  \
    \  while(Q--){\n        int64_t l, r; cin >> l >> r;\n        cout << sp.fold(l,\
    \ r) << '\\n';\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../template/template.cpp\"\n#include \"../DataStructure/SparseTable.cpp\"\n\
    \nint64_t op(int64_t a, int64_t b){\n    return min(a, b);\n}\n\nint64_t e(){\n\
    \    return INT64_MAX;\n}\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N, Q; cin >> N >> Q;\n    vector<int64_t> A(N);\n    for(int64_t\
    \ i = 0; i < N; i++) cin >> A[i];\n    SparseTable<int64_t, op, e> sp(A);\n  \
    \  while(Q--){\n        int64_t l, r; cin >> l >> r;\n        cout << sp.fold(l,\
    \ r) << '\\n';\n    }\n}\n\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: verify/SparseTable.test.cpp
  requiredBy: []
  timestamp: '2022-03-30 09:59:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/SparseTable.test.cpp
layout: document
redirect_from:
- /verify/verify/SparseTable.test.cpp
- /verify/verify/SparseTable.test.cpp.html
title: verify/SparseTable.test.cpp
---
