/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#include "HtmlText.h"
#include "cstring.h"

namespace sdds {
  void HtmlText::setEmpty() {
    m_title = nullptr;
  }

  HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
    setEmpty();
    if (title != nullptr) {
      m_title = new char[strLen(title) + 1];
      strCpy(m_title, title);
    }
  }

  HtmlText::HtmlText(const HtmlText& src) : Text(src) {
    setEmpty();
    if (src.m_title != nullptr) {
      m_title = new char[strLen(src.m_title) + 1];
      strCpy(m_title, src.m_title);
    }
  }

  HtmlText& HtmlText::operator=(const HtmlText& src) {
    if (this != &src) {
      Text::operator=(src);
      delete[] m_title;
      setEmpty();
      if (src.m_title != nullptr) {
        m_title = new char[strLen(src.m_title) + 1];
        strCpy(m_title, src.m_title);
      }
    }
    return *this;
  }

  HtmlText::~HtmlText() {
    delete[] m_title;
    setEmpty();
  }

  void HtmlText::write(std::ostream& ostr)const {
    bool ms = false;
    int i;
    ostr << "<html><head><title>";
    if (m_title != nullptr) {
      ostr << m_title;
    }
    else { 
      ostr << "No Title";
    }
    ostr << "</title></head>\n<body>\n";
    if (m_title != nullptr) {
      ostr << "<h1>" << m_title << "</h1>\n";
    }

    for (i = 0; (*this)[i] != '\0'; i++) {
      switch ((*this)[i]) {
        case ' ':
          if (ms) {
            ostr << "&nbsp;";
          }
          else {
            ms = true;
            ostr << " ";
          }
          break;
        case '<':
          ostr << "&lt;";
          ms = false;
          break;
        case '>':
          ostr << "&gt;";
          ms = false;
          break;
        case '\n':
          ostr << "<br />\n";
          ms = false;
          break;
        default:
          ostr << (*this)[i];
          ms = false;
      }
    }

    ostr << "</body>\n</html>";
  }
}