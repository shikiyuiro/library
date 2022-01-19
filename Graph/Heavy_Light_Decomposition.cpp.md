---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Graph/LowestCommonAncestor.md
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
    \  }\n};\n/**\n * @brief HL\u5206\u89E3\n * @docs docs/Graph/LowestCommonAncestor.md\n\
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
    \  }\n};\n/**\n * @brief HL\u5206\u89E3\n * @docs docs/Graph/LowestCommonAncestor.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/Heavy_Light_Decomposition.cpp
  requiredBy: []
  timestamp: '2022-01-19 21:36:56+09:00'
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

最小共通祖先です。あとでかきます。  

## 使い方  
- `LowestCommonAncestor(vector<vector<long>>& tree, long root)`：コンストラクタ。treeに木を、rootに根の頂点番号を代入してください。  
- `long query(long l, long r)`：頂点番号lと頂点番号rの最小共通祖先を求め、その頂点番号を返します。  

## 計算量

構築:$\mathrm{O}(NlogN)$  
クエリ:$\mathrm{O}(1)$  

## Tips

構築$\mathrm{O}(N)$,クエリ$\mathrm{O}(1)$のアルゴリズムがあるらしいです。精進します。  
