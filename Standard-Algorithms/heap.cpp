#include <iostream>
#include <stdlib.h>
#include <limits.h>

void swap(int *a, int *b)
{
        int temp = *b;
        *b = *a;
        *a = temp;
}

class Minheap
{
        int *heap;
        int capacity;
        int heap_size;
        public:
        Minheap();
        Minheap(int);
        int left(int);
        int right(int);
        int parent(int i) { return (i - 1) / 2; }
        void MinHeapify(int);
        int insert(int);
        void deleteKey(int);
        int getMin();
        int extractMin();
        void decreaseKey(int, int);
        private:
};

Minheap::Minheap(int _capacity)
{
        capacity = _capacity;
        heap = (int*)malloc(capacity * sizeof(int));
        heap_size = 0;
}

int Minheap::getMin()
{
        return *heap;
}

int Minheap::left(int node)
{
        if (((node * 2) + 1) < capacity)
                return (node * 2) + 1;
        return -1;
}

int Minheap::right(int node)
{
        if (((node * 2) + 2) < capacity)
                return (node * 2) + 2;
        return -1;
}

void Minheap::MinHeapify(int i)
{
        int minNode = i;
        int minValue = *(heap + i);

        if (left(i) != -1 && heap[left(i)] < minValue ) {
                minNode = left(i);
                minValue = heap[left(i)];
        }

        if (right(i) != -1 && heap[right(i)] < minValue ) {
                minNode = right(i);
                minValue = heap[right(i)];
        }

        if (minNode != i) {
                swap(heap + i, heap + minNode);
                MinHeapify(minNode);
        }
}

void Minheap::decreaseKey(int node, int value)
{
        heap[node] = value;
        int i = node;
        while (i != 0 && heap[parent(i)] > heap[node]) {
                swap(heap + parent(i), heap + node);
                node = parent(node);
        }
}

int Minheap::extractMin()
{
        swap(heap, (heap + capacity - 1));
        capacity--;
        MinHeapify(0);
}

int Minheap::insert(int num)
{
        if (heap_size == capacity) {
                std::cout << "Heap full" << std::endl;
                return 1;
        }
        heap[++heap_size] = num;
        if (heap_size == 1)
                return 0;
        int i = heap_size - 1;
        while (i != 0 && heap[parent(i)] > heap[i]) {
                swap(heap + parent(i), heap + i);
                i = parent(i);
        }
}

void Minheap::deleteKey(int i)
{
        decreaseKey(heap_size, INT_MAX);
        extractMin();
}

int main()
{
        return 0;
}
