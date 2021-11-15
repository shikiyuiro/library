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
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\nclass UnionFind{\nprivate:\n\
    \    vector<long> Root;\n    vector<long> Size;\npublic:\n    UnionFind(long size){\
    \ Root.resize(size); iota(Root.begin(), Root.end(), 0); Size.resize(size, 1);}\n\
    \    long find(long x){ return (Root[x] == x) ? x: Root[x] = find(Root[x]); }\n\
    \    void unite(long x, long y){\n        if(find(x) == find(y)) return;\n   \
    \     if(Size[find(x)] < Size[find(y)]) swap(x, y);\n        Size[find(x)] +=\
    \ Size[find(y)];\n        Root[find(y)] = find(x);\n    }\n    bool same(long\
    \ x, long y){ return find(x) == find(y);}\n    long size(long x){ return Size[find(x)];}\n\
    };\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(Union Find)\n\
    \ * @docs docs/DataStructure/UnionFind.md\n */\n"
  code: "class UnionFind{\nprivate:\n    vector<long> Root;\n    vector<long> Size;\n\
    public:\n    UnionFind(long size){ Root.resize(size); iota(Root.begin(), Root.end(),\
    \ 0); Size.resize(size, 1);}\n    long find(long x){ return (Root[x] == x) ? x:\
    \ Root[x] = find(Root[x]); }\n    void unite(long x, long y){\n        if(find(x)\
    \ == find(y)) return;\n        if(Size[find(x)] < Size[find(y)]) swap(x, y);\n\
    \        Size[find(x)] += Size[find(y)];\n        Root[find(y)] = find(x);\n \
    \   }\n    bool same(long x, long y){ return find(x) == find(y);}\n    long size(long\
    \ x){ return Size[find(x)];}\n};\n/**\n * @brief \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020(Union Find)\n * @docs docs/DataStructure/UnionFind.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-11-15 14:08:30+09:00'
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
$Union$クエリ:与えられた2頂点を含む集合を連結にする。  
$Find$クエリ:与えられた頂点の根を求める。  
$Same$クエリ:与えられた2頂点が連結であるか判定する。  
$Size$クエリ:与えられた頂点を含む集合の大きさを求める。

## 使い方

- `UnionFind(long size)`：コンストラクタ。頂点数sizeの素集合を構築する。  
- `long find(long x)`：頂点xの根を返す。  
- `void unite(long x, long y)`：頂点xを含む集合と頂点yを含む集合を連結にする。  
- `bool same(long x, long y)`：頂点xと頂点yが連結であるならば$true$、そうでなければ$false$を返す。  
- `long size(long x, long y)`：頂点xを含む集合の大きさを返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(\alpha(N))$(償却・$\alpha$はアッカーマン関数の逆関数)   

## Tips
  
グリッドなどの連結判定にも利用できる。
