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
  bundledCode: "#line 1 \"DataStructure/Compact_Sparse_Table.cpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)()>\nclass Compact_Sparse_Table{\npublic:\n    long\
    \ W = 8;\n    vector<S> A;\n    vector<S> Lfold, Rfold;\n    SparseTable<S, op,\
    \ e> st;\n    \n    explicit Compact_Sparse_Table() = default;\n    \n    Compact_Sparse_Table(vector<S>\
    \ &A) : A(A){\n        A.resize(A.size() + W - ((A.size() - 1) % W + 1), e());\n\
    \        vector<long> BLOCK(A.size() / W, e());\n        Lfold.resize(A.size(),\
    \ e());\n        Rfold.resize(A.size(), e());\n        for(long b = 0; b < BLOCK.size();\
    \ b++){\n            BLOCK[b] = A[W * b];\n            Lfold[W * b] = A[W * b];\n\
    \            Rfold[W * (b + 1) - 1] = A[W * (b + 1) - 1];\n            for(long\
    \ i = 1; i < W; i++){\n                BLOCK[b] = op(BLOCK[b], A[W * b + i]);\n\
    \                Lfold[W * b + i] = op(Lfold[W * b + i - 1], A[W * b + i]);\n\
    \                Rfold[W * (b + 1) - 1 - i] = op(Rfold[W * (b + 1) - i], A[W *\
    \ (b + 1) - 1 - i]);\n            }\n        }\n        st = SparseTable<S, op,\
    \ e> (BLOCK);\n    }\n    S query(long L, long R/*\u534A\u958B\u533A\u9593*/){\n\
    \        R--;\n        long lb = (L - (L % W) + W) / W;\n        long rb = (R\
    \ - (R % W)) / W;\n        if(rb > lb){\n            return op(st.query(lb, rb),\
    \ op(Lfold[R],Rfold[L]));\n        }\n        if(rb == lb){\n            return\
    \ op(Lfold[R],Rfold[L]);\n        }\n        S res = e();\n        for(long i\
    \ = L; i <= R; i++) res = op(res, A[i]);\n        return res;\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nclass Compact_Sparse_Table{\n\
    public:\n    long W = 8;\n    vector<S> A;\n    vector<S> Lfold, Rfold;\n    SparseTable<S,\
    \ op, e> st;\n    \n    explicit Compact_Sparse_Table() = default;\n    \n   \
    \ Compact_Sparse_Table(vector<S> &A) : A(A){\n        A.resize(A.size() + W -\
    \ ((A.size() - 1) % W + 1), e());\n        vector<long> BLOCK(A.size() / W, e());\n\
    \        Lfold.resize(A.size(), e());\n        Rfold.resize(A.size(), e());\n\
    \        for(long b = 0; b < BLOCK.size(); b++){\n            BLOCK[b] = A[W *\
    \ b];\n            Lfold[W * b] = A[W * b];\n            Rfold[W * (b + 1) - 1]\
    \ = A[W * (b + 1) - 1];\n            for(long i = 1; i < W; i++){\n          \
    \      BLOCK[b] = op(BLOCK[b], A[W * b + i]);\n                Lfold[W * b + i]\
    \ = op(Lfold[W * b + i - 1], A[W * b + i]);\n                Rfold[W * (b + 1)\
    \ - 1 - i] = op(Rfold[W * (b + 1) - i], A[W * (b + 1) - 1 - i]);\n           \
    \ }\n        }\n        st = SparseTable<S, op, e> (BLOCK);\n    }\n    S query(long\
    \ L, long R/*\u534A\u958B\u533A\u9593*/){\n        R--;\n        long lb = (L\
    \ - (L % W) + W) / W;\n        long rb = (R - (R % W)) / W;\n        if(rb > lb){\n\
    \            return op(st.query(lb, rb), op(Lfold[R],Rfold[L]));\n        }\n\
    \        if(rb == lb){\n            return op(Lfold[R],Rfold[L]);\n        }\n\
    \        S res = e();\n        for(long i = L; i <= R; i++) res = op(res, A[i]);\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Compact_Sparse_Table.cpp
  requiredBy: []
  timestamp: '2022-01-17 10:17:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/Compact_Sparse_Table.cpp
layout: document
redirect_from:
- /library/DataStructure/Compact_Sparse_Table.cpp
- /library/DataStructure/Compact_Sparse_Table.cpp.html
title: DataStructure/Compact_Sparse_Table.cpp
---
