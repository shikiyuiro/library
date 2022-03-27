---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Inversion.test.cpp
    title: verify/Inversion.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Classic/Inversion.md
    document_title: "\u8EE2\u5012\u6570"
    links: []
  bundledCode: "#line 1 \"Classic/Inversion.cpp\"\nint64_t inversion(vector<int64_t>\
    \ &v){\n    vector<int64_t> st = v;\n    sort(st.begin(), st.end());\n    st.erase(unique(st.begin(),\
    \ st.end()), st.end());\n    vector<int64_t> table(st.size()+1);\n    for(auto\
    \ e : v){\n        int64_t a = st.size() + (st.begin() - lower_bound(st.begin(),\
    \ st.end(), e)), b = a - 1;\n        for(;a < table.size(); a += (a & -a)) ++table[a];\n\
    \        for(;b > 0; b -= (b & -b)) table[0] += table[b];\n    }\n    return table[0];\n\
    }\n/**\n * @brief \u8EE2\u5012\u6570\n * @docs docs/Classic/Inversion.md\n */\n"
  code: "int64_t inversion(vector<int64_t> &v){\n    vector<int64_t> st = v;\n   \
    \ sort(st.begin(), st.end());\n    st.erase(unique(st.begin(), st.end()), st.end());\n\
    \    vector<int64_t> table(st.size()+1);\n    for(auto e : v){\n        int64_t\
    \ a = st.size() + (st.begin() - lower_bound(st.begin(), st.end(), e)), b = a -\
    \ 1;\n        for(;a < table.size(); a += (a & -a)) ++table[a];\n        for(;b\
    \ > 0; b -= (b & -b)) table[0] += table[b];\n    }\n    return table[0];\n}\n\
    /**\n * @brief \u8EE2\u5012\u6570\n * @docs docs/Classic/Inversion.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: Classic/Inversion.cpp
  requiredBy: []
  timestamp: '2022-03-27 20:01:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Inversion.test.cpp
documentation_of: Classic/Inversion.cpp
layout: document
redirect_from:
- /library/Classic/Inversion.cpp
- /library/Classic/Inversion.cpp.html
title: "\u8EE2\u5012\u6570"
---
## 使い方  
- `int64_t inversion(vector<int64_t> &v)`：配列vの転倒数を返す。  

## 使用例
<a href="https://atcoder.jp/contests/chokudai_S001/submissions/30509909" target="_blank">AtCoder Chokudai SpeedRun 001 J - 転倒数</a>
