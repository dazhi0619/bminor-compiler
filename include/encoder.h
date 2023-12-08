#ifndef ENCODER_H
#define ENCODER_H

extern int NO_QUOTE;
extern int OPEN_QUOTE;
extern int QUOTE_PAIRED;
extern int ENCODER_ERROR;
extern int ENCODER_SUCCESS;

int string_decode(const char *es, char *s);
int string_encode(const char *es, char *s);
int char_decode(const char *es, char *s);
#endif  // !ENCODER_H
