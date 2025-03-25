//
// 2025-03-24 17:01:53 dpw
//
#include <domainkeys/keys.hpp>
#include <chrono>

namespace domainkeys::keys {
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
        // fetch now in microseconds
        // fetch
        return TimestampKey("123456789012");
    }

    // create the route key
    RouteKey create_route_key() {
        return RouteKey("1234567890123456");
    }
} // namespace domainkeys::keys
