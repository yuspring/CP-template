vector<int> v(arr, arr + n);
sort(v.begin(), v.end());
v.resize(unique(v.begin(), v.end()) - v.begin());
for (int i = 0;i < n;i++){
    arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
}
