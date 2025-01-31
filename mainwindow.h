#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <byteops.h>
#include <fileops.h>
#include <settingsmodal.h>
#include <QMessageBox>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, ByteOps* bops = nullptr, FileOps* fops = nullptr);
    ~MainWindow();

private slots:
    void on_chooseFileButton_clicked();
    void on_paramatersMenu_triggered();

private:
    Ui::MainWindow *ui;
    QMenu *fileMenu;
    ByteOps* bops;
    FileOps* fops;
    SettingsModal smodal;
};
#endif // MAINWINDOW_H
