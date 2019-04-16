#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

const int maxn=100000;
struct node{
    int data;
    vector<int> l;
}Node[maxn];
int findmax(int x,int &count){
    sort(Node[x].l.begin(),Node[x].l.end());
    count+=Node[x].l.size();
    for (int i:Node[x].l) {
        findmax(i,count);
    }

    return count;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i <n-1 ; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<y) swap(x,y);
        Node[y].l.push_back(x);
    }
    int countl=1;
    int countr=1;
    int res=0;
    res=max(findmax(Node[1].l[0],countl),findmax(Node[1].l[1],countr));
    printf("%d",res);
    return 0;
}