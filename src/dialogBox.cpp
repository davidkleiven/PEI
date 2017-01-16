#include "dialogBox.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

pei::DialogBox::~DialogBox()
{
  if ( window != NULL ) delete window;
  for ( unsigned int i=0;i<input.size();i++ )
  {
    Fl::delete_widget(input[i]);
  }
  Fl::delete_widget( ok );
}

void pei::DialogBox::init()
{
  if ( initDisabled ) return;

  readPrevParams();
  // Allocate window
  window = new Fl_Window( width, height );
  window->label("Enter Parameters");

  unsigned int counter = 0;
  for ( auto iter=params->begin(); iter != params->end(); ++iter )
  {
    unsigned int y = getEntryYPos( counter );
    unsigned int x = getEntryXPos( counter++ );
    if ( y >= height-entryHeight ) break;

    stringstream ss;
    ss << iter->second;

    input.push_back( new Fl_Float_Input( x, y, getX(entryWidth), getY(entryHeight), iter->first.c_str() ) );
    input.back()->value( ss.str().c_str() );
  }

  ok = new Fl_Return_Button( getX(0.6), getY(0.9), getX(0.3), getY(0.05), "OK and Close" );
  ok->callback( okCallback, this );
  initDisabled = true;
}

unsigned int pei::DialogBox::getEntryYPos( unsigned int number ) const
{
  return (number/2)*getY(entryHeight)*( 1.0 + entrySepFracOfHeight ) + entrySepFracOfHeight*getY(entryHeight);
}

unsigned int pei::DialogBox::getEntryXPos( unsigned int number ) const
{
  if ( number%2 == 0 )
  {
    return 0.3*width;
  }
  return 0.8*width;
}

int pei::DialogBox::show()
{
  if ( !initDisabled )
  {
    init();
  }

  window->end();
  window->show();
  return Fl::run();
}

void pei::DialogBox::okCallback( Fl_Widget *button, void *box )
{
  pei::DialogBox* self = static_cast<pei::DialogBox*>( box );

  auto iter = self->params->begin();
  for ( unsigned int i=0;i<self->input.size();i++ )
  {
    iter->second = getNumber( self->input[i]->value() );
    ++iter;
  }
  self->window->hide();
  self->save();
}

double pei::DialogBox::getNumber( const char* value )
{
  stringstream ss;
  ss << value;
  double returnVal;
  ss >> returnVal;
  return returnVal;
}

void pei::DialogBox::save()
{
  ofstream os;
  os.open(backupFname.c_str());
  if ( !os.good() ) return;

  for ( auto iter=params->begin(); iter != params->end(); ++iter )
  {
    os << iter->first << "," << iter->second << "\n";
  }
  os.close();
}

void pei::DialogBox::readPrevParams()
{
  ifstream infile;
  infile.open( backupFname.c_str() );

  if ( !infile.good() ) return;

  string first;
  double second;
  char comma;
  string line;
  map<string,double> optionsFromFile;
  while ( getline(infile,line) )
  {
    unsigned int commaPos = line.find(",");
    first = line.substr(0,commaPos);
    stringstream ss(line.substr(commaPos+1));
    ss >> second;
    optionsFromFile.insert( pair<string,double>(first,second) );

  }
  infile.close();

  if ( keysAreEqual(optionsFromFile, *params) )
  {
    *params = optionsFromFile;
  }
}

bool pei::DialogBox::keysAreEqual( const map<string,double> &map1, const map<string,double> &map2 )
{
  if ( map1.size() != map2.size() )
  {
    return false;
  }

  auto iter1 = map1.begin();
  for ( auto iter2=map2.begin(); iter2 != map2.end(); ++iter2 )
  {
    if ( iter1->first != iter2->first )
    {
      return false;
    }
    ++iter1;
  }

  return true;
}
