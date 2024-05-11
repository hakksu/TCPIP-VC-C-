//https://docs.microsoft.com/zh-tw/windows/win32/winsock/getting-started-with-winsock?redirectedfrom=MSDN
//https://www.cnblogs.com/HappyXie/archive/2011/03/06/1972394.html
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512   //緩存(buffer)大小
#define DEFAULT_PORT "18888" //server的Port 需跟客戶端一致 Port範圍介於1024~65535，其中0~1023為系統保留不可使用

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Initialize Winsock 初始化 Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    //MAKEWORD (2，2) 參數會對系統上的 Winsock 2.2 版提出要求，
    //並將傳遞的版本設定為呼叫者可以使用的最高 Windows 通訊端支援版本。
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;  //表示該 Socket 的通訊協定家族系列，
    //可選擇：AF_UNIX（Unix 作業系統）、 AF_INET（Internet 網路）、AF_NS 或 AF_IMPLINK 等。
    hints.ai_socktype = SOCK_STREAM; //指定資料流程通訊端
    hints.ai_protocol = IPPROTO_TCP; //指定 TCP 通訊協定 。
    hints.ai_flags = AI_PASSIVE;//表示呼叫端想要在系 結 函式的呼叫中使用傳回的通訊端位址結構。 
    //當設定AI_PASSIVE旗標，而nodename參數設為getaddrinfo函式為Null指標時，通訊端位址結構的 IP 位址部分會設定為IPv4 位址的 INADDR_ANY，或 IPv6 位址的IN6ADDR_ANY_INIT

    // Resolve the server address and port  解析服務器地址和端口
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    //取得socket, bind到某個通訊埠, 然後listen (Listen)

    // Create a SOCKET for the server to listen for client connections.  呼叫 通訊端 函式，並將其值傳回至 ListenSocket 變數。
   
    //如果要建立的是遵從TCP/IP協議的socket，第二個參數type應為SOCK_STREAM，如為UDP（數據報）的socket，應為SOCK_DGRAM
    //Socket 的通訊協定家族系列 , Socket 的類型 (SOCK_STREAM、SOCK_DGRAM) , 通訊協定(如果使用者不指定則設為0)
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket  系結通訊端
    // 如果使用者不在意地址或端口的值，那麼可以設定地址為INADDR_ANY，及Port為0，Windows Sockets 會自動將其設定適當之地址及Port (1024 到 5000之間的值)。此後可以調用getsockname()函數來獲知其被設定的值。
    //Socket對象名 , Socket的地址值，這個地址必須是執行這個程式所在機器的IP地址 , 地址的長度
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    //呼叫 系結 函式之後， 不再需要 getaddrinfo 函式傳回的位址資訊。 會呼叫 freeaddrinfo函式，以釋放getaddrinfo函式為這個位址資訊配置的記憶體。
    freeaddrinfo(result);

    //接聽通訊端
    //SOMAXCONN。 這個值是特殊的常數，會指示此通訊端的 Winsock 提供者允許佇列中暫止連線的最大合理數目。
    //需要建立監聽的Socket , 最大連接個數
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        printf("Port : %s Waiting for connection...\n", DEFAULT_PORT);

    //服務器端的Socket調用完listen（）後，如果此時客戶端調用connect（）函數提出連接申請的話，Server 端必須再調用accept() 函數，這樣服務器端和客戶端才算正式完成通信程序的連接動作。

    // Accept a client socket
    //Socket的識別碼 , 存放來連接的客戶端的地址 , 地址的長度
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        printf("Connect to client!\n");
    

    // No longer need server socket
    closesocket(ListenSocket);

    // Receive until the peer shuts down the connection
    do {
        //socket descriptor ， 緩衝區（buffer） ， 緩衝區的最大長度 ， flags 
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            std::string s;
            printf("Bytes received: %d\n", iResult);   
            printf("收到的資料 : ");
            cout.write(recvbuf, iResult)<< endl;
       
           
            /*/ Echo the buffer back to the sender 將緩衝區回傳給發送者
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult); //*/
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    // shutdown the connection since we're done
    //當伺服器完成將資料傳送至用戶端時，可以呼叫 shutdown 函式，指定SD_SEND關閉通訊端的傳送端。 這可讓用戶端釋放此通訊端的一些資源。 伺服器應用程式仍然可以在通訊端上接收資料。

    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    //當用戶端應用程式完成接收資料時，會呼叫 closesocket 函式以關閉通訊端。 當用戶端應用程式使用 Windows Sockets DLL 完成時，會呼叫WSACleanup函式來釋放資源。
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}
