---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/Heavy_Light_Decomposition.test.cpp
    title: test/verify/Heavy_Light_Decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree.md
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SegmentTree{\npublic:\n    explicit SegmentTree() = default;\n\
    \    \n    vector<S> table;\n    long size = 1;\n    SegmentTree(vector<S> &vec){\n\
    \        while(size < vec.size()) size <<= 1;\n        table.resize(size << 1,\
    \ e());\n        for(long i = 0; i < (long)vec.size(); i++) table[i + size] =\
    \ vec[i];\n        for(long i = size - 1; i >= 1; i--) table[i] = op(table[i<<1|0],table[i<<1|1]);\n\
    \    }\n    S fold(long l, long r){\n        l += size; r += size;\n        S\
    \ Lres = e(), Rres = e();\n        while(l < r){\n            if(l & 1) Lres =\
    \ op(Lres, table[l++]);\n            if(r & 1) Rres = op(table[--r], Rres);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return op(Lres, Rres);\n  \
    \  }\n    void set(long p, S x){\n        p += size;\n        table[p] = x;\n\
    \        while(p >>= 1) table[p] = op(table[p<<1|0],table[p<<1|1]);\n    }\n \
    \   long partition_point(bool (*check)(S)){\n        //i\u756A\u76EE\u306E\u8981\
    \u7D20\u304Cfold(0, i+1)\u3067\u3042\u308B\u914D\u5217V\u306B\u3064\u3044\u3066\
    \u3001std::distance(V.begin(), std::partition_point(V.begin(), V.end(), check))\u3092\
    \u8FD4\u3059\n        if(check(table[1])) return table[0];\n        long vis =\
    \ 1;\n        S acc = e();\n        while(vis < table.size()){\n            vis\
    \ <<= 1;\n            S tmp = op(acc, table[vis]);\n            if(check[tmp]){\n\
    \                acc = tmp;\n                vis++;\n            }\n        }\n\
    \        return vis - size;\n    }\n};\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n * @docs docs/DataStructure/SegmentTree.md\n */\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass SegmentTree{\npublic:\n\
    \    explicit SegmentTree() = default;\n    \n    vector<S> table;\n    long size\
    \ = 1;\n    SegmentTree(vector<S> &vec){\n        while(size < vec.size()) size\
    \ <<= 1;\n        table.resize(size << 1, e());\n        for(long i = 0; i < (long)vec.size();\
    \ i++) table[i + size] = vec[i];\n        for(long i = size - 1; i >= 1; i--)\
    \ table[i] = op(table[i<<1|0],table[i<<1|1]);\n    }\n    S fold(long l, long\
    \ r){\n        l += size; r += size;\n        S Lres = e(), Rres = e();\n    \
    \    while(l < r){\n            if(l & 1) Lres = op(Lres, table[l++]);\n     \
    \       if(r & 1) Rres = op(table[--r], Rres);\n            l >>= 1; r >>= 1;\n\
    \        }\n        return op(Lres, Rres);\n    }\n    void set(long p, S x){\n\
    \        p += size;\n        table[p] = x;\n        while(p >>= 1) table[p] =\
    \ op(table[p<<1|0],table[p<<1|1]);\n    }\n    long partition_point(bool (*check)(S)){\n\
    \        //i\u756A\u76EE\u306E\u8981\u7D20\u304Cfold(0, i+1)\u3067\u3042\u308B\
    \u914D\u5217V\u306B\u3064\u3044\u3066\u3001std::distance(V.begin(), std::partition_point(V.begin(),\
    \ V.end(), check))\u3092\u8FD4\u3059\n        if(check(table[1])) return table[0];\n\
    \        long vis = 1;\n        S acc = e();\n        while(vis < table.size()){\n\
    \            vis <<= 1;\n            S tmp = op(acc, table[vis]);\n          \
    \  if(check[tmp]){\n                acc = tmp;\n                vis++;\n     \
    \       }\n        }\n        return vis - size;\n    }\n};\n/**\n * @brief \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n * @docs docs/DataStructure/SegmentTree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2022-01-19 22:58:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/Heavy_Light_Decomposition.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## きもち  
セグメント木だよ。  
区間演算と、一点更新を高速に行うことができるデータ構造だよ。  

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。  
- `SegmentTree(vector<S> &vec)`：コンストラクタ。列構造vecをもとにセグメント木を構成する。  
- `S fold(long l, long r)`：半開区間\[l, r)に対する演算結果を返す。  
- `void set(long p, S x)`：位置pに値xを代入する。  
- `long partition_point(bool (*check)(S))`:関数Sが[first,mid)においてfalse,[mid,last)においてtrueとなるような位置midを返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(logN)$  
