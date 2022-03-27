---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix.cpp
    title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/WaveletMatrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 1 \"DataStructure/WaveletMatrix.cpp\"\nclass WaveletMatrix{\n    using\
    \ i64 = int64_t;\npublic:\n    explicit WaveletMatrix() = default;\n    WaveletMatrix(vector<i64>\
    \ &_v){ __WaveletMatrix(_v);};\n    i64 range_freq(i64 L, i64 R, i64 lower, i64\
    \ upper){ return __range_freq(L, R, upper) - __range_freq(L, R, lower);}\n   \
    \ i64 range_Kth_min(i64 L, i64 R, i64 K){ return __range_Kth_min(L, R, K);}\n\
    \    i64 range_Kth_max(i64 L, i64 R, i64 K){ return __range_Kth_min(L, R, R -\
    \ L - K - 1);}\n    i64 range_successor(i64 L, i64 R, i64 value){ i64 C = __range_freq(L,\
    \ R, value + 1); return C == R - L ? -1 : __range_Kth_min(L, R, C);}\n    i64\
    \ range_predecessor(i64 L, i64 R, i64 value){ i64 C = __range_freq(L, R, value);\
    \ return C == 0 ? -1 : __range_Kth_min(L, R, C - 1);}\n    i64 range_min_assignXOR(i64\
    \ L, i64 R, i64 value){ return __range_min_assignXOR(L, R, value) xor value;}\n\
    \    i64 range_max_assignXOR(i64 L, i64 R, i64 value){ return __range_min_assignXOR(L,\
    \ R, ~value) xor value;}\nprivate:\n    vector<i64> Matrix;\n    i64 bitsize;\n\
    \    i64 prefixsize;\n    void __WaveletMatrix(vector<i64> v){\n        i64 v_max\
    \ = *max_element(v.begin(), v.end());\n        bitsize = 64 - __builtin_clzll(v_max);\n\
    \        prefixsize = v.size()+1;\n        Matrix.resize(prefixsize * bitsize);\n\
    \        for(i64 h = bitsize - 1; h >= 0; h--){\n            for(i64 i = 0; i\
    \ < v.size(); i++){\n                Matrix[i+1 + prefixsize * h] = Matrix[i +\
    \ prefixsize * h] + (v[i] >> h & 1);\n            }\n            stable_sort(v.begin(),\
    \ v.end(), [&](auto a, auto b){ return (a >> h & 1) < (b >> h & 1);});\n     \
    \   }\n    };\n    i64 __range_freq(i64 L, i64 R, i64 upper){\n        if(upper\
    \ >= ((i64)1 << bitsize)) return R - L;\n        if(upper < 0) return 0;\n   \
    \     i64 res = 0;\n        for(i64 h = bitsize - 1; h >= 0; h--){\n         \
    \   auto [L0, R0, L1, R1] = decomp(L, R, h);\n            if(upper & ((i64)1 <<\
    \ h)){\n                res += R0 - L0;\n                tie(L, R) = {L1, R1};\n\
    \            }else{\n                tie(L, R) = {L0, R0};\n            }\n  \
    \      }\n        return res;\n    };\n    i64 __range_Kth_min(i64 L, i64 R, i64\
    \ K){\n        i64 res = 0;\n        for(i64 h = bitsize - 1; h >= 0; h--){\n\
    \            auto [L0, R0, L1, R1] = decomp(L, R, h);\n            if(K >= R0\
    \ - L0){\n                res |= (i64)1 << h;\n                K -= R0 - L0;\n\
    \                tie(L, R) = {L1, R1};\n            }else{\n                tie(L,\
    \ R) = {L0, R0};\n            }\n        }\n        return res;\n    }\n    i64\
    \ __range_min_assignXOR(i64 L, i64 R, i64 value){\n        i64 res = 0;\n    \
    \    for(i64 h = bitsize - 1; h >= 0; h--){\n            auto [L0, R0, L1, R1]\
    \ = decomp(L, R, h);\n            if(R0 - L0 == 0){\n                res |= (i64)1\
    \ << h;\n                tie(L, R) = {L1, R1};\n                continue;\n  \
    \          }\n            if(R1 - L1 == 0){\n                tie(L, R) = {L0,\
    \ R0};\n                continue;\n            }\n            if(value & (1 <<\
    \ h)){\n                res |= (i64)1 << h;\n                tie(L, R) = {L1,\
    \ R1};\n            }else{\n                tie(L, R) = {L0, R0};\n          \
    \  }\n        }\n        return res;\n    }\n    tuple<i64,i64,i64,i64> decomp(i64\
    \ L, i64 R, i64 h){\n        return tuple<i64,i64,i64,i64>({\n            L -\
    \ Matrix[L + prefixsize * h],\n            R - Matrix[R + prefixsize * h],\n \
    \           prefixsize - 1 - Matrix[prefixsize * (h+1) - 1] + Matrix[L + prefixsize\
    \ * h],\n            prefixsize - 1 - Matrix[prefixsize * (h+1) - 1] + Matrix[R\
    \ + prefixsize * h]\n        });\n    }\n};\n/**\n * @brief \u30A6\u30A7\u30FC\
    \u30D6\u30EC\u30C3\u30C8\u884C\u5217\n * @docs docs/DataStructure/WaveletMatrix.md\n\
    \ */\n#line 5 \"verify/WaveletMatrix.test.cpp\"\n\nclass Compless{\npublic:\n\
    \    explicit Compless() = default;\n    Compless(vector<int64_t> &v){\n     \
    \   st = v;\n        sort(st.begin(), st.end());\n        st.erase(unique(st.begin(),\
    \ st.end()), st.end());\n        for(auto& e : v) e = comp(e);\n    }\n    int64_t\
    \ comp(int64_t val){\n        return distance(st.begin(), lower_bound(st.begin(),\
    \ st.end(), val));\n    }\n    int64_t fix(int64_t val){\n        return st[val];\n\
    \    }\nprivate:\n    vector<int64_t> st;\n};\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N, Q; cin >> N >> Q;\n    vector<int64_t> A(N); for(int64_t i = 0;\
    \ i < N; i++) cin >> A[i];\n    Compless cmp(A);\n    WaveletMatrix wm(A);\n \
    \   while(Q--){\n        int64_t l, r, k; cin >> l >> r >> k;\n        cout <<\
    \ cmp.fix(wm.range_Kth_min(l, r, k)) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../template/template.cpp\"\n#include \"../DataStructure/WaveletMatrix.cpp\"\
    \n\nclass Compless{\npublic:\n    explicit Compless() = default;\n    Compless(vector<int64_t>\
    \ &v){\n        st = v;\n        sort(st.begin(), st.end());\n        st.erase(unique(st.begin(),\
    \ st.end()), st.end());\n        for(auto& e : v) e = comp(e);\n    }\n    int64_t\
    \ comp(int64_t val){\n        return distance(st.begin(), lower_bound(st.begin(),\
    \ st.end(), val));\n    }\n    int64_t fix(int64_t val){\n        return st[val];\n\
    \    }\nprivate:\n    vector<int64_t> st;\n};\n\nint main(){\n    cin.tie(nullptr)->ios::sync_with_stdio(false);\n\
    \    int64_t N, Q; cin >> N >> Q;\n    vector<int64_t> A(N); for(int64_t i = 0;\
    \ i < N; i++) cin >> A[i];\n    Compless cmp(A);\n    WaveletMatrix wm(A);\n \
    \   while(Q--){\n        int64_t l, r, k; cin >> l >> r >> k;\n        cout <<\
    \ cmp.fix(wm.range_Kth_min(l, r, k)) << '\\n';\n    }\n}\n"
  dependsOn:
  - template/template.cpp
  - DataStructure/WaveletMatrix.cpp
  isVerificationFile: true
  path: verify/WaveletMatrix.test.cpp
  requiredBy: []
  timestamp: '2022-03-20 18:14:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/WaveletMatrix.test.cpp
layout: document
redirect_from:
- /verify/verify/WaveletMatrix.test.cpp
- /verify/verify/WaveletMatrix.test.cpp.html
title: verify/WaveletMatrix.test.cpp
---
