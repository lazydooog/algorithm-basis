/*
 * @Description: 792. 高精度减法
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 21:00:28
 * @LastEditTime: 2020-04-02 15:22:15
 */

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;

//a是否大于b
bool cmp(VI &a, VI &b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = a.size() - 1; i >=0; i--) 
        if(a[i]!=b[i]) return a[i] > b[i];
    return true;
}
//前提是 a > b
VI sub(VI &a, VI &b){
    VI c; int t = 0; //借位标记
    for(int i = 0; i < a.size(); i++){
        t = a[i] - t; //每处理新的一位就先减去进位，第一次是0
        if(i < b.size()) t -= b[i];
        c.push_back((t+10)%10);  //同时处理大于0和小于0的情况
        if(t < 0) t = 1; else t = 0;
    }
    //去掉前导0，如果差为0 则只剩下一位0就行
    while(c.size() > 1 && c.back()==0) c.pop_back();
    return c;
}


int main(){
    string a,b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i>=0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i>=0; i--) B.push_back(b[i] - '0');
    if(cmp(A, B)){
        auto c = sub(A,B);
        for(int i = c.size() - 1; i >= 0; i--) printf("%d" ,c[i]);
    } 
    else{
        auto c = sub(B, A);
        printf("-");  //结果是负数  先输出负号
        for(int i = c.size() - 1; i >= 0; i--) printf("%d" ,c[i]);
    }
     
    return 0;
}
