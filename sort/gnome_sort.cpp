#include <utility>

template<class RandomAccessIterator>
void gnome_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) {
        return;
    }

    auto iter = first + 1;
    while (iter != last) {
        if (*iter >= *(iter-1)) {
            iter++;
        } else {
            std::swap(*iter, *(iter-1));
            iter--;
            if (iter == first) {
                iter++;
            }
        }
    }
}

template<class RandomAccessIterator, class Compare>
void gnome_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    if (first == last) {
        return;
    }
    
    auto iter = first + 1;
    while (iter != last) {
        if (!cmp(*iter, *(iter-1))) {
            iter++;
        } else {
            std::swap(*iter, *(iter-1));
            iter--;
            if (iter == first) {
                iter++;
            }
        }
    }
}
