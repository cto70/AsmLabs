// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
void function1() {
    const int l = 7;
    int arr[l];
    double pi[l];
    double two = 2, eight = 8, ten = 10;
    __asm {
        finit
        mov ESI, 0
        fld1 // accuracy
        fld ten
        fdiv st(1), st(0)
        fdivp st(1), st(0)

        fldz // number of operations
        fldz // result

    loop1:
        fld1
        faddp st(2), st(0)
        fld st(1)
        fld two
        fmulp st(1), st(0)
        fld1
        fsubp st(1), st(0)
        fld st(0)
        fmulp st(1), st(0)
        fld1
        fxch st(1)
        fdivp st(1), st(0)
        faddp st(1), st(0)



        fld st(0)
        fld eight
        fmulp st(1), st(0)
        fsqrt
        fst pi[8 * ESI]

        fldpi
        fsubp st(1), st(0)
        fabs

        fcomip st(0), st(3)
        jae label1

        fxch st(1)
        fist arr[4 * ESI]
        fxch st(1)


        inc ESI
        cmp ESI, l
        je end_loop1


        fld ten
        fdivp st(3), st(0)


    label1:
        jmp loop1
    end_loop1:
    }
    std::cout << std::setprecision(15) << "PI: " << 2 * asin(1) << '\n';
    for (int i = 0; i < l; i++) {
        std::cout << "Sign " << i + 1 << ":  " <<
            " Number of members: " << std::setprecision(15) << arr[i] <<
            "    PI: " << pi[i] << '\n';
    }
    std::cout << '\n';
}
void function2() {
    const int l = 10;
    int arr[l];
    double ln2[l];
    double four = 4;
    double two = 2;
    double ten = 10;
    __asm {
        finit
        mov ESI, 0
        fld1 // accuracy
        fld ten
        fdiv st(1), st(0)
        fdivp st(1), st(0)

        fldz // number of operations
        fldz // result

    loop1:
        fld1
        faddp st(2), st(0)
        fld st(1)
        fmul st(0), st(2)
        fld four
        fmulp st(1), st(0)
        fld1
        fsubp st(1), st(0)
        fmul st(0), st(2)
        fld1
        fxch st(1)
        fdivp st(1), st(0)
        faddp st(1), st(0)



        fld st(0)
        fld1
        faddp st(1), st(0)
        fld two
        fdivp st(1), st(0)
        fst ln2[8 * ESI]

        fldln2
        fsubp st(1), st(0)
        fabs

        fcomip st(0), st(3)
        jae label1

        fxch st(1)
        fist arr[4 * ESI]
        fxch st(1)


        inc ESI
        cmp ESI, l
        je end_loop1


        fld ten
        fdivp st(3), st(0)


    label1:
        jmp loop1
    end_loop1:
    }
    std::cout << std::setprecision(15) << "Logarithm2: " << log(2) << '\n';
    for (int i = 0; i < l; i++) {
        std::cout << "Sign " << i + 1 << ":  " <<
            " Number of members: " << std::setprecision(15) << arr[i] <<
            "    Logarithm2: " << ln2[i] << '\n';
    }
    std::cout << '\n';
}
void function3(double a, double b, double c, double step, double accuracy) {
    double x;
    double first = -10;
    double last = 10;
    double eleven = 11;
    double two = 2;
    double res = eleven + 1;
    __asm {
        finit
        fld first
        fld first
        fmul st(0), st(1)
        fld a
        fmulp st(1), st(0)
        fld b
        fld st(2)
        fld eleven
        faddp st(1), st(0)
        fdivp st(1), st(0)
        faddp st(1), st(0)
        fld c
        faddp st(1), st(0)

    loop1:
        fld st(1)
        fld step
        faddp st(1), st(0)
        fld st(0)
        fmul st(0), st(1)
        fld a
        fmulp st(1), st(0)
        fld b
        fld st(2)
        fld eleven
        faddp st(1), st(0)
        fdivp st(1), st(0)
        faddp st(1), st(0)
        fld c
        faddp st(1), st(0)

        fld st(0)
        fmul st(0), st(3)
        fldz
        fcomip st(0), st(1)
        fstp x
        jae end_loop1
        fxch st(2)
        fstp x
        fxch st(2)
        fstp x

        fld last
        fcomip st(0), st(2)
        jbe no_roots
        jmp loop1
    end_loop1:

    loop2:
        fld st(1)
        fadd st(0), st(4)
        fld two
        fdivp st(1), st(0)

        fld st(0)
        fmul st(0), st(1)
        fld a
        fmulp st(1), st(0)

        fld st(1)
        fld eleven
        faddp st(1), st(0)
        fld b
        fxch st(1)
        fdivp st(1), st(0)
        faddp st(1), st(0)
        fld c
        faddp st(1), st(0)

        fld st(0)
        fmul st(0), st(3)
        fldz
        fcomip st(0), st(1)
        fstp x
        jae label1
        fxch st(2)
        fstp x
        fxch st(2)
        fstp x
        jmp label2
    label1:
        fxch st(4)
        fstp x
        fxch st(4)
        fstp x
    label2:
        fld st(0)
        fabs
        fld accuracy
        fcomip st(0), st(1)
        fstp x
        jae end_loop2
        jmp loop2
    end_loop2:
        fxch st(1)
        fst res
    no_roots:
    }
    if (res < last) {
        std::cout << std::setprecision(15) << "The root is: " << res << '\n';
    }
    else {
        std::cout << "No roots or chose another splitting\n\n";
    }
}
int main()
{
    function1();
    function2();
    function3(1, 1, -1, 0.1, 0.0000000001);
}
