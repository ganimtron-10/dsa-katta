// https://leetcode.com/problems/water-bottles

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int totalBottle = 0;
        int fullExchangedBottle = numBottles, remainingBottle = 0;
        while (fullExchangedBottle + remainingBottle >= numExchange)
        {
            totalBottle += fullExchangedBottle;
            int curBottleCount = fullExchangedBottle + remainingBottle;
            fullExchangedBottle = curBottleCount / numExchange;
            remainingBottle = curBottleCount % numExchange;
        }
        return totalBottle + fullExchangedBottle;
    }
};