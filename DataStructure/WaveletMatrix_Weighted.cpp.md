---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/WaveletMatrix_Weighted.md
    document_title: "\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\
      \u884C\u5217"
    links: []
  bundledCode: "#line 1 \"DataStructure/WaveletMatrix_Weighted.cpp\"\nclass WeightedWaveletMatrix{\n\
    public:\n    WeightedWaveletMatrix(vector<pair<long,long>> table){\n        long\
    \ MOV = max_element(table.begin(), table.end())->first;\n        while(MOV >>=\
    \ 1) DIGIT++;\n        vector<bool> VBL(table.size());\n        vector<long> weight(table.size());\n\
    \        for(long k = 1; k <= DIGIT; k++){\n            for(long i = 0; i < (long)table.size();\
    \ i++) VBL[i] = (table[i].first >> (DIGIT - k)) & 1;\n            MAT.push_back(cmpBV(VBL));\n\
    \            for(long i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;\n\
    \            PSUM.push_back(PrefixSum(weight));\n            stable_sort(table.begin(),\
    \ table.end(), [&](auto a, auto b){ return (a.first >> (DIGIT - k) & 1) < (b.first\
    \ >> (DIGIT - k) & 1);});\n        }\n        table_sorted = table;\n        for(long\
    \ i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;\n        PSUM.push_back(PrefixSum(weight));\n\
    \    }\n    \n    long range_freq(long L, long R, long lower, long upper){\n \
    \       return range_freq(L, R, upper) - range_freq(L, R, lower);\n    }\n   \
    \ \n    long weighted_range_freq(long L, long R, long lower, long upper){\n  \
    \      return weighted_range_freq(L, R, upper) - weighted_range_freq(L, R, lower);\n\
    \    }\nprivate:\n    \n    struct cmpBV{\n        long size;\n        vector<long>\
    \ prefix;\n        cmpBV(vector<bool> &v) : size(v.size()), prefix(v.size()+1,0){\n\
    \            for(long i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1]\
    \ + v[i-1];\n        }\n        long rank(long L, long R) { return prefix[R] -\
    \ prefix[L];}\n    };\n    struct PrefixSum{\n        vector<long> prefix;\n \
    \       PrefixSum(vector<long> &v) : prefix(v.size()+1,0){\n            for(long\
    \ i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1] + v[i-1];\n       \
    \ }\n        long get(long L, long R) { return prefix[R] - prefix[L];}\n    };\n\
    \    \n    long DIGIT = 1;\n    vector<cmpBV> MAT;\n    vector<PrefixSum> PSUM;\n\
    \    vector<pair<long,long>> table_sorted;\n    \n    pair<pair<long,long>,pair<long,long>>\
    \ decomp(pair<long,long> p, long k){\n        //MAT[k]\u306B\u304A\u3051\u308B\
    \u534A\u958B\u533A\u9593[L, R)\u3092MAT[k+1]\u306E\u4E8C\u3064\u306E\u534A\u958B\
    \u533A\u9593\u306B\u5206\u89E3\u3059\u308B\u3002\u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217\u306E\u672C\u8CEA\u90E8\u5206\n        auto [L, R] =\
    \ p;\n        long allfreq_0 = MAT[k].size - MAT[k].rank(0, MAT[k].size);\n  \
    \      long rank_origin_1 = MAT[k].rank(0, L);\n        long rank_origin_0 = L\
    \ - rank_origin_1;\n        long rank_1 = MAT[k].rank(0, R);\n        long rank_0\
    \ = R - rank_1;\n        return {{rank_origin_0, rank_0}, {allfreq_0 + rank_origin_1,\
    \ allfreq_0 + rank_1}};\n    }\n    \n    long range_freq(long L, long R, long\
    \ upper){\n        if(upper >= (1L << DIGIT)) return R - L;\n        if(upper\
    \ < 0) return 0;\n        long res = 0;\n        long visL = L; long visR = R;\n\
    \        for(long k = 1; k <= DIGIT; k++){\n            long bit_o_upper = upper\
    \ >> (DIGIT - k) & 1;\n            auto [p0, p1] = decomp({visL, visR}, k-1);\n\
    \            if(bit_o_upper == 0){\n                visL = p0.first;\n       \
    \         visR = p0.second;\n            }else{\n                res += p0.second\
    \ - p0.first;\n                visL = p1.first;\n                visR = p1.second;\n\
    \            }\n        }\n        return res;\n    }\n    \n    long weighted_range_freq(long\
    \ L, long R, long upper){\n        if(upper >= (1L << DIGIT)) return PSUM[0].get(L,\
    \ R);\n        if(upper < 0) return 0;\n        long res = 0;\n        long visL\
    \ = L; long visR = R;\n        for(long k = 1; k <= DIGIT; k++){\n           \
    \ long bit_o_upper = upper >> (DIGIT - k) & 1;\n            auto [p0, p1] = decomp({visL,\
    \ visR}, k-1);\n            if(bit_o_upper == 0){\n                visL = p0.first;\n\
    \                visR = p0.second;\n            }else{\n                res +=\
    \ PSUM[k].get(p0.first, p0.second);\n                visL = p1.first;\n      \
    \          visR = p1.second;\n            }\n        }\n        return res;\n\
    \    }\n};\n/**\n * @brief \u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217\n * @docs docs/DataStructure/WaveletMatrix_Weighted.md\n\
    \ */\n"
  code: "class WeightedWaveletMatrix{\npublic:\n    WeightedWaveletMatrix(vector<pair<long,long>>\
    \ table){\n        long MOV = max_element(table.begin(), table.end())->first;\n\
    \        while(MOV >>= 1) DIGIT++;\n        vector<bool> VBL(table.size());\n\
    \        vector<long> weight(table.size());\n        for(long k = 1; k <= DIGIT;\
    \ k++){\n            for(long i = 0; i < (long)table.size(); i++) VBL[i] = (table[i].first\
    \ >> (DIGIT - k)) & 1;\n            MAT.push_back(cmpBV(VBL));\n            for(long\
    \ i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;\n         \
    \   PSUM.push_back(PrefixSum(weight));\n            stable_sort(table.begin(),\
    \ table.end(), [&](auto a, auto b){ return (a.first >> (DIGIT - k) & 1) < (b.first\
    \ >> (DIGIT - k) & 1);});\n        }\n        table_sorted = table;\n        for(long\
    \ i = 0; i < (long)table.size(); i++) weight[i] = table[i].second;\n        PSUM.push_back(PrefixSum(weight));\n\
    \    }\n    \n    long range_freq(long L, long R, long lower, long upper){\n \
    \       return range_freq(L, R, upper) - range_freq(L, R, lower);\n    }\n   \
    \ \n    long weighted_range_freq(long L, long R, long lower, long upper){\n  \
    \      return weighted_range_freq(L, R, upper) - weighted_range_freq(L, R, lower);\n\
    \    }\nprivate:\n    \n    struct cmpBV{\n        long size;\n        vector<long>\
    \ prefix;\n        cmpBV(vector<bool> &v) : size(v.size()), prefix(v.size()+1,0){\n\
    \            for(long i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1]\
    \ + v[i-1];\n        }\n        long rank(long L, long R) { return prefix[R] -\
    \ prefix[L];}\n    };\n    struct PrefixSum{\n        vector<long> prefix;\n \
    \       PrefixSum(vector<long> &v) : prefix(v.size()+1,0){\n            for(long\
    \ i = 1; i <= (long)v.size(); i++) prefix[i] = prefix[i-1] + v[i-1];\n       \
    \ }\n        long get(long L, long R) { return prefix[R] - prefix[L];}\n    };\n\
    \    \n    long DIGIT = 1;\n    vector<cmpBV> MAT;\n    vector<PrefixSum> PSUM;\n\
    \    vector<pair<long,long>> table_sorted;\n    \n    pair<pair<long,long>,pair<long,long>>\
    \ decomp(pair<long,long> p, long k){\n        //MAT[k]\u306B\u304A\u3051\u308B\
    \u534A\u958B\u533A\u9593[L, R)\u3092MAT[k+1]\u306E\u4E8C\u3064\u306E\u534A\u958B\
    \u533A\u9593\u306B\u5206\u89E3\u3059\u308B\u3002\u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217\u306E\u672C\u8CEA\u90E8\u5206\n        auto [L, R] =\
    \ p;\n        long allfreq_0 = MAT[k].size - MAT[k].rank(0, MAT[k].size);\n  \
    \      long rank_origin_1 = MAT[k].rank(0, L);\n        long rank_origin_0 = L\
    \ - rank_origin_1;\n        long rank_1 = MAT[k].rank(0, R);\n        long rank_0\
    \ = R - rank_1;\n        return {{rank_origin_0, rank_0}, {allfreq_0 + rank_origin_1,\
    \ allfreq_0 + rank_1}};\n    }\n    \n    long range_freq(long L, long R, long\
    \ upper){\n        if(upper >= (1L << DIGIT)) return R - L;\n        if(upper\
    \ < 0) return 0;\n        long res = 0;\n        long visL = L; long visR = R;\n\
    \        for(long k = 1; k <= DIGIT; k++){\n            long bit_o_upper = upper\
    \ >> (DIGIT - k) & 1;\n            auto [p0, p1] = decomp({visL, visR}, k-1);\n\
    \            if(bit_o_upper == 0){\n                visL = p0.first;\n       \
    \         visR = p0.second;\n            }else{\n                res += p0.second\
    \ - p0.first;\n                visL = p1.first;\n                visR = p1.second;\n\
    \            }\n        }\n        return res;\n    }\n    \n    long weighted_range_freq(long\
    \ L, long R, long upper){\n        if(upper >= (1L << DIGIT)) return PSUM[0].get(L,\
    \ R);\n        if(upper < 0) return 0;\n        long res = 0;\n        long visL\
    \ = L; long visR = R;\n        for(long k = 1; k <= DIGIT; k++){\n           \
    \ long bit_o_upper = upper >> (DIGIT - k) & 1;\n            auto [p0, p1] = decomp({visL,\
    \ visR}, k-1);\n            if(bit_o_upper == 0){\n                visL = p0.first;\n\
    \                visR = p0.second;\n            }else{\n                res +=\
    \ PSUM[k].get(p0.first, p0.second);\n                visL = p1.first;\n      \
    \          visR = p1.second;\n            }\n        }\n        return res;\n\
    \    }\n};\n/**\n * @brief \u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\
    \u30C3\u30C8\u884C\u5217\n * @docs docs/DataStructure/WaveletMatrix_Weighted.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WaveletMatrix_Weighted.cpp
  requiredBy: []
  timestamp: '2022-01-21 21:00:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/WaveletMatrix_Weighted.cpp
