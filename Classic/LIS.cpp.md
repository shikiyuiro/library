---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/LIS.test.cpp
    title: verify/LIS.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/Classic/LIS.md
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    links: []
  bundledCode: "#line 1 \"Classic/LIS.cpp\"\nvector<int64_t> LIS(vector<int64_t>&\
    \ v, bool non_strict = false, bool decrease = false){\n    if(decrease) for(auto&\
    \ e : v) e = (e == INT64_MIN ? INT64_MAX : -e-1);\n    vector<int64_t> res;\n\
    \    vector<int64_t> DP;\n    vector<int64_t> index(v.size());\n    vector<int64_t>\
    \ trace(v.size());\n    for(int64_t i = 0; i < v.size(); i++){\n        auto itr\
    \ = (non_strict ? upper_bound(DP.begin(), DP.end(), v[i]) : lower_bound(DP.begin(),\
    \ DP.end(), v[i]));\n        index[distance(DP.begin(), itr)] = i;\n        trace[i]\
    \ = (itr == DP.begin() ? -1 : index[distance(DP.begin(), itr) - 1]);\n       \
    \ if(itr == DP.end()) DP.emplace_back(v[i]); else *itr = v[i];\n    }\n    for(int64_t\
    \ vis = index[DP.size() - 1]; vis >= 0; vis = trace[vis]) res.push_back(v[vis]);\n\
    \    reverse(res.begin(), res.end());\n    if(decrease) for(auto& e : v) e = (e\
    \ == INT64_MIN ? INT64_MAX : -e-1);\n    if(decrease) for(auto& e : res) e = (e\
    \ == INT64_MIN ? INT64_MAX : -e-1);\n    return res;\n}\n/**\n * @brief \u6700\
    \u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/Classic/LIS.md\n */\n"
  code: "vector<int64_t> LIS(vector<int64_t>& v, bool non_strict = false, bool decrease\
    \ = false){\n    if(decrease) for(auto& e : v) e = (e == INT64_MIN ? INT64_MAX\
    \ : -e-1);\n    vector<int64_t> res;\n    vector<int64_t> DP;\n    vector<int64_t>\
    \ index(v.size());\n    vector<int64_t> trace(v.size());\n    for(int64_t i =\
    \ 0; i < v.size(); i++){\n        auto itr = (non_strict ? upper_bound(DP.begin(),\
    \ DP.end(), v[i]) : lower_bound(DP.begin(), DP.end(), v[i]));\n        index[distance(DP.begin(),\
    \ itr)] = i;\n        trace[i] = (itr == DP.begin() ? -1 : index[distance(DP.begin(),\
    \ itr) - 1]);\n        if(itr == DP.end()) DP.emplace_back(v[i]); else *itr =\
    \ v[i];\n    }\n    for(int64_t vis = index[DP.size() - 1]; vis >= 0; vis = trace[vis])\
    \ res.push_back(v[vis]);\n    reverse(res.begin(), res.end());\n    if(decrease)\
    \ for(auto& e : v) e = (e == INT64_MIN ? INT64_MAX : -e-1);\n    if(decrease)\
    \ for(auto& e : res) e = (e == INT64_MIN ? INT64_MAX : -e-1);\n    return res;\n\
    }\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/Classic/LIS.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Classic/LIS.cpp
  requiredBy: []
  timestamp: '2022-03-27 20:02:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/LIS.test.cpp
documentation_of: Classic/LIS.cpp
layout: document
redirect_from:
- /library/Classic/LIS.cpp
- /library/Classic/LIS.cpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
## 使い方  
- `vector<int64_t> LIS(vector<int64_t>& v, bool non_strict = false, bool decrease = false)`：配列vの最長増加部分列を返す。ただし、non_strict = trueのとき単調性が広義に、decrease = trueのとき最長減少部分列になる。  

## 使用例
<a href="https://atcoder.jp/contests/chokudai_S001/submissions/30497502" target="_blank">AtCoder Chokudai SpeedRun 001 H - LIS</a>
