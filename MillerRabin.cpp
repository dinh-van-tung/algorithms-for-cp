ll Mul(ll a, ll b, ll m) {
    ll ans = 0, tmp = a;
    while (b > 0) {
        if (b & 1) {
            ans = (ans + tmp) % m;
        }
        tmp = (tmp + tmp) % m;
        b /= 2;
    }
    return ans;
}

ll Pow(ll a, ll n, ll m) {
    ll ans = 1, tmp = a;
    while (n > 0) {
        if (n & 1) {
            ans = Mul(ans, tmp, m);
        }
        tmp = Mul(tmp, tmp, m);
        n /= 2;
    }
    return ans;
}

bool test(ll a, ll n, ll k, ll m) {
    ll mod = Pow(a, m, n);
    if (mod == 1 || mod == n - 1) {
        return true;
    }
    ff (i, 1, k - 1, 1) {
        mod = Mul(mod, mod, n);
        if (mod == n - 1) {
            return true;
        }
    }
    return false;
}

vector<int> prime_set = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

bool MillerRabin(ll n) {
    if (n == 2 || n == 3 || n == 5 || n == 7) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n < 11) {
        return false;
    }

    ll k = 0, m = n - 1;
    while (m % 2 == 0) {
        k++;
        m /= 2;
    }
    for (auto a : prime_set) {
        if (a < n && !test(a, n, k, m)) {
            return false;
        }
    }
    return true;
}
