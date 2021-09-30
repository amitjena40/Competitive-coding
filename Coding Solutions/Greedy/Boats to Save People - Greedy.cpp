class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0, j = n - 1;
        for (; i <= j;) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            count++;
        }

        return count;
    }
};