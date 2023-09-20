/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__

#include "Text.h"

namespace sdds {
  class HtmlText : public Text {
    char* m_title;
    void setEmpty();
  public:
    HtmlText(const char* filename=nullptr, const char* title = nullptr);

    // Rule of three (copy constructor, copy assignment, destructor)
    HtmlText(const HtmlText& src);
    HtmlText& operator=(const HtmlText& src);
    ~HtmlText();

    // override Text::write function
    void write(std::ostream& ostr)const;
  };
}

#endif // !SDDS_HTMLTEXT_H__