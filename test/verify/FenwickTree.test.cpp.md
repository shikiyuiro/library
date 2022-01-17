---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/FenwickTree.cpp
    title: "Fenwick\u6728"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/verify/FenwickTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 4 \"test/verify/FenwickTree.test.cpp\"\n\n#line 1 \"DataStructure/FenwickTree.cpp\"\
    \nclass FenwickTree{\npublic:\n    vector<long> table;\n    long siz;\n    FenwickTree(long\
    \ siz) : table(siz + 1), siz(siz) {}\n    long sum(long index){\n        long\
    \ res = 0;\n        index++;//0-indexed to 1-indexed\n        while(index > 0){\n\
    \            res += table[index];\n            index -= (index & -index);\n  \
    \      }\n        return res;\n    }\n    void add(long index, long value){\n\
    \        index++;//0-indexed to 1-indexed\n        while(index < siz + 1){\n \
    \           table[index] += value;\n            index += (index & -index);\n \
    \       }\n    }\n};\n/**\n * @brief Fenwick\u6728\n * @docs docs/DataStructure/FenwickTree.md\n\
    \ */\n#line 6 \"test/verify/FenwickTree.test.cpp\"\n\nint main(){\n    long N,\
    \ Q; cin >> N >> Q;\n    FenwickTree bit(N);\n    vector<long> A(N);\n    \n \
    \   for(long i = 0; i < N; i++){\n        cin >> A[i];\n        bit.add(i, A[i]);\n\
    \    }\n    \n    while(Q--){\n        long q, a, b; cin >> q >> a >> b;\n   \
    \     if(q == 0){\n            bit.add(a, b);\n        }else{\n            cout\
    \ << bit.sum(b - 1) - bit.sum(a - 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../template/template.cpp\"\n\n#include \"../../DataStructure/FenwickTree.cpp\"\
    \n\nint main(){\n    long N, Q; cin >> N >> Q;\n    FenwickTree bit(N);\n    vector<long>\
    \ A(N);\n    \n    for(long i = 0; i < N; i++){\n        cin >> A[i];\n      \
    \  bit.add(i, A[i]);\n    }\n    \n    while(Q--){\n        long q, a, b; cin\
    \ >> q >> a >> b;\n        if(q == 0){\n            bit.add(a, b);\n        }else{\n\
    \            cout << bit.sum(b - 1) - bit.sum(a - 1) << endl;\n        }\n   \
    \ }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/FenwickTree.cpp
  isVerificationFile: true
  path: test/verify/FenwickTree.test.cpp
  requiredBy: []
  timestamp: '2021-11-13 20:31:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/FenwickTree.test.cpp
layout: document
redirect_from:
- /verify/test/verify/FenwickTree.test.cpp
- /verify/test/verify/FenwickTree.test.cpp.html
title: test/verify/FenwickTree.test.cpp
---
