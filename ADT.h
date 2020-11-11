#pragma once
#include <vector>
#include <memory>
#include <stdlib.h>
#include <cmath>

using namespace std;

// From lab 6
void bubbleSort(std::shared_ptr<int[]> array, int size)
{
    bool isSorted = false; // we are done
    int bubbles = 1; // num operations

    while (!isSorted && (bubbles < size))
    {
        isSorted = true;
        for (int i = 0; i < size - bubbles; i++)
        {
            int nxt = i + 1;
            int count = 0;
            if (array[i] > array[nxt])
            {
                int temp_1 = array[i], temp_2 = array[nxt];
                array[i] = temp_2;
                array[nxt] = temp_1;
                isSorted = false;
            }
        }

        bubbles++;

    }
}

class  ArrayBasedQueue {
public:
    ArrayBasedQueue() {}
	ArrayBasedQueue(size_t size);
	virtual ~ArrayBasedQueue();
	bool isEmpty() const;
	bool isFull() const;
	bool enQueue(int val);
	bool deQueue();
    int GetSize();
	//If the ADT is empty throw an exception indicating this
	int Peek();
private:
    int array_size;
	std::shared_ptr<int[]> queue;
	int frontIndex, backIndex;
};

class IPriorityQueue
{
public:
    // Bool, return if Priority Queue is empty
    virtual bool IsEmpty() const = 0;
    // This will add an item to the queue in the appropriate location.
    virtual bool Insert(int payload) = 0;
    // This will remove an item from the queue from the appropriate location.
    virtual bool Remove(int payload) = 0;
    // Display Top Value
    // virtual shared_ptr<Node<int>> Peek() const = 0;

};


class QueuePriorityQueue : public IPriorityQueue
{
private:
    std::shared_ptr<ArrayBasedQueue> queue;

public:

    QueuePriorityQueue(size_t size) { queue = std::make_shared<ArrayBasedQueue>(size); }
    ~QueuePriorityQueue() {}

    bool IsEmpty() const override;
    bool Insert(int payload) override;
    bool Remove(int payload) override;
    int Peek() const;
    string PrintQueue() const;
    int GetSize() const;

};

class HeapPriorityQueue : public IPriorityQueue
{
private:
    HeapPriorityQueue() {};

    int GetNumberOfNode() const;
    int GetHeight() const;
    void Clear();
    void Organize(int root);

    int m_num_nodes;
    int m_cur_node;
    std::vector<int> m_nodes;

public:

    HeapPriorityQueue(int num_nodes) : m_num_nodes(num_nodes), m_cur_node(0)
    {
        for (int i=0; i < num_nodes; i++)
        {
            m_nodes.push_back(0);
        }
    }

    ~HeapPriorityQueue() {};

    bool IsEmpty() const override;
    bool Insert(int payload) override;
    bool Remove(int payload) override;
    int Peek() const;
    string PrintQueue() const;
};
