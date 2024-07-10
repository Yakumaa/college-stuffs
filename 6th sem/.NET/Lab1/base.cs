namespace Lab1
{
  public class Animal
  {
    public void Eat()
    {
      Console.WriteLine("Every animal eats food.");
    }
  }
  public class Dog: Animal
  {
    public new void Eat()
    {
      base.Eat();
      Console.WriteLine("Dog eats bones.");
    }
  }
}