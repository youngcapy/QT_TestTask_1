#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <fstream>
#include <bits/stdc++.h>

MainWindow::MainWindow(QWidget *parent, ByteOps* bops, FileOps* fops)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->fops = fops;
    this->bops = bops;
    ui->setupUi(this);
    ui->chooseFileButton->setEnabled(false);

    int ret = QMessageBox::information(this, tr("Тестовое задание Колибри"),
                                   tr("Данное приложение реализует выполнение логической операции XOR над последовательностью символов в текстовом файле.\n"
                                    "Выбор файла для операций будет возможен только после выбора настроек в меню параметров."),
                                   QMessageBox::Ok);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chooseFileButton_clicked()
{
    std::string fileFormat = fops->get_mask();
    const std::string formatingSequence = "*.";
    if(fileFormat.length() > 0)
        fileFormat.insert(0, formatingSequence);

    auto filename = QFileDialog::getOpenFileName(this,
                                                 tr("Get file"), "File", tr(fileFormat.c_str())); // Получаем имя файла

    if (filename.isEmpty()) {
        return;
    }

    auto bytes = fops->read_bytes(filename.toStdString());
    bops->xor_bytes(bytes, fops->get_bytes_quantity());
    fops->save_bytes(bytes);
    if(bops->getTimerBased()){
        unsigned time = bops->getTimerValue();
        ui->chooseFileButton->setEnabled(false); // Отключаем возможность выбора файла на обозначенное таймером время

        // Создаем таймер
        QTimer::singleShot(time * 1000, this, [this]() {
            ui->chooseFileButton->setEnabled(true); // Включаем кнопку обратно
        });
    }

}

void MainWindow::on_paramatersMenu_triggered()
{
    ui->chooseFileButton->setEnabled(true);
    SettingsModal smodal(this, bops, fops);
    smodal.exec();
    std::cout << "ServiceInfo" << std::endl;
}
