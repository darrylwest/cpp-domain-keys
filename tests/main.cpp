//
// 2025-03-24 17:01:53 dpw
//
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function

#include <vendor/ansi_colors.hpp>
#include <print>


struct MainTestSetup {
    MainTestSetup() {
        using namespace colors;
        std::print("{}Catch2 unit test setup.{}\n", green, reset);
        // start_config_service();
    }

    ~MainTestSetup() {
        // using namespace colors;
        // fmt::print("{}unit test tear-down.{}\n", green, reset);
        // app::cfgsvc::stop_worker();
    }
};

const MainTestSetup setup = MainTestSetup();

