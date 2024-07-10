namespace Lab1
{
  public interface IWalk
  {
    void Walk();
  }
  public interface ISwim
  {
    void Swim();
  }

  public class Human : IWalk, ISwim
  {
    public void Walk()
    {
      Console.WriteLine("Human walks");
    }

    public void Swim()
    {
      Console.WriteLine("Human swims");
    }
  }
}