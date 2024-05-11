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

#define DEFAULT_BUFLEN 512   //�w�s(buffer)�j�p
#define DEFAULT_PORT "18888" //server��Port �ݸ�Ȥ�ݤ@�P Port�d�򤶩�1024~65535�A�䤤0~1023���t�ΫO�d���i�ϥ�

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

    // Initialize Winsock ��l�� Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    //MAKEWORD (2�A2) �ѼƷ|��t�ΤW�� Winsock 2.2 �����X�n�D�A
    //�ñN�ǻ��������]�w���I�s�̥i�H�ϥΪ��̰� Windows �q�T�ݤ䴩�����C
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;  //��ܸ� Socket ���q�T��w�a�ڨt�C�A
    //�i��ܡGAF_UNIX�]Unix �@�~�t�Ρ^�B AF_INET�]Internet �����^�BAF_NS �� AF_IMPLINK ���C
    hints.ai_socktype = SOCK_STREAM; //���w��Ƭy�{�q�T��
    hints.ai_protocol = IPPROTO_TCP; //���w TCP �q�T��w �C
    hints.ai_flags = AI_PASSIVE;//��ܩI�s�ݷQ�n�b�t �� �禡���I�s���ϥζǦ^���q�T�ݦ�}���c�C 
    //��]�wAI_PASSIVE�X�СA��nodename�ѼƳ]��getaddrinfo�禡��Null���ЮɡA�q�T�ݦ�}���c�� IP ��}�����|�]�w��IPv4 ��}�� INADDR_ANY�A�� IPv6 ��}��IN6ADDR_ANY_INIT

    // Resolve the server address and port  �ѪR�A�Ⱦ��a�}�M�ݤf
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    //���osocket, bind��Y�ӳq�T��, �M��listen (Listen)

    // Create a SOCKET for the server to listen for client connections.  �I�s �q�T�� �禡�A�ñN��ȶǦ^�� ListenSocket �ܼơC
   
    //�p�G�n�إߪ��O��qTCP/IP��ĳ��socket�A�ĤG�ӰѼ�type����SOCK_STREAM�A�p��UDP�]�ƾڳ��^��socket�A����SOCK_DGRAM
    //Socket ���q�T��w�a�ڨt�C , Socket ������ (SOCK_STREAM�BSOCK_DGRAM) , �q�T��w(�p�G�ϥΪ̤����w�h�]��0)
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket  �t���q�T��
    // �p�G�ϥΪ̤��b�N�a�}�κݤf���ȡA����i�H�]�w�a�}��INADDR_ANY�A��Port��0�AWindows Sockets �|�۰ʱN��]�w�A���a�}��Port (1024 �� 5000��������)�C����i�H�ե�getsockname()��ƨ��򪾨�Q�]�w���ȡC
    //Socket��H�W , Socket���a�}�ȡA�o�Ӧa�}�����O����o�ӵ{���Ҧb������IP�a�} , �a�}������
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    //�I�s �t�� �禡����A ���A�ݭn getaddrinfo �禡�Ǧ^����}��T�C �|�I�s freeaddrinfo�禡�A�H����getaddrinfo�禡���o�Ӧ�}��T�t�m���O����C
    freeaddrinfo(result);

    //��ť�q�T��
    //SOMAXCONN�C �o�ӭȬO�S���`�ơA�|���ܦ��q�T�ݪ� Winsock ���Ѫ̤��\��C���Ȥ�s�u���̤j�X�z�ƥءC
    //�ݭn�إߺ�ť��Socket , �̤j�s���Ӽ�
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else
        printf("Port : %s Waiting for connection...\n", DEFAULT_PORT);

    //�A�Ⱦ��ݪ�Socket�եΧ�listen�]�^��A�p�G���ɫȤ�ݽե�connect�]�^��ƴ��X�s���ӽЪ��ܡAServer �ݥ����A�ե�accept() ��ơA�o�˪A�Ⱦ��ݩM�Ȥ�ݤ~�⥿�������q�H�{�Ǫ��s���ʧ@�C

    // Accept a client socket
    //Socket���ѧO�X , �s��ӳs�����Ȥ�ݪ��a�} , �a�}������
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
        //socket descriptor �A �w�İϡ]buffer�^ �A �w�İϪ��̤j���� �A flags 
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            std::string s;
            printf("Bytes received: %d\n", iResult);   
            printf("���쪺��� : ");
            cout.write(recvbuf, iResult)<< endl;
       
           
            /*/ Echo the buffer back to the sender �N�w�İϦ^�ǵ��o�e��
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
    //����A�������N��ƶǰe�ܥΤ�ݮɡA�i�H�I�s shutdown �禡�A���wSD_SEND�����q�T�ݪ��ǰe�ݡC �o�i���Τ�����񦹳q�T�ݪ��@�Ǹ귽�C ���A�����ε{�����M�i�H�b�q�T�ݤW������ơC

    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    //��Τ�����ε{������������ƮɡA�|�I�s closesocket �禡�H�����q�T�ݡC ��Τ�����ε{���ϥ� Windows Sockets DLL �����ɡA�|�I�sWSACleanup�禡������귽�C
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}
