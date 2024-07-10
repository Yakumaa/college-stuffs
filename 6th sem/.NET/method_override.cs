namespace Lab1
{
    class Parent
    {
        public virtual void display()
        {
            Console.WriteLine("parent class display method");
        }
    }

    class Child: Parent
    {
        public override void display()
        {
            base.display(); //calling parent class method
            Console.WriteLine("child class display method");
        }
    }
}