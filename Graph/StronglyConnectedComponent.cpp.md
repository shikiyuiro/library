---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/StronglyConnectedComponent.cpp\"\nclass StronglyConnectedComponent{\n\
    private:\n    long Gsize;\n    vector<bool> visited;\n    vector<vector<long>>\
    \ forward;\n    vector<vector<long>> backward;\n    stack<long> bfs_seed;\n  \
    \  \n    void dfs(){\n        fill(visited.begin(), visited.end(), false);\n \
    \       for(long i = 0; i < Gsize; i++){\n            dfs_rec(i);\n        }\n\
    \    }\n    \n    void dfs_rec(long i){\n        if(visited[i]) return;\n    \
    \    visited[i] = true;\n        for(auto e : forward[i]){\n            dfs_rec(e);\n\
    \        }\n        bfs_seed.push(i);\n    }\n    \n    void bfs(){\n        fill(visited.begin(),\
    \ visited.end(), false);\n        queue<long> bfs;\n        while(not bfs_seed.empty()){\n\
    \            long t = bfs_seed.top(); bfs_seed.pop();\n            if(visited[t])\
    \ continue;\n            bfs.push(t);\n            vector<long> result_seed;\n\
    \            while(not bfs.empty()){\n                long f = bfs.front(); bfs.pop();\n\
    \                if(visited[f]) continue;\n                visited[f] = true;\n\
    \                for(auto e : backward[f]){\n                    bfs.push(e);\n\
    \                }\n                result_seed.push_back(f);\n            }\n\
    \            result.push_back(result_seed);\n        }\n    }\n    \npublic:\n\
    \    vector<vector<long>> result;\n    \n    StronglyConnectedComponent(vector<vector<long>>\
    \ &graph) : forward(graph){\n        Gsize = graph.size();\n        visited.resize(Gsize);\n\
    \        backward.resize(Gsize);\n        for(long e = 0; e < Gsize; e++) for(auto\
    \ f : graph[e]) backward[f].push_back(e);\n        dfs();\n        bfs();\n  \
    \  }\n};\n"
  code: "class StronglyConnectedComponent{\nprivate:\n    long Gsize;\n    vector<bool>\
    \ visited;\n    vector<vector<long>> forward;\n    vector<vector<long>> backward;\n\
    \    stack<long> bfs_seed;\n    \n    void dfs(){\n        fill(visited.begin(),\
    \ visited.end(), false);\n        for(long i = 0; i < Gsize; i++){\n         \
    \   dfs_rec(i);\n        }\n    }\n    \n    void dfs_rec(long i){\n        if(visited[i])\
    \ return;\n        visited[i] = true;\n        for(auto e : forward[i]){\n   \
    \         dfs_rec(e);\n        }\n        bfs_seed.push(i);\n    }\n    \n   \
    \ void bfs(){\n        fill(visited.begin(), visited.end(), false);\n        queue<long>\
    \ bfs;\n        while(not bfs_seed.empty()){\n            long t = bfs_seed.top();\
    \ bfs_seed.pop();\n            if(visited[t]) continue;\n            bfs.push(t);\n\
    \            vector<long> result_seed;\n            while(not bfs.empty()){\n\
    \                long f = bfs.front(); bfs.pop();\n                if(visited[f])\
    \ continue;\n                visited[f] = true;\n                for(auto e :\
    \ backward[f]){\n                    bfs.push(e);\n                }\n       \
    \         result_seed.push_back(f);\n            }\n            result.push_back(result_seed);\n\
    \        }\n    }\n    \npublic:\n    vector<vector<long>> result;\n    \n   \
    \ StronglyConnectedComponent(vector<vector<long>> &graph) : forward(graph){\n\
    \        Gsize = graph.size();\n        visited.resize(Gsize);\n        backward.resize(Gsize);\n\
    \        for(long e = 0; e < Gsize; e++) for(auto f : graph[e]) backward[f].push_back(e);\n\
    \        dfs();\n        bfs();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/StronglyConnectedComponent.cpp
  requiredBy: []
  timestamp: '2021-11-13 18:51:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/StronglyConnectedComponent.cpp
layout: document
redirect_from:
- /library/Graph/StronglyConnectedComponent.cpp
- /library/Graph/StronglyConnectedComponent.cpp.html
title: Graph/StronglyConnectedComponent.cpp
---
