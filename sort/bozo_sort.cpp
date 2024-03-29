#include <random>
#include <utility>

template<class RandomAccessIterator>
bool sorted(RandomAccessIterator first, RandomAccessIterator last) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        if (*(first+i) > *(first+i+1)) {
            return false;
        }
    }
    return true;
}

template <class RandomAccessIterator, class Compare>
bool sorted(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    int len = last - first;
    for (int i=0; i<len-1; i++) {
        if (cmp(*(first+i+1), *(first+i))) {
            return false;
        }
    }
    return true;
}

template<class RandomAccessIterator>
void bozo_sort(RandomAccessIterator first, RandomAccessIterator last) {
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());
    
    int len = last - first;

    std::uniform_int_distribution<> dist(0, len-1);

    int i = 0, j = 0;
    while (!::sorted(first, last)) {
        do {
            i = dist(engine), j = dist(engine);
        } while (i == j);
        std::swap(*(first+i), *(first+j));
    }
}

template<class RandomAccessIterator, class Compare>
void bozo_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen());

    int len = last - first;

    std::uniform_int_distribution<> dist(0, len-1);

    int i = 0, j = 0;
    while (!::sorted(first, last, cmp)) {
        do {
            i = dist(engine), j = dist(engine);
        } while (i == j);
        std::swap(*(first+i), *(first+j));
    }
}
