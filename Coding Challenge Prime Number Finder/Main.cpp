/*
Rafael Gallegos Cespedes
Computer Science Fall 2024
Due: Nov 11, 2024
Coding Challenge Prime Number Finder
*/
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    // Define range
    const int limit = 1000000;

    // Timing start
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // Create a boolean vector for the sieve
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

    // Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    // Collect primes
    std::vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // Timing end
    end = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsed = end - start;

    // Output results
    std::cout << "Found " << primes.size() << " primes between 1 and " << limit << ".\n";
    std::cout << "Elapsed time: " << elapsed.count() << " seconds.\n";

    return 0;
}
