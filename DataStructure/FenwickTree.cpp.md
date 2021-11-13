---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/FenwickTree.test.cpp
    title: test/verify/FenwickTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/FenwickTree.md
    document_title: "Fenwick\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructure/FenwickTree.cpp\"\nclass FenwickTree{\npublic:\n\
    \    vector<long> table;\n    long siz;\n    FenwickTree(long siz) : table(siz\
    \ + 1), siz(siz) {}\n    long sum(long index){\n        long res = 0;\n      \
    \  index++;//0-indexed to 1-indexed\n        while(index > 0){\n            res\
    \ += table[index];\n            index -= (index & -index);\n        }\n      \
    \  return res;\n    }\n    void add(long index, long value){\n        index++;//0-indexed\
    \ to 1-indexed\n        while(index < siz + 1){\n            table[index] += value;\n\
    \            index += (index & -index);\n        }\n    }\n};\n/**\n * @brief\
    \ Fenwick\u6728\n * @docs docs/DataStructure/FenwickTree.md\n */\n"
  code: "class FenwickTree{\npublic:\n    vector<long> table;\n    long siz;\n   \
    \ FenwickTree(long siz) : table(siz + 1), siz(siz) {}\n    long sum(long index){\n\
    \        long res = 0;\n        index++;//0-indexed to 1-indexed\n        while(index\
    \ > 0){\n            res += table[index];\n            index -= (index & -index);\n\
    \        }\n        return res;\n    }\n    void add(long index, long value){\n\
    \        index++;//0-indexed to 1-indexed\n        while(index < siz + 1){\n \
    \           table[index] += value;\n            index += (index & -index);\n \
    \       }\n    }\n};\n/**\n * @brief Fenwick\u6728\n * @docs docs/DataStructure/FenwickTree.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FenwickTree.cpp
  requiredBy: []
  timestamp: '2021-11-13 19:54:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/FenwickTree.test.cpp
documentation_of: DataStructure/FenwickTree.cpp
layout: document
redirect_from:
- /library/DataStructure/FenwickTree.cpp
- /library/DataStructure/FenwickTree.cpp.html
title: "Fenwick\u6728"
---
## きもち

フェニック木です。あとでかきます。  

## 使い方  
- `FenwickTree(long siz)`：コンストラクタ。サイズsizの配列におけるフェニック木を構築する。  
- `long sum(long index)`：配列の0番目からindex番目までの要素の和を求める。  
- `void add(long index, long value)`：配列のindex番目の要素にvalueを加算する  

## 計算量
サイズをNとして、  
sumクエリ:$\mathrm{O}(N)$  
addクエリ:$\mathrm{O}(logN)$  

## Tips

加算だけでなく、モノイドをなす演算に拡張できる。  
また、累積和の要領で始点が0番目でないときの区間和も求められる。  
