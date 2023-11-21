class Trial
{
    public static void main(String[] args)
    {
        int a = 9, b=0;
        try
        {
            System.out.println(a/b);
        }
        catch(Exception e)
        {
            System.out.println("Exception");
            System.exit(0);
        }
        finally
        {
            System.out.println("Finally");
            return;
        }
    }
}