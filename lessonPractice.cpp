#include <iostream>
#include "Stack.cpp"
#include "Queue.cpp"

using namespace std;

int main() {
    //1
    Stack<int> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    cout << "Stack: ";
    stack.print();
    cout << "Stack size : " << stack.size() << endl;
    cout << "Stack top : " << stack.peek() << endl;
    stack.pop();
    cout << "Stack after pop : ";
    stack.print();
    stack.clear();
    cout << "Stack after clear : ";
    stack.print();
    //2
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "Queue : ";
    queue.print();
    cout << "Queue size : " << queue.size() << endl;
    cout << "Queue front : " << queue.peek() << endl;
    queue.dequeue();
    cout << "Queue after dequeue : ";
    queue.print();
    queue.clear();
    cout << "Queue after clear : ";
    queue.print();

    return 0;
}