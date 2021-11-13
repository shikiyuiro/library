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
  bundledCode: "#line 1 \"DataStructure/FenwickTree.cpp\"\nclass FenwickTree{\npublic:\n\
    \    vector<long> table;\n    long siz;\n    FenwickTree(long siz) : table(siz\
    \ + 1), siz(siz) {}\n    long sum(long index){\n        long res = 0;\n      \
    \  index++;//0-indexed to 1-indexed\n        while(index > 0){\n            res\
    \ += table[index];\n            index -= (index & -index);\n        }\n      \
    \  return res;\n    }\n    void add(long index, long value){\n        index++;//0-indexed\
    \ to 1-indexed\n        while(index < siz + 1){\n            table[index] += value;\n\
    \            index += (index & -index);\n        }\n    }\n};\n"
  code: "class FenwickTree{\npublic:\n    vector<long> table;\n    long siz;\n   \
    \ FenwickTree(long siz) : table(siz + 1), siz(siz) {}\n    long sum(long index){\n\
    \        long res = 0;\n        index++;//0-indexed to 1-indexed\n        while(index\
    \ > 0){\n            res += table[index];\n            index -= (index & -index);\n\
    \        }\n        return res;\n    }\n    void add(long index, long value){\n\
    \        index++;//0-indexed to 1-indexed\n        while(index < siz + 1){\n \
    \           table[index] += value;\n            index += (index & -index);\n \
    \       }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/FenwickTree.cpp
  requiredBy: []
  timestamp: '2021-11-13 19:25:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/FenwickTree.cpp
layout: document
redirect_from:
- /library/DataStructure/FenwickTree.cpp
- /library/DataStructure/FenwickTree.cpp.html
title: DataStructure/FenwickTree.cpp
---
