#include <string>
#include <stack>
using namespace std;
bool mess_with_stack(const stack<string>* s);

int main{}
{
  bool test;
  stack<string> s;
  s.push("something");
  test = mess_with_stack(&s);
}

bool mess_with_stack(const stack<string>* s)
{
   if (s.empty())
      return true;
}
