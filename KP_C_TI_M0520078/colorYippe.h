//untuk Windows (32-bit and 64-bit)
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
  #include <windows.h>
  #define colorYippe1(x) \
  system(""#x"") \

//untuk MAC atau linux atau unix OS
#elif defined __APPLE__ || __linux__ || __unix__
  #define cyan          "\e[36m"    
  #define green         "\e[32m"     
  #define blue          "\e[34m" 
  #define black         "\e[30m"
  #define magenta       "\e[35m"
  #define lightgrey     "\e[37m"
  #define darkgrey      "\e[100m"
  #define lightred      "\e[101m"
  #define lightgreen    "\e[102m"
  #define yellow        "\e[103m"
  #define lightblue     "\e[104m"
  #define lightpurple   "\e[105m"
  #define teal          "\e[106m"
  #define white         "\e[107m"
  #define resetColor    "\e[0m"

#endif