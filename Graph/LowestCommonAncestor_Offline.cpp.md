---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/LowestCommonAncestor_Offline.test.cpp
    title: test/verify/LowestCommonAncestor_Offline.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/LowestCommonAncestor_Offline.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148( \u30AA\u30D5\u30E9\u30A4\
      \u30F3 )"
    links: []
  bundledCode: "#line 1 \"Graph/LowestCommonAncestor_Offline.cpp\"\nclass OffLCA{\n\
    public:\n    OffLCA(vector<vector<long>> &tree, long root, vector<tuple<long,long,long>>\
    \ &query){\n        vector<vector<pair<long,long*>>> fellow(tree.size());\n  \
    \      for(auto& [f, s, t] : query){\n            fellow[f].push_back({s, &t});\n\
    \            fellow[s].push_back({f, &t});\n        }\n        vector<bool> visited(tree.size(),\
    \ false);\n        UnionFind uni(tree.size());\n        auto dfs = [&](auto &&self,\
    \ long vis, long prev) -> void {\n            visited[vis] = true;\n         \
    \   for(auto e : tree[vis]) {\n                if(e == prev) continue;\n     \
    \           self(self, e, vis);\n                uni.unite(vis, e);\n        \
    \        uni.Size[vis] = uni.Size[uni.find(vis)];\n                uni.Root[e]\
    \ = vis;\n                uni.Root[vis] = vis;\n            }\n            for(auto\
    \ [e, f] : fellow[vis]) if(visited[e]) *f = uni.find(e);\n        };\n       \
    \ dfs(dfs, root, -1);\n    }\nprivate:\n    struct UnionFind{\n        vector<long>\
    \ Root;\n        vector<long> Size;\n        UnionFind(long size){ Root.resize(size);\
    \ iota(Root.begin(), Root.end(), 0); Size.resize(size, 1);}\n        long find(long\
    \ x){ return (Root[x] == x) ? x: Root[x] = find(Root[x]); }\n        void unite(long\
    \ x, long y){\n            if(find(x) == find(y)) return;\n            if(Size[find(x)]\
    \ < Size[find(y)]) swap(x, y);\n            Size[find(x)] += Size[find(y)];\n\
    \            Root[find(y)] = find(x);\n        }\n        bool same(long x, long\
    \ y){ return find(x) == find(y);}\n        long size(long x){ return Size[find(x)];}\n\
    \    };\n};\n/**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148( \u30AA\u30D5\
    \u30E9\u30A4\u30F3 )\n * @docs docs/Graph/LowestCommonAncestor_Offline.md\n */\n"
  code: "class OffLCA{\npublic:\n    OffLCA(vector<vector<long>> &tree, long root,\
    \ vector<tuple<long,long,long>> &query){\n        vector<vector<pair<long,long*>>>\
    \ fellow(tree.size());\n        for(auto& [f, s, t] : query){\n            fellow[f].push_back({s,\
    \ &t});\n            fellow[s].push_back({f, &t});\n        }\n        vector<bool>\
    \ visited(tree.size(), false);\n        UnionFind uni(tree.size());\n        auto\
    \ dfs = [&](auto &&self, long vis, long prev) -> void {\n            visited[vis]\
    \ = true;\n            for(auto e : tree[vis]) {\n                if(e == prev)\
    \ continue;\n                self(self, e, vis);\n                uni.unite(vis,\
    \ e);\n                uni.Size[vis] = uni.Size[uni.find(vis)];\n            \
    \    uni.Root[e] = vis;\n                uni.Root[vis] = vis;\n            }\n\
    \            for(auto [e, f] : fellow[vis]) if(visited[e]) *f = uni.find(e);\n\
    \        };\n        dfs(dfs, root, -1);\n    }\nprivate:\n    struct UnionFind{\n\
    \        vector<long> Root;\n        vector<long> Size;\n        UnionFind(long\
    \ size){ Root.resize(size); iota(Root.begin(), Root.end(), 0); Size.resize(size,\
    \ 1);}\n        long find(long x){ return (Root[x] == x) ? x: Root[x] = find(Root[x]);\
    \ }\n        void unite(long x, long y){\n            if(find(x) == find(y)) return;\n\
    \            if(Size[find(x)] < Size[find(y)]) swap(x, y);\n            Size[find(x)]\
    \ += Size[find(y)];\n            Root[find(y)] = find(x);\n        }\n       \
    \ bool same(long x, long y){ return find(x) == find(y);}\n        long size(long\
    \ x){ return Size[find(x)];}\n    };\n};\n/**\n * @brief \u6700\u5C0F\u5171\u901A\
    \u7956\u5148( \u30AA\u30D5\u30E9\u30A4\u30F3 )\n * @docs docs/Graph/LowestCommonAncestor_Offline.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LowestCommonAncestor_Offline.cpp
  requiredBy: []
  timestamp: '2022-01-29 15:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/LowestCommonAncestor_Offline.test.cpp
documentation_of: Graph/LowestCommonAncestor_Offline.cpp
layout: document
redirect_from:
- /library/Graph/LowestCommonAncestor_Offline.cpp
- /library/Graph/LowestCommonAncestor_Offline.cpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148( \u30AA\u30D5\u30E9\u30A4\u30F3 )"
---
## きもち

オフラインに最小共通祖先を求める。  
基本方針は深さ優先探索。  
LCAを求めたいペア(P, Q)が与えられているとしよう。  
Pが既に探索済みである状態で、Qに到着したとする。  
このとき、LCA(P, Q)は、Qの探索を開始した時点で、まだすべての子について探索を終えていないPの祖先のうち、最も深い頂点である。  
UnionFindを用いて、そのクエリに効率よく答えることができる。  
具体的には、ある頂点Vのすべての子について探索を終えた時、  
・その親を Par(V)とする。  
・Vの(V自身を含む)すべての子 x について UnionFind::find(x)がPar(V)となるようにしたい。  
・VとPar(V)をUniteする(Union by size)。  
・Union by sizeによって計算量が落ちるが、VとPar(V)どちらがUnionFind木の根になるかわからない。  
・VがPar(V)の根にならないように強制的にUnionFind::Root[V]をPar(V)に変更。これでOK.  


## 使い方  
- `OffLCA(vector<vector<long>>& tree, long root, vector<tuple<long,long,long>> &query)`:コンストラクタ。treeに木を、rootに根の頂点番号を、queryはLCAを求めたい二頂点とそのLCAを格納する変数をこの順にもつtupleのvectorを代入してください。  

## 計算量

$\mathrm{O}(Nα(N) + Q)$　$α$はアッカーマン関数の逆関数  
$\mathrm{O}(N + Q)$のLCAにはオーダーが劣るがこちらは定数倍がかなり軽め。  

## Tips

面白い。レートへの寄与は低そうだけど。  
