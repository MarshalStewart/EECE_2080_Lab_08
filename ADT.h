#pragma once
#include <vector>
#include <memory>
#include <stdlib.h>
#include <cmath>

using namespace std;

template<typename PayloadType>
class Node
{
	Node();
	std::shared_ptr<Node> m_nxt;
	PayloadType m_payload;
public:
	Node(std::shared_ptr<Node> nxt, PayloadType payload) : m_nxt(nxt), m_payload(payload) {};
	~Node() {}
	std::shared_ptr<Node> GetNxt() { return m_nxt; }
	PayloadType GetPayload() { return m_payload; }
	void SetNxt(std::shared_ptr<Node> nxt) { m_nxt = nxt;  }
	void SetPayload(PayloadType payload) { m_payload = payload;  }
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
    shared_ptr<Node<int>> m_front_ptr;
    void SetFrontPtr(shared_ptr<Node<int>> front_ptr ) { m_front_ptr = front_ptr; }


public:

    QueuePriorityQueue() : m_front_ptr(nullptr) {}
    QueuePriorityQueue(shared_ptr<Node<int>> front_ptr) : m_front_ptr(front_ptr) {} 

    ~QueuePriorityQueue() {}

    bool IsEmpty() const override;
    bool Insert(int payload) override;
    bool Remove(int payload) override;
    shared_ptr<Node<int>> Peek() const;
    string PrintQueue() const;
    int GetSize() const;

    shared_ptr<Node<int>> GetFrontPtr() const { return m_front_ptr; };

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
