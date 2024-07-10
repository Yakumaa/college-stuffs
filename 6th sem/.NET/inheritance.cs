/*
 * * Program to demonstrate Single-level and Multi-level inheritance in C#
 */

namespace Lab1
{
  // Base class
  public class Vehicle
  {
      public string Brand { get; set; }
      public int Year { get; set; }

      public Vehicle(string brand, int year)
      {
          Brand = brand;
          Year = year;
      }

      public virtual void DisplayInfo()
      {
          Console.WriteLine($"Brand: {Brand}, Year: {Year}");
      }
  }

  // Single-level inheritance: Car inherits from Vehicle
  public class Car : Vehicle
  {
      public int NumberOfDoors { get; set; }

      public Car(string brand, int year, int doors) : base(brand, year)
      {
          NumberOfDoors = doors;
      }

      public override void DisplayInfo()
      {
          base.DisplayInfo();
          Console.WriteLine($"Number of Doors: {NumberOfDoors}");
      }
  }

  // Multi-level inheritance: ElectricCar inherits from Car, which inherits from Vehicle
  public class ElectricCar : Car
  {
      public int BatteryCapacity { get; set; }

      public ElectricCar(string brand, int year, int doors, int batteryCapacity) : base(brand, year, doors)
      {
          BatteryCapacity = batteryCapacity;
      }

      public override void DisplayInfo()
      {
          base.DisplayInfo();
          Console.WriteLine($"Battery Capacity: {BatteryCapacity} kWh");
      }
  }
}
