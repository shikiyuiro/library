---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/WaveletMatrix.test.cpp
    title: verify/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/WaveletMatrix.md
    document_title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
    links: []
  bundledCode: "#line 1 \"DataStructure/WaveletMatrix.cpp\"\nclass WaveletMatrix{\n\
    \    using i64 = int64_t;\npublic:\n    explicit WaveletMatrix() = default;\n\
    \    WaveletMatrix(vector<i64> &_v){ __WaveletMatrix(_v);};\n    i64 range_freq(i64\
    \ L, i64 R, i64 lower, i64 upper){ return __range_freq(L, R, upper) - __range_freq(L,\
    \ R, lower);}\n    i64 range_Kth_min(i64 L, i64 R, i64 K){ return __range_Kth_min(L,\
    \ R, K);}\n    i64 range_Kth_max(i64 L, i64 R, i64 K){ return __range_Kth_min(L,\
    \ R, R - L - K - 1);}\n    i64 range_successor(i64 L, i64 R, i64 value){ i64 C\
    \ = __range_freq(L, R, value + 1); return C == R - L ? -1 : __range_Kth_min(L,\
    \ R, C);}\n    i64 range_predecessor(i64 L, i64 R, i64 value){ i64 C = __range_freq(L,\
    \ R, value); return C == 0 ? -1 : __range_Kth_min(L, R, C - 1);}\n    i64 range_min_assignXOR(i64\
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
    \ */\n"
  code: "class WaveletMatrix{\n    using i64 = int64_t;\npublic:\n    explicit WaveletMatrix()\
    \ = default;\n    WaveletMatrix(vector<i64> &_v){ __WaveletMatrix(_v);};\n   \
    \ i64 range_freq(i64 L, i64 R, i64 lower, i64 upper){ return __range_freq(L, R,\
    \ upper) - __range_freq(L, R, lower);}\n    i64 range_Kth_min(i64 L, i64 R, i64\
    \ K){ return __range_Kth_min(L, R, K);}\n    i64 range_Kth_max(i64 L, i64 R, i64\
    \ K){ return __range_Kth_min(L, R, R - L - K - 1);}\n    i64 range_successor(i64\
    \ L, i64 R, i64 value){ i64 C = __range_freq(L, R, value + 1); return C == R -\
    \ L ? -1 : __range_Kth_min(L, R, C);}\n    i64 range_predecessor(i64 L, i64 R,\
    \ i64 value){ i64 C = __range_freq(L, R, value); return C == 0 ? -1 : __range_Kth_min(L,\
    \ R, C - 1);}\n    i64 range_min_assignXOR(i64 L, i64 R, i64 value){ return __range_min_assignXOR(L,\
    \ R, value) xor value;}\n    i64 range_max_assignXOR(i64 L, i64 R, i64 value){\
    \ return __range_min_assignXOR(L, R, ~value) xor value;}\nprivate:\n    vector<i64>\
    \ Matrix;\n    i64 bitsize;\n    i64 prefixsize;\n    void __WaveletMatrix(vector<i64>\
    \ v){\n        i64 v_max = *max_element(v.begin(), v.end());\n        bitsize\
    \ = 64 - __builtin_clzll(v_max);\n        prefixsize = v.size()+1;\n        Matrix.resize(prefixsize\
    \ * bitsize);\n        for(i64 h = bitsize - 1; h >= 0; h--){\n            for(i64\
    \ i = 0; i < v.size(); i++){\n                Matrix[i+1 + prefixsize * h] = Matrix[i\
    \ + prefixsize * h] + (v[i] >> h & 1);\n            }\n            stable_sort(v.begin(),\
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
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WaveletMatrix.cpp
  requiredBy: []
  timestamp: '2022-03-20 18:14:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/WaveletMatrix.test.cpp
documentation_of: DataStructure/WaveletMatrix.cpp
layout: document
redirect_from:
- /library/DataStructure/WaveletMatrix.cpp
- /library/DataStructure/WaveletMatrix.cpp.html
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
---
## 使い方  
- `WaveletMatrix(vector<int64_t> &_v)`：配列_vをもとにウェーブレット行列を構築する。  
- `int64_t range_freq(int64_t L, int64_t R, int64_t lower, int64_t upper)`:区間`[L, R)`内のlower以上upper未満の値の個数を返す。  
- `int64_t range_Kth_max(int64_t L, int64_t R, int64_t K)`:区間`[L, R)`内でK番目に大きな値を返す。Kは0-indexed.  
- `int64_t range_Kth_min(int64_t L, int64_t R, int64_t K)`:区間`[L, R)`内でK番目に小さな値を返す。Kは0-indexed.  
- `int64_t range_successor(int64_t L, int64_t R, int64_t value)`:区間`[L, R)`内の値のうちvalueより真に大きい最小のものを返す。存在しない場合-1を返す。  
- `int64_t range_predecessor(int64_t L, int64_t R, int64_t value)`:区間`[L, R)`内の値のうちvalueより真に小さい最大のものを返す。存在しない場合-1を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/83011" target="_blank">yosupo judge - Range Kth Smallest</a>
