#include "date.h"
#include <iostream.h>
#include <strstream.h>
#include <assert.h>

int main()
{
  cout << "11/30/2001 == " << Date(11,30,2001) << endl;

  for (int m=1; m<13; m++){
    Date d(m, 28, 2001);
    assert(d.GetDay() == 28);
  }
  Date angela(6,8,1975);
  cout << "Angela's birthday was:   " << angela   << endl;
  cout << "The day after was:        " << angela+1 << endl;
  cout << "The day before was:       " << angela-1 << endl;
    
  Date now;
  cout << "Today is:                 " << now.GetDayOfWeekName()
       << " " << now << endl;
  cout << "In two weeks it will be:  " << now + 14 << endl;
  cout << "Two weeks ago it was:     " << now - 14 << endl;
    
  Date then = now - 14;
  for (int i=0; i<5; i++)
    {
      then -= 365;
      cout << "365 days before that was: " << then << endl;
    }
  cout << "Days from now to then:    " << (now - then) << endl;
  assert( (now-then) == 365*5+14);
    
  Date yesterday = now-1;
  Date tomorrow = now+1;
  assert(yesterday < now);
  assert(now < tomorrow);
  assert(now == now);
  assert(now != yesterday);
  assert(now >= now);
  assert(now <= now);
  assert(now <= tomorrow);
  assert(yesterday <= now);
  assert(tomorrow==(1+now));
  assert(tomorrow==(now+1));
    
  Date theTarget = now+5;
  for (Date d=now; d<theTarget; d++)
    {
      cout << d << " is less than " << theTarget << endl;
    }
    
  Date x = now;
  assert(x == now);
  assert(x++ == now);
  assert(x == (now+1));
  assert(++x == (now+2));
  assert(--x == (now+1));
  assert(x-- == (now+1));
  assert(x == now);
    
  istrstream dateStream("   4  /  29    /  1986  ");
  Date gina;
  dateStream >> gina;
  cout << "Gina's birthday was read in as: " << gina << endl;
  Date ginax(4,29,1986);
  cout << "Gina's birthday is known to be: " << ginax << endl;
  assert(gina == ginax);
    
  cout << "Everything seems to work just fine....." << endl;
}

