#include <utility>

template<class RandomAccessIterator>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        int cur = i;
        while (cur > 0) {
            int parent = (cur+1)/2-1;
            if (*(first+parent) < *(first+cur)) {
                std::swap(*(first+parent), *(first+cur));
                cur = parent;
            } else {
                break;
            }
        }
    }
    for (int i=1; i<len; i++) {
        std::swap(*first, *(last-i));
        int cur = 0;
        while (true) {
            int child1 = cur*2+1, child2 = cur*2+2;
            if (child1 >= len-i) {
                break;
            } else if (child2 >= len-i) {
                if (*(first+cur) < *(first+child1)) {
                    std::swap(*(first+cur), *(first+child1));
                    cur = child1;
                } else {
                    break;
                }
            } else {
                if (*(first+cur) < *(first+child1)) {
                    if (*(first+child1) < *(first+child2)) {
                        std::swap(*(first+cur), *(first+child2));
                        cur = child2;
                    } else {
                        std::swap(*(first+cur), *(first+child1));
                        cur = child1;
                    }
                } else if (*(first+cur) < *(first+child2)) {
                    std::swap(*(first+cur), *(first+child2));
                    cur = child2;
                } else {
                    break;
                }
            }
        }
    }
}

template<class RandomAccessIterator, class Compare>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        int cur = i;
        while (cur > 0) {
            int parent = (cur+1)/2-1;
            if (cmp(*(first+parent), *(first+cur))) {
                std::swap(*(first+parent), *(first+cur));
                cur = parent;
            } else {
                break;
            }
        }
    }
    for (int i=1; i<len; i++) {
        std::swap(*first, *(last-i));
        int cur = 0;
        while (true) {
            int child1 = cur*2+1, child2 = cur*2+2;
            if (child1 >= len-i) {
                break;
            } else if (child2 >= len-i) {
                if (cmp(*(first+cur), *(first+child1))) {
                    std::swap(*(first+cur), *(first+child1));
                    cur = child1;
                } else {
                    break;
                }
            } else {
                if (cmp(*(first+cur), *(first+child1))) {
                    if (cmp(*(first+child1), *(first+child2))) {
                        std::swap(*(first+cur), *(first+child2));
                        cur = child2;
                    } else {
                        std::swap(*(first+cur), *(first+child1));
                        cur = child1;
                    }
                } else if (cmp(*(first+cur), *(first+child2))) {
                    std::swap(*(first+cur), *(first+child2));
                    cur = child2;
                } else {
                    break;
                }
            }
        }
    }
}
