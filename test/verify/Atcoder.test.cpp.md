---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: DataStructure/MergeTree.cpp
    title: "\u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728"
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind_PartiallyPersistent.cpp
    title: "\u90E8\u5206\u6C38\u7D9AUnionFind"
  - icon: ':heavy_check_mark:'
    path: DataStructure/WaveletMatrix_Weighted.cpp
    title: "\u91CD\u307F\u4ED8\u304D\u30A6\u30A7\u30FC\u30D6\u30EC\u30C3\u30C8\u884C\
      \u5217"
  - icon: ':heavy_check_mark:'
    path: Utility/CoordinateCompless.cpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc036/submissions/26855886
    - https://atcoder.jp/contests/abc133/submissions/28651189
    - https://atcoder.jp/contests/abc183/submissions/28824947
    - https://atcoder.jp/contests/typical90/submissions/27052694
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/verify/Atcoder.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/template/template.md\n\
    \ */\n#line 4 \"test/verify/Atcoder.test.cpp\"\n\n#line 1 \"Utility/CoordinateCompless.cpp\"\
    \ntemplate < typename Element = long >\nclass CoordinateCompless{\nprivate:\n\
    \    long index = 0;\n    vector<Element> uniq;\npublic:\n    vector<long> After;\n\
    \    map<Element, long> BtoA;\n    map<long, Element> AtoB;\n    \n    CoordinateCompless(vector<Element>&\
    \ Before){\n        uniq = Before;\n        sort(uniq.begin(), uniq.end());\n\
    \        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());\n        for(auto\
    \ &e : uniq){\n            BtoA.insert(make_pair(e, index));\n            AtoB.insert(make_pair(index,\
    \ e));\n            index++;\n        }\n        for(auto &e : Before) After.push_back(BtoA.at(e));\n\
    \    }\n};\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n * @docs docs/Utility/CoordinateCompless.md\n\
    \ */\n#line 6 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\
    \n#line 1 \"DataStructure/LazySegmentTree.cpp\"\ntemplate < typename Element =\
    \ long >\nclass LazySegmentTree {\nprivate:\n    Element e;\n    long vsiz;\n\
    \    long tsiz;\n    long queryL = -1, queryR = -1, queryV = -1;\n    vector<Element>\
    \ Table;\n    vector<long> TableL, TableR;\n    vector<Element> lazy;\n    vector<bool>\
    \ lazyFlag;\n    function<Element(Element)> lazyDeal;\n    function<Element(Element,\
    \ Element)> operation;\n    \n    long opera_rec(long vis = 1){\n        if(queryR\
    \ <= TableL[vis] or TableR[vis] <= queryL){\n            return e;\n        }\n\
    \        lazyEval(vis);\n        if(queryL <= TableL[vis] and TableR[vis] <= queryR){\n\
    \            return Table[vis];\n        }\n        return operation(opera_rec(vis\
    \ * 2), opera_rec(vis * 2 + 1));\n    }\n    \n    void update_rec(long vis =\
    \ 1){\n        lazyEval(vis);\n        if(queryR <= TableL[vis] or TableR[vis]\
    \ <= queryL){\n            return;\n        }\n        if(queryL <= TableL[vis]\
    \ and TableR[vis] <= queryR){\n            lazy[vis] = queryV;\n            lazyFlag[vis]\
    \ = true;\n            lazyEval(vis);\n            return;\n        }\n      \
    \  update_rec(vis * 2);\n        update_rec(vis * 2 + 1);\n        Table[vis]\
    \ = operation(Table[vis * 2], Table[2 * vis + 1]);\n    }\n    \n    void lazyEval(long\
    \ vis) {\n        if (not lazyFlag.at(vis)) return;\n        Table[vis] = lazy[vis];\n\
    \        if (vis < tsiz / 2) {\n            lazy[2 * vis + 1] = lazy[2 * vis]\
    \ = lazyDeal(lazy[vis]);\n            lazyFlag[2 * vis + 1] = lazyFlag[2 * vis]\
    \ = true;\n        }\n        lazyFlag[vis] = false;\n    }\n    \npublic:\n \
    \   LazySegmentTree(vector<Element> v, Element e, function<Element(Element, Element)>\
    \ operation, function<Element(Element)> lazyDeal = [](Element a){return a;}) :\
    \ e(e), operation(operation), lazyDeal(lazyDeal){\n        vsiz = v.size();\n\
    \        tsiz = 1;\n        while(tsiz < vsiz) tsiz *= 2;\n        tsiz *= 2;\n\
    \        Table.resize(tsiz, e);\n        TableL.resize(tsiz, e);\n        TableR.resize(tsiz,\
    \ e);\n        lazy.resize(tsiz, e);\n        lazyFlag.resize(tsiz, false);\n\
    \        for(long vi = 0; vi < tsiz / 2; vi++){\n            if(vi < vsiz) Table[vi\
    \ + tsiz / 2] = v[vi];\n            TableL[vi + tsiz / 2] = vi;\n            TableR[vi\
    \ + tsiz / 2] = vi + 1;\n        }\n        for(long p = tsiz / 2 - 1; p >= 1;\
    \ p--){\n            Table[p] = operation(Table[p * 2], Table[p * 2 + 1]);\n \
    \           TableL[p] = TableL[p * 2];\n            TableR[p] = TableR[p * 2 +\
    \ 1];\n        }\n    }\n    \n    Element query_opera(long l, long r/*\u534A\u958B\
    \u533A\u9593*/){\n        queryL = l; queryR = r;\n        return opera_rec();\n\
    \    }\n    \n    void query_update(long l, long r/*\u534A\u958B\u533A\u9593*/,\
    \ Element value){\n        queryL = l; queryR = r; queryV = value;\n        return\
    \ update_rec();\n    }\n};\n/**\n * @brief \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @docs docs/DataStructure/LazySegmentTree.md\n */\n\
    #line 10 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\
    \u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/typical90/submissions/27052694\n\
    \n#line 1 \"DataStructure/WaveletMatrix_Weighted.cpp\"\nclass WeightedWaveletMatrix{\n\
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
    \ */\n#line 14 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc133/submissions/28651189\n\
    \n#line 1 \"DataStructure/UnionFind_PartiallyPersistent.cpp\"\nclass PPUF{\npublic:\n\
    \    PPUF(long size){\n        Parent.resize(size); iota(Parent.begin(), Parent.end(),\
    \ 0);\n        Size.resize(size, 1);\n        history.resize(size); for(auto &s\
    \ : history) s.push_back({LONG_MIN, 1});\n        United.resize(size, LONG_MAX);\n\
    \    }\n    long find(long u, long t){ return (United[u] > t) ? u: find(Parent[u],\
    \ t); }//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u6839\u3092\u6C42\u3081\u308B\u3002\
    \n    bool unite(long u, long v, long t){\n        //t\u306Funite\u30AF\u30A8\u30EA\
    \u3054\u3068\u306B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u3067\u306A\u3051\u308C\
    \u3070\u306A\u3089\u306A\u3044\u304C\u3001\u9023\u7D9A\u3059\u308B\u5024\u3067\
    \u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n        long fu = find(u), fv\
    \ = find(v);\n        if(fu == fv) return false;\n        if(Size[fu] < Size[fv]){\
    \ swap(u, v); swap(fu, fv);}\n        Parent[fv] = fu;\n        Size[fu] += Size[fv];\n\
    \        history[fu].push_back({t, Size[fu]});\n        United[fv] = t;\n    \
    \    return true;\n    }\n    bool same(long u, long v, long t){//\u6642\u523B\
    t\u76F4\u5F8C\u306Bu\u3068v\u304C\u9023\u7D50\u3067\u3042\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\u3002\n        return find(u, t) == find(v, t);\n    }\n    long\
    \ size(long u, long t){//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u9023\u7D50\u6210\
    \u5206\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\u308B\u3002\n        long fu\
    \ = find(u, t);\n        return prev(upper_bound(history[fu].begin(), history[fu].end(),\
    \ pair<long,long>({t, LONG_MAX})))->second;\n    }\n    explicit PPUF() = default;\n\
    private:\n    vector<long> Parent;\n    vector<long> Size;\n    vector<vector<pair<long,long>>>\
    \ history;//unite\u76F4\u5F8C\u306E\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \u3092\u4FDD\u5B58\u3059\u308B\n    vector<long> United;//\u4F55\u56DE\u76EE\u306E\
    \u7D50\u5408\u3067\u6839\u3067\u306F\u306A\u304F\u306A\u308B\u304B\u3000\u30FC\
    \uFF1E \u305D\u306E\u5024\u4EE5\u4E0B\u306E\u6642\u523B\u3067\u3042\u308C\u3070\
    \u305D\u306E\u9802\u70B9\u306F\u6839\u3001\u305D\u3046\u3067\u306A\u304B\u3063\
    \u305F\u3089Parent\u3092\u305F\u3069\u308C\u3070\u3088\u3044\u3002\n    long find(long\
    \ u){ return (Parent[u] == u) ? u: find(Parent[u]); }\n};\n/**\n * @brief \u90E8\
    \u5206\u6C38\u7D9AUnionFind\n * @docs docs/DataStructure/UnionFind_PartiallyPersistent.md\n\
    \ */\n#line 2 \"DataStructure/MergeTree.cpp\"\n\nclass MergeTree{\n    //UnionFind\u306E\
    \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728(\u306E\u30AA\u30A4\u30E9\
    \u30FC\u30C4\u30A2\u30FC)\u3002  \n    //\u300C\u6642\u523Bt\u306B\u304A\u3051\
    \u308B\u8981\u7D20u\u306E\u9023\u7D50\u6210\u5206\u300D\u306B\u5BFE\u3059\u308B\
    \u30AF\u30A8\u30EA\u3092\u5217\u30AF\u30A8\u30EA\u306B\u5E30\u7740\u3067\u304D\
    \u308B\u3002  \n    //\u8FFD\u52A0\u3059\u308B\u8FBA\u3068\u305D\u306E\u6642\u523B\
    \u304C\u5148\u8AAD\u307F\u53EF\u80FD\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\npublic:\n    MergeTree(long siz, vector<tuple<long,long,long>> merge){\n\
    \        uni = PPUF(siz);\n        forest.resize(siz);\n        pos.resize(siz);\n\
    \        for(auto [u, v, t] : merge){\n            long fu = uni.find(u, t), fv\
    \ = uni.find(v, t);\n            if(uni.unite(fu, fv, t)){\n                forest[fu].push_back(fv);\n\
    \                forest[fv].push_back(fu);\n            }\n        }\n       \
    \ vector<bool> visited(siz, false);\n        for(long v = 0; v < siz; v++){\n\
    \            if(visited[v]) continue;\n            long fv = uni.find(v, INT_MAX);\n\
    \            auto dfs = [&](auto &&self, long vis, long prev) -> void {\n    \
    \            visited[vis] = true;\n                tour.push_back(vis);\n    \
    \            pos[vis] = tour.size() - 1;\n                for(auto e : forest[vis])\
    \ if(e != prev) self(self, e, vis);\n            };\n            dfs(dfs, fv,\
    \ -1);\n        }\n    }\n    vector<long> get_tour(){\n        return tour;\n\
    \    }\n    pair<long,long> get_range(long u, long t){\n        long L = pos[uni.find(u,\
    \ t)];\n        return {L, L + uni.size(u, t)};\n    }\nprivate:\n    vector<vector<long>>\
    \ forest;\n    vector<long> tour;\n    vector<long> pos;\n    PPUF uni;\n};\n\
    /**\n * @brief \u30DE\u30FC\u30B8\u904E\u7A0B\u3092\u8868\u3059\u6728\n */\n#line\
    \ 18 \"test/verify/Atcoder.test.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\
    \u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc183/submissions/28824947\n\
    \nint main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.cpp\"\n\n#include \"../../Utility/CoordinateCompless.cpp\"\
    \n//\u4EE5\u4E0B\u306E\u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\
    \u3059\u3002\n//https://atcoder.jp/contests/abc036/submissions/26855886\n\n#include\
    \ \"../../DataStructure/LazySegmentTree.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/typical90/submissions/27052694\n\
    \n#include \"../../DataStructure/WaveletMatrix_Weighted.cpp\"\n//\u4EE5\u4E0B\u306E\
    \u554F\u984C\u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc133/submissions/28651189\n\
    \n#include \"../../DataStructure/MergeTree.cpp\"\n//\u4EE5\u4E0B\u306E\u554F\u984C\
    \u3067\u52D5\u4F5C\u78BA\u8A8D\u6E08\u307F\u3067\u3059\u3002\n//https://atcoder.jp/contests/abc183/submissions/28824947\n\
    \nint main(){\n    long A, B; cin >> A >> B;\n    cout << A + B << endl;\n}\n"
  dependsOn:
  - template/template.cpp
  - Utility/CoordinateCompless.cpp
  - DataStructure/LazySegmentTree.cpp
  - DataStructure/WaveletMatrix_Weighted.cpp
  - DataStructure/MergeTree.cpp
  - DataStructure/UnionFind_PartiallyPersistent.cpp
  isVerificationFile: true
  path: test/verify/Atcoder.test.cpp
  requiredBy: []
  timestamp: '2022-01-29 15:29:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/Atcoder.test.cpp
layout: document
redirect_from:
- /verify/test/verify/Atcoder.test.cpp
- /verify/test/verify/Atcoder.test.cpp.html
title: test/verify/Atcoder.test.cpp
---
