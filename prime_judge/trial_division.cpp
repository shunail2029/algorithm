bool trial_division(long long n) {
    if (n == 1) {
        return false;
    }
    for (long long i=2; i*i<=n; i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
