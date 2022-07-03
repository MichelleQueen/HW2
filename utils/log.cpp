#include "log.hpp"
#include <stdarg.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#define LOG_ENABLED

void LOG::game_log(const char *format, ...){
#ifdef LOG_ENABLED
    va_list arg;
    va_start(arg, format);
    game_vlog(format, arg);
    va_end(arg);
#endif
}

void LOG::game_vlog(const char* format, va_list arg) {
#ifdef LOG_ENABLED
    static bool clear_file = true;
    vprintf(format, arg);
    printf("\n");
    // Write log to file for later debugging.
    FILE* pFile = fopen("log.txt", clear_file ? "w" : "a");
    if (pFile) {
        vfprintf(pFile, format, arg);
        fprintf(pFile, "\n");
        fclose(pFile);
    }
    clear_file = false;
#endif
}

void LOG::game_abort(const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    game_vlog(format, arg);
    va_end(arg);
    fprintf(stderr, "error occured, exiting after 2 secs");
    // Wait 2 secs before exiting.
    al_rest(2);
    // Force exit program.
    exit(1);
}