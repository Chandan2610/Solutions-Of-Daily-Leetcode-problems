int numRollsToTarget(int d, int f, int target, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i)) % 1000000007;
  return res;
}
