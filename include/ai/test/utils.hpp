#pragma once

#include <string>
#include <stdexcept>

using namespace std;

namespace Test {
   struct Result {
      bool state;
      bool isError;
      char* message;
   };

   class TestClass {
      private: 
         int index;

      public: 
         TestClass() {
            this->index = 0;
         }

         template <class Output>
         void run(Output output, Output expected, string msg = "") {
            this->index++;
            if (!(output == expected)) {
               string error = "Test with index [" + this->index;
               error += "] has failed\n\t";
               error += msg;
               // throw error.c_str();
               throw "Error";
            }
         }
   };
}

