namespace Lab1
{
  class ExceptionHandling
  {
    public void Divide(int a, int b)
    {
      try
      {
        int result = a / b;
        Console.WriteLine("Result: " + result);
      }
      catch (DivideByZeroException e)
      {
        Console.WriteLine("Exception caught: " + e.Message);
      }
      finally
      {
        Console.WriteLine("Finally block executed");
      }
    }
  }
}