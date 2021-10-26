---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/UnionFind.test.cpp
    title: test/verify/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/UnionFind.md
    document_title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)"
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\nclass Union_find{\npublic:\n\
    \    vector<long> par;\n    Union_find(long size){ par.resize(size); for(long\
    \ i = 0; i < size; i++) par[i] = i; }\n    long root(long x){ return (par[x] ==\
    \ x) ? x: par[x] = root(par[x]); }\n    void unite(long x, long y){ par[root(x)]\
    \ = root(y); }\n    bool same(long x, long y){ return root(x) == root(y); }\n\
    };\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)\n\
    \ * @docs docs/DataStructure/UnionFind.md\n */\n"
  code: "class Union_find{\npublic:\n    vector<long> par;\n    Union_find(long size){\
    \ par.resize(size); for(long i = 0; i < size; i++) par[i] = i; }\n    long root(long\
    \ x){ return (par[x] == x) ? x: par[x] = root(par[x]); }\n    void unite(long\
    \ x, long y){ par[root(x)] = root(y); }\n    bool same(long x, long y){ return\
    \ root(x) == root(y); }\n};\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020(Union Find)\n * @docs docs/DataStructure/UnionFind.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-10-26 17:33:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/UnionFind.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)"
---
## きもち

素集合を根付き木の集合として管理することで以下のクエリを高速に実行できる。  
$Union$クエリ:与えられた2頂点の根A, Bに対してBの根をAとすることで、2頂点を含む集合を連結にする。  
$Find$クエリ:与えられた頂点の根を求める。  
$Same$クエリ:与えられた2頂点の根を比較し、2頂点が連結であるか判定する(根が等しいなら連結であるといえるため)。  

## 使い方

- `Union_find(long size)`：頂点数sizeの素集合を構築する。  
- `long root(long x)`：頂点xの根を返す。  
- `void unite(long x, long y)`：頂点xを含む集合と頂点yを含む集合を連結にする。  
- `bool same(long x, long y)`：頂点xと頂点yが連結であるかどうかを返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(log N)$。  

## Tips

上手に実装すると$\mathrm{O}(log N)$より速くなるらしいです。精進します。  
