#include "pch.h"

#include "FarApi.h"

const wchar_t* S3Manager::FarApi::getMessage(S3Manager::Message message) {
  return startupInfo->GetMsg(&GUID_MAIN, message);
}
