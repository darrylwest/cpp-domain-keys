//
// 2025-03-24 17:01:53 dpw
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function

#include <domainkeys/keys.hpp>
#include <print>
#include <vendor/ansi_colors.hpp>


struct MainTestSetup {
    MainTestSetup() {
        using namespace colors;
        std::println("\n{}Catch2 unit test setup;{}", bright::cyan, reset);
        std::println("{}Version {}{}\n", bright::yellow, domainkeys::keys::VERSION, reset);
        // start_config_service();
    }

    ~MainTestSetup() {
        // using namespace colors;
        // fmt::print("{}unit test tear-down.{}\n", green, reset);
        // app::cfgsvc::stop_worker();
    }
};

const MainTestSetup setup = MainTestSetup();

