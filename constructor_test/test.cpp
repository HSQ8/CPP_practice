#include <iostream>
class Foo
{
  public:
    Foo( int x=20, int my_int=7)
    {
      std::cout << "Foo's constructor "
        << "called with "
        << x
        << std::endl;
      this->my_int=my_int;
    }
  void display(){std::cout << my_int << std::endl;}
  private:
  int my_int;
};

class Bar : public Foo
{
  public:
    Bar() : Foo(30,45)  // construct the Foo part of Bar
  {
    std::cout << "Bar's constructor" << std::endl;

  }
};

int main()
{
  Bar stool;
  stool.display();
}
