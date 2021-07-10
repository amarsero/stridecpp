#include "ConsoleLogListener.h"

inline void ConsoleLogListener::OnLog(ILogMessage logMessage)
{
  static const char * const debug = "\x1B[30m";
  static const char * const verbose = "\x1B[30m";
  static const char * const info = "\x1B[90m";
  static const char * const warning = "\x1B[33m";
  static const char * const error = "\x1B[31m";
  static const char * const fatal = "\033[1;37;91m";
  static const char * const colorSuffix = "\033[0m";
  const char *color = NULL;
  switch (logMessage.Type) {
  case LogMessageType::Debug:
    color = debug;
    break;
  case LogMessageType::Verbose:
    color = verbose;
    break;
  case LogMessageType::Info:
    color = info;
    break;
  case LogMessageType::Warning:
    color = warning;
    break;
  case LogMessageType::Error:
    color = error;
    break;
  case LogMessageType::Fatal:
    color = fatal;
    break;
  default:
    color = info;
    break;
  }
  printf("%s%s%s\n", color, logMessage.Text.c_str(), colorSuffix);
}
