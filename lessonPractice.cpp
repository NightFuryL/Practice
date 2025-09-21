#include <iostream>

using namespace std;

// Черга на основі масиву
template<typename T>
class Queue {
private:
    T* data;
    int capacity;
    int size;
    int front;
    int last;

    void reasize(int newCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }
public:
    Queue(int initCapacity = 10) :
        capacity(initCapacity), size(0), front(0), last(-1) {
		data = new T[capacity];
    }
    ~Queue() {
        delete[] data;
    }
    bool isEmpty() const {
        return size == 0;
	}
    int getSize() const {
        return size;
    }
    void clear() {
        size = 0;
        front = 0;
        last = -1;
	}
    void enqueue(const T& value) {
        if (size == capacity) {
            reasize(capacity * 2);
        }
        last = (last + 1) % capacity;
        data[last] = value;
        size++;
    }
    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
    T peek() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return data[front];
	}
};

int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;
    q.clear();
    cout << "Queue cleared. Is empty: " << q.isEmpty() << endl;
    return 0;
}

