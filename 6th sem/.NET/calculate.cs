/* 
 * Create a class Calculate which contains data member num1 and num2 both in integer and 
 * methods setCalc() to set the data, 
 * calcSum() that calculate the sum of num1 and num2 and display the result, 
 * calcMulti() that calculate the multiplication of num1 and num2 and returns the result, 
 * calcDifference that calculate the difference between num1 and num2 and display the result. 
 * Now, create some instance of Calculate and invoke all the methods.
 */
 
namespace Lab1
{
  public class Calculate
  {
      private int num1;
      private int num2;

      public void setCalc(int a, int b)
      {
          num1 = a;
          num2 = b;
      }

      public void calcSum()
      {
          int sum = num1 + num2;
          Console.WriteLine($"Sum of {num1} and {num2} is: {sum}");
      }

      public int calcMulti()
      {
          return num1 * num2;
      }

      public void calcDifference()
      {
          int difference = num1 - num2;
          Console.WriteLine($"Difference between {num1} and {num2} is: {difference}");
      }
  }
}