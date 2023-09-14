#include "encoder.h"
int NO_QUOTE = 0;
int OPEN_QUOTE = 1;
int QUOTE_PAIRED = 2;
int ENCODER_ERROR = 0;
int ENCODER_SUCCESS = 1;

/*
 * Convert the hexadecimal string into the integer.
 * args: 
 *  s: const string with 2 letters denoting a hexadecimal number.
 *  ret: the corresponding decimal integer output.
 * return: 1 for valid, 0 for invalid.
 */
int hex2dec(const char *s, int *ret) {
  if (*s > 127 || *(s+1) > 127) return ENCODER_ERROR;

  // Initialize the look-up table for conversion
  int hex_table[128]; for (int i = 0; i < 128; i++) hex_table[i] = -1;
  for (int i = 48; i < 58; i++) {
    hex_table[i] = i - 48;
  }
  for (int i = 65; i < 71; i++) {
    hex_table[i] = 10 + i - 65;
  }
  for (int i = 97; i < 103; i++) {
    hex_table[i] = 10 + i - 97;
  }
  
  // Look up in the table and validate
  const int first = hex_table[*s];
  const int second = hex_table[*(s+1)];
  if (first == -1 || second == -1) return ENCODER_ERROR;

  *ret = first * 16 + second;
  return ENCODER_SUCCESS;
}

/*
 * Convert the escape character into corresponding ASCII char.
 * args:
 *  s: The input escape character.
 *  ret: The output escaped character.
 * return: 0 for invalid, other positive integer for the length of the escape
 *  characters string.
 */
int escape(const char *s, char *ret) {
  if (*s != '\\') return ENCODER_ERROR;
  int convert_table[128]; for (int i = 0; i < 128; i++) convert_table[i] = -1;
  convert_table['a'] = 7; convert_table['b'] = 8; convert_table['e'] = 27;
  convert_table['f'] = 12; convert_table['n'] = 10; convert_table['r'] = 13;
  convert_table['t'] = 9; convert_table['v'] = 11; convert_table['\\'] = 92;
  convert_table['\''] = 39; convert_table['\"'] = 34;

  int length = 1;
  if (*(s+1) == '0' && *(s+2) == 'x') {
    int hex = 0;
    if (hex2dec(s + 3, &hex)) {
      *ret = hex;
      length = 5;
    } else {
      return ENCODER_ERROR;
    }
  } else if (convert_table[*(s+1)] != -1) {
    *ret = convert_table[*(s+1)];
    length = 2;
  } else {
    return ENCODER_ERROR;
  }
  return length;
}

int reverse_escape(const char *s, char *ret) {
  char convert_table[128]; for (int i = 0; i < 128; i++) convert_table[i] = 0;
  convert_table[7] = 'a'; convert_table[8] = 'b'; convert_table[27] = 'e';
  convert_table[12] = 'f'; convert_table[10] = 'n'; convert_table[13] = 'r';
  convert_table[9] = 't'; convert_table[11] = 'v'; convert_table[92] = '\\';
  convert_table[39] = '\''; convert_table[34] = '\"';

  char escaped = convert_table[*s];
  if (!escaped) return ENCODER_ERROR;
  *ret = '\\';
  char *next = ret + 1;
  *next = escaped;
  return 2;
}

int string_decode(const char *es, char *s) {
  const char *es_ptr = es;
  char *s_ptr = s;
  int quote = NO_QUOTE;
  while (*es_ptr != '\0') {
    if (!(32 <= *es_ptr && *es_ptr <= 126)) return ENCODER_ERROR;

    // Limit the length of the string
    if (es_ptr - es >= 256) return ENCODER_ERROR;

    char escaped ='\0';
    int escape_result = 0;

    switch (*es_ptr) {
      case '\"':
      es_ptr++;
      if (quote == NO_QUOTE)
        quote = OPEN_QUOTE;
      else
        if (*es_ptr != '\0') return ENCODER_ERROR;
        else quote = QUOTE_PAIRED;
      break;
      case '\\':
      if (quote != OPEN_QUOTE) return ENCODER_ERROR;
      escape_result = escape(es_ptr, &escaped);
      if (escape_result) {
        *s_ptr = escaped;
        s_ptr++;
        es_ptr += escape_result;
      } else {
        return ENCODER_ERROR;
      }
      break;
      default:
      if (quote != OPEN_QUOTE) return ENCODER_ERROR;
      *s_ptr = *es_ptr;
      s_ptr++;
      es_ptr++;
    }
  }
  if (quote == QUOTE_PAIRED) {
    *s_ptr = 0;
    return ENCODER_SUCCESS;
  }
  else return ENCODER_ERROR;
}

int string_encode(const char *es, char *s) {
  const char *es_ptr = es;
  char *s_ptr = s;
  *s_ptr = '\"';
  s_ptr++;
  while (*es_ptr != '\0') {
    int advance = reverse_escape(es_ptr, s_ptr);
    if (advance) {
      es_ptr++;
      s_ptr += advance;
    }
    else if (32 <= *es_ptr && *es_ptr <= 126) {
      *s_ptr = *es_ptr;
      s_ptr++;
      es_ptr++;
    } else {
      return ENCODER_ERROR;
    }
  }
  *s_ptr = '\"';
  s_ptr++;
  *s_ptr = 0;
  return ENCODER_SUCCESS;
}

int char_decode(const char *es, char *s) {
  const char *es_ptr = es;
  char *s_ptr = s;
  int quote = NO_QUOTE;
  while (*es_ptr != '\0') {
    if (!(32 <= *es_ptr && *es_ptr <= 126)) return ENCODER_ERROR;

    // Limit the length of the string
    if (es_ptr - es >= 256) return ENCODER_ERROR;

    char escaped ='\0';
    int escape_result = 0;

    switch (*es_ptr) {
      case '\'':
      es_ptr++;
      if (quote == NO_QUOTE)
        quote = OPEN_QUOTE;
      else
        if (*es_ptr != '\0') return ENCODER_ERROR;
        else quote = QUOTE_PAIRED;
      break;
      case '\\':
      if (quote != OPEN_QUOTE) return ENCODER_ERROR;
      escape_result = escape(es_ptr, &escaped);
      if (escape_result) {
        *s_ptr = escaped;
        s_ptr++;
        es_ptr += escape_result;
      } else {
        return ENCODER_ERROR;
      }
      break;
      default:
      if (quote != OPEN_QUOTE) return ENCODER_ERROR;
      *s_ptr = *es_ptr;
      s_ptr++;
      es_ptr++;
    }
  }
  if (quote == QUOTE_PAIRED) {
    *s_ptr = 0;
    return ENCODER_SUCCESS;
  }
  else return ENCODER_ERROR;
}
