#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=11;
int n,P[maxn],hashTable[maxn]={false};
//使用的是递归思想
void generateP(int index){
    if(index==n+1){
        for (int i = 1; i <=n ; i++) {
            cout<<P[i];
        }
        cout<<endl;
        return;
    }
    // index是索引，对所有数字都给弄一个哈希，主要是因为后边还需要用，但是
    // 找组合和这个就不一样了，找组合就是，找出那种组合就行了
    // 实际上都是深度优先搜索的变种，
    for (int j = 1; j <=n; j++) {
        if(hashTable[j]==false){
            P[index]=j;
            hashTable[j]= true;
            generateP(index+1);
            hashTable[j]= false;
        }
    }
}
int main() {
    n=4;
    generateP(1);

    return 0;
}