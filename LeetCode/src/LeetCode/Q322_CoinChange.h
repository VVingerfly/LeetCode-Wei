
#pragma once
#include <iostream>
#include <vector>
using namespace std;

#ifndef Q322_CoinChange_h_
#define Q322_CoinChange_h_


/**
 * @brief Ó²±Ò´ÕÊý
 *
 * You are given coins of different denominations and a total amount of money amount.
 * Write a function to compute the fewest number of coins that you need to make up that amount. 
 * If that amount of money cannot be made up by any combination of the coins, return -1.

 * **Example 1:**
 * ```
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 * ```
 * 
 * **Example 2:**
 * ```
 * coins = [2], amount = 3
 * return -1.
 * ```

 * @note You may assume that you have an infinite number of each kind of coin.
 * @see https://leetcode.com/problems/coin-change/description/
 */
class A322_CoinChange
{
#define min(x,y) (x<y?x:y)
public:
	/*! 
	 * @brief Use brief, otherwise the index won't have a brief explanation.
	 *
	 * This is a fundamental DP problem. 

	 * @param coins 
	 * @param amount 
	 * @return 
	 * @note  
	 * @see https://leetcode.com/problems/coin-change/discuss/
	*/
	int coinChange(vector<int>& coins, int amount)
	{
		int Max = amount + 1;
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) 
		{
			for (int j = 0; j < coins.size(); j++) 
			{
				if (coins[j] <= i) 
				{
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}



	void runTest()
	{
		vector<int> coins = { 1, 2, 5 };
		int amount = 11;
		cout << coinChange(coins, amount) << endl;
	}
};


#endif // Q322_CoinChange_h_