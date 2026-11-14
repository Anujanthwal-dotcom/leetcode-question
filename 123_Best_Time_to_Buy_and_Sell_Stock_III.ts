// 123. Best Time to Buy and Sell Stock III
// Difficulty: Hard
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
//
// Find the maximum profit you can achieve. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
//
//
// Example 1:
//
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
// Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
//
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
//
// Example 3:
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
//
//
// Constraints:
//
// 	  * 1 <= prices.length <= 105
//
// 	  * 0 <= prices[i] <= 105

function maxProfit(prices: number[]): number {
    return helper(prices, 0, true, 0);
};


function helper(prices: number[], idx: number, canBuy: boolean, count: number):  number {
    if(prices.length === idx) return 0;
    if(count ===  2) return 0;

    let buy: number = -1e9;
    let sell: number = -1e9;
    if(canBuy){
        buy = -prices[idx]+helper(prices, idx+1, !canBuy, count++);
    } else {
        sell = prices[idx]+helper(prices, idx+1, !canBuy, count++);
    }

    let moveOn = helper(prices, idx+1, canBuy, count);

    return Math.max(buy, sell, moveOn);
}