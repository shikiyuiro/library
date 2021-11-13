---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/StronglyConnectedComponent.cpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/verify/StronglyConnectedComponent.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 4 \"test/verify/StronglyConnectedComponent.test.cpp\"\
    \n\n#line 1 \"Graph/StronglyConnectedComponent.cpp\"\nclass StronglyConnectedComponent{\n\
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
    \  }\n};\n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @docs\
    \ docs/Graph/StronglyConnectedComponent.md\n */\n#line 6 \"test/verify/StronglyConnectedComponent.test.cpp\"\
    \n\nint main(){\n    long N, M; cin >> N >> M;\n    vector<vector<long>> graph(N);\n\
    \    while(M--){\n        long a, b; cin >> a >> b;\n        graph[a].push_back(b);\n\
    \    }\n    \n    StronglyConnectedComponent scc(graph);\n    auto res = scc.result;\n\
    \    cout << res.size() << endl;\n    for(auto e : res){\n        cout << e.size()\
    \ << \" \";\n        for(auto f : e) cout << f << \" \";\n        cout << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../Graph/StronglyConnectedComponent.cpp\"\n\nint main(){\n \
    \   long N, M; cin >> N >> M;\n    vector<vector<long>> graph(N);\n    while(M--){\n\
    \        long a, b; cin >> a >> b;\n        graph[a].push_back(b);\n    }\n  \
    \  \n    StronglyConnectedComponent scc(graph);\n    auto res = scc.result;\n\
    \    cout << res.size() << endl;\n    for(auto e : res){\n        cout << e.size()\
    \ << \" \";\n        for(auto f : e) cout << f << \" \";\n        cout << endl;\n\
    \    }\n}\n"
  dependsOn:
  - template/template.cpp
  - Graph/StronglyConnectedComponent.cpp
  isVerificationFile: true
  path: test/verify/StronglyConnectedComponent.test.cpp
  requiredBy: []
  timestamp: '2021-11-13 20:00:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/StronglyConnectedComponent.test.cpp
layout: document
redirect_from:
- /verify/test/verify/StronglyConnectedComponent.test.cpp
- /verify/test/verify/StronglyConnectedComponent.test.cpp.html
title: test/verify/StronglyConnectedComponent.test.cpp
---
