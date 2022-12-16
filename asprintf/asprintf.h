#ifndef ASPRINTF_H
#define ASPRINTF_H

int asprintf(char **str, const char *fmt, ...)
	__attribute__((format(printf, 2, 3)));

// __printf(string-index, first-to-check)
// is preferred over
// __attribute__((format(printf, string-index, first-to-check)))


#endif
