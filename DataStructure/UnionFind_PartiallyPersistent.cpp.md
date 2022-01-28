---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/UnionFind_PartiallyPersistent.md
    document_title: "\u90E8\u5206\u6C38\u7D9AUnionFind"
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind_PartiallyPersistent.cpp\"\nclass\
    \ PPUF{\npublic:\n    PPUF(long size){\n        Parent.resize(size); iota(Parent.begin(),\
    \ Parent.end(), 0);\n        Size.resize(size, 1);\n        history.resize(size);\
    \ for(auto &s : history) s.push_back({LONG_MIN, 1});\n        United.resize(size,\
    \ LONG_MAX);\n    }\n    long find(long u, long t){ return (United[u] > t) ? u:\
    \ find(Parent[u], t); }//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u6839\u3092\u6C42\
    \u3081\u308B\u3002\n    bool unite(long u, long v, long t){\n        //t\u306F\
    unite\u30AF\u30A8\u30EA\u3054\u3068\u306B\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u3067\
    \u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\u304C\u3001\u9023\u7D9A\u3059\
    \u308B\u5024\u3067\u3042\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n        long\
    \ fu = find(u), fv = find(v);\n        if(fu == fv) return false;\n        if(Size[fu]\
    \ < Size[fv]){ swap(u, v); swap(fu, fv);}\n        Parent[fv] = fu;\n        Size[fu]\
    \ += Size[fv];\n        history[fu].push_back({t, Size[fu]});\n        United[fv]\
    \ = t;\n        return true;\n    }\n    bool same(long u, long v, long t){//\u6642\
    \u523Bt\u76F4\u5F8C\u306Bu\u3068v\u304C\u9023\u7D50\u3067\u3042\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\u3002\n        return find(u, t) == find(v, t);\n    }\n  \
    \  long size(long u, long t){//\u6642\u523Bt\u76F4\u5F8C\u306Eu\u306E\u9023\u7D50\
    \u6210\u5206\u306E\u500B\u6570\u3092\u53D6\u5F97\u3059\u308B\u3002\n        long\
    \ fu = find(u, t);\n        return prev(upper_bound(history[fu].begin(), history[fu].end(),\
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
    \ */\n"
  code: "class PPUF{\npublic:\n    PPUF(long size){\n        Parent.resize(size);\
    \ iota(Parent.begin(), Parent.end(), 0);\n        Size.resize(size, 1);\n    \
    \    history.resize(size); for(auto &s : history) s.push_back({LONG_MIN, 1});\n\
    \        United.resize(size, LONG_MAX);\n    }\n    long find(long u, long t){\
    \ return (United[u] > t) ? u: find(Parent[u], t); }//\u6642\u523Bt\u76F4\u5F8C\
    \u306Eu\u306E\u6839\u3092\u6C42\u3081\u308B\u3002\n    bool unite(long u, long\
    \ v, long t){\n        //t\u306Funite\u30AF\u30A8\u30EA\u3054\u3068\u306B\u5E83\
    \u7FA9\u5358\u8ABF\u5897\u52A0\u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\
    \u3044\u304C\u3001\u9023\u7D9A\u3059\u308B\u5024\u3067\u3042\u308B\u5FC5\u8981\
    \u306F\u306A\u3044\u3002\n        long fu = find(u), fv = find(v);\n        if(fu\
    \ == fv) return false;\n        if(Size[fu] < Size[fv]){ swap(u, v); swap(fu,\
    \ fv);}\n        Parent[fv] = fu;\n        Size[fu] += Size[fv];\n        history[fu].push_back({t,\
    \ Size[fu]});\n        United[fv] = t;\n        return true;\n    }\n    bool\
    \ same(long u, long v, long t){//\u6642\u523Bt\u76F4\u5F8C\u306Bu\u3068v\u304C\
    \u9023\u7D50\u3067\u3042\u308B\u304B\u5224\u5B9A\u3059\u308B\u3002\n        return\
    \ find(u, t) == find(v, t);\n    }\n    long size(long u, long t){//\u6642\u523B\
    t\u76F4\u5F8C\u306Eu\u306E\u9023\u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u53D6\
    \u5F97\u3059\u308B\u3002\n        long fu = find(u, t);\n        return prev(upper_bound(history[fu].begin(),\
    \ history[fu].end(), pair<long,long>({t, LONG_MAX})))->second;\n    }\n    explicit\
    \ PPUF() = default;\nprivate:\n    vector<long> Parent;\n    vector<long> Size;\n\
    \    vector<vector<pair<long,long>>> history;//unite\u76F4\u5F8C\u306E\u9023\u7D50\
    \u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u4FDD\u5B58\u3059\u308B\n    vector<long>\
    \ United;//\u4F55\u56DE\u76EE\u306E\u7D50\u5408\u3067\u6839\u3067\u306F\u306A\u304F\
    \u306A\u308B\u304B\u3000\u30FC\uFF1E \u305D\u306E\u5024\u4EE5\u4E0B\u306E\u6642\
    \u523B\u3067\u3042\u308C\u3070\u305D\u306E\u9802\u70B9\u306F\u6839\u3001\u305D\
    \u3046\u3067\u306A\u304B\u3063\u305F\u3089Parent\u3092\u305F\u3069\u308C\u3070\
    \u3088\u3044\u3002\n    long find(long u){ return (Parent[u] == u) ? u: find(Parent[u]);\
    \ }\n};\n/**\n * @brief \u90E8\u5206\u6C38\u7D9AUnionFind\n * @docs docs/DataStructure/UnionFind_PartiallyPersistent.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind_PartiallyPersistent.cpp
  requiredBy: []
  timestamp: '2022-01-28 15:05:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/UnionFind_PartiallyPersistent.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind_PartiallyPersistent.cpp
- /library/DataStructure/UnionFind_PartiallyPersistent.cpp.html
title: "\u90E8\u5206\u6C38\u7D9AUnionFind"
---
## きもち

UnionFindに時刻の概念を追加したもの。  
経路圧縮を行わないUnionFindは親が変わることが高々1回しかなく、親を変更する必要のあるノードもクエリごとに1個であるため  
親が変わる時刻を保存しておけば与えられた時刻におけるFindクエリに答えられる。  
SameクエリはFindクエリをそのまま使えばよく、  
Sizeクエリは[部分永続配列の要領で](https://37zigen.com/persistent-array/)記憶しておけばよい。  
Uniteクエリも時刻とそのときのサイズを保存しておく以外は通常の(経路圧縮をしない)UnionFindと同じ。  

## 使い方

- `UnionFind(long size)`：コンストラクタ。頂点数sizeの素集合を構築する。  
- `long find(long x, long t)`：時刻t直後における頂点xの根を返す。  
- `void unite(long x, long y, long t)`：時刻tにおいて、頂点xを含む集合と頂点yを含む集合を連結にする。tはクエリごとに広義単調増加でなければならないが、連続する値である必要はない。  
- `bool same(long x, long y, long t)`：時刻t直後において、頂点xと頂点yが連結であるならば$true$、そうでなければ$false$を返す。  
- `long size(long x, long y, long t)`：時刻t直後における頂点xを含む集合の大きさを返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(logN)$   

## Tips

・辺の重みをその辺を追加する時刻と見立てると、時刻t直後において頂点Uと頂点Vが連結であることと、U-V間のパスの重みの最大値がt以下であることは同値。  
[CODE THANKS FESTIVAL 2017 H](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h)  
[ABC235 E](https://atcoder.jp/contests/abc235/tasks/abc235_e)  
・がんばればrollbackも実装できる。いつかやります。  
