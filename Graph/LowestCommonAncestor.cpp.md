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
  bundledCode: "#line 1 \"Graph/LowestCommonAncestor.cpp\"\nclass LowestCommonAncestor{\n\
    private:\n    long N;\n    vector<bool> visited;\n    vector<vector<long> > Tree;\n\
    \    vector<vector<long> > STtable;\n    vector<long> STcf;\n    \n    void make_EularTour(long\
    \ vis){\n        EularTour.push_back(depth[vis] * N + vis);\n        visited[vis]\
    \ = true;\n        for(auto e : Tree[vis]){\n            if(visited[e]) continue;\n\
    \            depth[e] = depth[vis] + 1;\n            make_EularTour(e);\n    \
    \        EularTour.push_back(depth[vis] * N + vis);\n        }\n    }\n    \n\
    \    void make_SparseTable(){\n        SparseTable<long> st(EularTour, LONG_MAX,\
    \ [](long a, long b){return min(a, b);});\n        STtable = st.table;\n     \
    \   STcf = st.cf;\n    }\n    \n    void make_first(){\n        long index = 0;\n\
    \        for(auto e : EularTour){\n            first_index[e % N] = min(first_index[e\
    \ % N], index);\n            index++;\n        }\n    }\npublic:\n    vector<long>\
    \ depth;\n    vector<long> EularTour;\n    vector<long> first_index;\n    \n \
    \   LowestCommonAncestor(vector<vector<long>>& tree, long root) : Tree(tree){\n\
    \        N = Tree.size();\n        visited.resize(N, false);\n        depth.resize(N,\
    \ 0);\n        first_index.resize(N, INT_MAX);\n        make_EularTour(root);\n\
    \        make_SparseTable();\n        make_first();\n    }\n    \n    long query(long\
    \ l, long r){\n        long ltmp = l, rtmp = r;\n        l = min(first_index[ltmp],\
    \ first_index[rtmp]); r = max(first_index[ltmp], first_index[rtmp]) + 1;\n   \
    \     long b = STcf[r - l];\n        return min(STtable[l][b], STtable[r - (1\
    \ << b)][b]) % N;\n    }\n};\n"
  code: "class LowestCommonAncestor{\nprivate:\n    long N;\n    vector<bool> visited;\n\
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
    \ STtable[r - (1 << b)][b]) % N;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/LowestCommonAncestor.cpp
  requiredBy: []
  timestamp: '2021-11-13 18:33:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/LowestCommonAncestor.cpp
layout: document
redirect_from:
- /library/Graph/LowestCommonAncestor.cpp
- /library/Graph/LowestCommonAncestor.cpp.html
title: Graph/LowestCommonAncestor.cpp
---
