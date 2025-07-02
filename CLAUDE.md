# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Domain Keys is a C++23 library for creating database keys based on timestamp and random characters for routing. The library provides compact, routable keys suitable for database sharding and domain-specific unique identifiers.

## Build System

**CMake Configuration:**
- Uses CMake 3.30.0 minimum
- C++23 standard required
- Catch2 3.x for testing
- Creates static library `libdomainkeys.a`

**Build Commands:**
```bash
# Initialize build directory
./mk init

# Build project
./mk build

# Run tests
./mk unit

# Run examples
./mk examples

# Format code
./mk format

# Watch for changes (requires watchexec)
./mk watch

# Full help
./mk help
```

**Direct CMake Usage:**
```bash
mkdir build && cd build
cmake ..
make -j8
./unit_tests
```

## Architecture

**Core Components:**
- `domainkeys::keys` namespace - Main API
- `TimestampKey` (12 chars) - Microsecond timestamp + random
- `RouteKey` (16 chars) - 4-char route prefix + TimestampKey  
- Base62 encoding for size reduction

**Key Features:**
- Timestamp-based for ordering capability
- Random routing for database sharding
- Base62 encoding: `[0-9][A-Z][a-z]`
- Uniform distribution for load balancing

**File Structure:**
- `include/domainkeys/` - Public headers
- `src/` - Implementation
- `tests/` - Catch2 unit tests
- `examples/` - Usage examples

## API

**Primary Functions:**
- `create_timestamp_key()` → TimestampKey (12 chars)
- `create_route_key(route="")` → RouteKey (16 chars)
- `create_random_key(size=16)` → std::string
- `decode_timestamp_key(key)` → int64_t microseconds

**Platform Specifics:**
- macOS: Universal binary support
- Linux: Static linking for libgcc/libstdc++
- Development: macOS clang 17.0.0, Ubuntu 24.10
- Target: Ubuntu 24.10 with gcc-14.2.0


