#ifndef _LOG_HPP
#define _LOG_HPP

#include <stdio.h>

namespace LOG{
	/* Declare function prototypes for debugging. */
	// Display error message and exit the program, used like 'printf'.
	// Write formatted output to stdout and file from the format string.
	// If the program crashes unexpectedly, you can inspect "log.txt" for
	// further information.
	void game_abort(const char* format, ...);
	// Log events for later debugging, used like 'printf'.
	// Write formatted output to stdout and file from the format string.
	// You can inspect "log.txt" for logs in the last run.
	void game_log(const char* format, ...);
	// Called by 'game_abort', 'game_log' to deal with va_lists.
	void game_vlog(const char* format, va_list arg);
}

#endif