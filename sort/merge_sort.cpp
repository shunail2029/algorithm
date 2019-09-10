#include <iostream>
#include <new>

template<class RandomAccessIterater>
void merge(RandomAccessIterater first, RandomAccessIterater mid, RandomAccessIterater last) {
    auto val = *first;
    using type = decltype(val);

    int len = last - first;
    type *buf;
    try {
        buf = new type[len];
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        throw;
    }
    
    auto iter1 = first, iter2 = mid;
    int i = 0;
    while (true) {
        if (iter1 == mid && iter2 == last) {
            break;
        }
        else if (iter1 == mid) {
            for (auto iter = iter2; iter != last; iter++) {
                buf[i++] = *iter;
            }
            iter2 = last;
        }
        else if (iter2 == last) {
            for (auto iter = iter1; iter != mid; iter++) {
                buf[i++] = *iter;
            }
            iter1 = mid;
        }
        else {
            if (*iter1 <= *iter2) {
                buf[i++] = *iter1;
                iter1++;
            }
            else {
                buf[i++] = *iter2;
                iter2++;
            }
        }
    }
    for (int i=0; i<len; i++) {
        *(first+i) = buf[i];
    }

    delete[] buf;
}

template<class RandomAccessIterater, class Compare>
void merge(RandomAccessIterater first, RandomAccessIterater mid, RandomAccessIterater last, Compare cmp) {
    auto val = *first;
    using type = decltype(val);

    int len = last - first;
    type *buf;
    try {
        buf = new type[len];
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
        throw;
    }
    
    auto iter1 = first, iter2 = mid;
    int i = 0;
    while (true) {
        if (iter1 == mid && iter2 == last) {
            break;
        }
        else if (iter1 == mid) {
            for (auto iter = iter2; iter != last; iter++) {
                buf[i++] = *iter;
            }
            iter2 = last;
        }
        else if (iter2 == last) {
            for (auto iter = iter1; iter != mid; iter++) {
                buf[i++] = *iter;
            }
            iter1 = mid;
        }
        else {
            if (!cmp(*iter2, *iter1)) {
                buf[i++] = *iter1;
                iter1++;
            }
            else {
                buf[i++] = *iter2;
                iter2++;
            }
        }
    }
    for (int i=0; i<len; i++) {
        *(first+i) = buf[i];
    }

    delete[] buf;
}

template<class RandomAccessIterater> 
void merge_sort(RandomAccessIterater first, RandomAccessIterater last) {
    if (first == last || first+1 == last) {
        return;
    }
    auto mid = first + (last - first) / 2;
    ::merge_sort(first, mid);
    ::merge_sort(mid, last);
    ::merge(first, mid, last);
}

template<class RandomAccessIterater, class Compare>
void merge_sort(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    if (first == last || first+1 == last) {
        return;
    }
    auto mid = first + (last - first) / 2;
    ::merge_sort(first, mid, cmp);
    ::merge_sort(mid, last, cmp);
    ::merge(first, mid, last, cmp);
}
