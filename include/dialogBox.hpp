#ifndef DIALOG_BOX_H
#define DIALOG_BOX_H
#include <map>
#include <string>

namespace pei
{
  class DialogBox
  {
  public:
    DialogBox( std::map<std::string,double> &params ):params(&params){};
    void show();
  private:
    std::map<std::string,double> *params;
  };
}
#endif
