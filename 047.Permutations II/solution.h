vector<vector<int>> permuteUnique(vector<int> &nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  do {
    res.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}

// algorithm中 sort, next_permutation, erase, unique的用法
