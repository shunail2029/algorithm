template<class RandomAccessIterater, typename T>
RandomAccessIterater binary_search(RandomAccessIterater first, RandomAccessIterater last, T key) {
    auto mid = first + (last - first) / 2;
    if (*mid >= key) {
        if (mid == first) {
            return mid;
        }
        else {
            return ::binary_search(first, mid-1, key);
        }
    }
    else {
        if (mid == last) {
            return mid+1;
        }
        else {
            return ::binary_search(mid+1, last, key);
        }
    }
}

template<class RandomAccessIterater, typename T, class Compare>
RandomAccessIterater binary_search(RandomAccessIterater first, RandomAccessIterater last, T key, Compare cmp) {
    auto mid = first + (last - first) / 2;
    if (!cmp(*mid, key)) {
        if (mid == first) {
            return mid;
        }
        else {
            return ::binary_search(first, mid-1, key, cmp);
        }
    }
    else {
        if (mid == last) {
            return mid+1;
        }
        else {
            return ::binary_search(mid+1, last, key, cmp);
        }
    }
}

template<class RandomAccessIterater>
void binary_insertion_sort(RandomAccessIterater first, RandomAccessIterater last) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first+i);
        auto insert = ::binary_search(first, first+i-1, tmp);
        for (auto iter = first+i; iter != insert; iter--) {
            *iter = *(iter-1);
        }
        *insert = tmp;
    }
}

template<class RandomAccessIterater, class Compare>
void binary_insertion_sort(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first+i);
        auto insert = ::binary_search(first, first+i-1, tmp, cmp);
        for (auto iter = first+i; iter != insert; iter--) {
            *iter = *(iter-1);
        }
        *insert = tmp;
    }
}
