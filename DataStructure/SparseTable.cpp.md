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
  - icon: ':x:'
    path: test/verify/SparseTable.test.cpp
    title: test/verify/SparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SparseTable.md
    document_title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate < typename elm\
    \ >\nclass SparseTable{\npublic:\n    explicit SparseTable() = default;\n    \n\
    \    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)> op) : op(op){\n\
    \        long isiz = v.size();\n        long jsiz = 0;\n        while((1 << jsiz)\
    \ <= isiz) jsiz++;\n        table.resize(isiz, vector<elm>(jsiz, e));\n      \
    \  for(long i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long j = 1;\
    \ j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){\n\
    \                table[i][j] = op(table[i][j - 1], table[i + (1 << (j - 1))][j\
    \ - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n        for(long\
    \ i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n    elm query(long\
    \ L, long R/*[L, R)*/){\n        assert(L < R);\n        long b = cf[R - L];\n\
    \        return op(table[L][b], table[R - (1 << b)][b]);\n    }\nprivate:\n  \
    \  function<elm(elm, elm)> op;\n    vector<vector<elm>> table;\n    vector<long>\
    \ cf;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n *\
    \ @docs docs/DataStructure/SparseTable.md\n */\n"
  code: "template < typename elm >\nclass SparseTable{\npublic:\n    explicit SparseTable()\
    \ = default;\n    \n    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)>\
    \ op) : op(op){\n        long isiz = v.size();\n        long jsiz = 0;\n     \
    \   while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz, vector<elm>(jsiz,\
    \ e));\n        for(long i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long\
    \ j = 1; j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz;\
    \ i++){\n                table[i][j] = op(table[i][j - 1], table[i + (1 << (j\
    \ - 1))][j - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n  \
    \      for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n\
    \    elm query(long L, long R/*[L, R)*/){\n        assert(L < R);\n        long\
    \ b = cf[R - L];\n        return op(table[L][b], table[R - (1 << b)][b]);\n  \
    \  }\nprivate:\n    function<elm(elm, elm)> op;\n    vector<vector<elm>> table;\n\
    \    vector<long> cf;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SparseTable.cpp
  requiredBy:
  - Graph/LowestCommonAncestor.cpp
  timestamp: '2021-12-22 19:48:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
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

演算£に対して £(l, r) = l £ l+1 £ l+2 £ ... £ r-1 を高速に求めたい。  
セグメント木では£が結合則を満たすとき、予めl,rに応じて定まる値mをとり、£(l, m)と£(m, r)を前計算しておくことでクエリを高速化した。  
このとき£が冪等性を持つならば同じmでなくとも l <= mr <= ml <= r なるml , mrをとり£(l, ml)と£(mr, r)を計算しておけばよい。  
言い換えると、前計算の始点を固定したとき、前計算する長さは終点とは独立して決めて良い。  
前計算の長さは2の冪乗ずつにすると、ダブリングを利用して求めることができ、かつ上手いことどのような範囲にも対応できる。  
セグメント木と比較するとクエリが高速だが、配列の値を更新するクエリには対応できない。  

## 使い方  
#### $Element$には集合の要素の型を代入してください。
- `SparseTable(vector<Element> v, Element e, function<Element(Element, Element)> operation)`：コンストラクタ。配列v, 演算の単位元e, 演算operationのスパーステーブルを構築する。  
- `Element query(long l, long r)`：半開区間\[l, r)に対して l £ l+1 £ ... £ r-1 を求める。  

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(1)$  

## Tips

このような演算£とその集合がなす代数構造は冪等半群とよばれるらしいです。
