//
// dpw
//

#pragma once

#include <algorithm>
#include <cstdint>
#include <cstring> // Required for std::strchr
#include <stdexcept>
#include <string>

namespace domainkeys::base62 {
    // The set of characters used for base62 encoding.
    static constexpr char base62_chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    /**
     * @brief Encodes a 64-bit integer into a base62 string.
     * @param value The integer to encode.
     * @return The base62 encoded string.
     */
    inline auto encodeBase62(long value) {
        if (value == 0) {
            return std::string(1, base62_chars[0]); // Handle the case for 0
        }

        std::string result;
        // Reserve space to avoid reallocations for typical 64-bit integers
        // A 64-bit unsigned integer will be at most 11 characters in base62.
        result.reserve(11);

        while (value > 0) {
            std::uint64_t remainder = value % 62;
            result.push_back(base62_chars[remainder]);
            value /= 62;
        }

        // The result is in reverse order, so we need to reverse it
        std::reverse(result.begin(), result.end());
        return result;
    }

    /**
     * @brief Decodes a base62 string into a 64-bit integer.
     * @param b62_str The base62 string to decode.
     * @return The decoded integer.
     * @throws std::invalid_argument if the string contains a character not in the base62 character set.
     */
    inline long decodeBase62(const std::string &b62_str) {
        long result = 0;

        for (char c: b62_str) {
            // Find the position of the character in our character set.
            // The position is its integer value.
            const char *p = std::strchr(base62_chars, c);

            if (p == nullptr) {
                // If the character is not found, it's invalid.
                throw std::invalid_argument("Invalid character in base62 string: " + std::string(1, c));
            }

            long value = p - base62_chars; // Calculate the integer value from the pointer offset.

            // Accumulate the result. This is equivalent to:
            // result = result + value * (62^power)
            result = result * 62 + value;
        }

        return result;
    }

} // namespace domainkeys::base62
