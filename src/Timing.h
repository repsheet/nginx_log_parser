#pragma once

#include <utility>
#include <string>
#include <chrono>
#include <iostream>

#define TIME(Name) \
Timing __FILE____LINE____timing__{#Name}; \

struct Timing {
    explicit Timing(std::string name)
    : name(std::move(name))
    , before(std::chrono::high_resolution_clock::now())
    {}

    ~Timing() {
        auto after = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
        std::cout << name << " took " << duration << " millis" << std::endl;
    }
private:
    std::string name;
    std::chrono::time_point<std::chrono::high_resolution_clock> before;
};