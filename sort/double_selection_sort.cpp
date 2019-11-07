#include <utility>

template<class RandomAccessIterator> 
void double_selection_sort(RandomAccessIterator first, RandomAccessIterator last) {
    auto top = first, bottom = last;
    while (top != bottom && top != bottom-1) {
        auto mini = top, maxi = top;
        for (auto iter = top; iter != bottom; iter++) {
            if (*iter < *mini) {
                mini = iter;
            }
            if (*iter >= *maxi) {
                maxi = iter;
            }
        }
        if (maxi == top && mini == bottom-1) {
            std::swap(*top, *(bottom-1));
        } else if (maxi == top) {
            std::swap(*(bottom-1), *maxi);
            std::swap(*top, *mini);
        } else {
            std::swap(*top, *mini);
            std::swap(*(bottom-1), *maxi);
        }
        top++;
        bottom--;
    }
}

template<class RandomAccessIterator, class Compare>
void double_selection_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    auto top = first, bottom = last;
    while (top != bottom && top != bottom-1) {
        auto mini = top, maxi = top;
        for (auto iter = top; iter != bottom; iter++) {
            if (cmp(*iter, *mini)) {
                mini = iter;
            }
            if (!cmp(*iter, *maxi)) {
                maxi = iter;
            }
        }
        if (maxi == top && mini == bottom-1) {
            std::swap(*top, *(bottom-1));
        } else if (maxi == top) {
            std::swap(*(bottom-1), *maxi);
            std::swap(*top, *mini);
        } else {
            std::swap(*top, *mini);
            std::swap(*(bottom-1), *maxi);
        }
        top++;
        bottom--;
    }
}
