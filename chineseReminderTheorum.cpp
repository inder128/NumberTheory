int inv(int a, int b){
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}


// Chinease Reminder Theorum;
// pr -> vecrtor of {{p1, r1}, {p2, r2}, ---, {pn, rn}};
// return x such that (x % pi = pi) for all 0 <= i < n;
int CRT(vector <pi> pr){
    int n = SZ(pr);

    int m = 1; // p1 * p2 * --- * pn;
    for(pi p : pr){
        m *= p.F;
    }

    // ((x1) + (x2 * p1) + ----- + (xn * p1 * -- * p(n - 1))) % m;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int curr = 1; 
        for(int j = 0; j < i; ++j){
            curr *= pr[j].F;
            curr *= inv(pr[j].F, pr[i].F);
            curr %= m;
        }
        ans = (ans + curr * (pr[i].S - ans + m)) % m;
    }

    return ans;
}