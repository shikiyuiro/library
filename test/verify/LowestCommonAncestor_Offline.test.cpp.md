---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/LowestCommonAncestor_Offline.cpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\u7956\u5148"
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
  bundledCode: "#line 1 \"test/verify/LowestCommonAncestor_Offline.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n/**\n * @brief \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n */\n#line 4 \"test/verify/LowestCommonAncestor_Offline.test.cpp\"\
    \n\n#line 1 \"Graph/LowestCommonAncestor_Offline.cpp\"\nclass OffLCA{\npublic:\n\
    \    OffLCA(vector<vector<long>> &tree, long root, vector<tuple<long,long,long>>\
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
    \    };\n};\n/**\n * @brief \u30AA\u30D5\u30E9\u30A4\u30F3\u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n * @docs docs/Graph/LowestCommonAncestor_Offline.md\n */\n#line\
    \ 6 \"test/verify/LowestCommonAncestor_Offline.test.cpp\"\n\nint main(){\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    long N, Q; cin >> N\
    \ >> Q;\n    vector<vector<long>> tree(N);\n    for(long i = 1; i < N; i++){\n\
    \        long p; cin >> p;\n        tree[p].push_back(i);\n    }\n    vector<tuple<long,long,long>>\
    \ query;\n    while(Q--){\n        long u, v; cin >> u >> v;\n        query.push_back({u,\
    \ v, 0});\n    }\n    OffLCA olca(tree, 0, query);\n    for(auto [f, s, t] : query)\
    \ cout << t << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../Graph/LowestCommonAncestor_Offline.cpp\"\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    long N, Q; cin >>\
    \ N >> Q;\n    vector<vector<long>> tree(N);\n    for(long i = 1; i < N; i++){\n\
    \        long p; cin >> p;\n        tree[p].push_back(i);\n    }\n    vector<tuple<long,long,long>>\
    \ query;\n    while(Q--){\n        long u, v; cin >> u >> v;\n        query.push_back({u,\
    \ v, 0});\n    }\n    OffLCA olca(tree, 0, query);\n    for(auto [f, s, t] : query)\
    \ cout << t << '\\n';\n}\n"
  dependsOn:
  - template/template.cpp
  - Graph/LowestCommonAncestor_Offline.cpp
  isVerificationFile: true
  path: test/verify/LowestCommonAncestor_Offline.test.cpp
  requiredBy: []
  timestamp: '2022-01-29 15:14:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/LowestCommonAncestor_Offline.test.cpp
layout: document
redirect_from:
- /verify/test/verify/LowestCommonAncestor_Offline.test.cpp
- /verify/test/verify/LowestCommonAncestor_Offline.test.cpp.html
title: test/verify/LowestCommonAncestor_Offline.test.cpp
---
