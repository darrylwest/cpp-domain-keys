//
// Created by Darryl West on 3/24/25.
//

// #include <domainkeys/keys.hpp>
#include <print>

#include <domainkeys/keys.hpp>

int main() {
    const auto key = domainkeys::keys::create_timestamp_key();
    std::println("ts key size: {}", key.size());

    std::println("ts key: {}", key.to_string());

    return 0;
}
