#include <iostream>
#include <string>
#include <memory>

#include "ADT.h"

/* QueuePriorityQueue */

bool QueuePriorityQueue::IsEmpty() const { return (GetSize() == 0); }

bool QueuePriorityQueue::Insert(int payload)
{
    auto node = make_shared<Node<int>>(nullptr, payload);
    auto cur_ptr = m_front_ptr;
    shared_ptr<Node<int>> prv_ptr = nullptr;

    // If the Queue is empty
    if (cur_ptr == nullptr)
    {
        m_front_ptr = node;
        return true;
    }

    // Loop till it's larger than or equal to cur
    while(payload < cur_ptr->GetPayload())
    {
        prv_ptr = cur_ptr;
        cur_ptr = cur_ptr->GetNxt();

        if (cur_ptr == nullptr) break;
    }

    // Check if there is a prv ptr, else set new node to front
    if (prv_ptr != nullptr)
        prv_ptr->SetNxt(node);
    else
        m_front_ptr = node; 

    node->SetNxt(cur_ptr);

    return true;

}

bool QueuePriorityQueue::Remove(int payload)
{
    auto cur_ptr = m_front_ptr;
    shared_ptr<Node<int>> prv_ptr = nullptr;

    // If the Queue is empty
    if (IsEmpty())
    {
        // m_front_ptr = node;
        return false;
    }

    // Loop till node is equal to cur
    while(payload < cur_ptr->GetPayload())
    {
        prv_ptr = cur_ptr;
        cur_ptr = cur_ptr->GetNxt();
    }

    // If we are larger than cur_ptr, couldn't find the node
    if (payload > cur_ptr->GetPayload())
    {
        return false;
    }

    // Remove the cur_ptr
    auto nxt_ptr = cur_ptr->GetNxt();
    if (prv_ptr != nullptr)
        prv_ptr->SetNxt(nxt_ptr);
    else
        m_front_ptr = nxt_ptr;

    return true;
}

shared_ptr<Node<int>> QueuePriorityQueue::Peek() const { return GetFrontPtr(); }

string QueuePriorityQueue::PrintQueue() const 
{
    auto cur_ptr = m_front_ptr;
    auto prv_ptr = cur_ptr;
    string str = "";

    // If the Queue is empty
    if (cur_ptr == nullptr)
    {
        return "";
    }

    // Loop till node is equal to cur
    while(cur_ptr != nullptr)
    {
        str += to_string(cur_ptr->GetPayload());
        str += " ";
        cur_ptr = cur_ptr->GetNxt();
    }

    // Print out and return 
    cout << str << endl;
    return str;
    
}

int QueuePriorityQueue::GetSize() const 
{
    shared_ptr<Node<int>> cur_ptr = m_front_ptr;
    int count = 0;
    while(cur_ptr != nullptr)
    {
        cur_ptr = cur_ptr->GetNxt();
        count++;
    }
    return count;
}

/* HeapPriorityQueue */
#if 0
int HeapPriorityQueue::GetNumberOfNode() const {}

int HeapPriorityQueue::GetHeight() const {}

shared_ptr<Node<int>> HeapPriorityQueue::PeekTop() const {}

void HeapPriorityQueue::Clear() {}

HeapPriorityQueue::HeapPriorityQueue() {}

HeapPriorityQueue::~HeapPriorityQueue() {}

bool HeapPriorityQueue::IsEmpty() const {}

bool HeapPriorityQueue::Insert(shared_ptr<Node<int>> node) {}

bool HeapPriorityQueue::Remove(shared_ptr<Node<int>> node) {}

shared_ptr<Node<int>> HeapPriorityQueue::Peek() const {}

void HeapPriorityQueue::PrintQueue() const {}

#endif // 0