/*
 * Create a class Shape that contains instance variable length, breadth and height. 
 * Create a default constructor that sets the value of instance variable to zero, 
 * constructor with two parameter that will sets the value of length and breadth only and 
 * constructor with three parameter that will sets the value of length, breadth and height. 
 * After this create calcAreaRectangle() that calculates the area of rectangle, 
 * calcVolumeBox() that calculates volume of box and display the result. 
 * 
 * 1. Create first object of Shape wihich will have name rectangle and calls constructor with two parameter and calAreaRectangle() method
 * 2. Create second object of Shape that will have name Box which will call constructor with three parameter and calcVolumeBox() method.
 */

namespace Lab1
{
  public class Shape
  {
      private double length;
      private double breadth;
      private double height;

      // Default constructor
      public Shape()
      {
          length = 0;
          breadth = 0;
          height = 0;
      }

      // Constructor with two parameters
      public Shape(double length, double breadth)
      {
          this.length = length;
          this.breadth = breadth;
          this.height = 0;
      }

      // Constructor with three parameters
      public Shape(double length, double breadth, double height)
      {
          this.length = length;
          this.breadth = breadth;
          this.height = height;
      }

      public void calcAreaRectangle()
      {
          double area = length * breadth;
          Console.WriteLine($"Area of Rectangle: {area}");
      }

      public void calcVolumeBox()
      {
          double volume = length * breadth * height;
          Console.WriteLine($"Volume of Box: {volume}");
      }
  }
}