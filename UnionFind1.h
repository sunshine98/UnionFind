//
// Created by Administrator on 2017/12/25.
//

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H

#include <iostream>
#include <cassert>
using namespace std;
namespace UF1{

    class UnionFind1{
    private:
        int *id;//一个数组用来存储每一位相应的集合id
        int count;//记录数据个数
    public:
        UnionFind1(int n){//构造函数
            id=new int[n];//构造id数组
            count=n;
            for(int i=0;i<n;i++){
                id[i]=i;//初始化，每一个id[i]都指向自己单独的一个集合
            }
        }

        ~UnionFind1(){
            delete []id;
        }
        //查找元素P所对应的集合编号
        int find(int p){
            assert(p>=0&&p<count);//确保查询的范围
            return id[p];//返回p元素所属的集合编号
        }
        //查询两个元素是否在同一个集合中
        bool isconnected(int p,int q){
            return id[p]==id[q];
        }

        // 合并元素p与元素q所在的两个集合
        void unionElements(int p,int q){
            int pID=find(p);//先找出p,q元素各自所在的集合的id
            int qID=find(q);
            if(pID==qID){//p,q的集合编号id一样，则p,q已经在同一个集合中了
                return;
            }
            else{//p,q两者不在同一个集合当中，需要进行合并操作
                for(int i=0;i<count;i++){//遍历数组所有的元素一遍
                    if(id[i]==qID){//把所有处于qID集合的元素的id改为pID,使得两个集合合并为一个集合qID集合
                        id[i]=pID;
                    }
                }
            }
        }

    };
}

#endif //UNIONFIND_UNIONFIND1_H
