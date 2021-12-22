---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/LowestCommonAncestor.test.cpp
    title: test/verify/LowestCommonAncestor.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/Graph/LowestCommonAncestor.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\n#define IGNORE\ntemplate\
    \ < typename elm >\nclass SparseTable{\npublic:\n    explicit SparseTable() =\
    \ default;\n    \n    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)>\
    \ operation) : operation(operation){\n        long isiz = v.size();\n        long\
    \ jsiz = 0;\n        while((1 << jsiz) <= isiz) jsiz++;\n        table.resize(isiz,\
    \ vector<elm>(jsiz, e));\n        for(long i = 0; i < isiz; i++)table[i][0] =\
    \ v[i];\n        for(long j = 1; j < jsiz; j++){\n            for(long i = 0;\
    \ i + (1 << (j - 1)) < isiz; i++){\n                table[i][j] = operation(table[i][j\
    \ - 1], table[i + (1 << (j - 1))][j - 1]);\n            }\n        }\n       \
    \ cf.resize(isiz + 1);\n        for(long i = 2; i <= isiz; i++) cf[i] = cf[i >>\
    \ 1] + 1;\n    }\n    \n    elm query(long l, long r/*\u534A\u958B\u533A\u9593\
    */){\n        assert(l < r);\n        long b = cf[r - l];\n        return operation(table[l][b],\
    \ table[r - (1 << b)][b]);\n    }\nprivate:\n    function<elm(elm, elm)> operation;\n\
    \    vector<vector<elm>> table;\n    vector<long> cf;\n};\n/**\n * @brief \u30B9\
    \u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n * @docs docs/DataStructure/SparseTable.md\n\
    \ */\n#line 2 \"Graph/LowestCommonAncestor.cpp\"\n\nclass LowestCommonAncestor{\n\
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
    \ << b)][b]) % N;\n    }\n};\n/**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\
    \n * @docs docs/Graph/LowestCommonAncestor.md\n */\n"
  code: "#include \"../DataStructure/SparseTable.cpp\"\n\nclass LowestCommonAncestor{\n\
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
    \ << b)][b]) % N;\n    }\n};\n/**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\
    \n * @docs docs/Graph/LowestCommonAncestor.md\n */\n"
  dependsOn:
  - DataStructure/SparseTable.cpp
  isVerificationFile: false
  path: Graph/LowestCommonAncestor.cpp
  requiredBy: []
  timestamp: '2021-12-22 19:41:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/LowestCommonAncestor.test.cpp
documentation_of: Graph/LowestCommonAncestor.cpp
layout: document
redirect_from:
- /library/Graph/LowestCommonAncestor.cpp
- /library/Graph/LowestCommonAncestor.cpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
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
