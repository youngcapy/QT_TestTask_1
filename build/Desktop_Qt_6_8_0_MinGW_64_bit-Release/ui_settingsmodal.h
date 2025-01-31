/********************************************************************************
** Form generated from reading UI file 'settingsmodal.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSMODAL_H
#define UI_SETTINGSMODAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_SettingsModal
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *sourceDelete;
    QComboBox *repeatMode;
    QCheckBox *timeBased;
    QTextEdit *xorTextBox;
    QTimeEdit *checkTimer;
    QTextEdit *fileMaskBox;
    QPushButton *dirChoiceButton;
    QTextEdit *pathToRead;

    void setupUi(QDialog *SettingsModal)
    {
        if (SettingsModal->objectName().isEmpty())
            SettingsModal->setObjectName("SettingsModal");
        SettingsModal->resize(400, 244);
        buttonBox = new QDialogButtonBox(SettingsModal);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 186, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        sourceDelete = new QCheckBox(SettingsModal);
        sourceDelete->setObjectName("sourceDelete");
        sourceDelete->setGeometry(QRect(210, 150, 171, 22));
        repeatMode = new QComboBox(SettingsModal);
        repeatMode->setObjectName("repeatMode");
        repeatMode->setGeometry(QRect(20, 186, 161, 31));
        timeBased = new QCheckBox(SettingsModal);
        timeBased->setObjectName("timeBased");
        timeBased->setGeometry(QRect(210, 120, 151, 22));
        xorTextBox = new QTextEdit(SettingsModal);
        xorTextBox->setObjectName("xorTextBox");
        xorTextBox->setGeometry(QRect(20, 146, 161, 31));
        checkTimer = new QTimeEdit(SettingsModal);
        checkTimer->setObjectName("checkTimer");
        checkTimer->setGeometry(QRect(20, 110, 161, 31));
        checkTimer->setCurrentSection(QDateTimeEdit::Section::SecondSection);
        checkTimer->setTime(QTime(0, 0, 0));
        fileMaskBox = new QTextEdit(SettingsModal);
        fileMaskBox->setObjectName("fileMaskBox");
        fileMaskBox->setGeometry(QRect(20, 20, 161, 31));
        dirChoiceButton = new QPushButton(SettingsModal);
        dirChoiceButton->setObjectName("dirChoiceButton");
        dirChoiceButton->setGeometry(QRect(210, 70, 161, 31));
        pathToRead = new QTextEdit(SettingsModal);
        pathToRead->setObjectName("pathToRead");
        pathToRead->setGeometry(QRect(20, 70, 161, 31));
        pathToRead->setReadOnly(true);

        retranslateUi(SettingsModal);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SettingsModal, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SettingsModal, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SettingsModal);
    } // setupUi

    void retranslateUi(QDialog *SettingsModal)
    {
        SettingsModal->setWindowTitle(QCoreApplication::translate("SettingsModal", "Dialog", nullptr));
        sourceDelete->setText(QCoreApplication::translate("SettingsModal", "\320\243\320\264\320\260\320\273\321\217\321\202\321\214 \320\262\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213?", nullptr));
#if QT_CONFIG(tooltip)
        repeatMode->setToolTip(QCoreApplication::translate("SettingsModal", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\200\320\265\320\266\320\270\320\274 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\260 \320\277\321\200\320\270 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\270 \320\270\320\274\320\265\320\275\320\270 \320\262 \321\206\320\265\320\273\320\265\320\262\320\276\320\271 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        repeatMode->setPlaceholderText(QCoreApplication::translate("SettingsModal", "\320\237\321\200\320\270 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\270 \320\270\320\274\320\265\320\275\320\270", nullptr));
        timeBased->setText(QCoreApplication::translate("SettingsModal", "\320\240\320\260\320\261\320\276\321\202\320\260 \320\277\320\276 \321\202\320\260\320\271\320\274\320\265\321\200\321\203?", nullptr));
#if QT_CONFIG(tooltip)
        xorTextBox->setToolTip(QCoreApplication::translate("SettingsModal", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 8 \320\261\320\260\320\271\321\202 \320\264\320\273\321\217 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270 XOR \320\275\320\260\320\264 \320\277\320\276\320\264\320\260\320\262\320\260\320\265\320\274\321\213\320\274 \321\204\320\260\320\271\320\273\320\276\320\274", nullptr));
#endif // QT_CONFIG(tooltip)
        xorTextBox->setPlaceholderText(QCoreApplication::translate("SettingsModal", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 8 \320\261\320\260\320\271\321\202 \320\264\320\273\321\217 XOR", nullptr));
#if QT_CONFIG(tooltip)
        checkTimer->setToolTip(QCoreApplication::translate("SettingsModal", "\320\242\320\260\320\271\320\274\320\265\321\200 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\320\260\321\205 \320\276\321\202 0 \320\264\320\276 59 \320\262\320\272\320\273\321\216\321\207\320\270\321\202\320\265\320\273\321\214\320\275\320\276", nullptr));
#endif // QT_CONFIG(tooltip)
        checkTimer->setDisplayFormat(QCoreApplication::translate("SettingsModal", "ss", nullptr));
#if QT_CONFIG(tooltip)
        fileMaskBox->setToolTip(QCoreApplication::translate("SettingsModal", "\320\222\320\262\320\276\320\264 \320\274\320\260\321\201\320\272\320\270 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\261\320\265\320\267 \321\202\320\276\321\207\320\272\320\270(\320\277\321\200\320\270\320\274\320\265\321\200 \"txt\")", nullptr));
#endif // QT_CONFIG(tooltip)
        fileMaskBox->setPlaceholderText(QCoreApplication::translate("SettingsModal", "\320\234\320\260\321\201\320\272\320\260 \321\207\320\270\321\202\320\260\320\265\320\274\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
#if QT_CONFIG(tooltip)
        dirChoiceButton->setToolTip(QCoreApplication::translate("SettingsModal", "\320\224\320\260\320\275\320\275\320\260\321\217 \320\272\320\275\320\276\320\277\320\272\320\260 \320\262\321\213\320\267\321\213\320\262\320\260\320\265\321\202 \320\274\320\276\320\264\320\260\320\273\321\214\320\275\320\276\320\265 \320\276\320\272\320\275\320\276 \320\262\321\213\320\261\320\276\321\200\320\260 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
#endif // QT_CONFIG(tooltip)
        dirChoiceButton->setText(QCoreApplication::translate("SettingsModal", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216", nullptr));
        pathToRead->setPlaceholderText(QCoreApplication::translate("SettingsModal", "\320\237\321\203\321\202\321\214 \320\264\320\276 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\270...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsModal: public Ui_SettingsModal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSMODAL_H
