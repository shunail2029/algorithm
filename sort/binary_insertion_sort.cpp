template<class RandomAccessIterator, typename T>
RandomAccessIterator binary_search(RandomAccessIterator first, RandomAccessIterator last, T key) {
    auto mid = first + (last - first) / 2;
    if (*mid <= key) {
        if (mid == last) {
            return mid+1;
        }
        else {
            return ::binary_search(mid+1, last, key);
        }
    }
    else {
        if (mid == first) {
            return mid;
        }
        else {
            return ::binary_search(first, mid-1, key);
        }
    }
}

template<class RandomAccessIterator, typename T, class Compare>
RandomAccessIterator binary_search(RandomAccessIterator first, RandomAccessIterator last, T key, Compare cmp) {
    auto mid = first + (last - first) / 2;
    if (!cmp(key, *mid)) {
        if (mid == last) {
            return mid+1;
        }
        else {
            return ::binary_search(mid+1, last, key, cmp);
        }
    }
    else {
        if (mid == first) {
            return mid;
        }
        else {
            return ::binary_search(first, mid-1, key, cmp);
        }
    }
}

template<class RandomAccessIterator>
void binary_insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
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

template<class RandomAccessIterator, class Compare>
void binary_insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
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
