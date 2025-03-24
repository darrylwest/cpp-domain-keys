//
// 2025-03-24 17:01:53 dpw
//

#pragma once

#include <array>

namespace domainkeys::keys {
    constexpr size_t TXKEY_SIZE = 12;
    constexpr size_t RTKEY_SIZE = 16;

    // timestamp key with microsecond timestamp + 4 byte random bytes converted to base62
    struct TimestampKey {
        std::array<char, TXKEY_SIZE> data;
        constexpr size_t size() const { return TXKEY_SIZE; };

        constexpr auto begin() const {
            return data.begin();
        }

        constexpr auto end() const {
            return data.begin() + TXKEY_SIZE;
        }
    };

    // routing key with 4 byte route, microsecond timestamp + 4 byte random bytes converted to base62
    struct RouteKey {
        std::array<char, RTKEY_SIZE> data;
        constexpr size_t size() const { return RTKEY_SIZE; };

        constexpr auto begin() const {
            return data.begin();
        }

        constexpr auto end() const {
            return data.begin() + TXKEY_SIZE;
        }
    };

    // create a new timestamp key
    constexpr TimestampKey create_timestamp_key();

    // create the route key
    constexpr RouteKey create_route_key();
}
