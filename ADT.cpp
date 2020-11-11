#include <iostream>
#include <string>
#include <memory>

#include "ADT.h"

/* Array Based Queue */

ArrayBasedQueue::ArrayBasedQueue(const size_t size) : 
    backIndex(0), frontIndex(0), array_size(size)
{   
    queue = shared_ptr<int[]> (new int[size]);
    for (int i=0; i<size; i++)
    {
        queue[i] = 0;
    }
}

ArrayBasedQueue::~ArrayBasedQueue() {}

bool ArrayBasedQueue::isEmpty() const
{
	return frontIndex == backIndex;
}

bool ArrayBasedQueue::isFull() const {
	if (backIndex - frontIndex == array_size)
		return true;
	else if (frontIndex - backIndex == array_size)
		return true;

	return false;
}

bool ArrayBasedQueue::enQueue(int val) {
	if(!isFull()) {
		queue[backIndex] = val;
		backIndex = (++backIndex) % array_size;
		return true;
	}
	else{
		return false;
	}

}

bool ArrayBasedQueue::deQueue() {
	if(!isEmpty()) {
		queue[frontIndex] = 0;
		frontIndex = (++frontIndex) % array_size;
		return true;
	}
	else{
		return false;
	}

}

int ArrayBasedQueue::Peek() {
	if (isEmpty())
	{
		throw "ADT is empty";
	}
	else
	{
		return queue[frontIndex];
	}
}

int ArrayBasedQueue::GetArraySize() { return array_size; } 

/* QueuePriorityQueue */

bool QueuePriorityQueue::IsEmpty() const { return (GetSize() == 0); }

bool QueuePriorityQueue::Insert(int payload)
{
    // Check if full
    if (queue->isFull())
        return false;

    // Add new payload
    queue->enQueue(payload);
    queue_size++;
    
    // Make a copy and get the size
    size_t buf_size = queue->GetArraySize();

    // populate data into tmp_array
    int tmp_array[buf_size] = {0};

    for (int i=0; i<queue_size; i++)
    {
        tmp_array[i] = queue->Peek();
        queue->deQueue();
    }
    
    bubbleSort(tmp_array, buf_size);

    for (int i=buf_size-1; i>=buf_size-queue_size; i--)
        queue->enQueue(tmp_array[i]);

    return true;
}

bool QueuePriorityQueue::Remove(int payload)
{
    // If the Queue is empty
    if (queue->isEmpty())
        return false;

    size_t buf_size = queue->GetArraySize();
    int tmp_array[buf_size] = {0};
    bool found_payload = false;


    for (int i=0; i<queue_size; i++)
    {
        if(queue->Peek() == payload)
            found_payload = true;
        else
            tmp_array[i] = queue->Peek();
        
        queue->deQueue();
    }

    if (found_payload)
        queue_size--;

    if(queue_size == 0)
        return true;

    // Organize and rebuild queue
    bubbleSort(tmp_array, buf_size);

    for (int i=0; i<queue_size; i++)
        queue->deQueue();

    for (int i=buf_size-1; i>=buf_size-queue_size; i--)
        queue->enQueue(tmp_array[i]);
    
    return true;

}

int QueuePriorityQueue::Peek() const { return queue->Peek(); }

string QueuePriorityQueue::PrintQueue() const
{
    string str = "";
    
    // Get the size
    size_t buf_size = queue->GetArraySize();

    // populate data into tmp_array
    int tmp_array[buf_size] = {0};

    for (int i=0; i<queue_size; i++)
    {
        tmp_array[i] = queue->Peek();
        queue->deQueue();
    }

    // Populate String
    for (int i=0; i<queue_size; i++)
    {
        str += to_string(tmp_array[i]);
        str += " ";
    }

    // Repopulate the queue
    for (int i=0; i<queue_size; i++)
        queue->enQueue(tmp_array[i]);
    
    // Print out and return 
    cout << str << endl;
    return str;
    
}

int QueuePriorityQueue::GetSize() const { return queue_size; }

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
