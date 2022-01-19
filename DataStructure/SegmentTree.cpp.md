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
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nclass SegmentTree{\npublic:\n    explicit SegmentTree() = default;\n\
    \    \n    vector<S> table;\n    long size = 1;\n    SegmentTree(vector<S> &vec){\n\
    \        while(size < vec.size()) size <<= 1;\n        table.resize(size << 1,\
    \ e());\n        for(long i = 0; i < (long)vec.size(); i++) table[i + size] =\
    \ vec[i];\n        for(long i = size - 1; i >= 1; i--) table[i] = op(table[i<<1|0],table[i<<1|1]);\n\
    \    }\n    S fold(long l, long r){\n        l += size; r += size;\n        S\
    \ Lres = e(), Rres = e();\n        while(l < r){\n            if(l & 1) Lres =\
    \ op(Lres, table[l++]);\n            if(r & 1) Rres = op(table[--r], Rres);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return op(Lres, Rres);\n  \
    \  }\n    void set(long p, S x){\n        p += size;\n        table[p] = x;\n\
    \        while(p >>= 1) table[p] = op(table[p<<1|0],table[p<<1|1]);\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass SegmentTree{\npublic:\n\
    \    explicit SegmentTree() = default;\n    \n    vector<S> table;\n    long size\
    \ = 1;\n    SegmentTree(vector<S> &vec){\n        while(size < vec.size()) size\
    \ <<= 1;\n        table.resize(size << 1, e());\n        for(long i = 0; i < (long)vec.size();\
    \ i++) table[i + size] = vec[i];\n        for(long i = size - 1; i >= 1; i--)\
    \ table[i] = op(table[i<<1|0],table[i<<1|1]);\n    }\n    S fold(long l, long\
    \ r){\n        l += size; r += size;\n        S Lres = e(), Rres = e();\n    \
    \    while(l < r){\n            if(l & 1) Lres = op(Lres, table[l++]);\n     \
    \       if(r & 1) Rres = op(table[--r], Rres);\n            l >>= 1; r >>= 1;\n\
    \        }\n        return op(Lres, Rres);\n    }\n    void set(long p, S x){\n\
    \        p += size;\n        table[p] = x;\n        while(p >>= 1) table[p] =\
    \ op(table[p<<1|0],table[p<<1|1]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2022-01-19 22:38:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: DataStructure/SegmentTree.cpp
---
