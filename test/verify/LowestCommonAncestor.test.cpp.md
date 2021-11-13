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
    title: template/template.cpp
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
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 4 \"test/verify/LowestCommonAncestor.test.cpp\"\
    \n\n#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate < typename Element = long\
    \ >\nclass SparseTable{\npublic:\n    function<Element(Element, Element)> operation;\n\
    \    vector<vector<Element>> table;\n    vector<long> cf;\n    \n    SparseTable(vector<Element>&\
    \ v, Element e, function<Element(Element, Element)> operation) : operation(operation){\n\
    \        long isiz = v.size();\n        long jsiz = 0;\n        while((1 << jsiz)\
    \ <= isiz) jsiz++;\n        table.resize(isiz, vector<Element>(jsiz, e));\n  \
    \      for(long i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long j =\
    \ 1; j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){\n\
    \                table[i][j] = operation(table[i][j - 1], table[i + (1 << (j -\
    \ 1))][j - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n    \
    \    for(long i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n  \
    \  Element query(long l, long r/*\u534A\u958B\u533A\u9593*/){\n        assert(l\
    \ < r);\n        long b = cf[r - l];\n        return operation(table[l][b], table[r\
    \ - (1 << b)][b]);\n    }\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\
    \u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n */\n#line 2 \"Graph/LowestCommonAncestor.cpp\"\
    \n\nclass LowestCommonAncestor{\nprivate:\n    long N;\n    vector<bool> visited;\n\
    \    vector<vector<long> > Tree;\n    vector<vector<long> > STtable;\n    vector<long>\
    \ STcf;\n    \n    void make_EularTour(long vis){\n        EularTour.push_back(depth[vis]\
    \ * N + vis);\n        visited[vis] = true;\n        for(auto e : Tree[vis]){\n\
    \            if(visited[e]) continue;\n            depth[e] = depth[vis] + 1;\n\
    \            make_EularTour(e);\n            EularTour.push_back(depth[vis] *\
    \ N + vis);\n        }\n    }\n    \n    void make_SparseTable(){\n        SparseTable<long>\
    \ st(EularTour, LONG_MAX, [](long a, long b){return min(a, b);});\n        STtable\
    \ = st.table;\n        STcf = st.cf;\n    }\n    \n    void make_first(){\n  \
    \      long index = 0;\n        for(auto e : EularTour){\n            first_index[e\
    \ % N] = min(first_index[e % N], index);\n            index++;\n        }\n  \
    \  }\npublic:\n    vector<long> depth;\n    vector<long> EularTour;\n    vector<long>\
    \ first_index;\n    \n    LowestCommonAncestor(vector<vector<long>>& tree, long\
    \ root) : Tree(tree){\n        N = Tree.size();\n        visited.resize(N, false);\n\
    \        depth.resize(N, 0);\n        first_index.resize(N, INT_MAX);\n      \
    \  make_EularTour(root);\n        make_SparseTable();\n        make_first();\n\
    \    }\n    \n    long query(long l, long r){\n        long ltmp = l, rtmp = r;\n\
    \        l = min(first_index[ltmp], first_index[rtmp]); r = max(first_index[ltmp],\
    \ first_index[rtmp]) + 1;\n        long b = STcf[r - l];\n        return min(STtable[l][b],\
    \ STtable[r - (1 << b)][b]) % N;\n    }\n};\n/**\n * @brief \u6700\u5C0F\u5171\
    \u901A\u7956\u5148\n * @docs docs/Graph/LowestCommonAncestor.md\n */\n#line 6\
    \ \"test/verify/LowestCommonAncestor.test.cpp\"\n\nint main(){\n    long N, Q;\
    \ cin >> N >> Q;\n    vector<vector<long>> tree(N);\n    for(long i = 1; i <=\
    \ N - 1; i++){\n        long p; cin >> p;\n        tree[i].push_back(p);\n   \
    \     tree[p].push_back(i);\n    }\n    \n    LowestCommonAncestor lca(tree, 0);\n\
    \    while(Q--){\n        long u, v; cin >> u >> v;\n        cout << lca.query(u,\
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
  timestamp: '2021-11-13 20:11:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/verify/LowestCommonAncestor.test.cpp
- /verify/test/verify/LowestCommonAncestor.test.cpp.html
title: test/verify/LowestCommonAncestor.test.cpp
---
