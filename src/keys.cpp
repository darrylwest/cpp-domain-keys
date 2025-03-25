//
// 2025-03-24 17:01:53 dpw
//
#include <chrono>
#include <random>
#include <domainkeys/keys.hpp>
#include <domainkeys/base62.hpp>

namespace domainkeys::keys {
    // the min/max keeps the base62 encodeing to 3 chars 100..zzz
    constexpr int BASE62_MIN = 3844;
    constexpr int BASE62_MAX = 238327;

    inline std::random_device random_device;  // Obtain a random number from hardware
    inline std::mt19937 generator(random_device());

    inline auto random_int(int min = BASE62_MIN, int max = BASE62_MAX) {
        std::uniform_int_distribution<int> distr(min, max);
        return distr(generator);
    }

    std::time_t now_microseconds() {
        using namespace std::chrono;
        auto now = system_clock::now();
        return duration_cast<microseconds>(now.time_since_epoch()).count();
    }
    // TODO get now microseconds
    // TODO generate random int

    // TODO encode to base62
    // TODO decode base62 to int

    // create a new timestamp key
    TimestampKey create_timestamp_key() {
        auto now = now_microseconds();
        auto rand = random_int();

        auto s1 = domainkeys::base62::encodeBase62(now);
        auto s2 = domainkeys::base62::encodeBase62(rand);
        auto ss = s1 + s2;

        std::println("now: {} rand: {}, ss: {} size: {}", now, rand, ss, ss.size());

        return TimestampKey{ss};
    }

    // create the route key
    RouteKey create_route_key() {
        return RouteKey("1234567890123456");
    }
} // namespace domainkeys::keys
