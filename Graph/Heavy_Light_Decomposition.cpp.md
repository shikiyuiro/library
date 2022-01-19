---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Graph/Heavy_Light_Decomposition.md
    document_title: "HL\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"Graph/Heavy_Light_Decomposition.cpp\"\nclass Heavy_Light_Decomposition{\n\
    public:\n    \n    Heavy_Light_Decomposition(vector<vector<long>> &tree, long\
    \ root = 0) : tree(tree), root(root){\n        depth.resize(tree.size(), 0);\n\
    \        heavy.resize(tree.size(), -1);\n        subtree_size.resize(tree.size(),\
    \ 1);\n        calc_depth(root, -1);\n        table_index.resize(tree.size(),\
    \ -1);\n        terminal.resize(tree.size(), {root, -1});\n        tour();\n \
    \   }\n    \n    vector<long> get_table(){\n        return table;\n    }\n   \
    \ long get_pos(long p){\n        return table_index[p];\n    }\n    \n    vector<pair<long,long>>\
    \ path_decomp(long u, long v, bool edge_is_weighted = false){\n        vector<pair<long,long>>\
    \ res;\n        stack<pair<long,long>> ser;\n        while(terminal[u].first !=\
    \ terminal[v].first){\n            auto [TermiU, TransU] = terminal[u];\n    \
    \        auto [TermiV, TransV] = terminal[v];\n            if(depth[TermiU] >=\
    \ depth[TermiV]){\n                res.push_back({table_index[u], table_index[TermiU]});\n\
    \                u = TransU;\n            }else{\n                ser.push({table_index[TermiV],\
    \ table_index[v]});\n                v = TransV;\n            }\n        }\n \
    \       if(edge_is_weighted){\n            if(u == v) return res;\n          \
    \  if(table_index[u] < table_index[v]) res.push_back({table_index[heavy[u]], table_index[v]});\n\
    \            else res.push_back({table_index[u], table_index[heavy[v]]});\n  \
    \      }else{\n            res.push_back({table_index[u], table_index[v]});\n\
    \        }\n        while(not ser.empty()){\n            auto p = ser.top(); ser.pop();\n\
    \            res.push_back(p);\n        }\n        return res;\n    }\n    \n\
    \    pair<long,long> subtree_decomp(long v){\n        return {table_index[v],\
    \ table_index[v] + subtree_size[v] - 1};\n    }\n    \nprivate:\n    long root\
    \ = 0;\n    vector<vector<long>> &tree;\n    vector<long> depth;\n    vector<long>\
    \ heavy;\n    vector<long> subtree_size;\n    vector<long> table;\n    vector<long>\
    \ table_index;\n    vector<pair<long,long>> terminal;\n    void calc_depth(long\
    \ vis, long prev){\n        if(prev != -1) depth[vis] = depth[prev] + 1;\n   \
    \     long max_subtree_size = 0;\n        for(auto nex : tree[vis]){\n       \
    \     if(nex == prev) continue;\n            calc_depth(nex, vis);\n         \
    \   subtree_size[vis] += subtree_size[nex];\n            if(subtree_size[nex]\
    \ <= max_subtree_size) continue;\n            max_subtree_size = subtree_size[nex];\n\
    \            heavy[vis] = nex;\n        }\n    }\n    void tour(){\n        stack<long>\
    \ Q; Q.push(root);\n        while(not Q.empty()){\n            long t = Q.top();\
    \ Q.pop();\n            table.push_back(t);\n            table_index[t] = table.size()\
    \ - 1;\n            for(auto nex : tree[t]){\n                if(depth[nex] <\
    \ depth[t]) continue;\n                if(nex == heavy[t]) continue;\n       \
    \         Q.push(nex);\n                terminal[nex] = {nex, t};\n          \
    \  }\n            if(heavy[t] != -1){\n                Q.push(heavy[t]);\n   \
    \             terminal[heavy[t]] = terminal[t];\n            }\n        }\n  \
    \  }\n};\n/**\n * @brief HL\u5206\u89E3\n * @docs docs/Graph/Heavy_Light_Decomposition.md\n\
    \ */\n"
  code: "class Heavy_Light_Decomposition{\npublic:\n    \n    Heavy_Light_Decomposition(vector<vector<long>>\
    \ &tree, long root = 0) : tree(tree), root(root){\n        depth.resize(tree.size(),\
    \ 0);\n        heavy.resize(tree.size(), -1);\n        subtree_size.resize(tree.size(),\
    \ 1);\n        calc_depth(root, -1);\n        table_index.resize(tree.size(),\
    \ -1);\n        terminal.resize(tree.size(), {root, -1});\n        tour();\n \
    \   }\n    \n    vector<long> get_table(){\n        return table;\n    }\n   \
    \ long get_pos(long p){\n        return table_index[p];\n    }\n    \n    vector<pair<long,long>>\
    \ path_decomp(long u, long v, bool edge_is_weighted = false){\n        vector<pair<long,long>>\
    \ res;\n        stack<pair<long,long>> ser;\n        while(terminal[u].first !=\
    \ terminal[v].first){\n            auto [TermiU, TransU] = terminal[u];\n    \
    \        auto [TermiV, TransV] = terminal[v];\n            if(depth[TermiU] >=\
    \ depth[TermiV]){\n                res.push_back({table_index[u], table_index[TermiU]});\n\
    \                u = TransU;\n            }else{\n                ser.push({table_index[TermiV],\
    \ table_index[v]});\n                v = TransV;\n            }\n        }\n \
    \       if(edge_is_weighted){\n            if(u == v) return res;\n          \
    \  if(table_index[u] < table_index[v]) res.push_back({table_index[heavy[u]], table_index[v]});\n\
    \            else res.push_back({table_index[u], table_index[heavy[v]]});\n  \
    \      }else{\n            res.push_back({table_index[u], table_index[v]});\n\
    \        }\n        while(not ser.empty()){\n            auto p = ser.top(); ser.pop();\n\
    \            res.push_back(p);\n        }\n        return res;\n    }\n    \n\
    \    pair<long,long> subtree_decomp(long v){\n        return {table_index[v],\
    \ table_index[v] + subtree_size[v] - 1};\n    }\n    \nprivate:\n    long root\
    \ = 0;\n    vector<vector<long>> &tree;\n    vector<long> depth;\n    vector<long>\
    \ heavy;\n    vector<long> subtree_size;\n    vector<long> table;\n    vector<long>\
    \ table_index;\n    vector<pair<long,long>> terminal;\n    void calc_depth(long\
    \ vis, long prev){\n        if(prev != -1) depth[vis] = depth[prev] + 1;\n   \
    \     long max_subtree_size = 0;\n        for(auto nex : tree[vis]){\n       \
    \     if(nex == prev) continue;\n            calc_depth(nex, vis);\n         \
    \   subtree_size[vis] += subtree_size[nex];\n            if(subtree_size[nex]\
    \ <= max_subtree_size) continue;\n            max_subtree_size = subtree_size[nex];\n\
    \            heavy[vis] = nex;\n        }\n    }\n    void tour(){\n        stack<long>\
    \ Q; Q.push(root);\n        while(not Q.empty()){\n            long t = Q.top();\
    \ Q.pop();\n            table.push_back(t);\n            table_index[t] = table.size()\
    \ - 1;\n            for(auto nex : tree[t]){\n                if(depth[nex] <\
    \ depth[t]) continue;\n                if(nex == heavy[t]) continue;\n       \
    \         Q.push(nex);\n                terminal[nex] = {nex, t};\n          \
    \  }\n            if(heavy[t] != -1){\n                Q.push(heavy[t]);\n   \
    \             terminal[heavy[t]] = terminal[t];\n            }\n        }\n  \
    \  }\n};\n/**\n * @brief HL\u5206\u89E3\n * @docs docs/Graph/Heavy_Light_Decomposition.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Heavy_Light_Decomposition.cpp
  requiredBy: []
  timestamp: '2022-01-19 22:18:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/Heavy_Light_Decomposition.cpp
