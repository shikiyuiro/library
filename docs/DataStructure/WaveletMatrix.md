## きもち

ウェーブレット行列だよ。  
オンラインの区間比較クエリが得意。  
動的配列や負の数が含まれる配列は扱うことができないよ。  

## 使い方  
- `WaveletMatrix(vector<long> table)`：コンストラクタ。配列 $table$ をもとに、ウェーブレット行列を構築する。  
- `long rank(long r, long x)`：区間 $[0, r)$ に含まれる $x$ の個数を返す。  
- `long kth_min(long l, long r, long k)`:区間 $[l, r)$ の $k$ 番目に小さい値を返す。$k$ は 0-indexed. 　
- `long range_freq(long l, long r, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの個数を返す　　

## 計算量
サイズをN、最大値をmaxVとして、  
構築:$\mathrm{O}(NlogmaxV)$  
クエリ:$\mathrm{O}(logmaxV)$  

## Tips

転倒数を平面走査により求める。(atcoder ABC231-F Jealous Two https://atcoder.jp/contests/abc231/tasks/abc231_f)  
静的な配列の区間中央値を求める。(yukicoder no.924 紲星 https://yukicoder.me/problems/no/924)
