## きもち  
セグメント木だよ。  
区間演算と、一点更新を高速に行うことができるデータ構造だよ。  

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。  
- `SegmentTree(vector<S> &vec)`：コンストラクタ。列構造vecをもとにセグメント木を構成する。  
- `S fold(long l, long r)`：半開区間\[l, r)に対する演算結果を返す。  
- `void set(long p, S x)`：位置pに値xを代入する。  
- `long partition_point(bool (*check)(S))`:V[i] = fold(0, i+1)なる配列Vにおける、  
std::distance(V.begin(), std::partition_point(V.begin(), V.end(), check))を返す。

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(logN)$  
