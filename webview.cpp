#include "webview.h"
#include <QMenu>
#include <QtWebKitWidgets>

WebviewMenu::WebviewMenu(QObject *parent):QObject(parent)
{ 
}

bool WebviewMenu::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type()==QEvent::ContextMenu){
        QWebView *web=qobject_cast<QWebView*>(obj); 
        QMenu menu(web); 
        menu.addAction(tr("refresh"),this,SLOT(refresh()));
        menu.addAction(tr("save priview"),this,SLOT(savepriview()));
        QContextMenuEvent *evt=static_cast<QContextMenuEvent*>(event);
        menu.exec(evt->globalPos());
        return true;
    }
    else {
            // standard event processing
            return QObject::eventFilter(obj, event);
    }
}

void WebviewMenu::savepriview()
{
    emit emitsavepriview();
}

void WebviewMenu::refresh()
{
    emit emitrefresh();
}
 

