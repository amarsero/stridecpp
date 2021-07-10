#pragma once
#include <string>
#include "LogMessageType.h"
#include "ModulesEnum.h"
class ILogMessage
{
public:
  /// <summary>
  /// Gets or sets the module.
  /// </summary>
  /// <value>The module.</value>
  /// <remarks>
  /// The module is an identifier for a logical part of the system. It can be a class name, a namespace or a regular string not linked to a code hierarchy.
  /// </remarks>
  Modules Module;

  /// <summary>
  /// Gets or sets the type of this message.
  /// </summary>
  /// <value>The type.</value>
  LogMessageType Type;

  /// <summary>
  /// Gets or sets the text.
  /// </summary>
  /// <value>The text.</value>
  std::string Text;

  /// <summary>
  /// Gets or sets the exception info.
  /// </summary>
  //ExceptionInfo ExceptionInfo { get; }
};