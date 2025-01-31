#ifndef SETTINGSMODAL_H
#define SETTINGSMODAL_H

#include <QFileDialog>
#include <QDialog>
#include <iostream>
#include <byteops.h>
#include <fileops.h>

namespace Ui {
class SettingsModal;
}

class SettingsModal : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsModal(QWidget *parent = nullptr, ByteOps* bops = nullptr, FileOps* fops = nullptr);
    ~SettingsModal();

private slots:
    void on_dirChoiceButton_clicked();
    void on_buttonBox_accepted();
    void on_timeBased_checkStateChanged(const Qt::CheckState &arg1);

private:
    Ui::SettingsModal *ui;
    SaveOption so;
    ByteOps* bops; // Указатель на объект ByteOps
    FileOps* fops; // Указатель на объект FileOps
};

#endif // SETTINGSMODAL_
