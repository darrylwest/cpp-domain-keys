//
// Created by Darryl West on 3/24/25.
//

#include <domainkeys/keys.hpp>
#include <print>

int main(int argc, char** argv) {
    std::string route;

    if  (argc > 1) {
        route = argv[1];
    }
    const auto key = domainkeys::keys::create_route_key(route);

    std::puts(key.to_string().c_str());

    return 0;
}
