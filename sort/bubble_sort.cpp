#include <utility>

template<class Iterater> 
void bubble_sort(Iterater first, Iterater last) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        for (auto iter = first; iter != last-i-1; iter++) {
            if (*iter > *(iter+1)) {
                std::swap(*iter, *(iter+1));
            }
        }
    }
}

template<class Iterater, class Compare>
void bubble_sort(Iterater first, Iterater last, Compare cmp) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        for (auto iter = first; iter != last-i-1; iter++) {
            if (!cmp(*iter, *(iter+1))) {
                std::swap(*iter, *(iter+1));
            }
        }
    }
}
