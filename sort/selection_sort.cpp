#include <utility>

template<class RandomAccessIterator> 
void selection_sort(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        auto next = first + i;
        for (auto iter = next; iter != last; iter++) {
            if (*iter < *next) {
                next = iter;
            }
        }
        std::swap(*(first+i), *next);
    }
}

template<class RandomAccessIterator, class Compare>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        auto next = first + i;
        for (auto iter = next; iter != last; iter++) {
            if (cmp(*iter, *next)) {
                next = iter;
            }
        }
        std::swap(*(first+i), *next);
    }
}
