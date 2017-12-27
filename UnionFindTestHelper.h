//
// Created by Administrator on 2017/12/25.
//

#ifndef UNIONFIND_UNIONFINDTESTHELPER_H
#define UNIONFIND_UNIONFINDTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "UnionFind1.h"
#include "UnionFind2.h"
using namespace std;

//测试并查集的辅助函数
namespace UnionFindTestHelper {
    void TestUF1(int n) {//测试第一版本的并查集辅助函数
        srand(time(NULL));//初始化随机种子
        UF1::UnionFind1 uf = UF1::UnionFind1(n);//实例化UF1并查集
        time_t starttime = clock();//记录起始时间
        //进行n次操作，每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a=rand()%n;//随机选取a,b两个随机数
            int b=rand()%n;
            uf.unionElements(a,b);
        }

        //在进行n次查询操作
        for(int i=0;i<n;i++){
            int a=rand()%n;//随机选取a,b两个随机数
            int b=rand()%n;
            uf.isconnected(a,b);
        }

        time_t endtime=clock();//记录下所有操作结束时的时间点
        //打印输出耗时
        cout<<"UF1 have done:"<<2*n<<" performances,use time:"<<double(endtime-starttime)/CLOCKS_PER_SEC<<"s"<<endl;




    }


    void TestUF2(int n) {//测试第二版本的并查集辅助函数
        srand(time(NULL));//初始化随机种子
        UF2::UnionFind2 uf=UF2::UnionFind2(n);
        time_t starttime = clock();//记录起始时间
        //进行n次操作，每次随机选择两个元素进行合并操作
        for (int i = 0; i < n; i++) {
            int a=rand()%n;//随机选取a,b两个随机数
            int b=rand()%n;
            uf.unoinelements(a,b);
        }

        //在进行n次查询操作
        for(int i=0;i<n;i++){
            int a=rand()%n;//随机选取a,b两个随机数
            int b=rand()%n;
            uf.isconnected(a,b);
        }

        time_t endtime=clock();//记录下所有操作结束时的时间点
        //打印输出耗时
        cout<<"UF2 have done:"<<2*n<<" performances,use time:"<<double(endtime-starttime)/CLOCKS_PER_SEC<<"s"<<endl;




    }
}


#endif //UNIONFIND_UNIONFINDTESTHELPER_H
