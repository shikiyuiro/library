---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/RMQ_ON_O1.test.cpp
    title: verify/RMQ_ON_O1.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/SparseTable.test.cpp
    title: verify/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
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
    \ * @docs docs/DataStructure/SparseTable.md\n */\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n\
    \    explicit SparseTable() = default;\n    SparseTable(vector<S>& v){\n     \
    \   isiz = v.size();\n        jsiz = 32 - __builtin_clz(isiz);\n        table.resize(isiz\
    \ * jsiz, e());\n        for(int32_t i = 0; i < isiz; i++) table[i] = v[i];\n\
    \        for(int32_t j = 1; j < jsiz; j++){\n            for(int32_t i = 0; i\
    \ + (1 << (j - 1)) < isiz; i++){\n                table[i + isiz * j] = op(table[i\
    \ + isiz * (j - 1)], table[i + (1 << (j - 1)) + isiz * (j - 1)]);\n          \
    \  }\n        }\n    }\n    S fold(int32_t L, int32_t R){\n        if(L == R)\
    \ return e();\n        int32_t b = 32 - __builtin_clz(R - L) - 1;\n        return\
    \ op(table[L + isiz * b], table[R - (1 << b) + isiz * b]);\n    }\nprivate:\n\
    \    vector<S> table;\n    int32_t isiz;\n    int32_t jsiz;\n};\n/**\n * @brief\
    \ \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy: []
  timestamp: '2022-03-29 17:04:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/SparseTable.test.cpp
  - verify/RMQ_ON_O1.test.cpp
documentation_of: DataStructure/SparseTable.cpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.cpp
- /library/DataStructure/SparseTable.cpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
## 使い方  
- <a href="https://atcoder.github.io/ac-library/production/document_ja/segtree.html" target="_blank">テンプレートの定義はACLのSegtreeに準じる。</a>  
- `SparseTable(vector<S> &v)`：配列vをもとにスパーステーブルを構築する。  
- `S fold(int64_t L, int64_t R)`：半開区間\[L, R)に対して演算結果を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/82979" target="_blank">yosupo judge - Static RMQ</a>
