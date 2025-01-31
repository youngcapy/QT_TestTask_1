#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileOps fops = FileOps{false, "default1", SaveOption::Modification, ""};
    unsigned char defaultXor[8]{};
    ByteOps bops = ByteOps{false, 0, defaultXor, false};
    MainWindow w{nullptr, &bops, &fops};
    w.setWindowTitle("НПО_Колибри_Тестовое_Задание");
    w.show();
    return a.exec();
}
