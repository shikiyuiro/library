## 使い方  
- <a href="https://atcoder.github.io/ac-library/production/document_ja/segtree.html" target="_blank">テンプレートの定義はACLのSegtreeに準じる。 ただし、opは比較関数でなければならない。</a>  
- `RMQ_ON_O1(vector<S> &_v)`：配列_vをもとにデータ構造を構築する。  
- `S fold(int32_t L, int32_t R)`：半開区間\[L, R)に対して演算結果を返す。  

## 使用例
<a href="https://judge.yosupo.jp/submission/84078" target="_blank">yosupo judge - Static RMQ</a>

## 参考文献
<a href="https://qiita.com/okateim/items/e2f4a734db4e5f90e410" target="_blank">Range Minimum Query(@okateimさんの記事)</a>
