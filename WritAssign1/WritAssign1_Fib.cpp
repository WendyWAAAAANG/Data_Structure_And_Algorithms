int fib(int n){
    //declare two variable as temp result of fib.
	int temp1 = 0;
    int temp2 = 1;
    //declare res to store the result of fib.
    int res = n;
	for(int i = 2; i <= n; i++){
        //do the calculation of result.
		res = temp1 + temp2;
        //update the temp result.
		temp1 = temp2;
		temp2 = res;
	}
    //then return the result.
	return res;
}