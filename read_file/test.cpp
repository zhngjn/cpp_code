#include <iostream>
#include <chrono>
#include "read1.hpp"
#include "read2.hpp"

int main(int argc, char** argv) {
    std::string path = argv[1];

    {
        auto begin_ts = std::chrono::steady_clock::now();

        for (std::size_t i = 0; i < 1000; i++) {
            std::string result;
            bool res = read1(path, result);
            if (!res) {
                std::cerr << "read1 failed" << std::endl;
            }
        }

        auto end_ts = std::chrono::steady_clock::now();

        auto elapse = std::chrono::duration_cast<std::chrono::microseconds>(end_ts - begin_ts);

        std::cout << "read1:" << (elapse.count() / 1000.0) << std::endl;
    }

    {
        auto begin_ts = std::chrono::steady_clock::now();

        for (std::size_t i = 0; i < 1000; i++) {
            std::string result;
            bool res = read2(path, result);
            if (!res) {
                std::cerr << "read2 failed" << std::endl;
            }
        }

        auto end_ts = std::chrono::steady_clock::now();

        auto elapse = std::chrono::duration_cast<std::chrono::microseconds>(end_ts - begin_ts);

        std::cout << "read2:" << (elapse.count() / 1000.0) << std::endl;
    }
}