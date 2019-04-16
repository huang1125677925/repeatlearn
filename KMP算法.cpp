#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

void get_next(string s,int next[]){
    int k=1;
    next[1]=0;
    for (int j = 2; j <s.size() ; ++j) {
        k=next[j-1];
        a3:
            if(s[j-1]==s[k]){
                next[j]=k+1;
                continue;
            }else{
                k=next[k];
            }

        if(k==0){
            next[j]=1;
        }else{

            goto a3;
        }
    }

    return;
}

bool KMP(string s2,string s1,int next[],int pos){
    int i=pos;
    int j=1;
//    都从位置1开始匹配
    while(i<s2.size() && j<s1.size()){
//        保证二者的扫描指针都在自己长度范围内
        if(j==0 || s1[j]==s2[i]){
            ++i;
            ++j;
//            如果二者相等就继续往后边扫描
        }else{
            j=next[j];
//            否则的话就改变开始扫描的位置
        }
    }
    if(j>=s1.size()) {
        return true;

    }else{
        return false;
    }
}
int main(){
    string s1="aabaabe";
    string s2="aabcabaaabaabcacfdddddd";
    int next[100]={0};
    next[0]=-1;
   get_next(s1,next);
    for (int i = 0; i <10 ; ++i) {
        printf("%d",next[i]);
    }
    cout<<endl;
    bool res=KMP(s2,s1,next,1);
    if (res) cout<<"true"<<endl;

    return 0;
}
