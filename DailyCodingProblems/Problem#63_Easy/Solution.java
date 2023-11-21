public class Solution
{
    public boolean findWord(char[][] charArr, String word)
    {
        int i,j, size,k=1;
        size = charArr.length;
        for(i=0;i<size;i++)
        {
           for(j=0;j<size;j++)
            {
                if(charArr[i][j]==word.charAt(0))
                {
                    k=1;
                    while(j+k<size && charArr[i][j+k]==word.charAt(k))
                    {
                        k++;
                    }
                    if(k==1)
                    {
                      while(i+k<size && charArr[i+k][j]==word.charAt(k))
                    {
                        k++;
                    }  
                    }
                }
                if(k==word.length())
                    return true;
                k=1;
            }
        }
        return false;
    }
    public static void main(String[] args) {

        Solution sol = new Solution();
        char[][] charArr={{'F', 'A', 'C', 'B'}, {'O', 'B', 'Q', 'A'}, {'A', 'N', 'O', 'I'}, {'M', 'A', 'S', 'S'}};
        String word = "BAIS";
        System.out.println(sol.findWord(charArr, word));
        
    }
}