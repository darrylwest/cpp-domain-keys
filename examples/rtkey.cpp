//
// Created by Darryl West on 3/24/25.
//

#include <domainkeys/keys.hpp>
#include <print>

int main() {
    const auto key = domainkeys::keys::create_route_key();

    std::puts(key.to_string().c_str());

    return 0;
}
