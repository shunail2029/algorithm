#include <utility>

template<class RandomAccessIterator>
RandomAccessIterator middle(RandomAccessIterator one, RandomAccessIterator two, RandomAccessIterator three) {
    if (*one < *two) {
        if (*two < *three) {
            return two;
        }
        else if (*three < *one) {
            return one;
        }
        else {
            return three;
        }
    }
    else {
        if (*one < *three) {
            return one;
        }
        else if (*three < *two) {
            return two;
        }
        else {
            return three;
        }
    }
}

template<class RandomAccessIterator, class Compare>
RandomAccessIterator middle(RandomAccessIterator one, RandomAccessIterator two, RandomAccessIterator three, Compare cmp) {
    if (cmp(*one, *two)) {
        if (cmp(*two, *three)) {
            return two;
        }
        else if (cmp(*three, *one)) {
            return one;
        }
        else {
            return three;
        }
    }
    else {
        if (cmp(*one, *three)) {
            return one;
        }
        else if (cmp(*three, *two)) {
            return two;
        }
        else {
            return three;
        }
    }
}

template<class RandomAccessIterator> 
void quick_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last || first+1 == last) {
        return;
    }
    auto iter1 = first, iter2 = last-1;
    auto mid = first + (last - first) / 2;
    auto pivot = *(::middle(iter1, mid, iter2));
    while (true) {
        while (*iter1 < pivot) {
            iter1++;
        }
        while (*iter2 > pivot) {
            iter2--;
        }
        if (iter1 == iter2 || iter1 == iter2+1) {
            break;
        }
        std::swap(*iter1, *iter2);
        iter1++;
        iter2--;
    }
    ::quick_sort(first, iter1);
    ::quick_sort(iter2+1, last);
}

template<class RandomAccessIterator, class Compare>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    if (first == last || first+1 == last) {
        return;
    }
    auto iter1 = first, iter2 = last-1;
    auto mid = first + (last - first) / 2;
    auto pivot = *(::middle(iter1, mid, iter2, cmp));
    while (true) {
        while (cmp(*iter1, pivot)) {
            iter1++;
        }
        while (cmp(pivot, *iter2)) {
            iter2--;
        }
        if (iter1 == iter2 || iter1 == iter2+1) {
            break;
        }
        std::swap(*iter1, *iter2);
        iter1++;
        iter2--;
    }
    ::quick_sort(first, iter1, cmp);
    ::quick_sort(iter2+1, last, cmp);
}
