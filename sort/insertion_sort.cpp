template<class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first + i);
        int j = i;
        while (j > 0 && tmp < *(first+j-1)) {
            *(first+j) = *(first+j-1);
            j--;
        }
        *(first+j) = tmp;
    }
}

template<class RandomAccessIterator, class Compare>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first + i);
        int j = i;
        while (j > 0 && cmp(tmp, *(first+j-1))) {
            *(first+j) = *(first+j-1);
            j--;
        }
        *(first+j) = tmp;
    }
}
