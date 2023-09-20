/*
  Name: Temitope Oladimeji Samuel Adebayo

  I have done all the coding by myself and only copied the code that my professor 
  provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>

namespace sdds {
  class Text {
    char* m_filename;
    char* m_content;
    int getFileLength()const;
    void setEmpty();
  protected:
    const char& operator[](int index)const;
  public:
    Text(const char* filename=nullptr);

    // Rule of three (copy constructor, copy assignment, destructor)
    Text(const Text& src);
    Text& operator=(const Text& src);
    ~Text();

    void read();
    virtual void write(std::ostream& ostr)const;
  };

  std::ostream& operator<<(std::ostream& ostr, const Text&);
}
#endif // !SDDS_PERSON_H__