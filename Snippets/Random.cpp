mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random(int l, int r) {
    return l + rng() % (r-l+1);
}
