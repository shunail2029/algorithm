template<class RandomAccessIterater>
void insertion_sort(RandomAccessIterater first, RandomAccessIterater last) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first + i);
        int j = i;
        while (j > 0 && *(first+j-1) > tmp) {
            *(first+j) = *(first+j-1);
            j--;
        }
        *(first+j) = tmp;
    }
}

template<class RandomAccessIterater, class Compare>
void insertion_sort(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    int len = last - first;
    for (int i=1; i<len; i++) {
        auto tmp = *(first + i);
        int j = i;
        while (j > 0 && !cmp(*(first+j-1), tmp)) {
            *(first+j) = *(first+j-1);
            j--;
        }
        *(first+j) = tmp;
    }
}
