#pragma once

template <typename ItemType>
class IPriorityQueue
{
public:
    // Bool, return if Priority Queue is empty
    virtual bool IsEmpty() const = 0;
    // This will add an item to the queue in the appropriate location.
    virtual bool Insert(ItemType node) = 0;
    // This will remove an item from the queue from the appropriate location.
    virtual bool Remove(ItemType node) = 0;
    // Display Top Value
    virtual ItemType Peek() const = 0;

};


template <typename ItemType>
class QueuePriorityQueue : IPriorityQueue
{
    bool push(ItemType node);
    bool pop();

public:

    QueuePriorityQueue();
    ~QueuePriorityQueue();

    bool IsEmpty() const override;
    bool Insert(ItemType node) override;
    bool Remove(ItemType node) override;
    ItemType Peek() const override;
    void PrintQueue() const;
};


template <typename ItemType>
class HeapPriorityQueue : IPriorityQueue
{
    int GetNumberOfNode();
    int GetHeight();
    ItemType PeekTop();
    void Clear();

public:
    bool IsEmpty() const override;
    bool Insert(ItemType node) override;
    bool Remove(ItemType node) override;
    ItemType Peek() const override;
    void PrintHeap() const;
};
