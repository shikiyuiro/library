---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/LowestCommonAncestor.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/LowestCommonAncestor.test.cpp
    title: test/verify/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/SparseTable.test.cpp
    title: test/verify/SparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SparseTable{\npublic:\n    vector<vector<S>> table;\n \
    \   vector<long> cf;\n    \n    explicit SparseTable() = default;\n    \n    SparseTable(vector<S>&\
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
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass SparseTable{\npublic:\n\
    \    vector<vector<S>> table;\n    vector<long> cf;\n    \n    explicit SparseTable()\
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
    \u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy:
  - Graph/LowestCommonAncestor.cpp
  timestamp: '2022-01-17 10:14:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/SparseTable.test.cpp
  - test/verify/LowestCommonAncestor.test.cpp
documentation_of: DataStructure/SparseTable.cpp
layout: document
redirect_from:
- /library/DataStructure/SparseTable.cpp
- /library/DataStructure/SparseTable.cpp.html
title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
---
## きもち

スパーステーブルだよ。  
冪等性をもつ静的な区間クエリに構築O(NlogN), クエリO(1)で答えられるよ。  
冪等性を仮定しないdisjointなスパーステーブルや、  
[構築O(N), クエリO(1)のスパーステーブル](https://shikiyuiro.github.io/library/DataStructure/SparseTable_Compact.cpp)もあるよ。  

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。 
- `SparseTable(vector<S> &v)`：コンストラクタ。配列vをもとにスパーステーブルを構築する。  
- `Element query(long l, long r)`：半開区間\[l, r)に対して演算結果を返す。  

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(1)$  

## Tips

todo:ここに使用例を書く
