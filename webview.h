#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QtCore>
#include <QtGui>

class WebviewMenu : public QObject
{
    Q_OBJECT
public:
    WebviewMenu(QObject *parent=0);
    ~WebviewMenu(){}
    bool eventFilter(QObject *obj, QEvent *event);
     
private Q_SLOTS:
    void savepriview();
    void refresh();
Q_SIGNALS:
    void emitsavepriview();
    void emitrefresh();
};

#endif // WEBVIEW_H
