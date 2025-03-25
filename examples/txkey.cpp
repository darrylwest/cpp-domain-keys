//
// Created by Darryl West on 3/24/25.
//

// #include <domainkeys/keys.hpp>
#include <print>

#include <domainkeys/keys.hpp>

int main() {
    const auto key = domainkeys::keys::create_timestamp_key();

    std::puts(key.to_string().c_str());

    return 0;
}
