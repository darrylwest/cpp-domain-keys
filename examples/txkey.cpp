//
// Created by Darryl West on 3/24/25.
//

// #include <domainkeys/keys.hpp>
#include <print>
#include <domainkeys/keys.hpp>

int main(int argc, char **argv) {
    using namespace domainkeys;
    const auto key = keys::create_timestamp_key();

    if (argc == 1) {
        std::puts(key.to_string().c_str());
    } else {
        auto k = key.to_string();
        std::println("{} {}", k, keys::decode_timestamp_key(k));
    }

    return 0;
}
