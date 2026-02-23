#include "student_code.h"

int main() {

  char* test_c_string_1 = "Hello";
  String test_str_1 = String__init(test_c_string_1);

  char* test_c_string_2 = "Goodbye";
  String test_str_2 = String__init(test_c_string_2);

  int replacement_offset = 1;
  int replacement_length = 2;	


String__replace(&test_str_1, replacement_offset, replacement_length, &test_str_2);

return 0;
}
