template<class RandomAccessIterator>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    int h = 0;
    while (3*h+1 < len) {
        h = 3*h+1;
    }
    while (h > 0) {
        for (int i=0; i<h; i++) {
            for (int j=i+h; j<len; j+=h) {
                auto tmp = *(first+j);
                int k = j;
                while (k > h-1 && tmp < *(first+k-h)) {
                    *(first+k) = *(first+k-h);
                    k -= h;
                }
                *(first+k) = tmp;
            }
        }
        h = (h-1)/3;
    }
}

template<class RandomAccessIterator, class Compare>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    int h = 0;
    while (3*h+1 < len) {
        h = 3*h+1;
    }
    while (h > 0) {
        for (int i=0; i<h; i++) {
            for (int j=i+h; j<len; j+=h) {
                auto tmp = *(first+j);
                int k = j;
                while (k > h-1 && cmp(tmp, *(first+k-h))) {
                    *(first+k) = *(first+k-h);
                    k -= h;
                }
                *(first+k) = tmp;
            }
        }
        h = (h-1)/3;
    }
}