layout: document
redirect_from:
- /library/Graph/Heavy_Light_Decomposition.cpp
- /library/Graph/Heavy_Light_Decomposition.cpp.html
title: "HL\u5206\u89E3"
---
## きもち

HL分解だよ。重軽分解とも呼ばれているよ。  
木構造のパスに対するクエリを列構造に対するクエリへと変換できるよ。

## 使い方  
- `Heavy_Light_Decomposition(vector<vector<long>>& tree, long root = 0)`：コンストラクタ。treeに木を、rootに根の頂点番号を代入してください。  
- `vector<long> get_table()`：木をHL分解した列$table$を返す。  
- `long get_pos(long p)`:番号pの頂点の$table$における位置を返す。　　
- `vector<pair<long,long>> path_decomp(long u, long v, bool edge_is_weighted = false)`:与えられた木上のパスを$table$上の閉区間の集合に対応させ、列挙する。  
- `pair<long,long> subtree_decomp`:与えられた頂点を根とする部分木を$table$上の閉区間に対応させ、返す。  

## 計算量

構築:$\mathrm{O}(N)$  
path_decompクエリ:$\mathrm{O}(logN)$  
subtree_decompクエリ:$\mathrm{O}(1)$  

## 補足

上記では説明が不十分なのでここで補足します。  
ユーザーの基本的な利用方法としては、  
①木を与え、get_table()によりHL分解した列を取得する(この時点では列構造は重みではなく頂点番号を持っている。)  
②①で取得した列に重みを持たせる(上書きして良い)  
③データ構造(セグメント木など)に②の列を持たせる。  
④path_decompによりパスに対するクエリを列に対するクエリに変換し、③のデータ構造で解く。  
⑤HAPPY  
以上です。  

## Tips

・全体的な計算量は列に対するクエリにかかる時間に$\mathrm{O}(logN)$がかかったものになるよ。  
・部分木に対するクエリ(「部分木の全ての頂点に対し加算せよ」など)も処理できるよ。この場合計算量は列に対するクエリと変わらないよ。  
・辺に重みがついている場合は端点のうち深い方の頂点の重みとすれば、頂点重みの問題に帰着できるよ。  
・可換性を仮定せずに実装したので、閉区間[L, R]において、L > R となることがあるよ。これは、  
　・演算が可換なときは取得した閉区間を適宜swapする。  
　・演算が非可換なときはあらかじめreverseした列に対するデータ構造も持っておき、[N - L - 1, N - R - 1]として解く。  
 ことで解決できるよ。
