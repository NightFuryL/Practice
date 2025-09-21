#include "Node.cpp"
template <typename T>
class Stack {
private:
    Node<T>* top;
    int count;
public:
    Stack() : top(nullptr), count(0) {}
    ~Stack() {
        clear();
    }
    void push(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        ++count;
    }
    void pop() {
        if (isEmpty()) {
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        --count;
    }
    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return top->data;
    }
    bool isEmpty() const {
        return top == nullptr;
    }
    int size() const {
        return count;
    }
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
    void print() const {
        Node<T>* current = top;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};