using System;

namespace Lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            // Question 1
            Console.WriteLine("1. Class, Constructor, Properties and Methods");
            Person person = new Person("Ben", 19);
            person.Greetings();
            Console.WriteLine("----------------------------------\n");

            // Question 2
            Console.WriteLine("2. Method Overloading");
            Calculation c1 = new Calculation();
            c1.calc();
            c1.calc(20, 30);
            c1.calc(20.5, 22.3);
            int mul = c1.calc(12, 23, 34);
            Console.WriteLine("multiplication is " + mul);
            Console.WriteLine("----------------------------------\n");

            // Question 3
            Console.WriteLine("3. Different arithmetic operations using class");
            Calculate calculate = new Calculate();
            calculate.setCalc(4, 8);
            calculate.calcSum();
            Console.WriteLine("Multiplication of 10 and 5 is " + calculate.calcMulti());
            calculate.calcDifference();
            Console.WriteLine("----------------------------------\n");

            // Question 4
            Console.WriteLine("4. Even and Odd number");
            Number number = new Number(5, 15);
            number.findOdd();
            number.findEven();
            Console.WriteLine("----------------------------------\n");

            // Question 5
            Console.WriteLine("5. Area of Rectangle and Volume of Box");
            Shape rectangle = new Shape(5, 3);
            rectangle.calcAreaRectangle();
            Shape box = new Shape(4, 3, 2);
            box.calcVolumeBox();
            Console.WriteLine("----------------------------------\n");

            // Question 6
            Console.WriteLine("6. Salary Information");
            SalaryInfo employee = new SalaryInfo(101, "John Doe", 'M', "Kathmandu", "Senior Engineer", 950000);
            employee.Display();
            employee.CalcTax();
            Console.WriteLine("----------------------------------\n");
        }
    }
}