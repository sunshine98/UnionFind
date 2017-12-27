#include <iostream>
#include "UnionFindTestHelper.h"
using namespace std;

int main() {
        int n=100000;
        UnionFindTestHelper::TestUF1(n);
        UnionFindTestHelper::TestUF2(n);
        UnionFindTestHelper::TestUF3(n);
        UnionFindTestHelper::TestUF4(n);
    return 0;
}