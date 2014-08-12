#ifndef MEGAUPLOADER_H
#define MEGAUPLOADER_H

#include <QString>
#include <QFileInfo>
#include <QDir>
#include <QQueue>
#include "Preferences.h"
#include "sdk/megaapi.h"
#include "sdk/qt/QTMegaRequestListener.h"

class MegaUploader : public QObject, public mega::MegaRequestListener
{
    Q_OBJECT

public:
    MegaUploader(mega::MegaApi *megaApi);
    virtual ~MegaUploader();
    void upload(QString path, mega::MegaNode *parent);
    virtual void onRequestFinish(mega::MegaApi* api, mega::MegaRequest *request, mega::MegaError* e);

signals:
    void dupplicateUpload(QString localPath, QString name, long long handle);

protected:
    void upload(QFileInfo info, mega::MegaNode *parent);

    mega::MegaApi *megaApi;
    mega::QTMegaRequestListener *delegateListener;
    QQueue<QFileInfo> folders;
};

#endif // MEGAUPLOADER_H
