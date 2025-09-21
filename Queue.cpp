#include "Node.cpp"

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* tail;
    int count;
public:
    Queue() : front(nullptr), tail(nullptr), count(0) {}
    ~Queue() {
        clear();
    }
    void enqueue(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            front = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }
    void dequeue() {
        if (isEmpty()) {
            return;
        }
        Node<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            tail = nullptr;
        }
        delete temp;
        --count;
    }
    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return front->data;
    }
    bool isEmpty() const {
        return front == nullptr;
    }
    int size() const {
        return count;
    }
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void print() const {
        Node<T>* current = front;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};
