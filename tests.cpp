#include <gtest/gtest.h>
#include "ADT.cpp"
#include <random>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;


static int randomData[5000] = {0};
std::string timer = "";

// Queue Tests
TEST(Queue, Empty)
{
    // create new queue
    auto pq = QueuePriorityQueue(0);

    string str = pq.PrintQueue();
    ASSERT_EQ(str, "");
}

TEST(Queue, Add)
{
    // create new queue
    auto pq = QueuePriorityQueue(2);
    
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
    auto pq = QueuePriorityQueue(3);
    
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

// Heap Tests
TEST(Heap, Empty)
{
    // create new queue
    HeapPriorityQueue hp(10);
    string str = hp.PrintQueue();
    ASSERT_EQ(str, "");
}

TEST(Heap, Add)
{
    // create new queue
    HeapPriorityQueue hp(10);
    hp.Insert(5);
    string str = hp.PrintQueue();
    ASSERT_EQ(str, "5 ");
    hp.Insert(10);
    str = hp.PrintQueue();
    ASSERT_EQ(str, "10 5 ");
}

TEST(Heap, Remove)
{
    // create new queue
    HeapPriorityQueue hp(10);
    hp.Insert(20);
    hp.Insert(15);
    hp.Insert(10);
    string str = hp.PrintQueue();
    ASSERT_EQ(str, "20 15 10 ");
    hp.Remove(15);
    str = hp.PrintQueue();
    ASSERT_EQ(str, "20 10 ");
    hp.Remove(20);
    str = hp.PrintQueue();
    ASSERT_EQ(str, "10 ");
}

TEST(Queue, FiveHundred)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    auto pq = QueuePriorityQueue(500);
    for (int i=0; i<500; i++)
    {
        pq.Insert(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Hundred Queue Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<500; i++)
    {
        pq.Remove(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Hundred Queue Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Queue, Thousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    auto pq = QueuePriorityQueue(1000);
    for (int i=0; i<1000; i++)
    {
        pq.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "One Thousand Queue Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        pq.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "One Thousand Queue Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Queue, TwoThousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    auto pq = QueuePriorityQueue(2000);
    for (int i=0; i<2000; i++)
    {
        pq.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Two Thousand Queue Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        pq.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Two Thousand Queue Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Queue, FiveThousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    auto pq = QueuePriorityQueue(5000);
    for (int i=0; i<5000; i++)
    {
        pq.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Thousand Queue Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        pq.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Thousand Queue Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Heap, FiveHundred)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    HeapPriorityQueue hp(500);
    for (int i=0; i<500; i++)
    {
        hp.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Hundred Heap Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        hp.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Hundred Heap Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Heap, Thousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    HeapPriorityQueue hp(1000);
    for (int i=0; i<1000; i++)
    {
        hp.Insert(randomData[i]);
    }

    // report time
    stop = high_resolution_clock::now();
    timer += "One Thousand Heap Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        hp.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "One Thousand Heap Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Heap, TwoThousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    HeapPriorityQueue hp(2000);
    for (int i=0; i<2000; i++)
    {
        hp.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Two Thousand Heap Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        hp.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Two Thousand Heap Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
}

TEST(Heap, FiveThousand)
{
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    
    HeapPriorityQueue hp(5000);
    for (int i=0; i<5000; i++)
    {
        hp.Insert(randomData[i]);
    }
    
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Thousand Heap Based Insertion: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";
    start = high_resolution_clock::now();
    // remove everything
    for (int i=0; i<1000; i++)
    {
        hp.Remove(randomData[i]);
    }
    // report time
    stop = high_resolution_clock::now();
    timer += "Five Thousand Heap Based Removal: " + to_string(duration_cast<microseconds>(stop-start).count());
    timer += "\n";

    std::cout << timer << std::endl;
    std::cout << "Time is in ms" << std::endl;

}


bool alreadyExists(int* data, size_t size, int payload)
{
    for (int i=0; i<size; i++)
    {
        if (data[i] == payload)
            return true;
    }

    return false;
}

int *getRandomData(int* data, size_t size)
{
    int randInt = 0;
    for (int i=0; i<size; i++)
    {
        randInt = rand() % size + 1; // can't be 0
        
        while (alreadyExists(data, size, randInt))
            randInt = rand() % size + 1;

        data[i] = randInt;

    }
    return data;
}


int main(int argc, char **argv) {

    srand(time(NULL));
    getRandomData(randomData, 5000);

    std::cout << timer << std::endl;

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}