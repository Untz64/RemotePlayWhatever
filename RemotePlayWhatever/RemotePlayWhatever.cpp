// RemotePlayWhatever.cpp : Defines the entry point for the application.
//

#include <wx/wx.h>
#include <wx/taskbar.h>

#include <Steamworks.h>
#include "RemotePlayWhatever.h"
#include "IClientRemoteClientManager.h"
#include "RemoteApp.h"

wxIMPLEMENT_APP(RemoteApp);


/*
INT WINAPI wWinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPWSTR, INT) 
{
	if (!OpenAPI_LoadLibrary())
	{
		std::cout << "Could not load steamclient library" << std::endl;
		return 0;
	}

    IClientEngine* pClientEngine = (IClientEngine*)SteamInternal_CreateInterface(CLIENTENGINE_INTERFACE_VERSION);
    if (pClientEngine == NULL)
    {
        std::cout << "Could not create client engine interface" << std::endl;
        return 0;
    }

    HSteamPipe hPipe = pClientEngine->CreateSteamPipe();
    if (!hPipe)
    {
        std::cout << "Could not create steam pipe" << std::endl;
        return 0;
    }

    HSteamUser hUser = pClientEngine->ConnectToGlobalUser(hPipe);
    if (!hUser)
    {
        std::cout << "Could not connect to global user" << std::endl;
        return 0;
    }

    IClientRemoteClientManager* pRemoteClient = (IClientRemoteClientManager*)pClientEngine->GetIClientRemoteClientManager(hPipe);
    IClientUser* pClientUser = (IClientUser*)pClientEngine->GetIClientUser(hUser, hPipe);
    IClientFriends* pClientFriends = (IClientFriends*)pClientEngine->GetIClientFriends(hUser, hPipe);

    pRemoteClient->SetStreamingDesktopToRemotePlayTogetherEnabled(true);

    CGameID gameid = pClientUser->GetRunningGameID(0);

    CSteamID steamIDFriend((uint64)76561198050552750);

    pRemoteClient->CreateRemotePlayInviteAndSession(steamIDFriend, 480);
    pRemoteClient->SetStreamingDriversInstalled(1);

    CallbackMsg_t msg;
    while (true)
    {
        while (Steam_BGetCallback(hPipe, &msg))
        {
            std::cout << "Got callback " << msg.m_iCallback << " Callback size " << msg.m_cubParam << std::endl;
            if (msg.m_iCallback == 3311)
            {
                RemoteClientStartStreamSession_t* remoteStartCb = (RemoteClientStartStreamSession_t*)msg.m_pubParam;

                char buf[512] = { '\0' };
                std::string authKey;
                char hexBuf[2];
                for (int i = 0; i < remoteStartCb->m_cubAuthToken; ++i)
                {
                    sprintf(hexBuf, "%02x", remoteStartCb->m_rgubAuthToken[i]);
                    authKey += hexBuf;
                }

                sprintf(buf, "steam://remoteplay/connect/%llu?appid=%d&auth=%s&transport=k_EStreamTransportSDR&relay=%s&restricted_countries=CN,XC", pClientUser->GetSteamID().ConvertToUint64(), 480, authKey.c_str(), remoteStartCb->m_szRelayServer);

                pClientFriends->SendMsgToFriend(steamIDFriend, k_EChatEntryTypeChatMsg, buf);
                std::cout << "Got start streaming session" << std::endl;
            }
            Steam_FreeLastCallback(hPipe);
        }
        Sleep(100);
    }

	return 0;
}
*/