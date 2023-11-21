public class Solution {
    public static boolean checkSquare(int num)
    {
        int sqrt = (int)Math.sqrt(num);
        return (sqrt*sqrt == num);
    }
    public static int checkSquaresCount(int n, int ct)
    {
        int newCt=-1;
        if(checkSquare(n)){
            return ct;
        }
        int v =1;
        while(v*v<=n-(v*v))
        {
            if(checkSquare(n-(v*v))){
                return ++ct;
            }
            v++;
        }
        v =1;
        while(newCt<0 && v*v<=n-(v*v))
        {
            newCt =checkSquaresCount(n-(v*v), (ct+1));
            v++;
        }
        return newCt;
    }
    public static void main(String[] args) {
        for(int i=0;i<10;i++)
        {
            int n = (int) (Math.random()*1000.0);
            System.out.println("Perfect Squares Counting up to "+n+" is "+checkSquaresCount(n,1));
        }
    }
}
