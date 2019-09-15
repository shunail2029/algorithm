#include <iostream>
#include <new>
#include <typeinfo>

template<class RandomAccessIterator>
void radix_sort(RandomAccessIterator first, RandomAccessIterator last, long long digit = 1) {
    if (first == last) {
        return;
    }

    auto val = *first;
    using type = decltype(val);

    if (typeid(val) != typeid(int) && typeid(val) != typeid(long long)) {
        std::cout << "this sort can only be used for integer allay." << std::endl;
        return; 
    }

    int len = last - first;
    type *zero = new type[len];
    type *one = new type[len];
    int cnt_zero = 0, cnt_one = 0;
    bool finish = true;
    for (auto iter = first; iter != last; iter++) {
        type tmp = *iter;
        if (tmp > digit) {
            finish = false;
        }
        if ((tmp & digit) == 0) {
            zero[cnt_zero++] = tmp;
        }
        else {
            one[cnt_one++] = tmp;
        }
    }

    int cur = 0;
    for (int i=0; i<cnt_zero; i++) {
        *(first+cur) = zero[i];
        cur++;
    }
    for (int i=0; i<cnt_one; i++) {
        *(first+cur) = one[i];
        cur++;
    }
    
    delete [] zero;
    delete [] one;

    if (finish) {
        return;
    }
    else {
        ::radix_sort(first, last, digit << 1);
    }
}

template<class RandomAccessIterator>
void radix_sort_greater(RandomAccessIterator first, RandomAccessIterator last, long long digit = 1) {
    if (first == last) {
        return;
    }

    auto val = *first;
    using type = decltype(val);

    if (typeid(val) != typeid(int) && typeid(val) != typeid(long long)) {
        std::cout << "this sort can only be used for integer allay." << std::endl;
        return; 
    }

    int len = last - first;
    type *zero = new type[len];
    type *one = new type[len];
    int cnt_zero = 0, cnt_one = 0;
    bool finish = true;
    for (auto iter = first; iter != last; iter++) {
        type tmp = *iter;
        if (tmp > digit) {
            finish = false;
        }
        if ((tmp & digit) == 0) {
            zero[cnt_zero++] = tmp;
        }
        else {
            one[cnt_one++] = tmp;
        }
    }

    int cur = 0;
    for (int i=0; i<cnt_one; i++) {
        *(first+cur) = one[i];
        cur++;
    }
    for (int i=0; i<cnt_zero; i++) {
        *(first+cur) = zero[i];
        cur++;
    }
    
    delete [] zero;
    delete [] one;

    if (finish) {
        return;
    }
    else {
        ::radix_sort_greater(first, last, digit << 1);
    }
}
