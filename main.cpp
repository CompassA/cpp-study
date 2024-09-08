#include <cstdio>

#include <static-lib/sum.h>
#include <shared-lib/sub.h>
#include <shared-lib/mul.h>

int main() {
    int a = 100;
    int b = 200;
    std::printf("sum(%d,%d)=:%d\n", a, b, sum(a, b));
    std::printf("sub(%d,%d)=%d\n", a, b, sub(a, b));
    std::printf("mul(%d,%d)=%f\n", a, b, mul((double) a, (double) b));
    return 0;
}