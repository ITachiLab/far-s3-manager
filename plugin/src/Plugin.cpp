#include "pch.h"

#include "FarApi.h"
#include "Message.h"

S3Manager::FarApi *farApi = nullptr;

void WINAPI GetGlobalInfoW(struct GlobalInfo *globalInfo) {
  globalInfo->StructSize = sizeof(*globalInfo);
  globalInfo->MinFarVersion = MAKEFARVERSION(
      FARMANAGERVERSION_MAJOR, FARMANAGERVERSION_MINOR,
      FARMANAGERVERSION_REVISION, FARMANAGERVERSION_BUILD, VS_RELEASE);
  globalInfo->Version = PLUGIN_VERSION;
  globalInfo->Guid = GUID_MAIN;
  globalInfo->Title = PLUGIN_NAME;
  globalInfo->Description = PLUGIN_DESC;
  globalInfo->Author = PLUGIN_AUTHOR;
}

void WINAPI SetStartupInfoW(const struct PluginStartupInfo *pluginStartupInfo) {
  delete farApi;

  farApi = new S3Manager::FarApi(pluginStartupInfo);
}

void WINAPI GetPluginInfoW(struct PluginInfo *pluginInfo) {
  pluginInfo->StructSize = sizeof(*pluginInfo);
  pluginInfo->Flags = PF_EDITOR | PF_VIEWER;

  static const wchar_t *pluginMenuStrings[] = {
      farApi->getMessage(S3Manager::MSG_PLUGIN_NAME)
  };

  pluginInfo->PluginMenu.Guids = &GUID_PLUGINS_MENU;
  pluginInfo->PluginMenu.Strings = pluginMenuStrings;
  pluginInfo->PluginMenu.Count = 1;
}

HANDLE WINAPI OpenW(const struct OpenInfo *openInfo) { return nullptr; }