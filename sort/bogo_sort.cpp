#include <random>
#include <utility>

template<class RandomAccessIterater>
bool sorted(RandomAccessIterater first, RandomAccessIterater last) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        if (*(first+i) > *(first+i+1)) {
            return false;
        }
    }
    return true;
}

template <class RandomAccessIterater, class Compare>
bool sorted(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        if (cmp(*(first+i+1), *(first+i))) {
            return false;
        }
    }
    return true;
}

template<class RandomAccessIterater>
void shuffle(RandomAccessIterater first, RandomAccessIterater last) {
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    std::uniform_int_distribution<> dist;

    int len = last - first;
    for (int i=len-1; i>0; i--) {
        std::uniform_int_distribution<>::param_type para(0, i);
        dist.param(para);
        int j = dist(engine);
        std::swap(*(first+i), *(first+j));
    }
}

template<class RandomAccessIterater>
void bogo_sort(RandomAccessIterater first, RandomAccessIterater last) {
    while (!::sorted(first, last)) {
        ::shuffle(first, last);
    }
}

template<class RandomAccessIterater, class Compare>
void bogo_sort(RandomAccessIterater first, RandomAccessIterater last, Compare cmp) {
    while (!::sorted(first, last, cmp)) {
        ::shuffle(first, last);
    }
}
