#ifndef __STRING_H__
#define __STRING_H__

/*
 * See "man 3 strlen"
 */
long strlen(const char *str);

/*
 * See "man 3 strstr"
 */
char *strstr(const char *haystack, const char *needle);

/*
 * See "man 3 strncat"
 */
char *strncat(char *dest, const char *src, long n);

int strncmp(const char *s1, const char *s2, long n);

#endif // __STRING_H__
