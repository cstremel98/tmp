
#include "student_code.h"
#include <string.h>
#include <stdlib.h>

String String__init(char* input_c_str) {
  String new_str;

  size_t length_of_string = strlen(input_c_str);

  new_str.length = length_of_string;
  new_str.capacity = length_of_string + 1;

  new_str.data = malloc(new_str.capacity);
  strncpy(new_str.data, input_c_str, new_str.capacity);

  return new_str;
}

void String__delete(String* str) {
  free(str->data);
}

size_t String__length(const String* str) {
  return str->length;
}

void String__reserve(String* str, size_t new_capacity) {
	if(new_capacity < str->capacity) {
		//Do nothing
	} else {
			size_t old_cap = str->capacity;
			str->data = realloc(str->data, new_capacity+1);
			str->capacity = new_capacity+1;	
			for(int i=old_cap; i<str->capacity; i++) {
				str->data[i] = '\0';
			}
	}
}

void String__resize(String* str, size_t new_size, const char c) {
	
}

void String__clear(String* str) {
  // todo
}

bool String__empty(String* str) {
  // todo
  return false;  // placeholder return value
}

char String__at(String* str, size_t index) {
  // todo
  return '\0';  // placeholder return value
}

char String__back(String* str) {
  // todo
  return '\0';  // placeholder return value
}

char String__front(String* str) {
  // todo
  return '\0';  // placeholder return value
}

void String__append(String* str, const String* str_to_add) {
  // todo
}

void String__push_back(String* str, const char char_to_add) {
  // todo
}

void String__pop_back(String* str) {
  // todo
}

void String__insert(String* str, const String* str_to_insert, size_t index) {
  // todo
}

void String__erase(String* str, size_t pos, size_t len) {
  // todo
}

void String__replace(String* str, size_t pos, size_t len, const String* str_to_replace_with) {
  // todo
}

void String__swap(String* str1, String* str2) {
  // todo
}
