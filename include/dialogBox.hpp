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

    /** Display the dialogbox */
    int show();
  private:
    std::map<std::string,double> *params;
    unsigned int width{720};
    unsigned int height{640};
    Fl_Window *window{NULL};
    Fl_Return_Button *ok;
    std::vector<Fl_Float_Input*> input;
    bool initDisabled{false};
    double entryWidth{0.2};
    double entryHeight{0.03};
    double entryXPos{0.6};
    double entrySepFracOfHeight{0.33};
    std::string backupFname{"dialogBoxBackupParameters.csv"};

    /** Get the position of the n-th entry box */
    unsigned int getEntryXPos( unsigned int number ) const;

    /** Get entry y-position of the n-th entry box */
    unsigned int getEntryYPos( unsigned int number ) const;

    /** Initialize the dialogbox */
    void init();

    /** Get the global coordinate in horizontal direction crd =[0,1] */
    unsigned int getX( double crd ) const { return width*crd; };

    /** Ge the global coordinate in vertical direction crd=[0,1] */
    unsigned int getY( double crd ) const { return height*crd; };

    /** Save the parameters. They will be re*/
    void save();

    /** Read back the previous values for the parameters */
    void readPrevParams();

    /** Callback function for the return button */
    static void okCallback( Fl_Widget *button, void *dialogBox );

    /** Convert const char* to double */
    static double getNumber( const char* value );

    /** Check whether the key in two maps are equal */
    static bool keysAreEqual( const std::map<std::string,double> &map1, const std::map<std::string,double> &map2 );
  };
}
#endif
