import java.util.*;
public class PivotProduct
{
    public static void main(String[] args) {
        
        int[] nums = new int[]{2,8,4,1};
        int product = 1;
        for(int i=0;i<nums.length;i++)
        {
            product = product* nums[i];
        }
        for(int i=0;i<nums.length;i++)
        {
            int num = nums[i];
            if(product==(num*num))
            {
                System.out.println(num);
                return;
            }
        }

    }
}

{2,4,9,8,6,2,1}

{2,4,8,1,16,2}