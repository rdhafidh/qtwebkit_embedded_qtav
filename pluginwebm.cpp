#include "pluginwebm.h"
#include "playerwindow.h"
#include <QtAVWidgets>
class PluginMime: public QWebPluginFactory::MimeType
{
    QString description(){
        return QString("webm support");
    }
    QString name(){
        return QString("webm player");
    }
    QStringList fileExtensions(){
        QStringList ext;
        ext << ".webm";
        return ext;
    }
};

class PluginInfo: public QWebPluginFactory::Plugin
{
    QString description(){
        return QString("webm plugin bos!");
    }
    QString name(){
        return QString("webm");
    }
    QList<QWebPluginFactory::MimeType> mimeTypes()
    {
        QList<QWebPluginFactory::MimeType> mime;
        PluginMime m1;
        mime <<m1;
        return mime;
    }
};

PluginWebm::PluginWebm(QObject *parent):QWebPluginFactory(parent)
{
}

QObject *PluginWebm::create(const QString &mimeType, const QUrl &url, const QStringList &argumentNames, const QStringList &argumentValues) const
{   
    Q_UNUSED(argumentNames)
    Q_UNUSED(argumentValues)
    qDebug()<<"url:"<<url;
    if (mimeType== "video/webm"){  
         qDebug()<<"playing..";
         
         QtAV::Widgets::registerRenderers();
          PlayerWindow *pl =new PlayerWindow;
        pl->playMedia(url); 
        return pl;
    }
    return 0; 
}

QList<QWebPluginFactory::Plugin> PluginWebm::plugins() const
{
    QList<QWebPluginFactory::Plugin> pls;
    PluginInfo inf1;
    pls <<inf1;
    return pls;
}
 

PluginWebm::~PluginWebm()
{
   // pl->deleteLater();
}

void PluginWebm::refreshPlugins()
{ 
}

