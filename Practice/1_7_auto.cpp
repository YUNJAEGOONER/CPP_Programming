#include <iostream>
#include <memory>
#include <tuple>

auto sum(int a, int b){
    return std::tuple{"sum:",a+b};
}

int practice1_7() {
    // C++ 17 version 사용하기 -> cmake에서 set(CMAKE_CXX_STANDARD 17)로 수정
    // auto를 활용해 type을 자동추론

    auto pa = std::make_unique<int>(1);
    auto pb = std::make_unique<int>(2);

    std::cout << *pa << ", " << *pb << std::endl;

    auto my_swap = [ ] (auto a, auto b) { auto temp = *a; *a = *b; *b=temp;};
    my_swap(pa.get(), pb.get());
    std::cout << "a: " << *pa << ", b: " << *pb << std::endl;

    auto [label, result] = sum(*pa, *pb);
    std::cout << label << result << std::endl;

    return 0;

}