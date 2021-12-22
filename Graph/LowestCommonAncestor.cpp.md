---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: DataStructure/SparseTable.cpp
    title: "\u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/LowestCommonAncestor.test.cpp
    title: test/verify/LowestCommonAncestor.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/LowestCommonAncestor.md
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148"
    links: []
  bundledCode: "#line 1 \"DataStructure/SparseTable.cpp\"\ntemplate < typename elm\
    \ >\nclass SparseTable{\npublic:\n    explicit SparseTable() = default;\n    \n\
    \    SparseTable(vector<elm>& v, elm e, function<elm(elm, elm)> op) : op(op){\n\
    \        long isiz = v.size();\n        long jsiz = 0;\n        while((1 << jsiz)\
    \ <= isiz) jsiz++;\n        table.resize(isiz, vector<elm>(jsiz, e));\n      \
    \  for(long i = 0; i < isiz; i++)table[i][0] = v[i];\n        for(long j = 1;\
    \ j < jsiz; j++){\n            for(long i = 0; i + (1 << (j - 1)) < isiz; i++){\n\
    \                table[i][j] = op(table[i][j - 1], table[i + (1 << (j - 1))][j\
    \ - 1]);\n            }\n        }\n        cf.resize(isiz + 1);\n        for(long\
    \ i = 2; i <= isiz; i++) cf[i] = cf[i >> 1] + 1;\n    }\n    \n    elm query(long\
    \ L, long R/*[L, R)*/){\n        assert(L < R);\n        long b = cf[R - L];\n\
    \        return op(table[L][b], table[R - (1 << b)][b]);\n    }\nprivate:\n  \
    \  function<elm(elm, elm)> op;\n    vector<vector<elm>> table;\n    vector<long>\
    \ cf;\n};\n/**\n * @brief \u30B9\u30D1\u30FC\u30B9\u30C6\u30FC\u30D6\u30EB\n *\
    \ @docs docs/DataStructure/SparseTable.md\n */\n#line 2 \"Graph/LowestCommonAncestor.cpp\"\
    \n\nclass LowestCommonAncestor{\npublic:\n    LowestCommonAncestor(vector<vector<long>>\
    \ &tree, long root) : tree(tree){\n        ETpos.resize(tree.size(), -1);\n  \
    \      dfs(root, 0);\n        st = SparseTable<long>(EularTour, LONG_MAX, [](long\
    \ a, long b){return min(a, b);});\n    }\n    \n    long query(long L, long R){\n\
    \        if(ETpos[L] > ETpos[R]) swap(L, R);\n        return st.query(ETpos[L],\
    \ ETpos[R] + 1) % tree.size();\n    }\n    \nprivate:\n    vector<vector<long>>\
    \ tree;\n    vector<long> EularTour;\n    vector<long> ETpos;\n    long ETsize\
    \ = 0;\n    SparseTable<long> st;\n    \n    void dfs(long vis, long depth){\n\
    \        EularTour.push_back(depth * tree.size() + vis);\n        ETpos[vis] =\
    \ ETsize++;\n        for(auto e : tree[vis]) if(ETpos[e] == -1) {dfs(e, depth\
    \ + 1); EularTour.push_back(depth * tree.size() + vis); ETsize++;}\n    }\n};\n\
    /**\n * @brief \u6700\u5C0F\u5171\u901A\u7956\u5148\n * @docs docs/Graph/LowestCommonAncestor.md\n\
    \ */\n"
  code: "#include \"../DataStructure/SparseTable.cpp\"\n\nclass LowestCommonAncestor{\n\
    public:\n    LowestCommonAncestor(vector<vector<long>> &tree, long root) : tree(tree){\n\
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
    \ */\n"
  dependsOn:
  - DataStructure/SparseTable.cpp
  isVerificationFile: false
  path: Graph/LowestCommonAncestor.cpp
  requiredBy: []
  timestamp: '2021-12-22 19:48:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
