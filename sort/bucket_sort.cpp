#include <iostream>
#include <new>
#include <typeinfo>

template<class RandomAccessIterator>
void bucket_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) {
        return;
    }
    
    if (typeid(*first) != typeid(int)) {
        std::cout << "this sort can only be used for int array." << std::endl;
        return;
    }

    int mini = INT32_MAX, maxi = INT32_MIN;
    for (auto iter = first; iter != last; iter++) {
        mini = std::min(mini, *iter);
        maxi = std::max(maxi, *iter);
    }
    unsigned int range = maxi - mini + 1;
    
    int *cnt = new int[range];
    for (unsigned int i=0; i<range; i++) {
        cnt[i] = 0;
    }

    for (auto iter = first; iter != last; iter++) {
        cnt[*iter-mini]++;
    }

    int cur = 0;
    unsigned int put = 0;
    while (true) {
        while (cnt[put] == 0 && put < range) {
            put++;
        }
        if (put == range) {
            break;
        }
        while (cnt[put] > 0) {
            *(first+cur) = put + mini;
            cur++;
            cnt[put]--;
        }
    }

    delete [] cnt;
}
