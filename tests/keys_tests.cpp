//
// 2025-03-24 17:01:53 dpw
//

#include <domainkeys/keys.hpp>
#include <catch2/catch_all.hpp>  // For Catch2 v3
#include <print>
#include <chrono>
#include <iomanip>

auto date_to_timestamp(const int year, const int month = 12, const int day = 31) {
    std::tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;

    std::time_t tt_value = mktime(&tm);
    // Create a time_point from time_t
    auto time_point = std::chrono::system_clock::from_time_t(tt_value);

    // Convert time_point to microseconds since epoch
    auto duration = time_point.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

TEST_CASE("Library Version", "[version]") {
    REQUIRE(domainkeys::keys::VERSION >= "0.5.1-100");
    std::string version = std::string(domainkeys::keys::VERSION);
    REQUIRE(version.size() >= 8);
    REQUIRE(version.starts_with("0.5"));
}

TEST_CASE("TimestampKeys constructed", "[keys][txkey]") {
    domainkeys::keys::TimestampKey key("123456789012");
    REQUIRE(key.size() == domainkeys::keys::TXKEY_SIZE);
    REQUIRE(true);
}

TEST_CASE("RouteKeys can be constructed", "[keys][rtkey]") {
    domainkeys::keys::RouteKey key("1234567890123456");
    REQUIRE(key.size() == domainkeys::keys::RTKEY_SIZE);
    REQUIRE(true);
}

TEST_CASE("TimstampKeys min/max", "[keys][txkey-min-max]") {
    int year = 2020;
    auto past_date = date_to_timestamp(year, 1, 1);
    std::println("past: {}-{}-{} {}", year, 12, 31, past_date);

    auto sdt = std::to_string(past_date);

    INFO("test the string length of past date to ensure it's 16 chars");
    REQUIRE(sdt.size() == 16);

    year = 2300;
    auto future_date = date_to_timestamp(year, 12, 31);
    std::println("future: {}-{}-{} ts: {}", year, 12, 31, future_date);

    sdt = std::to_string(future_date);

    INFO("test the string length of the future date to ensure it's 17 chars");
    REQUIRE(sdt.size() == 17);
}

// TODO test base62 for int = 3843; should == zz
// TODO test timestamp key length for dates between 2020 and 2300 to ensure 12 chars
// TODO test route key length for dates between 2020 and 2300 to ensure 16 chars
