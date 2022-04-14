// AsmTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <bitset>
#include <iostream>

int main()
{
    const int n = 4;
    int a[n];
    a[0] = 268500992;
    a[2] = 1073742336;
    a[3] = 2147483776;
    a[1] = 536903680;
    __asm {
        mov ESI, 0
    loop1:
        cmp ESI, n
        je end_loop1


        mov EAX, a[4 * ESI] // transformation of the left element
        shl EAX, 4
        shr EAX, 19
        shl EAX, 6
        mov EBX, EAX

        mov EAX, a[4 * ESI] 
        shl EAX, 19
        shr EAX, 26
        add EAX, EBX // finish transformation


        mov EDI, ESI
        inc EDI
        
    loop2:
        cmp EDI, n
        je end_loop2


        mov EDX, a[4 * EDI] // transformation of the right element
        shl EDX, 4
        shr EDX, 19
        shl EDX, 6
        mov EBX, EDX

        mov EDX, a[4 * EDI]
        shl EDX, 19
        shr EDX, 26
        add EDX, EBX // finish transformation


        cmp EAX, EDX
        jng label1
        
        mov EAX, EDX // changing elements
        mov ECX, a[4 * ESI]
        mov EDX, a[4 * EDI]
        mov a[4 * EDI], ECX
        mov a[4 * ESI], EDX // finish changing
    label1:

        inc EDI
        jmp loop2
    end_loop2:

        inc ESI 
        jmp loop1
    end_loop1:
    }
    for (int i = 0; i < n; i++) {
        std::cout << std::bitset<32>(a[i]) << " " << a[i] << "\n";
    }
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