layout: document
redirect_from:
- /library/DataStructure/WaveletMatrix_Weighted.cpp
- /library/DataStructure/WaveletMatrix_Weighted.cpp.html
title: "\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
---
## きもち

普通のウェーブレット行列はrange_freqのときに分割した範囲の幅を足し合わせることで答えを求めているのだけれど、  
この「幅を足す部分」を重みの累積和に置き換えることによって、重みの和を求めることができるよ。  
今回は累積和を載せて実装したけど以下のような一般化が可能だよ。  
・スパーステーブルを乗せるとminやgcdが可能に。  
・重みの変更クエリがある場合はセグメント木を載せれば解決できる。  
・元の配列の値に対して変更クエリが入る場合は平衡二分探索木で解決できるらしいけど、重そ〜  
・重み付きウェーブレット行列にウェーブレット行列をのせると三次元のクエリがこなせるよ。  
・その上にさらにウェーブレット行列を載せると・・・　笑  

## 使い方  
- `WeightedWaveletMatrix(vector<pair<long,long>> table)`：コンストラクタ。firstに値、secondに重みをもつ配列 $table$ をもとに、重み付きウェーブレット行列を構築する。  
- `long range_freq(long L, long R, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの個数を返す。　　
- `long weighted_range_freq(long L, long R, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの重みの和を返す。　　

## 計算量
サイズをN、最大値をmaxVとして、  
構築:$\mathrm{O}(NlogmaxV)$  
クエリ:$\mathrm{O}(logmaxV)$  

## Tips
ネタバレになるので一つだけ。たとえば↓これが思考停止で解ける(HLDして、これをはる。)  
([atcoder ABC133-F Colorful Tree](https://atcoder.jp/contests/abc133/tasks/abc133_f))  
