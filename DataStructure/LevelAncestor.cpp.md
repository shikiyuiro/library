---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/LevelAncestor.test.cpp
    title: verify/LevelAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/LevelAncestor.md
    document_title: "Level Ancestor( \u69CB\u7BC9$\\mathrm{O}(NlogN)$\u30FB\u30AF\u30A8\
      \u30EA$\\mathrm{O}(1)$ )"
    links: []
  bundledCode: "#line 1 \"DataStructure/LevelAncestor.cpp\"\nclass LevelAncestor{\n\
    \    using i32 = int32_t;\npublic:\n    explicit LevelAncestor() = default;\n\
    \    LevelAncestor(vector<vector<i32>> &_tree, i32 root) : tree(&_tree){\n   \
    \     depth.resize(_tree.size());\n        height.resize(_tree.size());\n    \
    \    jump.resize(_tree.size());\n        Lpath.resize(_tree.size());\n       \
    \ Lpath_root.resize(_tree.size());\n        jump[root].push_back(-1);\n      \
    \  calc_H(root, -1, 0);\n        make_Lpath(root, root);\n    }\n    i32 query(i32\
    \ V, i32 D){\n        if(depth[V] < D) return -1;\n        if(depth[V] == D) return\
    \ V;\n        i32 jmp_idx = 32 - __builtin_clz(depth[V] - D) - 1;\n        V =\
    \ jump[V][jmp_idx];\n        i32 R = Lpath_root[V];\n        return Lpath[R][depth[Lpath[R][0]]\
    \ - D];\n    }\n    i32 get_depth(i32 V){\n        return depth[V];\n    }\n \
    \   i32 get_height(i32 V){\n        return height[V];\n    }\nprivate:\n    vector<i32>\
    \ depth;\n    vector<i32> height;\n    vector<vector<i32>> *tree;\n    vector<vector<i32>>\
    \ jump;\n    vector<i32> offline;\n    vector<vector<i32>> Lpath;\n    vector<i32>\
    \ Lpath_root;\n    i32 calc_H(i32 vis, i32 prv, i32 D){\n        offline.push_back(vis);\n\
    \        for(i32 b = 1; b <= D; b <<= 1) jump[vis].push_back(offline[D - b]);\n\
    \        i32 H = 0;\n        depth[vis] = D;\n        for(auto nxt : tree->at(vis)){\n\
    \            if(nxt == prv) continue;\n            H = max(H, calc_H(nxt, vis,\
    \ D+1) + 1);\n        }\n        height[vis] = H;\n        offline.pop_back();\n\
    \        return H;\n    }\n    void make_Lpath(i32 vis, i32 root){\n        Lpath_root[vis]\
    \ = root;\n        i32 L_nxt = -1;\n        for(auto nxt : tree->at(vis)) if(height[nxt]+1\
    \ == height[vis]) L_nxt = nxt;\n        for(auto nxt : tree->at(vis)){\n     \
    \       if(depth[nxt] != depth[vis]+1) continue;\n            if(nxt == L_nxt)\
    \ make_Lpath(nxt, root);\n            else make_Lpath(nxt, nxt);\n        }\n\
    \        Lpath[root].push_back(vis);\n        if(vis == root){\n            i32\
    \ ladder_size = (i32)Lpath.size();\n            i32 parent = jump[vis][0];\n \
    \           while(parent != -1 and ladder_size--){\n                Lpath[root].push_back(parent);\n\
    \                parent = jump[parent][0];\n            }\n        }\n    }\n\
    };\n/**\n * @brief Level Ancestor( \u69CB\u7BC9$\\mathrm{O}(NlogN)$\u30FB\u30AF\
    \u30A8\u30EA$\\mathrm{O}(1)$ )\n * @docs docs/DataStructure/LevelAncestor.md\n\
    \ */\n"
  code: "class LevelAncestor{\n    using i32 = int32_t;\npublic:\n    explicit LevelAncestor()\
    \ = default;\n    LevelAncestor(vector<vector<i32>> &_tree, i32 root) : tree(&_tree){\n\
    \        depth.resize(_tree.size());\n        height.resize(_tree.size());\n \
    \       jump.resize(_tree.size());\n        Lpath.resize(_tree.size());\n    \
    \    Lpath_root.resize(_tree.size());\n        jump[root].push_back(-1);\n   \
    \     calc_H(root, -1, 0);\n        make_Lpath(root, root);\n    }\n    i32 query(i32\
    \ V, i32 D){\n        if(depth[V] < D) return -1;\n        if(depth[V] == D) return\
    \ V;\n        i32 jmp_idx = 32 - __builtin_clz(depth[V] - D) - 1;\n        V =\
    \ jump[V][jmp_idx];\n        i32 R = Lpath_root[V];\n        return Lpath[R][depth[Lpath[R][0]]\
    \ - D];\n    }\n    i32 get_depth(i32 V){\n        return depth[V];\n    }\n \
    \   i32 get_height(i32 V){\n        return height[V];\n    }\nprivate:\n    vector<i32>\
    \ depth;\n    vector<i32> height;\n    vector<vector<i32>> *tree;\n    vector<vector<i32>>\
    \ jump;\n    vector<i32> offline;\n    vector<vector<i32>> Lpath;\n    vector<i32>\
    \ Lpath_root;\n    i32 calc_H(i32 vis, i32 prv, i32 D){\n        offline.push_back(vis);\n\
    \        for(i32 b = 1; b <= D; b <<= 1) jump[vis].push_back(offline[D - b]);\n\
    \        i32 H = 0;\n        depth[vis] = D;\n        for(auto nxt : tree->at(vis)){\n\
    \            if(nxt == prv) continue;\n            H = max(H, calc_H(nxt, vis,\
    \ D+1) + 1);\n        }\n        height[vis] = H;\n        offline.pop_back();\n\
    \        return H;\n    }\n    void make_Lpath(i32 vis, i32 root){\n        Lpath_root[vis]\
    \ = root;\n        i32 L_nxt = -1;\n        for(auto nxt : tree->at(vis)) if(height[nxt]+1\
    \ == height[vis]) L_nxt = nxt;\n        for(auto nxt : tree->at(vis)){\n     \
    \       if(depth[nxt] != depth[vis]+1) continue;\n            if(nxt == L_nxt)\
    \ make_Lpath(nxt, root);\n            else make_Lpath(nxt, nxt);\n        }\n\
    \        Lpath[root].push_back(vis);\n        if(vis == root){\n            i32\
    \ ladder_size = (i32)Lpath.size();\n            i32 parent = jump[vis][0];\n \
    \           while(parent != -1 and ladder_size--){\n                Lpath[root].push_back(parent);\n\
    \                parent = jump[parent][0];\n            }\n        }\n    }\n\
    };\n/**\n * @brief Level Ancestor( \u69CB\u7BC9$\\mathrm{O}(NlogN)$\u30FB\u30AF\
    \u30A8\u30EA$\\mathrm{O}(1)$ )\n * @docs docs/DataStructure/LevelAncestor.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LevelAncestor.cpp
  requiredBy: []
  timestamp: '2022-04-07 12:47:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/LevelAncestor.test.cpp
documentation_of: DataStructure/LevelAncestor.cpp
layout: document
redirect_from:
- /library/DataStructure/LevelAncestor.cpp
- /library/DataStructure/LevelAncestor.cpp.html
title: "Level Ancestor( \u69CB\u7BC9$\\mathrm{O}(NlogN)$\u30FB\u30AF\u30A8\u30EA$\\\
  mathrm{O}(1)$ )"
---
## 使い方  
- `LevelAncestor(vector<vector<i32>> &_tree, i32 root)`：rootを根とする木_treeをもとにデータ構造を構築する。  
- `i32 query(i32 V, i32 D)`：頂点Vの祖先であり、深さがDである頂点の番号を返す。  
- `i32 get_depth(i32 V)`：頂点Vの深さを返す。  
- `i32 get_height(i32 V)`：頂点Vの高さを返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/84950" target="_blank">yosupo judge - Lowest Common Ancestor</a>

## 参考文献
<a href="https://37zigen.com/level-ancestor-problem/" target="_blank">Level Ancestor Problem - 37zigenのHP(37zigenさんの記事)</a>
