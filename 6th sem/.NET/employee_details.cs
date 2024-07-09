/*
 * Create a class EmployeeDetails having data member empId, empName, empGender, empAddress, and empPosition.
 * Constructor to set the details and 
 * display method to display the details. 
 * 
 * Create a subclass SalaryInfo that will inherit EmployeeDetails having own data member salary which will record salary per year.
 * Constructor to set the value of salary and 
 * method calcTax() that deduct the tax on salary and display the final salary. 
 * 
 * Tax rate is given as (if salary <= 400000 tax is 1%, salary between 400001 to 800000 tax is 10% and salary > 800000 tax 20%). 
 * Now create the object of Salary info and demonstrate the scenario.
 */

namespace Lab1
{
  public class EmployeeDetails
  {
      protected int empId;
      protected string empName;
      protected char empGender;
      protected string empAddress;
      protected string empPosition;

      public EmployeeDetails(int id, string name, char gender, string address, string position)
      {
          empId = id;
          empName = name;
          empGender = gender;
          empAddress = address;
          empPosition = position;
      }

      public void Display()
      {
          Console.WriteLine("Employee Details:");
          Console.WriteLine($"ID: {empId}");
          Console.WriteLine($"Name: {empName}");
          Console.WriteLine($"Gender: {empGender}");
          Console.WriteLine($"Address: {empAddress}");
          Console.WriteLine($"Position: {empPosition}");
      }
  }

  public class SalaryInfo : EmployeeDetails
  {
      private double salary;

      public SalaryInfo(int id, string name, char gender, string address, string position, double salary)
          : base(id, name, gender, address, position)
      {
          this.salary = salary;
      }

      public void CalcTax()
      {
          double tax = 0;
          double finalSalary;

          if (salary <= 400000)
          {
              tax = salary * 0.01;
          }
          else if (salary <= 800000)
          {
              tax = salary * 0.10;
          }
          else
          {
              tax = salary * 0.20;
          }

          finalSalary = salary - tax;

          Console.WriteLine($"Salary: NPR {salary:N2}");
          Console.WriteLine($"Tax: NPR {tax:N2}");
          Console.WriteLine($"Final Salary after tax deduction: NPR {finalSalary:N2}");
      }
  }
}