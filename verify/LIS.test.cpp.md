---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Classic/LIS.cpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/chokudai_S001/submissions/30497502
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/LIS.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"Classic/LIS.cpp\"\nvector<int64_t> LIS(vector<int64_t> v, bool\
    \ non_strict = false, bool decrease = false){\n    if(decrease) for(auto& e :\
    \ v) e = ~e;\n    vector<int64_t> res, DP, index(v.size()), trace(v.size());\n\
    \    for(int64_t i = 0; i < v.size(); i++){\n        auto itr = (non_strict ?\
    \ upper_bound(DP.begin(), DP.end(), v[i]) : lower_bound(DP.begin(), DP.end(),\
    \ v[i]));\n        index[distance(DP.begin(), itr)] = i;\n        trace[i] = (itr\
    \ == DP.begin() ? -1 : index[distance(DP.begin(), itr) - 1]);\n        if(itr\
    \ == DP.end()) DP.emplace_back(v[i]); else *itr = v[i];\n    }\n    for(int64_t\
    \ vis = index[DP.size() - 1]; vis >= 0; vis = trace[vis]) res.push_back(v[vis]);\n\
    \    reverse(res.begin(), res.end());\n    if(decrease) for(auto& e : res) e =\
    \ ~e;\n    return res;\n}\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\n * @docs docs/Classic/LIS.md\n */\n#line 5 \"verify/LIS.test.cpp\"\n//\u4EE5\
    \u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\
    \u3002\n//https://atcoder.jp/contests/chokudai_S001/submissions/30497502\n\nint\
    \ main(){\n    int64_t A, B; cin >> A >> B;\n    cout << A + B << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../template/template.cpp\"\n#include \"../Classic/LIS.cpp\"\n//\u4EE5\u4E0B\u306E\
    \u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/chokudai_S001/submissions/30497502\n\
    \nint main(){\n    int64_t A, B; cin >> A >> B;\n    cout << A + B << '\\n';\n\
    }\n"
  dependsOn:
  - template/template.cpp
  - Classic/LIS.cpp
  isVerificationFile: true
  path: verify/LIS.test.cpp
  requiredBy: []
  timestamp: '2022-03-28 06:48:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/LIS.test.cpp
layout: document
redirect_from:
- /verify/verify/LIS.test.cpp
- /verify/verify/LIS.test.cpp.html
title: verify/LIS.test.cpp
---
