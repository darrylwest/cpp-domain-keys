//
// dpw
//

#include <print>
#include <domainkeys/keys.hpp>

int main(int argc, char **argv) {
    using namespace domainkeys;

    if (argc < 2) {
        std::puts("USE: decode_txkey key\n");
        return 1;
    }

    auto k = std::string(argv[1]);
    auto ts = keys::decode_timestamp_key(k);
    std::println("key: {} -> ts: {} micros, ts: {} seconds", k, ts, ts / 1000000);

    return 0;
}
