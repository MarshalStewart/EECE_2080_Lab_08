#include <gtest/gtest.h>
#include "ADT.cpp"
#include <iostream>

using namespace std;

// Queue Tests
TEST(Queue, Empty)
{
    // create new queue
    auto pq = QueuePriorityQueue();

    string str = pq.PrintQueue();
    ASSERT_EQ(str, "");
}

TEST(Queue, Add)
{
    // create new queue
    auto pq = QueuePriorityQueue();
    
    pq.Insert(5);
    string str = pq.PrintQueue();
    ASSERT_EQ(str, "5 ");
    pq.Insert(10);
    str = pq.PrintQueue();
    ASSERT_EQ(str, "10 5 ");
}

TEST(Queue, Remove)
{
    // create new queue
    auto pq = QueuePriorityQueue();
    
    pq.Insert(20);
    pq.Insert(15);
    pq.Insert(10);
    string str = pq.PrintQueue();
    ASSERT_EQ(str, "20 15 10 ");
    pq.Remove(15);
    str = pq.PrintQueue();
    ASSERT_EQ(str, "20 10 ");
    pq.Remove(20);
    str = pq.PrintQueue();
    ASSERT_EQ(str, "10 ");
}

#if 0
// Heap Tests
TEST(Heap, Empty)
{
    // create new queue
    string str = pq.PrintQueue();
    ASSERT_EQ(str, "");
}

TEST(Heap, Add)
{
    // create new queue
    Insert(5);
    string str = PrintQueue();
    ASSERT_EQ(str, "5");
    Insert(10);
    string str = PrintQueue();
    ASSERT_EQ(str, "10 5");
}

TEST(Heap, Remove)
{
    // create new queue
    Insert(20);
    Insert(15);
    Insert(10);
    string str = PrintQueue();
    ASSERT_EQ(str, "20 15 10");
    Remove(15);
    string str = PrintPriorityQueue();
    ASSERT_EQ(str, "20 10");
    Remove(20);
    string str = PrintPriorityQueue();
    ASSERT_EQ(str, "10");
}
#endif //0


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}