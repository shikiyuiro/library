## きもち

普通のウェーブレット行列はrange_freqのときに分割した範囲の幅を足し合わせることで答えを求めているのだけれど、  
この「幅を足す部分」を重みの累積和に置き換えることによって、重みの和を求めることができるよ。  
今回は累積和を載せて実装したけど以下のような一般化が可能だよ。  
・スパーステーブルを乗せるとminやgcdが可能に。  
・重みの変更クエリがある場合はセグメント木を載せれば解決できる。  
・元の配列の値に対して変更クエリが入る場合は平衡二分探索木で解決できるらしいけど、重そ〜  
・重み付きウェーブレット行列にウェーブレット行列をのせると三次元のクエリがこなせるよ。  

## 使い方  
- `WeightedWaveletMatrix(vector<pair<long,long>> table)`：コンストラクタ。firstに値、secondに重みをもつ配列 $table$ をもとに、重み付きウェーブレット行列を構築する。  
- `long range_freq(long L, long R, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの個数を返す。　　
- `long weighted_range_freq(long L, long R, long lower, long upper)`:区間 $[l, r)$ に含まれる値 $V$ のうち $lower ≦ V < upper$ をみたすものの重みの和を返す。　　

## 計算量
サイズをN、最大値をmaxVとして、  
構築:$\mathrm{O}(NlogmaxV)$  
クエリ:$\mathrm{O}(logmaxV)$  

## Tips
[atcoder ABC133-F Colorful Tree](https://atcoder.jp/contests/abc133/tasks/abc133_f)  
