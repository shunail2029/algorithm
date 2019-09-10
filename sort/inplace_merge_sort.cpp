template<class RandomAccessIterator>
void inplace_merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last) {
    auto iter1 = first, iter2 = mid;
    while (true) {
        if (iter1 == iter2 || iter2 == last) {
            return;
        }
        else {
            if (*iter1 <= *iter2) {
                iter1++;
            }
            else {
                auto tmp = *iter2;
                for (auto iter = iter2; iter != iter1; iter--) {
                    *iter = *(iter-1);
                }
                *iter1 = tmp;
                iter1++;
                iter2++;
            }
        }
    }
}

template<class RandomAccessIterator, class Compare>
void inplace_merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last, Compare cmp) {
    auto iter1 = first, iter2 = mid;
    while (true) {
        if (iter1 == iter2 || iter2 == last) {
            return;
        }
        else {
            if (!cmp(*iter2, *iter1)) {
                iter1++;
            }
            else {
                auto tmp = *iter2;
                for (auto iter = iter2; iter != iter1; iter--) {
                    *iter = *(iter-1);
                }
                *iter1 = tmp;
                iter1++;
                iter2++;
            }
        }
    }
}

template<class RandomAccessIterator> 
void inplace_merge_sort(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last || first+1 == last) {
        return;
    }
    auto mid = first + (last - first) / 2;
    ::inplace_merge_sort(first, mid);
    ::inplace_merge_sort(mid, last);
    ::inplace_merge(first, mid, last);
}

template<class RandomAccessIterator, class Compare>
void inplace_merge_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    if (first == last || first+1 == last) {
        return;
    }
    auto mid = first + (last - first) / 2;
    ::inplace_merge_sort(first, mid, cmp);
    ::inplace_merge_sort(mid, last, cmp);
    ::inplace_merge(first, mid, last, cmp);
}
