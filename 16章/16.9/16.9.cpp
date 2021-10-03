#include <iostream>
#include <vector>
template <typename Container>
void print_16_19(const Container& c) {
    for (typename Container::size_type i = 0; i != c.size(); i++) {
        std::cout << c[i] << "    ";
    }
    std::cout << std::endl;
}

int main()
{
    auto vec = std::vector<int>{ 1,2,3,4,5,6 };
    print_16_19(vec);
}
