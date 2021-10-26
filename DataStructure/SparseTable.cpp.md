---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/SparseTable.test.cpp
    title: test/verify/SparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate < typename T =\
    \ long >\nclass SparseTable{\nprivate:\n    function<T(T, T)> opera;\npublic:\n\
    \    vector<vector<T>> table;\n    vector<long> cf;\n    \n    SparseTable(vector<T>&\
    \ v, T e, function<T(T, T)> operation) {\n        opera = operation;\n       \
    \ long isiz = v.size();\n        long jsiz = 0;\n        while((1 << jsiz) <=\
    \ isiz) jsiz++;\n        table.resize(isiz, vector<T>(jsiz, e));\n        for(long\
    \ i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long j = 1; j < jsiz;\
    \ j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){\n      \
    \          table[i][j] = opera(table[i][j - 1], table[i + (1 << (j - 1))][j -\
    \ 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n        for(long\
    \ i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n    T query(long\
    \ l, long r/*\u534A\u958B\u533A\u9593*/){\n        assert(l < r);\n        long\
    \ b = cf[r - l];\n        return opera(table[l][b], table[r - (1 << b)][b]);\n\
    \    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n\
    \ * @docs docs/DataStructure/SparseTable.md\n */\n"
  code: "template < typename T = long >\nclass SparseTable{\nprivate:\n    function<T(T,\
    \ T)> opera;\npublic:\n    vector<vector<T>> table;\n    vector<long> cf;\n  \
    \  \n    SparseTable(vector<T>& v, T e, function<T(T, T)> operation) {\n     \
    \   opera = operation;\n        long isiz = v.size();\n        long jsiz = 0;\n\
    \        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz, vector<T>(jsiz,\
    \ e));\n        for(long i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long\
    \ j = 1; j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz;\
    \ i++){\n                table[i][j] = opera(table[i][j - 1], table[i + (1 <<\
    \ (j - 1))][j - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n\
    \        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n\
    \    T query(long l, long r/*\u534A\u958B\u533A\u9593*/){\n        assert(l <\
    \ r);\n        long b = cf[r - l];\n        return opera(table[l][b], table[r\
    \ - (1 << b)][b]);\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy: []
  timestamp: '2021-10-26 23:18:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/SparseTable.test.cpp
documentation_of: DataStructure/SparseTable.cpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.cpp
- /library/DataStructure/SparseTable.cpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
## きもち

演算£に対して £(l, r) = l £ l+1 £ l+2 £ ... £ r-1 を高速に求めたい。  
セグメント木では£が結合則を満たすとき、予めl,rに応じて定まる値mをとり、£(l, m)と£(m, r)を前計算しておくことでクエリを高速化した。  
このとき£が冪等性を持つならば同じmでなくとも l <= mr <= ml <= r なるml , mrをとり£(l, ml)と£(mr, r)を計算しておけばよい。  
言い換えると、前計算の始点を固定したとき、前計算する長さは終点とは独立して決めて良い。  
前計算の長さは2の冪乗ずつにすると、ダブリングを利用して求めることができ、かつ上手いことどのような範囲にも対応できる。  
セグメント木と比較するとクエリが高速だが、配列の値を更新するクエリには対応できない。  

## 使い方

- `SparseTable(long v, long e, function<long(long, long)> operation)`：配列v, 演算の単位元e, 演算operationのスパーステーブルを構築する。  
- `long query(long l, long r)`：半開区間\[l, r)に対して l £ l+1 £ ... £ r-1 を求める。  

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(1)$  

## Tips

このような演算£とその集合がなす代数構造は冪等半群とよばれるらしいです。
