

#include "student_code.h"
#include <string.h>
#include <stdlib.h>

String String__init(char* input_c_str) {
  String new_str;

  // Get size of the input string since we use it a few times throughout
  size_t length_of_string = strlen(input_c_str);

  // Set metadata associated with the string
  new_str.length = length_of_string;
  new_str.capacity = length_of_string + 1;

  // Copy over the data itself
  new_str.data = malloc(new_str.capacity);
  strncpy(new_str.data, input_c_str, new_str.capacity);

  // Return the string
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

	// new_size > str->capacity
	if(str->capacity < new_size) {
		for(int i=str->length; i<new_size; i++) {
			str->data[i] = c;
		}
	// new_size < str->capcity
	} else {
		for(int i=str->capacity; i>=new_size; i--) {
			if(i > new_size) {
				str->data[i] = '\0'; // Space beyond new size
			} else if(i == new_size) {
				str->data[i] = '\0'; // New capacity
			} else {
				str->data[i] = c; // New length
			}
		}
		str->data = realloc(str->data, new_size);
		str->capacity = new_size;
		str->length = new_size-1;
	}

}

void String__clear(String* str) {
	str->data = malloc(1);
	str->capacity = 1;
	str->data[0] = '\0';
	str->length = 0;
	//str->data = realloc(str->data, 0);
	//str->data = realloc(str->data, empty);
}

bool String__empty(String* str) {
  if(str->length == 0) {
		return true;
	} else {
		return false;
	}
}

char String__at(String* str, size_t index) {
  return str->data[index];
	if(index == str->capacity) {
		return '\0';  // placeholder return value
	}
}

char String__back(String* str) {
	return str->data[str->length-1];
}

char String__front(String* str) {
	return str->data[0];
}

void String__append(String* str, const String* str_to_add) {
	
	size_t new_len = str->length + str_to_add->length;
	char* tmp = realloc(str->data, new_len+1);
	if(tmp == NULL) {
	} else {
		str->data = tmp;
	}

	int it = 0;
	for(int i=str->length; i<new_len; i++) {
		str->data[i] = str_to_add->data[it];
		it++;
	}
	str->data[new_len] = '\0';

	str->length = new_len;

}

void String__push_back(String* str, const char char_to_add) {
	str->data[str->length] = char_to_add;
	str->length += 1;
	str->capacity += 1;
}

void String__pop_back(String* str) {
	str->data[str->length-1] = str->data[str->length];
	str->length -= 1;
	str->capacity -= 1;
	char* tmp = realloc(str->data, str->capacity-1);
}

void String__insert(String* str, const String* str_to_insert, size_t index) {
	
	size_t new_len = str->length + str_to_insert->length;
	char* tmp = realloc(str->data, new_len+1);
	str->data = tmp;

	int it = index;
	for(int i=str_to_insert->length + index; i<new_len; i++) {
		str->data[i] = str->data[it];
		it++;
	}
	str->data[new_len] = '\0';
	
	it = 0;
	for(int i=index; i<str_to_insert->length + index; i++) {
		str->data[i] = str_to_insert->data[it];
		it++;
	}
	
	str->length = new_len;

}

void String__erase(String* str, size_t pos, size_t len) {

	for(int i=pos; i<=len; i++) {
		for(int j=i; j<str->length; j++) {
			char tmp = str->data[j];
			str->data[j] = str->data[j+1];
			str->data[j+1] = tmp;
		}
	}

	str->length = str->length - len;
	str->data[str->length] = '\0';
	
	str->data = realloc(str->data, str->length+1);

}

void String__replace(String* str, size_t pos, size_t len, const String* str_to_replace_with) {
	
	size_t old_len = str->length;
	size_t new_len = (str->length-len) + str_to_replace_with->length;
	char* tmp = realloc(str->data, new_len+1);
	str->data = tmp;
	

	int it = old_len-len;
	for(int i=str_to_replace_with->length + pos; i<new_len; i++) {
		str->data[i] = str->data[it];
		it++;
	}
	str->data[new_len] = '\0';

	it = 0;
	for(int i=pos; i<str_to_replace_with->length+pos; i++) {
		str->data[i] = str_to_replace_with->data[it];
		it++;
	}
	str->length = new_len;

}

void String__swap(String* str1, String* str2) {
	
	char* tmp1 = realloc(str1->data, str1->capacity);
	char* tmp2 = realloc(str2->data, str2->capacity);
	
	size_t strLen = str1->length;
	size_t strCap = str1->capacity;
	str1->data = tmp2;
	str1->length = str2->length;
	str1->capacity = str2->capacity;
	
	str2->data = tmp1;
	str2->length = strLen;
	str2->capacity = strCap;
	
}
