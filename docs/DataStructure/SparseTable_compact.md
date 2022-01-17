## きもち


構築O(N), クエリO(1)のスパーステーブルだよ。  
通常のスパーステーブルの3倍くらい速いよ。  
たぶん厳密には構築O(N)じゃないかもしれない。  
これも見て　->　[noshi91さんの記事](https://noshi91.hatenablog.com/entry/2018/08/16/125415)

## 使い方  
#### template<S, op, e> ここで、Sは区間の要素の型、opは区間に対する演算、eはopの単位元。 
- `Compact_Sparse_Table(vector<S> &A)`：コンストラクタ。配列Aをもとにスパーステーブルを構築する。  
- `Element query(long L, long R)`：半開区間\[L, R)に対して演算結果を返す。  

## 計算量

構築:$\mathrm{O}(N)$  
クエリ:$\mathrm{O}(1)$  

## Tips

todo:ここに使用例を書く
