//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include "catch.hpp"
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
// class Complex {
//     void operator>>(std::string&) const;
//     void operator<<(const std::string&);
// };


class Complex
{
private:
        int imaginary, real;
public:



 Complex(int real = 0, int imaginary = 0) : imaginary{imaginary}, real {real} {}

  int re() 
   {
    return real;
   }

  int im()
   {
    return imaginary;
   }

   void operator>>(std::string& s) const
   {
    s.append(std::to_string(this->real));
    if (this->imaginary >= 0)
    {
    s.append("+=");

    }
    
    s.append(std::to_string(this->imaginary));
    s.append("i");

    }

  void operator<<(const std::string& s)
   {

    if (s[0] == '-')
    {
     int re = s[1] - '0';
     this->real = -1 * re;
    }
   else
    {
    this->real = s[0] - '0'; //converting char to int;
    }

  int a = s.find("i");
  int b = a - 1;
  int c = a - 2;
  if (s[c] == '-')
  {
   this->imaginary = -1 * (s[b] - '0');
  }
   else
  {
   this->imaginary = s[b] - '0';
  }


  }
  };





//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
