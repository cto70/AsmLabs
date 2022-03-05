// AsmLab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
bool IsPalindrom_asm(__int32 a) {
    __int32 b = 0;
    bool IsPal = 0;
    __asm {
        mov EAX, a
        cmp EAX, 0
        je label2
        shl EAX, 1
        jb label2
        shr EAX, 1

        mov EBX, 10
        mov ECX, 0

        loop1:

        mov EDX, 0
            div EBX
            add b, EDX
            cmp EAX, 0

            je end_loop1

            mov EDX, b
            imul EDX, EBX
            mov b, EDX

            loop loop1

            end_loop1 :

        mov EAX, a
            cmp EAX, b
            jne label1
            mov IsPal, 1

            label1 :
            label2 :
    }
    return IsPal;
}

bool IsPalindrom_cpp(__int32 x) {
    if (x <= 0) {
        return false;
    }
    std::stringstream ss;
    ss << x;
    std::string s;
    ss >> s;
    for (__int32 i = 0; i <= s.size() / 2; i++) {
        if (s.at(i) != s.at(s.size() - i - 1)) {
            return false;
        }
    }
    return true;
}

bool TestIsPalinrom() {
    for (__int32 i = -1000000; i <= 1000000; i++) {
        if (IsPalindrom_asm(i) != IsPalindrom_cpp(i)) {
            return false;
        }
    }
    return true;
}
int CountFirst_asm(__int32 x) {
    __int32 result;
    __int32 sign = 1;
    __asm {
        mov EAX, 0


        mov EBX, 1
        mov ECX, 2
        loop1:
        imul EBX, x
            loop loop1
            add EAX, EBX


            sub EAX, 4


            imul EAX, 2


            mov EBX, 1
            mov ECX, 5
            loop2:
        imul EBX, x
            loop loop2
            add EAX, EBX


            add EAX, x


            mov EBX, 1
            mov ECX, 3
            loop3:
        imul EBX, x
            loop loop3


            mov EDX, 1
            cmp EAX, 0
            jg label1
            neg EAX
            neg EDX
            label1 :
        cmp EBX, 0
            jg label2
            neg EBX
            neg EDX
            label2 :
        mov sign, EDX


            mov EDX, 0
            div EBX
            imul EAX, sign
            mov result, EAX
    }
    return result;
}
int CountFirst_cpp(__int32 x) {
    return (((__int32)pow(x, 5) + 2 * ((__int32)pow(x, 2) - 4) + x)) / (__int32)pow(x, 3);
}

void Count(__int32 x) {
    std::cout << CountFirst_asm(x) << " " << CountFirst_cpp(x) << '\n';
}

bool TestCount() {
    for (__int32 i = -70; i <= -1; i++) {
        if (CountFirst_asm(i) != CountFirst_cpp(i)) {
            return false;
        }
    }
    for (__int32 i = 1; i <= 70; i++) {
        if (CountFirst_asm(i) != CountFirst_cpp(i)) {
            return false;
        }
    }
    return true;
}
int main()
{
    std::cout << TestIsPalinrom() << " " << TestCount();
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
