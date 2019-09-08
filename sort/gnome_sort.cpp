#include <utility>

template<class RandomAccessIterater>
void gnome_sort(RandomAccessIterater first, RandomAccessIterater last) {
    if (first == last) return;
    auto iter = first + 1;
    while (iter != last) {
        if (*iter >= *(iter-1)) {
            iter++;
        }
        else {
            std::swap(*iter, *(iter-1));
            iter--;
            if (iter == first) {
                iter++;
            }
        }
    }
}

template<class RandomAccessIterater, class Compare>
void gnome_sort(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    if (first == last) return;
    auto iter = first + 1;
    while (iter != last) {
        if (!cmp(*iter, *(iter-1))) {
            iter++;
        }
        else {
            std::swap(*iter, *(iter-1));
            iter--;
            if (iter == first) {
                iter++;
            }
        }
    }
}
