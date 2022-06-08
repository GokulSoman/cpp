#include <iostream>
// #include <utility>
#include <any>
#include<string>
using namespace std;

int main()
{ 
  auto a = std::any("Hello World!");
  
  try 
{
    cout << std::any_cast<std::string>(a) << endl;
}
catch(const std::bad_any_cast& e) 
{
    std::cout << e.what() << '\n';
}
  return 0;
}
