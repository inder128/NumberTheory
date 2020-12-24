// n <= 1e14;
int phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            ans /= i, ans *= (i - 1);
        }
    }
    if(n > 1){
        ans -= ans / n;
    }
    return ans;
}

// for all n upto 1e7;
// make sure to initialise;
const int N = 1e7;
// phi[i] -> no. of integers j such that (j <= i and gcd(j, i) == 1);
vi phi(N + 1); 
void findPHI() {
    iota(rng(phi), 0);    
    for(int i = 2; i <= N; i++){
        if (phi[i] != i) continue;
        // i is a prime;
        for (int j = i; j <= N; j += i){
            phi[j] /= i, phi[i] *= (i - 1);
        }
    }
}