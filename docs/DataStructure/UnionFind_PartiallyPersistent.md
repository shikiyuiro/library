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
