---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/template/template.md
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
    \u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/template/template.md\n */\n"
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
    }\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\n * @docs docs/template/template.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: Classic/LIS.cpp
  requiredBy: []
  timestamp: '2022-03-27 19:47:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Classic/LIS.cpp
layout: document
redirect_from:
- /library/Classic/LIS.cpp
- /library/Classic/LIS.cpp.html
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
## きもち

テンプレートです。マクロの類は使っていません。オーガニックですね（？）
