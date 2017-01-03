#include "dialogBox.hpp"
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

/* Prints the content of the map */
void printMap( map<string,double> &map )
{
  for ( auto iter = map.begin(); iter != map.end(); ++iter )
  {
    cout << iter->first << ": " << iter->second << endl;
  }
}

int main( int argc, char** argv )
{
  map<string,double> params;
  params["First parameter"] = 1.5;
  params["Second parameter"] = 1.5;
  params["Third parameter"] = 2.0;
  params["Fourth parameter"] = 2.0;

  cout << "Before edited map contains\n";
  printMap( params );
  try
  {
    pei::DialogBox box( params );
    box.show();
  }
  catch ( exception &exc )
  {
    cout << exc.what() << endl;
    return 1;
  }
  catch (...)
  {
    cout << "Unknown exception!\n";
    return 1;
  }

  cout << "\nAfter editing in GUI\n";
  printMap( params );
  return 0;
}
