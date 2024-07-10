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
            Console.WriteLine("Multiplication of 4 and 8 is " + calculate.calcMulti());
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

            // Question 7
            Console.WriteLine("7. Inheritance");
            Console.WriteLine("Demonstrating Single-level Inheritance:");
            Car myCar = new Car("Toyota", 2022, 4);
            myCar.DisplayInfo();

            Console.WriteLine("\nDemonstrating Multi-level Inheritance:");
            ElectricCar myElectricCar = new ElectricCar("Tesla", 2023, 4, 75);
            myElectricCar.DisplayInfo();
            Console.WriteLine("----------------------------------\n");

            // Question 8
            Console.WriteLine("8. Use of base keyword");
            Dog dog = new Dog();
            dog.Eat();
            Console.WriteLine("----------------------------------\n");

            // Question 9
            Console.WriteLine("9. Method Overriding");
            Parent obj = new Child();
            obj.display();
            Console.WriteLine("----------------------------------\n");

            // Question 10
            Console.WriteLine("10. Multiple Inheritance using Interface");
            Human Ben = new Human();
            Ben.Walk();
            Ben.Swim();
            Console.WriteLine("----------------------------------\n");

            // Question 11
            Console.WriteLine("11. Abstract Class");
            DerivedClass obj1 = new DerivedClass();
            // AbsClass obj2 = new AbsClass();  // Cannot create instance of abstract class
            obj1.AbsMethod();
            obj1.NonAbsMethod();
            Console.WriteLine("----------------------------------\n");

            // Question 12
            Console.WriteLine("12. Exception Handling");
            ExceptionHandling eh = new ExceptionHandling();
            eh.Divide(10, 0);
            Console.WriteLine("----------------------------------\n");

            // Question 13
            Console.WriteLine("13. Interface");
            Ben ben = new Ben();
            ben.Greetings();
            Console.WriteLine("----------------------------------\n");

            // Question 14
            Console.WriteLine("14. Lambda Expression");
            LambdaExpression lambda = new LambdaExpression();
            lambda.Lambda();
            Console.WriteLine("----------------------------------\n");
        }
    }
}