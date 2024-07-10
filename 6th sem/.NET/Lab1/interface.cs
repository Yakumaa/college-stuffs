namespace Lab1
{
  interface IPerson
    {
        void Greetings();
    }

    class Ben : IPerson
    {
        public void Greetings()
        {
            Console.WriteLine("Hello, I am Ben.");
        }
    }
}