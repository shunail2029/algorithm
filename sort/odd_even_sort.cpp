#include <utility>

template<class RandomAccessIterator>
void odd_even_sort(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i=0; i<len-1; i+=2) {
            if (*(first+i) > *(first+i+1)) {
                std::swap(*(first+i), *(first+i+1));
                changed = true;
            }
        }
        for (int i=1; i<len-1; i+=2) {
            if (*(first+i) > *(first+i+1)) {
                std::swap(*(first+i), *(first+i+1));
                changed = true;
            }
        }
    }
}

template<class RandomAccessIterator, class Compare>
void odd_even_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i=0; i<len-1; i+=2) {
            if (cmp(*(first+i+1), *(first+i))) {
                std::swap(*(first+i), *(first+i+1));
                changed = true;
            }
        }
        for (int i=1; i<len-1; i+=2) {
            if (cmp(*(first+i+1), *(first+i))) {
                std::swap(*(first+i), *(first+i+1));
                changed = true;
            }
        }
    }
}
