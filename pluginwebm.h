#ifndef PLUGINWEBM_H
#define PLUGINWEBM_H

#include <QWebPluginFactory>
class PlayerWindow;
class PluginWebm : public QWebPluginFactory
{
public:
    PluginWebm(QObject * parent = 0);
    virtual QObject *create(const QString & mimeType, const QUrl & url, const QStringList & argumentNames, const QStringList & argumentValues)const;
    QList<Plugin> plugins() const;
    ~PluginWebm();
    virtual void	refreshPlugins();
signals:
    
public slots:
    
private:
  mutable  PlayerWindow *pl;
};

#endif // PLUGINWEBM_H
