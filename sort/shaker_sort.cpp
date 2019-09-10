#include <utility>

template<class RandomAccessIterator> 
void shaker_sort(RandomAccessIterator first, RandomAccessIterator last) {
    auto top = first, bottom = last-1;
    while (true) {
        auto last_change = top;
        for (auto iter = top; iter != bottom; iter++) {
            if (*iter > *(iter+1)) {
                std::swap(*iter, *(iter+1));
                last_change = iter;
            }
        }
        bottom = last_change;
        if (top == bottom) {
            break;
        }
        last_change = bottom;
        for (auto iter = bottom; iter != top; iter--) {
            if (*iter < *(iter-1)) {
                std::swap(*iter, *(iter-1));
                last_change = iter;
            }
        }
        top = last_change;
        if (top == bottom) {
            break;
        }
    }
}

template<class RandomAccessIterator, class Compare>
void shaker_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    auto top = first, bottom = last-1;
    while (true) {
        auto last_change = top;
        for (auto iter = top; iter != bottom; iter++) {
            if (cmp(*(iter+1), *iter)) {
                std::swap(*iter, *(iter+1));
                last_change = iter;
            }
        }
        bottom = last_change;
        if (top == bottom) {
            break;
        }
        last_change = bottom;
        for (auto iter = bottom; iter != top; iter--) {
            if (cmp(*iter, *(iter-1))) {
                std::swap(*iter, *(iter-1));
                last_change = iter;
            }
        }
        top = last_change;
        if (top == bottom) {
            break;
        }
    }
}
