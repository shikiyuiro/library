---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: DataStructure/UnionFind_PartiallyPersistent.cpp
    title: "\u90E8\u5206\u6C38\u7D9AUnionFind"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind_PartiallyPersistent.cpp\"\nclass\
    \ PPUF{\npublic:\n    PPUF(long size){\n        Parent.resize(size); iota(Parent.begin(),\
    \ Parent.end(), 0);\n        Size.resize(size, 1);\n        history.resize(size);\
    \ for(auto &s : history) s.push_back({LONG_MIN, 1});\n        United.resize(size,\
    \ LONG_MAX);\n    }\n    long find(long u, long t){ return (United[u] > t) ? u:\
    \ find(Parent[u], t); }//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u6839\u3092\u6C42\
    \u3081\u308B\u3002\n    bool unite(long u, long v, long t){\n        //t\u306F\
    unite\u30AF\u30A8\u30EA\u3054\u3068\u306B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u304C\u3001\u9023\u7D9A\u3059\
    \u308B\u5024\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n        long\
    \ fu = find(u), fv = find(v);\n        if(fu == fv) return false;\n        if(Size[fu]\
    \ < Size[fv]){ swap(u, v); swap(fu, fv);}\n        Parent[fv] = fu;\n        Size[fu]\
    \ += Size[fv];\n        history[fu].push_back({t, Size[fu]});\n        United[fv]\
    \ = t;\n        return true;\n    }\n    bool same(long u, long v, long t){//\u6642\
    \u523Bt\u76F4\u5F8C\u306Bu\u3068v\u304C\u9023\u7D50\u3067\u3042\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\u3002\n        return find(u, t) == find(v, t);\n    }\n  \
    \  long size(long u, long t){//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u9023\u7D50\
    \u6210\u5206\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\u308B\u3002\n        long\
    \ fu = find(u, t);\n        return prev(upper_bound(history[fu].begin(), history[fu].end(),\
    \ pair<long,long>({t, LONG_MAX})))->second;\n    }\n    explicit PPUF() = default;\n\
    private:\n    vector<long> Parent;\n    vector<long> Size;\n    vector<vector<pair<long,long>>>\
    \ history;//unite\u76F4\u5F8C\u306E\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \u3092\u4FDD\u5B58\u3059\u308B\n    vector<long> United;//\u4F55\u56DE\u76EE\u306E\
    \u7D50\u5408\u3067\u6839\u3067\u306F\u306A\u304F\u306A\u308B\u304B\u3000\u30FC\
    \uFF1E \u305D\u306E\u5024\u4EE5\u4E0B\u306E\u6642\u523B\u3067\u3042\u308C\u3070\
    \u305D\u306E\u9802\u70B9\u306F\u6839\u3001\u305D\u3046\u3067\u306A\u304B\u3063\
    \u305F\u3089Parent\u3092\u305F\u3069\u308C\u3070\u3088\u3044\u3002\n    long find(long\
    \ u){ return (Parent[u] == u) ? u: find(Parent[u]); }\n};\n/**\n * @brief \u90E8\
    \u5206\u6C38\u7D9AUnionFind\n * @docs docs/DataStructure/UnionFind_PartiallyPersistent.md\n\
    \ */\n#line 2 \"DataStructure/MergeTree.cpp\"\n\nclass MergeTree{\n    //Union-Find\u306E\
    \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\u3002  \n    //\u300C\u6642\
    \u523Bt\u306B\u304A\u3051\u308B\u8981\u7D20u\u306E\u9023\u7D50\u6210\u5206\u300D\
    \u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u3092\u5217\u30AF\u30A8\u30EA\u306B\
    \u5E30\u7740\u3067\u304D\u308B\u3002  \n    //\u767A\u60F3\u306FHL\u5206\u89E3\
    \u306E\u90E8\u5206\u6728\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\u306B\u8FD1\
    \u3044\u3002\npublic:\n    MergeTree(long siz, vector<tuple<long,long,long>> merge){\n\
    \        uni = PPUF(siz);\n        forest.resize(siz);\n        pos.resize(siz);\n\
    \        for(auto [u, v, t] : merge){\n            long fu = uni.find(u, t), fv\
    \ = uni.find(v, t);\n            if(uni.unite(fu, fv, t)){\n                forest[fu].push_back(fv);\n\
    \                forest[fv].push_back(fu);\n            }\n        }\n       \
    \ vector<bool> visited(siz, false);\n        for(long v = 0; v < siz; v++){\n\
    \            if(visited[v]) continue;\n            long fv = uni.find(v, INT_MAX);\n\
    \            auto dfs = [&](auto &&self, long vis, long prev) -> void {\n    \
    \            visited[vis] = true;\n                tour.push_back(vis);\n    \
    \            pos[vis] = tour.size() - 1;\n                for(auto e : forest[vis])\
    \ if(e != prev) self(self, e, vis);\n            };\n            dfs(dfs, fv,\
    \ -1);\n        }\n    }\n    vector<long> get_tour(){\n        return tour;\n\
    \    }\n    pair<long,long> get_range(long u, long t){\n        long L = pos[uni.find(u,\
    \ t)];\n        return {L, L + uni.size(u, t)};\n    }\nprivate:\n    vector<vector<long>>\
    \ forest;\n    vector<long> tour;\n    vector<long> pos;\n    PPUF uni;\n};\n"
  code: "#include \"../DataStructure/UnionFind_PartiallyPersistent.cpp\"\n\nclass\
    \ MergeTree{\n    //Union-Find\u306E\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\
    \u3059\u6728\u3002  \n    //\u300C\u6642\u523Bt\u306B\u304A\u3051\u308B\u8981\u7D20\
    u\u306E\u9023\u7D50\u6210\u5206\u300D\u306B\u5BFE\u3059\u308B\u30AF\u30A8\u30EA\
    \u3092\u5217\u30AF\u30A8\u30EA\u306B\u5E30\u7740\u3067\u304D\u308B\u3002  \n \
    \   //\u767A\u60F3\u306FHL\u5206\u89E3\u306E\u90E8\u5206\u6728\u306B\u5BFE\u3059\
    \u308B\u30AF\u30A8\u30EA\u306B\u8FD1\u3044\u3002\npublic:\n    MergeTree(long\
    \ siz, vector<tuple<long,long,long>> merge){\n        uni = PPUF(siz);\n     \
    \   forest.resize(siz);\n        pos.resize(siz);\n        for(auto [u, v, t]\
    \ : merge){\n            long fu = uni.find(u, t), fv = uni.find(v, t);\n    \
    \        if(uni.unite(fu, fv, t)){\n                forest[fu].push_back(fv);\n\
    \                forest[fv].push_back(fu);\n            }\n        }\n       \
    \ vector<bool> visited(siz, false);\n        for(long v = 0; v < siz; v++){\n\
    \            if(visited[v]) continue;\n            long fv = uni.find(v, INT_MAX);\n\
    \            auto dfs = [&](auto &&self, long vis, long prev) -> void {\n    \
    \            visited[vis] = true;\n                tour.push_back(vis);\n    \
    \            pos[vis] = tour.size() - 1;\n                for(auto e : forest[vis])\
    \ if(e != prev) self(self, e, vis);\n            };\n            dfs(dfs, fv,\
    \ -1);\n        }\n    }\n    vector<long> get_tour(){\n        return tour;\n\
    \    }\n    pair<long,long> get_range(long u, long t){\n        long L = pos[uni.find(u,\
    \ t)];\n        return {L, L + uni.size(u, t)};\n    }\nprivate:\n    vector<vector<long>>\
    \ forest;\n    vector<long> tour;\n    vector<long> pos;\n    PPUF uni;\n};\n"
  dependsOn:
  - DataStructure/UnionFind_PartiallyPersistent.cpp
  isVerificationFile: false
  path: DataStructure/MergeTree.cpp
  requiredBy: []
  timestamp: '2022-01-28 15:07:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/MergeTree.cpp
layout: document
redirect_from:
- /library/DataStructure/MergeTree.cpp
- /library/DataStructure/MergeTree.cpp.html
title: DataStructure/MergeTree.cpp
---
