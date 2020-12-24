int inv(int a, int b){
	return 1 < a ? b - inv(b % a, a) * b / a : 1;
}