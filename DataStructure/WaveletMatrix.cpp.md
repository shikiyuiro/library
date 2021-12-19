---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/WaveletMatrix.test.cpp
    title: test/verify/WaveletMatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/WaveletMatrix.md
    document_title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
    links: []
  bundledCode: "#line 1 \"DataStructure/WaveletMatrix.cpp\"\nclass WaveletMatrix{\n\
    public:\n    WaveletMatrix(vector<long> table) : table_origin(table){\n      \
    \  long table_max = *max_element(table.begin(), table.end());\n        tablesize\
    \ = table.size();\n        bitsize = 0;\n        while(table_max){\n         \
    \   bitsize++;\n            table_max >>= 1;\n        }\n        assert(bitsize);\n\
    \        matrix.resize(bitsize, vector<bool>(tablesize));\n        zero_count.resize(bitsize,\
    \ vector<long>(tablesize + 1, 0));\n        for(long i = 0; i < bitsize; i++){\n\
    \            for(long j = 0; j < tablesize; j++){\n                matrix[i][j]\
    \ = (table[j] >> (bitsize - i - 1)) & 1;\n                if(not matrix[i][j])\
    \ zero_count[i][j + 1]++;\n                zero_count[i][j + 1] += zero_count[i][j];\n\
    \            }\n            stable_sort(table.begin(), table.end(), [&](auto a,\
    \ auto b){return ((a >> (bitsize - i - 1)) & 1) < ((b >> (bitsize - i - 1)) &\
    \ 1);});\n        }\n        table_sorted = table;\n    }\n    \n    long kth_min(long\
    \ l, long r, long k/*0-indexed*/){\n        long L = l; long R = r;\n        for(long\
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
    \ table[i] < upper\n        if(upper >= (1 << bitsize)) return r - l;\n      \
    \  if(upper < 0) return 0;\n        long res = 0;\n        long L = l; long R\
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
    \ */\n"
  code: "class WaveletMatrix{\npublic:\n    WaveletMatrix(vector<long> table) : table_origin(table){\n\
    \        long table_max = *max_element(table.begin(), table.end());\n        tablesize\
    \ = table.size();\n        bitsize = 0;\n        while(table_max){\n         \
    \   bitsize++;\n            table_max >>= 1;\n        }\n        assert(bitsize);\n\
    \        matrix.resize(bitsize, vector<bool>(tablesize));\n        zero_count.resize(bitsize,\
    \ vector<long>(tablesize + 1, 0));\n        for(long i = 0; i < bitsize; i++){\n\
    \            for(long j = 0; j < tablesize; j++){\n                matrix[i][j]\
    \ = (table[j] >> (bitsize - i - 1)) & 1;\n                if(not matrix[i][j])\
    \ zero_count[i][j + 1]++;\n                zero_count[i][j + 1] += zero_count[i][j];\n\
    \            }\n            stable_sort(table.begin(), table.end(), [&](auto a,\
    \ auto b){return ((a >> (bitsize - i - 1)) & 1) < ((b >> (bitsize - i - 1)) &\
    \ 1);});\n        }\n        table_sorted = table;\n    }\n    \n    long kth_min(long\
    \ l, long r, long k/*0-indexed*/){\n        long L = l; long R = r;\n        for(long\
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
    \ table[i] < upper\n        if(upper >= (1 << bitsize)) return r - l;\n      \
    \  if(upper < 0) return 0;\n        long res = 0;\n        long L = l; long R\
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
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/WaveletMatrix.cpp
  requiredBy: []
  timestamp: '2021-12-18 16:53:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/WaveletMatrix.test.cpp
documentation_of: DataStructure/WaveletMatrix.cpp
layout: document
redirect_from:
- /library/DataStructure/WaveletMatrix.cpp
- /library/DataStructure/WaveletMatrix.cpp.html
title: "\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\u5217"
---
## きもち

ウェーブレット行列だよ。  
オンラインの区間比較クエリが得意。  
動的配列や負の数が含まれる配列は扱うことができないよ。  

## 使い方  
- `WaveletMatrix(vector<long> table)`：コンストラクタ。配列 $table$ をもとに、ウェーブレット行列を構築する。  
- `long kth_min(long l, long r, long k)`:区間 $[l, r)$ の $k$ 番目に小さい値を返す。$k$ は 0-indexed. 　
- `long range_freq(long l, long r, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの個数を返す。　　

## 計算量
サイズをN、最大値をmaxVとして、  
構築:$\mathrm{O}(NlogmaxV)$  
クエリ:$\mathrm{O}(logmaxV)$  

## Tips

kth_minを k = (r-l-1)/2, (r-l)/2 として区間中央値を求める。([yukicoder no.924 紲星](https://yukicoder.me/problems/no/924))  
オイラーツアーやdfsと組み合わせると、木にも使える。([atcoder ABC202-E Count Descendants](https://atcoder.jp/contests/abc202/tasks/abc202_e))  
転倒数を平面走査により求める。([atcoder ABC231-F Jealous Two](https://atcoder.jp/contests/abc231/tasks/abc231_f))  
