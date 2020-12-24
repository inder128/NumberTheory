// make sure to initialise;
const int N = 1e7;
bitset <N + 1> isPrime;
vi mue(N + 1);
void mobius(){
    isPrime.set();
    isPrime[0] = isPrime[1] = false;
    fill(rng(mue), 1);
    for(int i = 2; i <= N; ++i){
        if(isPrime[i] == false) continue;
        mue[i] = -1;
        for(int j = 2 * i; j <= N; j += i){
            isPrime[j] = false;
            if(j / i % i == 0){
                mue[j] = 0;
            }
            mue[j] *= -1;
        }
    }
}