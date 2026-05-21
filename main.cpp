#include <iostream>
#include "winsock2.h"
#include <windows.h>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "ArraySequence.hpp"
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "MutableListSequence.hpp"
#include "MutableArraySequence.hpp"
#include "ImmutableArraySequence.hpp"
#include "SquareMatrix.hpp"
#include "Stack.hpp"
#include "my_types/Person.hpp"
#include "my_types/Complex.hpp"
#include "gui/app.hpp"
#include "hanoi/HanoiTower.hpp"

int main() {
    setlocale(LC_ALL, "C.UTF8");
    SetConsoleOutputCP(CP_UTF8);
    int result_q = run_gui();

    BitSequence<int> array();
   //SquareMatrix<Complex<double>, MutableArraySequence> mx1{{Complex<double>{1.1, 2.2}, Complex<double>{6.0, 3.0}}, {Complex<double>{1.0, 2.0}, Complex<double>{-1.0, -1.0}}};
   
 //SquareMatrix<Complex<double>, MutableArraySequence> mx2{{Complex<double>{1.1, 2.2}, Complex<double>{1.1, 2.2}}, {Complex<double>{1.1, 2.2}, Complex<double>{1.1, 2.2}}};
    
    //SquareMatrix<double, MutableArraySequence> mx1{{-1.0, -2.0}, {-3.0, 4.0}};
    // SquareMatrix<Complex<double>, MutableArraySequence> mx1{{1,2},{3,4}};
    // auto result = mx1.inverse();

    // SquareMatrix<int, MutableArraySequence> mx1{{1, 2}, {3, 4}};
    // SquareMatrix<int, MutableArraySequence> mx2{{1, 2}, {3, 4}};
    // auto result = mx1 + mx2;

    // std::cout << result[0][0] << " " << result[0][1] << std::endl;
    // std::cout << result[1][0] << " " << result[1][1] << std::endl;



    // Complex<double> z1(0, 1);
    // Complex<double> z2(1, 0);
    // Complex<double> z3(1, 1);
    // Complex<double> z4(0, -1);
    // Complex<double> z5(-1, 0);
    // Complex<double> z6(-1, -1);
    // Complex<double> z7(1, -1);
    // Complex<double> z8(-1, 1);
    // Complex<double> z9(0, 0);
    // std::string goida = z6.complex_to_string();
    // std::cout << goida.length() << std::endl;

    // std::cout << z1 << std::endl;
    // std::cout << z2 << std::endl;
    // std::cout << z3 << std::endl;
    // std::cout << z4 << std::endl;
    // std::cout << z5 << std::endl;
    // std::cout << z6 << std::endl;
    // std::cout << z7 << std::endl;
    // std::cout << z8 << std::endl;
    // std::cout << z9 << std::endl;
    // MutableArraySequence<Ring> rings;
    // rings.append(Ring(3, Color::Red));
    // rings.append(Ring(2, Color::Green));
    // rings.append(Ring(1, Color::Blue));

    // HanoiTower<Ring> tower;
    // tower.initialize(rings, 0);

    // while (!tower.is_finished()) {
    //     tower.do_move();
    // }

    // std::cout << tower.get_rod(1).top().get_size() << std::endl;
    // tower.get_rod(1).pop();
    // std::cout << tower.get_rod(1).top().get_size() << std::endl;
    // tower.get_rod(1).pop();
    // std::cout << tower.get_rod(1).top().get_size() << std::endl;
    // return 0;
    // Stack<int, MutableArraySequence> stack1;
    // stack1.push(24);
    // stack1.push(2444);
    // std::cout << stack1.top();
    // stack1.pop();
    // std::cout << stack1.top() << std::endl;

    // SquareMatrix<double, MutableArraySequence> matrix = {{1, 2}, {3, 4}};
    // SquareMatrix<int, MutableArraySequence> mx = {{1, 2}, {3, 4}};


    // // mx[0][0] = 4;
    // // mx[0][1] = 3;
    // // mx[1][0] = 2;
    // // mx[1][1] = 1;
    // mx.multiply_row(0, 5).multiply_row(0, 5);
    // std::cout << mx[0][0] << mx[0][1];
    // SquareMatrix<int, MutableArraySequence> res(2);
    // res = matrix.add(mx);
    // std::cout << res[0][0] << res[0][1] << res[1][0] << res[1][1];

    // Complex<int> z1(24, 22);
    // std::cout << z1.absolute() << std::endl << z1.absolute_squared();

    // SquareMatrix<Complex<double>, MutableArraySequence> matrix(3);
    // matrix[1][1] = Complex<double>(32, 33.1);
    // std::cout << matrix[1][1] << std::endl;

    // PersonID id1(4321, 31333);
    // Person person1(id1, "Бел", "Сер", "Дмит", time(nullptr) - 242424);
    // std::cout << person1.person_to_string() << std::endl;
    // std::cout << person1;

    // MutableListSequence<int> sequence;
    // sequence.append(0);
    // sequence.append(1);
    // sequence.append(2);
    // sequence.append(3);
    // sequence.append(4);
    // sequence.append(5);
    // sequence.append(6);
    // std::cout << sequence.get_last() << std::endl;
    // sequence.pop_last();
    // std::cout << sequence.get_last() << std::endl;
    // std::cout << sequence.get(3) << std::endl;
    // sequence.pop_at(3);
    // std::cout << sequence.get(3) << std::endl;
    // Stack<double, MutableArraySequence> stack1;

    // ImmutableArraySequence<int>* imseq = new ImmutableArraySequence<int>();
    // Sequence<int>* seq1 = imseq->append(42);
    // std::cout << seq1->get_first() << std::endl;
    // std::cout << imseq->get_first();
    // Stack<int, MutableListSequence> stack2;
    // stack1.append(234.012);
    // stack2.append(23);
    // auto b = stack2.get_last();

    // auto a = stack1.get_last();
    // std::cout << a << b;


    // Complex<double> z1(4.03, 6.13);
    // Complex<double> z2(1.04, 1.33);
    // Complex<double> result = z1 * z2;
    // std::cout << result;
    
    // Complex<int> z2(3, 4);

    // std::cout << z1-z2;


    
}

