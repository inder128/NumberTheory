int EED(int a, int b, int& x, int& y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int d = EED(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool findAnySolution(int a, int b, int c, int &x, int &y){
	// degenerate case;
	if(a == 0 and b == 0){
		x = y = 0;
		return c == 0;
	}

    int g = EED(abs(a), abs(b), x, y);
    if(c % g){
        return false;
    }

    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;
}