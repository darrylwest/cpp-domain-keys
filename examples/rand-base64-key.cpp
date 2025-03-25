//
// Created by Darryl West on 3/25/25.
//
#include <print>
#include <domainkeys/keys.hpp>

int main(int argc, char** argv) {
    size_t size = 16;

    if (argc > 1) {
        size = std::stoi(argv[1]);
    }

    auto key = domainkeys::keys::create_random_key(size);
    std::puts(key.c_str());

    return 0;
}
