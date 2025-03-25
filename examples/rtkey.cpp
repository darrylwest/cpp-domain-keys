//
// Created by Darryl West on 3/24/25.
//

#include <domainkeys/keys.hpp>
#include <print>

int main() {
    const auto key = domainkeys::keys::create_route_key();
    std::println("rt key size: {}", key.size());

    std::println("rt key: {}", key.to_string());

    return 0;
}
