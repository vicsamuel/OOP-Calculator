#include "Base_Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
#include <string>

int main(int argc, char *argv[])
{
    // ARRAY.CPP TEMPLATE BRIEF CHECK

    // template <typename T>
    // Array<T>::Array(size_t length, T fill)
    typedef Array<char> arrChar;
    arrChar a1(5, 'Z');
    for (int i = 0; i < 5; i++)
        std::cout << a1[i] << ", ";
    std::cout << '\n';

    // template <typename T>
    // void Array<T>::set(size_t index, T value)
    arrChar a2(7);
    a2.set(0, 'a');
    a2.set(1, 'b');
    a2.set(2, 'c');
    a2.set(3, 'd');
    a2.set(4, 'e');
    a2.set(5, 'f');
    a2.set(6, 'g');

    try
    {
        a2.find(10, 'h');
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Array a2: ";
    for (int i = 0; i < 7; i++)
    {
        std::cout << a2[i] << ", ";
    }
    std::cout << '\n';

    // Template change test
    typedef Array<std::string> arrString;
    arrString a3(3, "hi");
    for (int i = 0; i < 3; i++)
    {
        std::cout << a3[i] << ", ";
    }
    std::cout << '\n';

    a3.set(2, "NOPE");

    arrString a4(a3);
    for (int i = 0; i < 3; i++)
    {
        std::cout << a4[i] << ", ";
    }

    std::cout << '\n';

    // template <typename T>
    // int Array<T>::find(T value) const
    std::cout << "True statement (no index): " << a3.find("NOPE") << '\n';
    std::cout << "False statement (no index): " << a3.find("NO") << '\n';

    // template <typename T>
    // int Array::find(char ch, size_t start) const TESTED
    std::cout << "False statement (w/ index): " << a3.find("NO", 2) << '\n';
    std::cout << "True statement (w/ index): " << a3.find("NOPE", 2) << '\n';

    // NEW STACK TESTS

    // template <typename T>
    // void Stack <T>::push (T element)
    Stack<char> testStack;
    testStack.push('1');
    testStack.push('2');
    testStack.push('3');
    testStack.push('9');
    testStack.push('Q');
    testStack.print();
    std::cout << '\n';

    // // template <typename T>
    // // Stack <T>::Stack (const Stack & stack)
    // Stack<char> copyTest;
    // copyTest = testStack;
    // copyTest.print();
    // std::cout << '\n';

    // // template <typename T>
    // // void Stack <T>::pop (T element)
    // testStack.pop();
    // testStack.pop();
    // testStack.pop();
    // testStack.pop();
    // testStack.pop();
    // try
    // {
    //     copyTest.pop();
    // }
    // catch(std::runtime_error &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // //testStack.print();
    // std::cout << '\n';

    // // template <typename T>
    // // void Stack <T>::clear (void)
    // copyTest.clear();

    // try
    // {
    //     copyTest.print();
    // }
    // catch (std::runtime_error &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    //copyTest.print();
    std::cout << '\n';

    // template <typename T>
    // Queue<T>::Queue(void)
    Queue<char> testQueue;
    try
    {
        testQueue.dequeue();
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }

    // template <typename T>
    // Queue<T>::enqueue(T element)
    testQueue.enqueue('A');
    testQueue.enqueue('B');
    testQueue.enqueue('C');
    testQueue.enqueue('D');
    testQueue.print();
    std::cout << '\n';

    // template <typename T?
    // Queue<T>::dequeue(void)
    testQueue.dequeue();
    testQueue.dequeue();
    testQueue.dequeue();
    testQueue.dequeue();
    try
    {
        testQueue.dequeue();
    }
    catch(std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << '\n';
    testQueue.enqueue('A');
    testQueue.enqueue('B');
    testQueue.enqueue('C');
    testQueue.enqueue('D');
    testQueue.print();

    // template <typename T>
    // Queue<T>::Queue(const Queue &queue)
    Queue<char> copyQueue;
    std::cout << '\n';

    // Testing for resizing automatically
    copyQueue.enqueue('D');
    copyQueue.enqueue('E');
    copyQueue.enqueue('F');
    copyQueue.enqueue('G');
    copyQueue.enqueue('H');
    copyQueue.enqueue('I');
    copyQueue.enqueue('J');
    copyQueue.enqueue('J');
    copyQueue.enqueue('K');
    copyQueue.enqueue('L');
    copyQueue.enqueue('M');
    copyQueue.print();
    copyQueue.enqueue('N');
    copyQueue.enqueue('O');
    copyQueue.enqueue('P');
    copyQueue.enqueue('Q');
    copyQueue.enqueue('R');
    copyQueue.enqueue('S');
    copyQueue.enqueue('T');
    copyQueue.enqueue('U');
    copyQueue.enqueue('V');
    copyQueue.enqueue('W');
    copyQueue.enqueue('X');
    copyQueue.enqueue('Y');
    copyQueue.enqueue('Z');
    copyQueue.dequeue();
    copyQueue.dequeue();
    copyQueue.dequeue();
    copyQueue.dequeue();
    copyQueue.print();
    std::cout << '\n';

    // Fixed_Array(T fill);
    Fixed_Array<int, 5> fixedTest(100);

    for (int i = 0; i < 5; i++)
    {
        std::cout << fixedTest[i] << ", ";
    }
    std::cout << '\n';

    // Fixed_Array(const Fixed_Array<T, N> &arr);
    Fixed_Array<int, 5> copyFixed(fixedTest);
    for (int i = 0; i < 5; i++)
    {
        std::cout << copyFixed[i] << ", ";
    }
    std::cout << '\n';

    // Fixed_Array(void)
    Fixed_Array<int, 5> noargFixed;
    noargFixed = copyFixed;
    for (int i = 0; i < 5; i++)
    {
        std::cout << copyFixed[i] << ", ";
    }
    std::cout << '\n';

    return 0;
}
