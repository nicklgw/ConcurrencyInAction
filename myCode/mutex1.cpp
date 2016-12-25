#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

std::list<int> listTest;
std::mutex listMutex;

void addToList(int value)
{
    std::lock_guard<std::mutex> guard(listMutex);
    listTest.push_back(value);
    return;
}

bool isListContain(int value)
{
    std::lock_guard<std::mutex> guard(listMutex);
    return std::find(listTest.begin(), listTest.end(), value)
            != listTest.end();
}

int main()
{
    addToList(42);
    std::cout<<"contains(1)="<<isListContain(1)<<", contains(42)="<<isListContain(42)<<std::endl;
}
