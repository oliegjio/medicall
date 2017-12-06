#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "QtNetwork/QNetworkAccessManager"

class NetworkManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    static NetworkManager* getInstance();

private:
    NetworkManager();

    static NetworkManager* instance;
};

#endif // NETWORKMANAGER_H
