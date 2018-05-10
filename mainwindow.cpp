#include "mainwindow.h"
#include "ui_mainwindow.h" 
#include <QtCore>
#include <QtGui>
#include <QtWebKitWidgets>
#include "webview.h"
#include "mysum.h"
#include "pluginwebm.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wbm=new WebviewMenu(this);
    connect(wbm,SIGNAL(emitrefresh()),this,SLOT(refreshing()));
    connect(wbm,SIGNAL(emitsavepriview()),this,SLOT(savepriview()));
    ui->webView->installEventFilter(wbm);
    sum=new Mysum;
    connect(ui->webView->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(addJsObj()));
    QWebSettings * set=QWebSettings::globalSettings();
    set->setAttribute(QWebSettings::PluginsEnabled,true);
    PluginWebm *webm=new PluginWebm;
    ui->webView->page()->setPluginFactory(webm);
   refreshing();
}

MainWindow::~MainWindow()
{ 
    
    qCleanupResources_res();
    delete wbm;
    delete sum;
    delete ui;
}

void MainWindow::savepriview()
{
    QString format = "png";
    QPixmap originalPixmap=ui->webView->grab();
        QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
    
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), initialPath,
                                                        tr("%1 Files (*.%2);;All Files (*)")
                                                        .arg(format.toUpper())
                                                        .arg(format));
        if (!fileName.isEmpty())
            originalPixmap.save(fileName, format.toLatin1().constData());
}

void MainWindow::addJsObj()
{
    ui->webView->page()->mainFrame()->addToJavaScriptWindowObject(QString("Mysum"),sum);    
}

void MainWindow::refreshing()
{ 
    QEventLoop evt; 
    ui->webView->setUrl(QUrl("qrc:/webm.html")); 
    connect(ui->webView,SIGNAL(loadFinished(bool)),&evt,SLOT(quit()));
    evt.exec();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
