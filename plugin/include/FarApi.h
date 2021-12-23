#ifndef FAR_S3_MANAGER_PLUGIN_INCLUDE_FARAPI_H_
#define FAR_S3_MANAGER_PLUGIN_INCLUDE_FARAPI_H_

#include "Message.h"

namespace S3Manager {
/**
 * API for interaction with FAR Manager.
 *
 * This class exposes a set of useful methods that allow interaction with FAR.
 * Most of the methods are convenient wrappers around functions found in
 * #PluginStartupInfo.
 */
class FarApi {
 private:
  const struct PluginStartupInfo *startupInfo;

 public:
  /**
   * Create a new instance of FAR API class.
   *
   * @param[in] pluginStartupInfo a pointer to the PluginStartInfo structure,
   *                              obtained during the plugin's startup process
   */
  explicit FarApi(const struct PluginStartupInfo *pluginStartupInfo)
      : startupInfo(pluginStartupInfo) {}

  /**
   * Get localized message from a language file.
   *
   * @param[in] message a message to get, given as a Message enum
   * @return A pointer to a wchar_t containing a localized message.
   */
  const wchar_t *getMessage(Message message);
};
}  // namespace S3Manager

#endif  // FAR_S3_MANAGER_PLUGIN_INCLUDE_FARAPI_H_
