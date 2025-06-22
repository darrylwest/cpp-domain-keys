//
// 2025-03-24 17:01:53 dpw
//
#include <chrono>
#include <domainkeys/base62.hpp>
#include <domainkeys/keys.hpp>

namespace domainkeys::keys {

    // TODO generate random int

    // TODO encode to base62
    // TODO decode base62 to int

    // create a new timestamp key
    TimestampKey create_timestamp_key() {
        auto now = now_microseconds();
        auto rand = random_int();

        auto ss = base62::encodeBase62(now) + base62::encodeBase62(rand);

        return TimestampKey{ss};
    }

    // decode the microsecond timestamp from the tx key
    int64_t decode_timestamp_key(const std::string &b62_str) {
        auto ts_part = b62_str.substr(0, 9);
        return base62::decodeBase62(ts_part);
    }

    // create the route key
    RouteKey create_route_key(const std::string &route) {
        std::string rt = route;
        while (rt.size() < 4) {
            int n = random_int(0, 61);
            rt.append(1, base62::base62_chars[n]);
        }

        auto tx = create_timestamp_key().to_string();
        return RouteKey(rt + tx);
    }

    // create a random key the lenth specified by size
    std::string create_random_key(size_t size) {
        std::string key;
        key.reserve(size);
        for (size_t i = 0; i < size; i++) {
            key.push_back(base62::base62_chars[random_int(0, 61)]);
        }
        return key;
    }
} // namespace domainkeys::keys
