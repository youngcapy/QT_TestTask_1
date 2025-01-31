#include "settingsmodal.h"
#include "ui_settingsmodal.h"

SettingsModal::SettingsModal(QWidget *parent, ByteOps* bops, FileOps* fops)
    : QDialog(parent)
    , ui(new Ui::SettingsModal)
{
    this->bops = bops;
    this->fops = fops;

    ui->setupUi(this);
    this->setWindowTitle("Настройка работы приложения");
    ui->checkTimer->setReadOnly(true);
    auto modeChoice = ui->repeatMode;
    modeChoice->insertItem(modeChoice->count(), "Перезапись", modeChoice->count());
    modeChoice->insertItem(modeChoice->count(), "Модификация", modeChoice->count());
}

SettingsModal::~SettingsModal()
{
    delete ui;
}

void SettingsModal::on_dirChoiceButton_clicked()
{

    auto saveDir = QFileDialog::getExistingDirectory(this, tr("Выберите директорию"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    std::cout << saveDir.toStdString() << std::endl;
    ui->pathToRead->setText(saveDir);
}


void SettingsModal::on_buttonBox_accepted()
{
    std::string saveDir = ui->pathToRead->toPlainText().toStdString();
    int repMode = ui->repeatMode->itemData(ui->repeatMode->currentIndex()).toInt();
    unsigned time_interval{};

    if(ui->timeBased->isChecked())
        time_interval = ui->checkTimer->time().second();

    std::string fileMask = ui->fileMaskBox->toPlainText().toStdString();
    std::string xorMask = ui->xorTextBox->toPlainText().toStdString();

    bool removeFiles{false};
    if(ui->sourceDelete->isChecked())
        removeFiles = true;

    SaveOption newOption = repMode == 1? SaveOption::Modification : SaveOption::Rewrite;

    fops->set_new_values(removeFiles, fileMask, newOption, saveDir);
    unsigned char* xorBytes{new unsigned char[xorMask.size() + 1]};
    if(ui->byteEntryCb->isChecked()){
        xorMask.resize(16);
        try{

            bops->hexStringToBytes(reinterpret_cast<const unsigned char*>(xorMask.c_str()), xorBytes);

        }
        catch(std::exception& e){

            std::cout << e.what() << std::endl;

        }

    }
    else{
        xorMask.resize(8);
        strcpy((char*)xorBytes, xorMask.c_str());
    }


    bops->set_new_values(ui->timeBased->isChecked(), time_interval, xorBytes, ui->byteEntryCb->isChecked());
}

void SettingsModal::on_timeBased_checkStateChanged(const Qt::CheckState &arg1)
{

    if(arg1 == Qt::Unchecked)
        ui->checkTimer->setReadOnly(true);
    else
        ui->checkTimer->setReadOnly(false);

}

