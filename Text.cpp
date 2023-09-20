/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#include <fstream>
#include "Text.h"
#include "cstring.h"

using namespace std;

namespace sdds {
  int Text::getFileLength() const {
    int len = 0;
    ifstream fin(m_filename);
    while (fin) {
      fin.get();
      len += !!fin;
    }
    return len;
  }

  void Text::setEmpty() {
    m_content = nullptr;
    m_filename = nullptr;
  }

  const char& Text::operator[](int index) const {
    return m_content[index];
  }

  Text::Text(const char* filename) {
    setEmpty();
    if (filename != nullptr) {
      m_filename = new char[strLen(filename) + 1];
      strCpy(m_filename, filename);
      read();
    }
  }

  Text::Text(const Text& src) {
    setEmpty();
    if (src.m_filename != nullptr) {
      *this = src;
    }
  }

  Text& Text::operator=(const Text& src) {
    if (this != &src) {
      delete[] m_content;
      delete[] m_filename;
      setEmpty();
      if (src.m_filename != nullptr) {
        m_filename = new char[strLen(src.m_filename) + 1];
        strCpy(m_filename, src.m_filename);
        m_content = new char[strLen(src.m_content) + 1];
        strCpy(m_content, src.m_content);
      }
    }
    return *this;
  }

  Text::~Text() {
    delete[] m_content;
    delete[] m_filename;
    setEmpty();
  }

  void Text::read() {
    int i;
    if (m_filename != nullptr) {
      delete[] m_content;
      m_content = nullptr;

      ifstream fin(m_filename);
      if (fin.is_open()) {
        int len = getFileLength();
        m_content = new char[len + 1];

        for (i = 0; i < len; i++) {
          m_content[i] = fin.get();
        }

        m_content[len] = '\0';
      }

      fin.close();
    }
  }

  void Text::write(std::ostream& ostr) const {
    if (m_content != nullptr) {
      ostr << m_content;
    }
  }

  std::ostream& operator<<(std::ostream& ostr, const Text& text) {
    text.write(ostr);
    return ostr;
  }
}