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
int HeapPriorityQueue::GetNumberOfNode() const 
{
    // loop through every node
        // count++
    // return count
    return m_cur_node-1;
}

int HeapPriorityQueue::GetHeight() const 
{
    // has height n if GetNumberOfNode() returns a number greater than or equal to 2^(n-1) and less than 2^n
    int n = 0;
    for (int cur_node=0; cur_node <= m_cur_node; cur_node++)
    {
        if (cur_node >= pow(2, n-1) && cur_node < pow(2, n))
            n++;
    }

    return n;
}

void HeapPriorityQueue::Clear() { m_nodes = {0}; m_cur_node = 0; }

bool HeapPriorityQueue::IsEmpty() const { return (m_cur_node == 0); }

void HeapPriorityQueue::Organize(int root) 
{
    // highest payload is on top of the heap
    int root_val = 0;
    int left_child = 0;
    int right_child = 0;
    int cur_node = 0; 
    int larger_child = 0;

    while(cur_node < m_num_nodes)
    {
        root_val = m_nodes[root];
        left_child = ((root+1) * 2) - 1;
        right_child = ((root+1) * 2);
        
        // Only care about the larger child for swaps
        if (m_nodes[left_child] > m_nodes[right_child])
            larger_child = left_child;
        else
            larger_child = right_child;

        // Check if we can swap
        if (root_val < m_nodes[larger_child])
        {
            m_nodes[root] = m_nodes[larger_child]; 
            m_nodes[larger_child] = root_val;
            if (m_cur_node >= larger_child)
            {
                Organize(larger_child); // recursion
            }
        
        }
        
        cur_node++;
    }
    

}

bool HeapPriorityQueue::Insert(int payload) 
{
    for (int i=0; i <= m_cur_node; i++)
    {
        if (m_nodes[i] == payload)
            return false;
    }
    
    // Insert new node
    m_cur_node++;
    m_nodes[m_cur_node] = payload;
    Organize(0);
    return true;
}

bool HeapPriorityQueue::Remove(int payload) 
{
    // if node is leaf node, remove
    // else if not a leaf node, bump the correct child node up and continue until leaf nodes are reached
    
    // bump leaf nodes to fill required spaces
    bool found_node = false;
    for (int node=0; node <= m_cur_node; node++)
    {
        if (m_nodes[node] == payload)
        {
            found_node = true;
            m_nodes[node] = 0;
            Organize(0);
            m_cur_node--;
            return true;
        }
    }
    
    return false;
    
}

int HeapPriorityQueue::Peek() const { /* return top node */ return m_nodes[0]; }

std::string HeapPriorityQueue::PrintQueue() const 
{
    // loop through heap
        // add payload of each node to str

    // return str
    std::string str = "";
    for (auto i : m_nodes)
    {
        if (i != 0)
        {
            str += to_string(i);
            str += " ";
        }
    }

    std::cout << str << std::endl;
    return str;

}
