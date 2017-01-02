#ifndef DIALOG_BOX_H
#define DIALOG_BOX_H
#include <map>
#include <string>
#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Float_Input.H>
#include <Fl/Fl_Return_Button.H>
#include <vector>

namespace pei
{
  class DialogBox
  {
  public:
    DialogBox( std::map<std::string,double> &params ):params(&params){};
    ~DialogBox();

    /** Initialize the dialogbox */
    void init();

    /** Display the dialogbox */
    int show();
  private:
    std::map<std::string,double> *params;
    unsigned int width{480};
    unsigned int height{640};
    Fl_Window *window{NULL};
    Fl_Return_Button *ok;
    std::vector<Fl_Float_Input*> input;
    bool initDisabled{false};
    double entryWidth{0.3};
    double entryHeight{0.03};
    double entryXPos{0.6};
    double entrySepFracOfHeight{0.33};

    /** Get the position of the n-th entry box */
    unsigned int getEntryPos( unsigned int number ) const;

    unsigned int getX( double crd ) const { return width*crd; };
    unsigned int getY( double crd ) const { return height*crd; };

    static void okCallback( Fl_Widget *button, void *dialogBox );
    static double getNumber( const char* value );
  };
}
#endif
