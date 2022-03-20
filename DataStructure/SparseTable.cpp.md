---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SparseTable{\npublic:\n    explicit SparseTable() = default;\n\
    \    SparseTable(vector<S>& v){\n        isiz = v.size();\n        jsiz = 64 -\
    \ __builtin_clzll(isiz);\n        table.resize(isiz * jsiz, e());\n        for(int64_t\
    \ i = 0; i < isiz; i++) table[i] = v[i];\n        for(int64_t j = 1; j < jsiz;\
    \ j++){\n            for(int64_t i = 0; i + (1 << (j - 1)) < isiz; i++){\n   \
    \             table[i + isiz * j] = op(table[i + isiz * (j - 1)], table[i + (1\
    \ << (j - 1)) + isiz * (j - 1)]);\n            }\n        }\n    }\n    S fold(int64_t\
    \ L, int64_t R){\n        if(L == R) return e();\n        int64_t b = 64 - __builtin_clzll(R\
    \ - L) - 1;\n        return op(table[L + isiz * b], table[R - (1 << b) + isiz\
    \ * b]);\n    }\nprivate:\n    vector<S> table;\n    int64_t isiz;\n    int64_t\
    \ jsiz;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n\
    \ * @docs docs/DataStructure/SparseTable.md\n */\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n\
    \    explicit SparseTable() = default;\n    SparseTable(vector<S>& v){\n     \
    \   isiz = v.size();\n        jsiz = 64 - __builtin_clzll(isiz);\n        table.resize(isiz\
    \ * jsiz, e());\n        for(int64_t i = 0; i < isiz; i++) table[i] = v[i];\n\
    \        for(int64_t j = 1; j < jsiz; j++){\n            for(int64_t i = 0; i\
    \ + (1 << (j - 1)) < isiz; i++){\n                table[i + isiz * j] = op(table[i\
    \ + isiz * (j - 1)], table[i + (1 << (j - 1)) + isiz * (j - 1)]);\n          \
    \  }\n        }\n    }\n    S fold(int64_t L, int64_t R){\n        if(L == R)\
    \ return e();\n        int64_t b = 64 - __builtin_clzll(R - L) - 1;\n        return\
    \ op(table[L + isiz * b], table[R - (1 << b) + isiz * b]);\n    }\nprivate:\n\
    \    vector<S> table;\n    int64_t isiz;\n    int64_t jsiz;\n};\n/**\n * @brief\
    \ \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy: []
  timestamp: '2022-03-20 10:39:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SparseTable.cpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.cpp
- /library/DataStructure/SparseTable.cpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
## 使い方  
- [テンプレートの定義はACLのSegtreeに準じる。](https://atcoder.github.io/ac-library/production/document_ja/segtree.html)
- `SparseTable(vector<S> &v)`：配列vをもとにスパーステーブルを構築する。  
- `S fold(int64_t L, int64_t R)`：半開区間\[L, R)に対して演算結果を返す。  

## 使用例
[yosupo judge - StaticRMQ](https://judge.yosupo.jp/submission/82979)
