#include <cstdio>
#include <memory>

#include <static-lib/sum.h>
#include <shared-lib/sub.h>
#include <shared-lib/mul.h>

#include <spdlog/spdlog.h>

extern std::shared_ptr<spdlog::logger> console_logger;
extern std::shared_ptr<spdlog::logger> basic_logger;
extern std::shared_ptr<spdlog::logger> err_logger;
extern std::shared_ptr<spdlog::logger> daily_basic_logger;

int main() {
    int a = 100;
    int b = 200;
    console_logger->info("sum({},{})={}\n", a, b, sum(a, b));
    daily_basic_logger->info("sub({},{})={}\n", a, b, sub(a, b));
    err_logger->info("mul({},{})={}\n", a, b, mul((double) a, (double) b));
    return 0;
}