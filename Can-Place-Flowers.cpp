1class Solution {
2public:
3    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
4        int cnt = 0;
5        int size = flowerbed.size();
6        for (int i = 0; i < size; i++) {
7            if (flowerbed[i] == 0) {
8                bool left = (i == 0) or (flowerbed[i - 1] == 0);
9                bool right = (i == size - 1) or (flowerbed[i + 1] == 0);
10                if (left and right) {
11                    cnt++;
12                    flowerbed[i] = 1;
13                }
14            }
15        }
16        return (cnt >= n);
17    }
18};