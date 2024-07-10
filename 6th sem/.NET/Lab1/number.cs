/*
 * Create a class Number having instance variable x and y both in integer, 
 * default constructor that set the value of x and y to 0, 
 * parameterized constructor that sets the value of x and y, 
 * method findOdd() that calculates the odd no. occurring between x and y and display the result, 
 * method findEven() that calculates the even no. occurring between x and y and display the result. 
 * Now, create some instance of Number and invoke all the methods. 
 */

namespace Lab1
{
  public class Number
  {
    private int x;
    private int y;

    // Default constructor
    public Number()
    {
        x = 0;
        y = 0;
    }

    // Parameterized constructor
    public Number(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void findOdd()
    {
        Console.WriteLine($"Odd numbers between {x} and {y}:");
        for (int i = Math.Min(x, y); i <= Math.Max(x, y); i++)
        {
            if (i % 2 != 0)
            {
                Console.Write(i + " ");
            }
        }
        Console.WriteLine();
    }

    public void findEven()
    {
        Console.WriteLine($"Even numbers between {x} and {y}:");
        for (int i = Math.Min(x, y); i <= Math.Max(x, y); i++)
        {
            if (i % 2 == 0)
            {
                Console.Write(i + " ");
            }
        }
        Console.WriteLine();
    }
}
}