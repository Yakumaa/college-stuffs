// method overloading is a feature that allows a class to have more than one method having the same name
// if their argument lists are different.

namespace Lab1
{
    class Calculation
    {
        public void calc() {
            Console.WriteLine("this is default calc");
        }

        public void calc(int x, int y)
        {
            Console.WriteLine("Sum is "+ (x+y));
        }
        public void calc(double x, double y)
        {
            Console.WriteLine("difference is " + (x - y));
        }
        public int calc(int x, int y, int z)
        {
            return(x * y * z);
        }
    }
}