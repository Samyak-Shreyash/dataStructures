public class Solution2 {

    
    public int findProfit(int[] stocks)
    {
        int max_profit = 0,i, profit_ind = -1, profit=0, l = stocks.length;
        int[] maxPrices=new int[l];
        maxPrices[0]=stocks[0];
        for(i=1;i<l;i++)
        {
            maxPrices[i]= stocks[i]>maxprices[i-1]?stocks[i]:maxprices[i-1];
            profit = (maxPrices[i]-stock[i]);
        }


        for(i=0;i<stocks.length;i++)
        {
            if(profit>i)
            {
                profit_ind= findMaxPos(stocks, i);
                profit= stocks[profit_ind]-stocks[i];
            }
            else
            {
                profit_ind= findMaxPos(stocks, i+1);
                profit= stocks[profit_ind];
            }
            if(profit> max_profit)
            {
                max_profit= profit;
            }
        }
        return max_profit;
    }
    public static void main(String[] args) {
        
        int[] arr = {9, 11, 8, 5, 7, 10};
        Solution sol = new Solution();
        System.out.println(sol.findProfit(arr));
    }
}
