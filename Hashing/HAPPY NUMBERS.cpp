class solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int sum, d;
        while(n != 1) {
            set.insert(n);
            sum = 0;
            while(n != 0) {
                d = n % 10;
                sum += d * d;
                n = n / 10;
            }
            if (set.count(sum)) {
                return false;
            }
            n = sum;
        }
        return true;
    }
};

class Solution {
public:
    int fun(int n)
    {
        int ans  = 0, d;
        while(n > 0)
        {
            d = n % 10;
            ans += d * d;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int num) {
      int slow = num;
      int fast = num;
      do
      {
          slow = fun(slow);
          fast = fun(fun(fast));
      } while (slow != fast);
      return slow ==1;
    }
};