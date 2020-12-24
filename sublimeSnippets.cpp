// primeFactorisation;
int num = n;
map <int, int> primeFac;
for (int i = 2; i * i <= num; ++i){
    while(num % i == 0){
        num /= i;
        primeFac[i]++;
    }
}
if(num > 1) primeFac[num]++;


// seffOperations;
const int mod = 998244353;

void addSelf(int& x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
}

void subSelf(int& x, int y){
    add(x, -y);
}

void multSelf(int& x, int y){
    x = x * 1ll * y % mod;
}


// primes
// make sure to initialise;
const int N = 1e7;
bitset <N + 1> isPrime;
void findPrimes(){
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i){
        if(isPrime[i] == false) continue;
        for(int j = i * i; j <= N; j += i){
            isPrime[j] = false;
        }
    }
}   


// spf
// make sure to initialise;
const int N = 1e7;
vi spf(N + 1); // shortest prime factor;
void findSPF(){
    iota(rng(spf), 0);
    spf[0] = spf[1] = 0;
    for(int i = 2; i * i <= N; ++i){
        if(spf[i] != i) continue;
        for(int j = i * i; j <= N; j += i){
            if(spf[j] != j) continue;
            spf[j] = i;
        }
    }
}


// combanitorics
const int N = 200043;
const int mod = 998244353;
int fact[N], invFact[N];

int add(int x, int y){
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

int sub(int x, int y){
    return add(x, -y);
}

int mul(int x, int y){
    return (x * 1ll * y) % mod;
}

int binPow(int x, int y){
    int z = 1;
    while(y){
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int inv(int x){
    return binPow(x, mod - 2);
}

int divide(int x, int y){
    return mul(x, inv(y));
}

void preCalc(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    invFact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 0; i--)
        invFact[i] = mul(i + 1, invFact[i + 1]);
}

int C(int n, int k){
    if(k > n) return 0;
    return mul(fact[n], mul(invFact[k], invFact[n - k]));
}