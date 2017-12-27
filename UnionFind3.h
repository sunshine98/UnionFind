//
// Created by Administrator on 2017/12/27.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H
#include<cassert>
#include <array>

using namespace std;
namespace UF3{
    class UnionFind3{
    private:
        int* parent;//parent指针指向一个专门用来记录元素父亲元素的指针
        int count;//计录集合中元素的数量
        int *size;
    public:
        UnionFind3(int n){
            parent=new int[n];//初始化parent数组
            size=new int[n];//size[i]表示以i为根的集合的元素个数
            count=n;
            /*
             * 切记一定要记得初始化parent数组
             * 使每个元素的parent指针都指向自己
             */
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;//最开始所有的元素都指向自己，每一个元素都是根元素，每一个集合只有一个元素
            }

        }

        ~UnionFind3(){
            delete []parent;
            delete []size;
        }
        //找出元素p位于的集合的编号
        //即返回根元素
        int find(int p){
            assert(p>=0&&p<count);//防止数组越界
            while(p != parent[p]){//如果p元素的父亲指针指向的不是自己，说明p并不是集合中的根元素，还需要一直向上查找
                p=parent[p];//p变成其父亲
            }
            return p;//经过while循环后，p=parent[p],一定是一个根节点，我们返回即可
        }
        //判断两个元素是否位于同一个集合当中
        bool isconnected(int p,int q){
            return find(p)==find(q);//p，q元素的根节点一样，则位于同一个集合当中
        }
        //合并两个元素所在的集合
        void unoinelements(int p,int q){
            int proot=find(p);//找出p元素位于的集合的根元素
            int qroot=find(q);//找出q元素位于的结合的根元素
            if(proot==qroot){//如果两个元素的根元素都为同一个元素，则它们已经在同一个集合当中了
                return;
            }
            else{//两个元素在不同的集合当中
                if(size[proot]<=size[qroot]) {//以p元素为根的集合的元素个数小于等于以q元素为根的集合的元素个数
                    parent[proot] = qroot;//p所在集合的根元素proot的父亲指针指向q元素所在的集合的根元素
                    size[qroot]+=size[proot];//以qroot为根的集合元素数量增加了，需要更新
                }
                else{
                    parent[qroot]=proot;//q元素所在的集合并入p元素所在的集合当中
                    size[proot]+=size[qroot];//更新size数组
                }
            }
        }


    };
}
#endif //UNIONFIND_UNIONFIND3_H
