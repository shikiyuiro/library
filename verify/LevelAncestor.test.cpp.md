---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LevelAncestor.cpp
    title: "Level Ancestor( \u69CB\u7BC9$\\mathrm{O}(NlogN)$\u30FB\u30AF\u30A8\u30EA\
      $\\mathrm{O}(1)$ )"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/LevelAncestor.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"DataStructure/LevelAncestor.cpp\"\nclass LevelAncestor{\n    using\
    \ i32 = int32_t;\npublic:\n    explicit LevelAncestor() = default;\n    LevelAncestor(vector<vector<i32>>\
    \ &_tree, i32 root) : tree(&_tree){\n        depth.resize(_tree.size());\n   \
    \     height.resize(_tree.size());\n        jump.resize(_tree.size());\n     \
    \   Lpath.resize(_tree.size());\n        Lpath_root.resize(_tree.size());\n  \
    \      jump[root].push_back(-1);\n        calc_H(root, -1, 0);\n        make_Lpath(root,\
    \ root);\n    }\n    i32 query(i32 V, i32 D){\n        if(depth[V] < D) return\
    \ -1;\n        if(depth[V] == D) return V;\n        i32 jmp_idx = 32 - __builtin_clz(depth[V]\
    \ - D) - 1;\n        V = jump[V][jmp_idx];\n        i32 R = Lpath_root[V];\n \
    \       return Lpath[R][depth[Lpath[R][0]] - D];\n    }\n    i32 get_depth(i32\
    \ V){\n        return depth[V];\n    }\n    i32 get_height(i32 V){\n        return\
    \ height[V];\n    }\nprivate:\n    vector<i32> depth;\n    vector<i32> height;\n\
    \    vector<vector<i32>> *tree;\n    vector<vector<i32>> jump;\n    vector<i32>\
    \ offline;\n    vector<vector<i32>> Lpath;\n    vector<i32> Lpath_root;\n    i32\
    \ calc_H(i32 vis, i32 prv, i32 D){\n        offline.push_back(vis);\n        for(i32\
    \ b = 1; b <= D; b <<= 1) jump[vis].push_back(offline[D - b]);\n        i32 H\
    \ = 0;\n        depth[vis] = D;\n        for(auto nxt : tree->at(vis)){\n    \
    \        if(nxt == prv) continue;\n            H = max(H, calc_H(nxt, vis, D+1)\
    \ + 1);\n        }\n        height[vis] = H;\n        offline.pop_back();\n  \
    \      return H;\n    }\n    void make_Lpath(i32 vis, i32 root){\n        Lpath_root[vis]\
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
    \ */\n#line 5 \"verify/LevelAncestor.test.cpp\"\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    vector<vector<int>> tree(N);\n    for(int i\
    \ = 1; i < N; i++){\n        int p; cin >> p;\n        tree[p].push_back(i);\n\
    \    }\n    LevelAncestor LA(tree, 0);\n    while(Q--){\n        int u, v; cin\
    \ >> u >> v;\n        if(LA.get_depth(u) > LA.get_depth(v)) swap(u, v);\n    \
    \    v = LA.query(v, LA.get_depth(u));\n        if(u == v) cout << u << '\\n';\n\
    \        else{\n            int pass = 0;\n            int fail = LA.get_depth(u);\n\
    \            while(fail - pass > 1){\n                int mid = pass + (fail -\
    \ pass) / 2;\n                (LA.query(u, mid) == LA.query(v, mid) ? pass : fail)\
    \ = mid;\n            }\n            cout << LA.query(u, pass) << '\\n';\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../template/template.cpp\"\
    \n#include \"../DataStructure/LevelAncestor.cpp\"\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int N, Q; cin >> N >> Q;\n    vector<vector<int>> tree(N);\n    for(int i\
    \ = 1; i < N; i++){\n        int p; cin >> p;\n        tree[p].push_back(i);\n\
    \    }\n    LevelAncestor LA(tree, 0);\n    while(Q--){\n        int u, v; cin\
    \ >> u >> v;\n        if(LA.get_depth(u) > LA.get_depth(v)) swap(u, v);\n    \
    \    v = LA.query(v, LA.get_depth(u));\n        if(u == v) cout << u << '\\n';\n\
    \        else{\n            int pass = 0;\n            int fail = LA.get_depth(u);\n\
    \            while(fail - pass > 1){\n                int mid = pass + (fail -\
    \ pass) / 2;\n                (LA.query(u, mid) == LA.query(v, mid) ? pass : fail)\
    \ = mid;\n            }\n            cout << LA.query(u, pass) << '\\n';\n   \
    \     }\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/LevelAncestor.cpp
  isVerificationFile: true
  path: verify/LevelAncestor.test.cpp
  requiredBy: []
  timestamp: '2022-04-07 12:52:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LevelAncestor.test.cpp
layout: document
redirect_from:
- /verify/verify/LevelAncestor.test.cpp
- /verify/verify/LevelAncestor.test.cpp.html
title: verify/LevelAncestor.test.cpp
---
