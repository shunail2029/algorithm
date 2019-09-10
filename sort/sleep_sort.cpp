#include <iostream>
#include <mutex>
#include <thread>
#include <typeinfo>
#include <unistd.h>
#include <vector>

std::mutex m;

void sleeper(int time) {
    sleep(time);
    std::lock_guard<std::mutex> lk(m);
    std::cout << time << " ";
}

template<class RandomAccessIterator>
void sleep_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) {
        return;
    }
    auto val = *first;
    if (typeid(val) != typeid(int)) {
        std::cout << "this sort can only be used for int array." << std::endl;
        return;
    }
    for (auto iter = first; iter != last; iter++) {
        if (*iter < 0) {
            std::cout << "this sort cannot sort numbers less than zero." << std::endl;
            return;
        }
    }
    
    std::vector<std::thread> th;
    for (auto iter = first; iter != last; iter++) {
        th.push_back(std::thread(sleeper, *iter));
    }
    for (int i=0; i<(int)th.size(); i++) {
        th.at(i).join();
    }
    std::cout << std::endl;
}
