---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  - icon: ':heavy_check_mark:'
    path: Graph/LowestCommonAncestor.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
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
  bundledCode: "#line 1 \"test/verify/LowestCommonAncestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n/**\n * @brief \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n */\n#line 4 \"test/verify/LowestCommonAncestor.test.cpp\"\
    \n\n#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate < typename elm >\nclass\
    \ SparseTable{\npublic:\n    explicit SparseTable() = default;\n    \n    SparseTable(vector<elm>&\
    \ v, elm e, function<elm(elm, elm)> op) : op(op){\n        long isiz = v.size();\n\
    \        long jsiz = 0;\n        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz,\
    \ vector<elm>(jsiz, e));\n        for(long i = 0; i < isiz; i++)table[i][0] =\
    \ v[i];\n        for(long j = 1; j < jsiz; j++){\n            for(long i = 0;\
    \ i + (1 << (j - 1)) < isiz; i++){\n                table[i][j] = op(table[i][j\
    \ - 1], table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n       \
    \ cf.resize(isiz + 1);\n        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >>\
    \ 1] + 1;\n    }\n    \n    elm query(long L, long R/*[L, R)*/){\n        assert(L\
    \ < R);\n        long b = cf[R - L];\n        return op(table[L][b], table[R -\
    \ (1 << b)][b]);\n    }\nprivate:\n    function<elm(elm, elm)> op;\n    vector<vector<elm>>\
    \ table;\n    vector<long> cf;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\
    \u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n#line 2 \"\
    Graph/LowestCommonAncestor.cpp\"\n\nclass LowestCommonAncestor{\npublic:\n   \
    \ LowestCommonAncestor(vector<vector<long>> &tree, long root) : tree(tree){\n\
    \        ETpos.resize(tree.size(), -1);\n        dfs(root, 0);\n        st = SparseTable<long>(EularTour,\
    \ LONG_MAX, [](long a, long b){return min(a, b);});\n    }\n    \n    long query(long\
    \ L, long R){\n        if(ETpos[L] > ETpos[R]) swap(L, R);\n        return st.query(ETpos[L],\
    \ ETpos[R] + 1) % tree.size();\n    }\n    \nprivate:\n    vector<vector<long>>\
    \ tree;\n    vector<long> EularTour;\n    vector<long> ETpos;\n    long ETsize\
    \ = 0;\n    SparseTable<long> st;\n    \n    void dfs(long vis, long depth){\n\
    \        EularTour.push_back(depth * tree.size() + vis);\n        ETpos[vis] =\
    \ ETsize++;\n        for(auto e : tree[vis]) if(ETpos[e] == -1) {dfs(e, depth\
    \ + 1); EularTour.push_back(depth * tree.size() + vis); ETsize++;}\n    }\n};\n\
    /**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\n * @docs docs/Graph/LowestCommonAncestor.md\n\
    \ */\n#line 6 \"test/verify/LowestCommonAncestor.test.cpp\"\n\nint main(){\n \
    \   long N, Q; cin >> N >> Q;\n    vector<vector<long>> tree(N);\n    for(long\
    \ i = 1; i <= N - 1; i++){\n        long p; cin >> p;\n        tree[i].push_back(p);\n\
    \        tree[p].push_back(i);\n    }\n    \n    LowestCommonAncestor lca(tree,\
    \ 0);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../template/template.cpp\"\
    \n\n#include \"../../Graph/LowestCommonAncestor.cpp\"\n\nint main(){\n    long\
    \ N, Q; cin >> N >> Q;\n    vector<vector<long>> tree(N);\n    for(long i = 1;\
    \ i <= N - 1; i++){\n        long p; cin >> p;\n        tree[i].push_back(p);\n\
    \        tree[p].push_back(i);\n    }\n    \n    LowestCommonAncestor lca(tree,\
    \ 0);\n    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << lca.query(u,\
    \ v) << endl;\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - Graph/LowestCommonAncestor.cpp
  - DataStructure/SparseTable.cpp
  isVerificationFile: true
  path: test/verify/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2021-12-22 19:48:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/verify/LowestCommonAncestor.test.cpp
- /verify/test/verify/LowestCommonAncestor.test.cpp.html
title: test/verify/LowestCommonAncestor.test.cpp
---
