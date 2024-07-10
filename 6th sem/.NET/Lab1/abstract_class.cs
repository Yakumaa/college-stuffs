namespace Lab1
{
        abstract class AbsClass
        {
            public abstract void AbsMethod();
            public void NonAbsMethod()
            {
                Console.WriteLine("this is non abstract method");
            }
        }

        class DerivedClass : AbsClass
        {
            public override void AbsMethod()
            {
                Console.WriteLine("Overridden abstract method");
            }
        }
}