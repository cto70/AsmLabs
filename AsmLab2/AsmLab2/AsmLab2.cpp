// AsmLab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void function1() {
    unsigned int a;
    std::cin >> a;
    unsigned int sum;
    __asm {
        mov EAX, 0


        mov EDX, 1
        mov ECX, 12
    loop1:
        imul EDX, a
    loop loop1
        add EAX, EDX


        mov EDX, 1
        mov ECX, 8
    loop2:
        imul EDX, a 
    loop loop2
        add EAX, EDX


        add EAX, a


        mov sum, EAX
    }
    std::cout << "a = " << a << '\n';
    std::cout << "a^12 + a^8 + a = " << sum;
}

void function2(unsigned int a, unsigned int b, unsigned int result) {
    unsigned int* x = new unsigned int[result + 1];
    unsigned int* y = new unsigned int[result + 1];
    int result_ = result;
    unsigned int n;
    __asm {
        mov ESI, 0 // index of array
        mov EDI, 0 // x
        mov EAX, result_
    loop1:
        mov result_, EAX
        mov EDX, 0
        mov ECX, b
        cdq
        div ECX
        cmp EDX, 0
        jne label1
        mov EDX, x
        mov[EDX + 4 * ESI], EDI
        mov EDX, y
        mov[EDX + 4 * ESI], EAX
        inc ESI
    label1:
        mov EAX, result_
        sub EAX, a
        inc EDI
        cmp EAX, 0
        jl end_loop1
        jmp loop1
    end_loop1 :
        mov n, ESI
    }
    std::cout << "Number of solution of the equation " << a << "x + " << b << "y = " << result << " is " << n << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << "x = " << x[i] << ", y = " << y[i] << '\n';
    }
}

void function3() {
    unsigned int a[100];
    int n;
    __asm {
        mov a[0], 0
        mov a[4], 1
        mov ESI, 1
        mov EAX, a[0]
        mov EDX, a[4]
    loop1:
        add EAX, EDX
        jc end_loop1
        mov ECX, EAX
        mov EAX, EDX
        mov EDX, ECX
        inc ESI
        mov a[4 * ESI], EDX
        jmp loop1
    end_loop1 :
        mov n, ESI
    }
    std::cout << "Number of Fibonacci numbers is " << n + 1 << '\n';
    for (int i = 0; i <= n; i++) {
        std::cout << "F" << i << " = " << a[i] << '\n';
    }
}

void function4(int a, unsigned int b) {
    int a_, b_;
    int gcd;
    __asm {
        mov EAX, a
        mov ECX, b
    loop1:
        mov EDX, 0
        cdq
        idiv ECX
        mov EAX, ECX
        mov ECX, EDX
        cmp ECX, 0
        jne label2
        mov gcd, EAX
        jmp end_loop1
    label2:
        jmp loop1
    end_loop1:

        mov EAX, a
        mov ECX, gcd
        mov EDX, 0
        cdq
        idiv ECX
        mov a_, EAX

        mov EAX, b
        mov EDX, 0
        cdq
        idiv ECX
        mov b_, EAX

        cmp b_, 0
        jg label3
        neg a_
        neg b_
    label3:

        cmp gcd, 0
        jg label4
        neg gcd
    label4:
    }
    std::cout << "Numerator is " << a_ << '\n';
    std::cout << "Denominator is " << b_ << '\n';
    std::cout << "GCD is " << gcd;
}
int main()
{
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
