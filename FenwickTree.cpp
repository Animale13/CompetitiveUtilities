//
// Created by Giorgio Minoccari on 2019-10-15.
//
#include <vector>
#include <iostream>
#define LSB(i) (i & (-i))

using namespace std;

class FenwickTree{
private:
    vector <int> ft;
public:
    FenwickTree(int n){
        ft.assign(n+1, 0);
    }
    FenwickTree(vector <int> iter){
        ft.assign(iter.size()+1, 0);
        for(int i=1; i<iter.size(); i++){
            adjust(i, iter[i]);
        }
    }
    FenwickTree(int n, int iter[]){
        ft.assign(n+1, 0);
        for(int i=1; i<n; i++){
            adjust(i, iter[i]);
        }
    }
    int rsq(int b){
        int sum = 0;
        for( ; b; b-=LSB(b)){
            sum+=ft[b];
        }
        return sum;
    }
    int rsq(int a, int b){
        int sum = rsq(b) - (a==1 ? 0 : rsq(a-1));
        return sum;
    }
    void adjust(int idx, int v){
        for( ; idx<(int)ft.size(); idx+=LSB(idx)){
            ft[idx]+=v;
        }
    }
    int at(int idx){
        return rsq(idx, idx);
    }

};

int main(){

    int test[] = {0, 1, 2, 4, 6, 3, 2, 6};
    FenwickTree testTree(7, test);
    for(int i=1; i<7; i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    for(int i=1; i<7; i++){
        cout<<testTree.rsq(i)<<" ";
    }
    cout<<endl;
    cout<<testTree.at(3);
    

}