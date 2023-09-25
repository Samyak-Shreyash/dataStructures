public class Solution {
    public static boolean checkSquare(int num)
    {
        int sqrt = (int)Math.sqrt(num);
        return (sqrt*sqrt == num);
    }
    public static int checkSquares(int n, int beg, int ct)
    {
        int newCt=-1, retCt =1000;
        // Check if the Value is a Perfect Square
        if(checkSquare(n)){
            return ct;
        }
        int v=beg;
        int sqr = v * v;
        // Looping to  Check if the Value can be expressed as sum of 2 sqaures
        while(sqr<=n-(sqr))
        {
            if(checkSquare(n-(sqr))){
                return ++ct;
            }
            v++;
            sqr = v*v;
        }
        // Looping to  Check if the Value can be expressed as sum of more than 2 sqaures
        v = beg;
        while(v*v<=n-(v*v))
        {
            newCt =checkSquares(n-(v*v), (beg+1), (ct+1));
            if(newCt!=1000)
            if(newCt<retCt)
            {
                retCt = newCt;
            }
            v++;
        }
        return retCt;
    }
    public static void main(String[] args) {
        int n=807;
        System.out.println("Final Return Value is: "+checkSquares(n,1, 1));
    }
}
