vector<int> kmp(string &s) {
	vector<int> dp(sz(s));
    int j = 0;
	for(int i = 1, j = 0; i < sz(s); i++) {
		while(j && s[i] != s[j])
			j = dp[j - 1];
		if(s[i] == s[j])
			j++;
		dp[i] = j;
	}
	return dp;
}