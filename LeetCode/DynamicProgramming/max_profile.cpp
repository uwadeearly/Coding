/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_profile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wei.zhao <Wei.Zhao@stream_computing.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:31:25 by wei.zhao          #+#    #+#             */
/*   Updated: 2022/01/22 19:32:29 by wei.zhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
using namespace std;

/* 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <=1)return 0;

        int max = 0, min = prices[0];
        for(int i=0; i<len; ++i){
            int tmp = prices[i] - min;
            max = max > tmp ? max:tmp;
            min = prices[i]< min ? prices[i]:min;
        }
        return max;
        }