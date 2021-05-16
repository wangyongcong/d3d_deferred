#pragma once

#include <string>
#include "GameFramework.h"
#include "IGameWindow.h"
#include "IRenderDevice.h"

namespace wyc
{
	class CGameInstance;

	class GAME_FRAMEWORK_API CGameApplication
	{
		static HINSTANCE sModuleHandle;
		static HINSTANCE sApplicationHandle;
		static CGameApplication* sApplicationPtr;

	public:
		static bool CreateApplication(HINSTANCE hInstance, const wchar_t* appName, uint32_t windowWidth, uint32_t windowHeight);
		static void DestroyApplication();
		static CGameApplication* Get();

		static void SetModuleHandle(HINSTANCE hModuleInstance);

		CGameApplication(const wchar_t* appName);
		virtual ~CGameApplication();

		virtual void ShowWindow(bool bVisible);
		virtual void Run();
		virtual void Quit(int exitCode);
		virtual HINSTANCE GetApplicationHandle() const;
		virtual HINSTANCE GetApplicationModule() const;

	protected:
		virtual void StartLogger();
		virtual bool CreateGameWindow(uint32_t windowWidth, uint32_t windowHeight);
		virtual bool CreateDevice();

		std::wstring mAppName;
		CGameInstance* mGameInstance;
		IGameWindow* mWindow;
		IRenderDevice* mDevice;
	};

} // namespace wyc