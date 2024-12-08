
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool ascii_char_is_lower_case(char character) {
  return character >= 'a' && character <= 'z';
}

bool ascii_char_is_upper_case(char character) {
  return character >= 'A' && character <= 'Z';
}

char ascii_char_to_lower_case(char character) {
  assert(ascii_char_is_upper_case(character));
  return character + ('a' - 'A');
}

char ascii_char_to_upper_case(char character) {
  assert(ascii_char_is_lower_case(character));
  return character + ('A' - 'a');
}

void ascii_char_array_to_upper_case(char *zero_terminated_string) {
  assert(zero_terminated_string != 0);
  for (int array_index = 0;; array_index++) {
    char character = zero_terminated_string[array_index];
    if (character == '\0')
      break;
    if (ascii_char_is_lower_case(character)) {
      zero_terminated_string[array_index] =
          ascii_char_to_upper_case(zero_terminated_string[array_index]);
    }
  }
}

void ascii_char_array_to_upper_case_at_index(char *zero_terminated_string,
                                             int character_index) {
  assert(zero_terminated_string != 0);
  assert(index >= 0);
  char character = zero_terminated_string[character_index];
  if (character == '\0')
    return;
  if (ascii_char_is_lower_case(character)) {
    zero_terminated_string[character_index] =
        ascii_char_to_upper_case(zero_terminated_string[character_index]);
  }
}

bool ascii_char_array_is_equal_case_insensitively(char *string1,
                                                  char *string2) {
  int size1 = strlen(string1);
  int size2 = strlen(string2);
  if (size1 != size2)
    return false;
  for (int index = 0; index < size1; index++) {
    char character1 = string1[index];
    char character2 = string2[index];
    if (ascii_char_is_upper_case(character1))
      character1 = ascii_char_to_lower_case(character1);
    if (ascii_char_is_upper_case(character2))
      character2 = ascii_char_to_lower_case(character2);
    if (character1 != character2)
      return false;
  }
  return true;
}

int main() {
  bool boolean1 = false;
  puts(boolean1 ? "true" : "false");

  printf("%c\n", ascii_char_to_upper_case('a'));
  printf("%c\n", ascii_char_to_lower_case('A'));

  char string1[100];
  strcpy(string1, "krishna108");
  ascii_char_array_to_upper_case(string1);
  puts(string1);

  char string2[100];
  strcpy(string2, "krishna108");
  ascii_char_array_to_upper_case_at_index(string2, 0);
  puts(string2);

  char string3[100];
  strcpy(string3, "abcd");
  ascii_char_array_to_upper_case_at_index(string3, strlen(string3) - 1);
  puts(string3);

  bool is_equal_case_insensitively1 =
      ascii_char_array_is_equal_case_insensitively("0abCDx", "0aBcDX");
  puts(is_equal_case_insensitively1 ? "is_equal_case_insensitively1:true"
                                    : "is_equal_case_insensitively1:false");

  bool is_equal_case_insensitively2 =
      ascii_char_array_is_equal_case_insensitively("0abCDx", "0aBcDy");
  puts(is_equal_case_insensitively2 ? "is_equal_case_insensitively2:true"
                                    : "is_equal_case_insensitively2:false");
}
