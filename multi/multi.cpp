#include <iostream>
#include "thread.h"
using namespace std;

void lol ()
{
  cout << "lol" << endl;
}

void yo ()
{
  cout << "yo" << endl;
}

main()
{
  thread idiot(lol, 10);
  thread stupid(yo, 15);
  idiot.execute();
  stupid.execute();
}
