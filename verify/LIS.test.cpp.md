---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Classic/LIS.cpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  - icon: ':question:'
    path: template/template.cpp
    title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h
    links:
    - https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h
  bundledCode: "#line 1 \"verify/LIS.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"Classic/LIS.cpp\"\nvector<int64_t> LIS(vector<int64_t>& v, bool\
    \ non_strict = false, bool decrease = false){\n    if(decrease) for(auto& e :\
    \ v) e = (e == INT64_MIN ? INT64_MAX : -e-1);\n    vector<int64_t> res;\n    vector<int64_t>\
    \ DP;\n    vector<int64_t> index(v.size());\n    vector<int64_t> trace(v.size());\n\
    \    for(int64_t i = 0; i < v.size(); i++){\n        auto itr = (non_strict ?\
    \ upper_bound(DP.begin(), DP.end(), v[i]) : lower_bound(DP.begin(), DP.end(),\
    \ v[i]));\n        index[distance(DP.begin(), itr)] = i;\n        trace[i] = (itr\
    \ == DP.begin() ? -1 : index[distance(DP.begin(), itr) - 1]);\n        if(itr\
    \ == DP.end()) DP.emplace_back(v[i]); else *itr = v[i];\n    }\n    for(int64_t\
    \ vis = index[DP.size() - 1]; vis >= 0; vis = trace[vis]) res.push_back(v[vis]);\n\
    \    reverse(res.begin(), res.end());\n    if(decrease) for(auto& e : v) e = (e\
    \ == INT64_MIN ? INT64_MAX : -e-1);\n    if(decrease) for(auto& e : res) e = (e\
    \ == INT64_MIN ? INT64_MAX : -e-1);\n    return res;\n}\n/**\n * @brief \u6700\
    \u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/Classic/LIS.md\n */\n#line\
    \ 5 \"verify/LIS.test.cpp\"\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N; cin >> N;\n    vector<int64_t> a(N); for(auto& e : a) cin >> e;\n\
    \    cout << LIS(a).size() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_h\"\
    \n\n#include \"../template/template.cpp\"\n#include \"../Classic/LIS.cpp\"\n\n\
    int main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n    int64_t N;\
    \ cin >> N;\n    vector<int64_t> a(N); for(auto& e : a) cin >> e;\n    cout <<\
    \ LIS(a).size() << '\\n';\n}\n"
  dependsOn:
  - template/template.cpp
  - Classic/LIS.cpp
  isVerificationFile: true
  path: verify/LIS.test.cpp
  requiredBy: []
  timestamp: '2022-03-27 20:06:16+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/LIS.test.cpp
layout: document
redirect_from:
- /verify/verify/LIS.test.cpp
- /verify/verify/LIS.test.cpp.html
title: verify/LIS.test.cpp
---
