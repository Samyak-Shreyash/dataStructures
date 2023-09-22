public class Solution {
    public static void main(String[] args) {
        int[] arr= {-6, 0, 7, 40, 89, 100};
        int ind  =getFixedIndex(arr);
        System.out.println(ind>-1?"Fixed Index is present at: "+ind :"No Fixed index present");
    }

    private static int getFixedIndex(int[] arr) {
        int lo=0, hi = arr.length,mid;
        while(lo<hi)
        {
            mid = (lo+hi)/2;
            if(arr[mid]==mid)
                return mid;
            else if(arr[mid]>mid)
                hi=mid;
            else
                lo=mid+1;
        }
        return -1;
    }
}
