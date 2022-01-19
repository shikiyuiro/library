---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.cpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/verify/WaveletMatrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n/**\n * @brief \u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n */\n#line 4 \"test/verify/WaveletMatrix.test.cpp\"\
    \n\n#line 1 \"DataStructure/WaveletMatrix.cpp\"\nclass WaveletMatrix{\npublic:\n\
    \    WaveletMatrix(vector<long> table) : table_origin(table){\n        long table_max\
    \ = *max_element(table.begin(), table.end());\n        tablesize = table.size();\n\
    \        bitsize = 0;\n        while(table_max){\n            bitsize++;\n   \
    \         table_max >>= 1;\n        }\n        assert(bitsize);\n        matrix.resize(bitsize,\
    \ vector<bool>(tablesize));\n        zero_count.resize(bitsize, vector<long>(tablesize\
    \ + 1, 0));\n        for(long i = 0; i < bitsize; i++){\n            for(long\
    \ j = 0; j < tablesize; j++){\n                matrix[i][j] = (table[j] >> (bitsize\
    \ - i - 1)) & 1;\n                if(not matrix[i][j]) zero_count[i][j + 1]++;\n\
    \                zero_count[i][j + 1] += zero_count[i][j];\n            }\n  \
    \          stable_sort(table.begin(), table.end(), [&](auto a, auto b){return\
    \ ((a >> (bitsize - i - 1)) & 1) < ((b >> (bitsize - i - 1)) & 1);});\n      \
    \  }\n        table_sorted = table;\n    }\n    \n    long kth_min(long l, long\
    \ r, long k/*0-indexed*/){\n        long L = l; long R = r;\n        for(long\
    \ level = 0; level < bitsize; level++){\n            auto [Lcount0, Lcount1] =\
    \ counts(0, L, level);\n            auto [count0, count1] = counts(L, R, level);\n\
    \            if(k < count0){\n                L = Lcount0;\n                R\
    \ = L + count0;\n            }else{\n                L = zero_count[level][tablesize]\
    \ + Lcount1;\n                R = L + count1;\n                k -= count0;\n\
    \            }\n        }\n        return table_sorted[L];\n    }\n    \n    long\
    \ range_freq(long l, long r, long lower, long upper){\n        //count i s.t.\
    \ l <= i < r and lower <= table[i] < upper\n        return range_freq(l, r, upper)\
    \ - range_freq(l, r, lower);\n    }\n    \nprivate:\n    vector<vector<bool>>\
    \ matrix;\n    vector<vector<long>> zero_count;//count 0 in matrix[i][0, r)\n\
    \    long tablesize;\n    long bitsize;\n    vector<long> table_origin;\n    vector<long>\
    \ table_sorted;\n    \n    pair<long,long> counts(long l, long r, long level){\n\
    \        //{0\u306E\u500B\u6570, 1\u306E\u500B\u6570} in matrix[level][l, r)\u3092\
    \u8FD4\u3059\n        return {zero_count[level][r] - zero_count[level][l], (r\
    \ - zero_count[level][r]) - (l - zero_count[level][l])};\n    }\n    \n    long\
    \ range_freq(long l, long r, long upper){\n        //count i s.t. l <= i < r and\
    \ table[i] < upper\n        if(upper >= (1L << bitsize)) return r - l;\n     \
    \   if(upper < 0) return 0;\n        long res = 0;\n        long L = l; long R\
    \ = r;\n        for(long level = 0; level < bitsize; level++){\n            auto\
    \ [Lcount0, Lcount1] = counts(0, L, level);\n            auto [count0, count1]\
    \ = counts(L, R, level);\n            if(((upper >> (bitsize - level - 1)) & 1)\
    \ == 0){\n                //matrix[level][i] = 1\u3000\u306A\u3089\u3000\u5FC5\
    \u305A upper < table[i]\n                L = Lcount0;\n                R = L +\
    \ count0;\n            }else{\n                //matrix[level][i] = 0\u3000\u306A\
    \u3089\u3000\u5FC5\u305A table[i] < upper\n                res += count0;\n  \
    \              L = zero_count[level][tablesize] + Lcount1;\n                R\
    \ = L + count1;\n            }\n        }\n        return res;\n    }\n};\n/**\n\
    \ * @brief \u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217\n * @docs docs/DataStructure/WaveletMatrix.md\n\
    \ */\n#line 6 \"test/verify/WaveletMatrix.test.cpp\"\n\nint main(){\n  long N,\
    \ Q; cin >> N >> Q;\n    vector<long> A(N); for(long i = 0; i < N; i++) cin >>\
    \ A[i];\n    WaveletMatrix wm(A);\n    while(Q--){\n        long l, r, k; cin\
    \ >> l >> r >> k;\n        cout << wm.kth_min(l, r, k) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../template/template.cpp\"\n\n#include \"../../DataStructure/WaveletMatrix.cpp\"\
    \n\nint main(){\n  long N, Q; cin >> N >> Q;\n    vector<long> A(N); for(long\
    \ i = 0; i < N; i++) cin >> A[i];\n    WaveletMatrix wm(A);\n    while(Q--){\n\
    \        long l, r, k; cin >> l >> r >> k;\n        cout << wm.kth_min(l, r, k)\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/WaveletMatrix.cpp
  isVerificationFile: true
  path: test/verify/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2021-12-31 16:23:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/test/verify/WaveletMatrix.test.cpp
- /verify/test/verify/WaveletMatrix.test.cpp.html
title: test/verify/WaveletMatrix.test.cpp
---