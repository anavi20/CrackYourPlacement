// Time complexity O(n) and Space Complexity O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), totalPoints = 0, windowSize = n-k;

        for(int i=0; i<n; i++){
            totalPoints += cardPoints[i];
        }

        int ans = INT_MIN, windowSum = 0;
        for(int i=0; i<windowSize; i++){
            windowSum += cardPoints[i];
        }
        ans = max(ans, totalPoints - windowSum);

        for(int i=1; i<(n-windowSize+1); i++){
            windowSum += (cardPoints[i+windowSize-1] - cardPoints[i-1]);
            ans = max(ans, totalPoints - windowSum);
        }

        return ans;
    }
};


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), i=0, j=n-k;
        int windowSum = accumulate(cardPoints.end()-k, cardPoints.end(), 0);
        int ans = windowSum;

        while(i<n && i<k){
            windowSum -= cardPoints[j++];
            windowSum += cardPoints[i++];

            ans = max(ans,windowSum);
        }

        return ans;
    }
};
