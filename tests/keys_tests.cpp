//
// 2025-03-24 17:01:53 dpw
//

#include <domainkeys/keys.hpp>
#include <catch2/catch_all.hpp>  // For Catch2 v3

TEST_CASE("TimestampKeys constructed", "[keys][txkey]") {
    domainkeys::keys::TimestampKey key{};
    REQUIRE(key.size() == domainkeys::keys::TXKEY_SIZE);
    REQUIRE(true);
}

TEST_CASE("RouteKeys can be constructed", "[keys][rtkey]") {
    domainkeys::keys::RouteKey key{};
    REQUIRE(key.size() == domainkeys::keys::RTKEY_SIZE);
    REQUIRE(true);
}
