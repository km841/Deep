#include <iostream>

namespace OP
{   
    template<typename T>
    struct Plus
    {
        inline T operator()(T a, T b) const { return a + b; }
        inline T operator()(T a, T b) { return a + b; }
    };

    template<typename T>
    struct Minus
    {
        inline T operator()(T a, T b) const { return a - b; }
        inline T operator()(T a, T b) { return a - b; }
    };

    template<typename T>
    struct Multifly
    {
        inline T operator()(T a, T b) const { return a * b; }
        inline T operator()(T a, T b) { return a * b; }
    };

    template<typename T>
    struct Divide
    {
        inline T operator()(T a, T b) const { return a / b; }
        inline T operator()(T a, T b) { return a / b; }
    };

}

template<typename T, typename U> auto Operator(T arg1, T arg2, U func)
{
    return func(arg1, arg2);
}

int main()
{
    int a, b;
    char op;

    OP::Plus<int> f_plus;
    OP::Minus<int> f_minus;
    OP::Multifly<int> f_multiply;
    OP::Divide<int> f_divide;

    std::cout << "두 수를 공백으로 구분해서 입력하세요" << std::endl << ">>>";
    std::cin >> a >> b;
    
    std::cout << "연산자를 입력하세요" << std::endl << ">>>";
    std::cin >> op;

    switch (op)
    {
    case '+':
        std::cout << "답 : " << Operator(a, b, f_plus) << std::endl;
        break;

    case '-':
        std::cout << "답 : " << Operator(a, b, f_minus) << std::endl;
        break;

    case '*':
        std::cout << "답 : " << Operator(a, b, f_multiply) << std::endl;
        break;

    case '/':
        std::cout << "답 : " << Operator(a, b, f_divide) << std::endl;
        break;
    }
}
