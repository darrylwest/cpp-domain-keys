//
// 2025-03-24 17:01:53 dpw
//
#include <domainkeys/keys.hpp>

namespace domainkeys::keys {

    // create a new timestamp key
    TimestampKey create_timestamp_key() { return TimestampKey{}; }

    // create the route key
    RouteKey create_route_key() { return RouteKey{}; }
} // namespace domainkeys::keys
