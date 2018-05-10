#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class Mysum;
class WebviewMenu;
int qCleanupResources_res();
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private Q_SLOTS:
    void savepriview();
    void addJsObj();
    void refreshing();
protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::MainWindow *ui;
    WebviewMenu *wbm;
    Mysum * sum;
};

#endif // MAINWINDOW_H
