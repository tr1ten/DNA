#include <iostream>
#include <utility>
#include <array>

// All done during compile time -------------------------------------------------------------------
constexpr bool isPrime(size_t n) noexcept {
    if (n <= 1) return false;
    for (size_t i = 2; i*i <= n; i++)   if (n % i == 0) return false;
    return true;
}
constexpr unsigned int primeAtIndex(size_t i) noexcept {
    size_t k{3};
    for  (size_t counter{}; counter < i; ++k)
        if (isPrime(k)) ++counter;
    return k-1;
}
// Some helper to create a constexpr std::array initilized by a generator function
template <typename Generator, size_t ... Indices>
constexpr auto generateArrayHelper(Generator generator, std::index_sequence<Indices...>) {
    return std::array<decltype(std::declval<Generator>()(size_t{})), sizeof...(Indices) > { generator(Indices)... };
}
template <size_t Size, typename Generator>
constexpr auto generateArray(Generator generator) {
    return  generateArrayHelper(generator, std::make_index_sequence<Size>());
}

// This is the definition of a std::array<unsigned int, 100> with prime numbers in it
constexpr auto Primes = generateArray<10000>(primeAtIndex);
// End of: All done during compile time -----------------------------------------------------------


// Some debug test driver code
int main() {
    for (const auto p : Primes) std::cout << p << ' '; std::cout << '\n';
    return 0;
}