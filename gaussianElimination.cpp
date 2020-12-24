// 1) simple gaussian elimination :-
// return 0 (if no soln / incosistent), 1 (if unique soln), 1e9 (if infinite soln);
int gaussianElimination(vector<vector<double>> AB, vector<double>& X){
    // m equations and n variables;
    int m = SZ(AB), n = SZ(AB[0]) - 1; 
    const double EPS = 1e-9;

    vi pivotRow(n, -1);
    for(int col = 0, row = 0; col < n and row < m; ++col){
        // maximum hueristic;
        int sel = row;
        for(int i = row; i < m; ++i){
            if(abs(AB[i][col]) > abs(AB[sel][col])){
                sel = i;
            }
        }

        // no pivot row is found for this variable or this variable is free;
        // now defenately unique soln does not exist;
        if(abs(AB[sel][col]) < EPS){
            continue;
        }

        for(int i = col; i <= n; ++i){
            swap(AB[sel][i], AB[row][i]);
        }
        pivotRow[col] = row;

        for(int i = 0; i < m; ++i){
            if(i != row){
                double c = AB[i][col] / AB[row][col];
                for (int j = col; j <= n; ++j){
                    AB[i][j] -= AB[row][j] * c;
                }
            }
        }

        ++row;
    }

    X.assign(n, 0);
    for(int i = 0; i < n; ++i){
        if(pivotRow[i] != -1){
            X[i] = AB[pivotRow[i]][n] / AB[pivotRow[i]][i];
        }
        // else : free variables (pivotRow[i] == i) are taken 0 by default;
    }

    for(int i = 0; i < m; ++i){
        double sum = 0;
        for(int j = 0; j < n; ++j){
            sum += X[j] * AB[i][j];
        }

        // no solution or incosistent;
        if(abs(sum - AB[i][n]) > EPS){
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        // infinitely many solution or rank(AB) < n;
        if(pivotRow[i] == -1){
            return 1e9;
        }
    }

    // unique soln or rank(AB) = n;
    return 1;
}

// 2) gaussian elimination under mod (use modInverse template / code) :-
int gaussianElimination(vector <vector<int>> AB, vector <int>& X){
    int m = SZ(AB), n = SZ(AB[0]) - 1; 

    vi pivotRow(n, -1);
    for(int col = 0, row = 0; col < n and row < m; ++col){
        int sel = row;
        for(int i = row; i < m; ++i){
            if(AB[i][col] > AB[sel][col]){
                sel = i;
            }
        }

        if(AB[sel][col] == 0){
            continue;
        }

        for(int i = col; i <= n; ++i){
            swap(AB[sel][i], AB[row][i]);
        }
        pivotRow[col] = row;

        for(int i = 0; i < m; ++i){
            if(i != row){
                int c = divide(AB[i][col], AB[row][col]);
                for (int j = col; j <= n; ++j){
                    AB[i][j] = sub(AB[i][j], mul(AB[row][j], c));
                }
            }
        }

        ++row;
    }

    X.assign(n, 0);
    for(int i = 0; i < n; ++i){
        if(pivotRow[i] != -1){
            X[i] = divide(AB[pivotRow[i]][n], AB[pivotRow[i]][i]);
        }
    }

    for(int i = 0; i < m; ++i){
        int sum = 0;
        for(int j = 0; j < n; ++j){
            sum = add(sum, mul(X[j], AB[i][j]));
        }

        if(sum != AB[i][n]){
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        if(pivotRow[i] == -1){
            return 1e9;
        }
    }

    return 1;
}





// 3) gaussian elimination under mod (use modInt template / code) :-
int gaussianElimination(vector <vector<modInt>> AB, vector <modInt>& X){
    int m = SZ(AB), n = SZ(AB[0]) - 1; 

    vi pivotRow(n, -1);
    for(int col = 0, row = 0; col < n and row < m; ++col){
        int sel = row;
        for(int i = row; i < m; ++i){
            if(AB[i][col] > AB[sel][col]){
                sel = i;
            }
        }

        if(AB[sel][col] == 0){
            continue;
        }

        for(int i = col; i <= n; ++i){
            swap(AB[sel][i], AB[row][i]);
        }
        pivotRow[col] = row;

        for(int i = 0; i < m; ++i){
            if(i != row){
                modInt c = AB[i][col] / AB[row][col];
                for (int j = col; j <= n; ++j){
                    AB[i][j] -= AB[row][j] * c;
                }
            }
        }

        ++row;
    }

    X.assign(n, 0);
    for(int i = 0; i < n; ++i){
        if(pivotRow[i] != -1){
            X[i] = AB[pivotRow[i]][n] / AB[pivotRow[i]][i];
        }
    }

    for(int i = 0; i < m; ++i){
        modInt sum = 0;
        for(int j = 0; j < n; ++j){
            sum += X[j] * AB[i][j];
        }

        if(sum != AB[i][n]){
            return 0;
        }
    }

    for(int i = 0; i < n; ++i){
        if(pivotRow[i] == -1){
            return 1e9;
        }
    }

    return 1;
}