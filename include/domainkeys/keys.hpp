//
// 2025-03-24 17:01:53 dpw
//

#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <ctime>
#include <random>
#include <stdexcept>
#include <string>

namespace domainkeys::keys {
    constexpr std::string_view VERSION = "0.5.5-112";

    // the min/max keeps the base62 encoding to 3 chars 100..zzz
    constexpr size_t TXKEY_SIZE = 12;
    constexpr size_t RTKEY_SIZE = 16;

    constexpr int BASE62_MIN = 3844;
    constexpr int BASE62_MAX = 238327;

    inline std::random_device random_device; // Obtain a random number from hardware
    inline std::mt19937 generator(random_device());

    // return a random int between min/max bounds
    inline int random_int(int min = BASE62_MIN, int max = BASE62_MAX) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(generator);
    }

    // return a timestamp in microseconds
    inline std::time_t now_microseconds() {
        using namespace std::chrono;
        auto now = system_clock::now();
        return duration_cast<microseconds>(now.time_since_epoch()).count();
    }

    // return a timestamp in milliseconds
    inline std::time_t now_milliseconds() {
        using namespace std::chrono;
        auto now = system_clock::now();
        return duration_cast<milliseconds>(now.time_since_epoch()).count();
    }

    // return the unix timestamp
    inline std::time_t now_seconds() {
        using namespace std::chrono;
        auto now = system_clock::now();
        return duration_cast<seconds>(now.time_since_epoch()).count();
    }

    // timestamp key with microsecond timestamp + 4 byte random bytes converted to base62
    struct TimestampKey {
        std::array<char, TXKEY_SIZE> data{};
        [[nodiscard]] size_t size() const { return data.size(); };

        // construct from a string of exactly 12 chars
        explicit TimestampKey(const std::string &str) {
            if (str.size() != TXKEY_SIZE) {
                throw std::runtime_error("invalid timestamp key size");
            }
            std::copy(str.begin(), str.end(), data.begin());
        }

        [[nodiscard]] constexpr auto begin() const { return data.begin(); }

        [[nodiscard]] constexpr auto end() const { return data.begin() + TXKEY_SIZE; }

        [[nodiscard]] std::string to_string() const { return {data.data(), TXKEY_SIZE}; };
    };

    // routing key with 4 byte route, microsecond timestamp + 4 byte random bytes converted to base62
    struct RouteKey {
        std::array<char, RTKEY_SIZE> data{};
        [[nodiscard]] size_t size() const { return data.size(); };

        // construct from a string of exactly 16 chars
        explicit RouteKey(const std::string &str) {
            if (str.size() != RTKEY_SIZE) {
                throw std::runtime_error("invalid timestamp key size");
            }
            std::copy(str.begin(), str.end(), data.begin());
        }

        [[nodiscard]] constexpr auto begin() const { return data.begin(); }

        [[nodiscard]] constexpr auto end() const { return data.begin() + TXKEY_SIZE; }

        [[nodiscard]] std::string to_string() const { return {data.data(), RTKEY_SIZE}; };
    };

    // create a new timestamp key
    TimestampKey create_timestamp_key();

    // decode the microsecond timestamp from the tx key
    int64_t decode_timestamp_key(const std::string &b62_str);

    // create the route key
    RouteKey create_route_key(const std::string &route = "");

    // create a ramdom base62 key of a specified length
    std::string create_random_key(size_t size = 16);

} // namespace domainkeys::keys
