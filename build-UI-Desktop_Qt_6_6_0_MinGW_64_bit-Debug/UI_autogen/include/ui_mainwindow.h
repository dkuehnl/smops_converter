#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *lbl_program_title;
    QLabel *lbl_schritt1;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *btn_File_Browse;
    QLineEdit *le_Dateipfad;
    QLabel *lbl_schritt2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *lbl_Spalten;
    QComboBox *cb_Spaltenwahl;
    QLabel *lbl_schritt3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rb_isoneof;
    QRadioButton *rb_isnotoneof;
    QLabel *lbl_schritt4;
    QTabWidget *tbw_Filter;
    QWidget *NumberElement;
    QComboBox *cb_number;
    QWidget *CallNeworkElement;
    QComboBox *cb_ne;
    QWidget *RegNetworkElement;
    QComboBox *cb_reg_ne;
    QLabel *lbl_schritt4_alternative;
    QLineEdit *le_alternativer_Filter;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_reset;
    QPushButton *btn_convert;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QPushButton *btn_Path_Browse;
    QLineEdit *le_new_Path;
    QLabel *lbl_schritt5;
    QLabel *lbl_schritt5_hinweis;
    QLabel *lbl_statusmeldung;
    QPushButton *btn_exit;
    QLabel *lbl_ergebnis;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(722, 750);
        MainWindow->setMinimumSize(QSize(722, 750));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lbl_program_title = new QLabel(centralwidget);
        lbl_program_title->setObjectName("lbl_program_title");
        lbl_program_title->setGeometry(QRect(9, 9, 214, 29));
        QFont font;
        font.setFamilies({QString::fromUtf8("Calibri")});
        font.setPointSize(18);
        font.setBold(true);
        font.setUnderline(false);
        lbl_program_title->setFont(font);
        lbl_schritt1 = new QLabel(centralwidget);
        lbl_schritt1->setObjectName("lbl_schritt1");
        lbl_schritt1->setGeometry(QRect(20, 90, 261, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Calibri")});
        font1.setPointSize(12);
        lbl_schritt1->setFont(font1);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 110, 571, 31));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        btn_File_Browse = new QPushButton(formLayoutWidget);
        btn_File_Browse->setObjectName("btn_File_Browse");

        formLayout->setWidget(0, QFormLayout::LabelRole, btn_File_Browse);

        le_Dateipfad = new QLineEdit(formLayoutWidget);
        le_Dateipfad->setObjectName("le_Dateipfad");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Calibri")});
        font2.setItalic(true);
        le_Dateipfad->setFont(font2);

        formLayout->setWidget(0, QFormLayout::FieldRole, le_Dateipfad);

        lbl_schritt2 = new QLabel(centralwidget);
        lbl_schritt2->setObjectName("lbl_schritt2");
        lbl_schritt2->setGeometry(QRect(20, 170, 281, 16));
        lbl_schritt2->setFont(font1);
        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(50, 190, 571, 41));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        lbl_Spalten = new QLabel(formLayoutWidget_2);
        lbl_Spalten->setObjectName("lbl_Spalten");
        lbl_Spalten->setMaximumSize(QSize(16777189, 16777215));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Calibri")});
        font3.setPointSize(10);
        lbl_Spalten->setFont(font3);
        lbl_Spalten->setWordWrap(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lbl_Spalten);

        cb_Spaltenwahl = new QComboBox(formLayoutWidget_2);
        cb_Spaltenwahl->setObjectName("cb_Spaltenwahl");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, cb_Spaltenwahl);

        lbl_schritt3 = new QLabel(centralwidget);
        lbl_schritt3->setObjectName("lbl_schritt3");
        lbl_schritt3->setGeometry(QRect(20, 250, 281, 16));
        lbl_schritt3->setFont(font1);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(170, 280, 261, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        rb_isoneof = new QRadioButton(horizontalLayoutWidget);
        rb_isoneof->setObjectName("rb_isoneof");
        rb_isoneof->setFont(font3);
        rb_isoneof->setChecked(true);

        horizontalLayout->addWidget(rb_isoneof);

        rb_isnotoneof = new QRadioButton(horizontalLayoutWidget);
        rb_isnotoneof->setObjectName("rb_isnotoneof");
        rb_isnotoneof->setFont(font3);

        horizontalLayout->addWidget(rb_isnotoneof);

        lbl_schritt4 = new QLabel(centralwidget);
        lbl_schritt4->setObjectName("lbl_schritt4");
        lbl_schritt4->setGeometry(QRect(20, 350, 281, 16));
        lbl_schritt4->setFont(font1);
        tbw_Filter = new QTabWidget(centralwidget);
        tbw_Filter->setObjectName("tbw_Filter");
        tbw_Filter->setGeometry(QRect(50, 370, 411, 61));
        NumberElement = new QWidget();
        NumberElement->setObjectName("NumberElement");
        cb_number = new QComboBox(NumberElement);
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->addItem(QString());
        cb_number->setObjectName("cb_number");
        cb_number->setGeometry(QRect(0, 0, 301, 21));
        tbw_Filter->addTab(NumberElement, QString());
        CallNeworkElement = new QWidget();
        CallNeworkElement->setObjectName("CallNeworkElement");
        cb_ne = new QComboBox(CallNeworkElement);
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->addItem(QString());
        cb_ne->setObjectName("cb_ne");
        cb_ne->setGeometry(QRect(0, 0, 301, 21));
        tbw_Filter->addTab(CallNeworkElement, QString());
        RegNetworkElement = new QWidget();
        RegNetworkElement->setObjectName("RegNetworkElement");
        cb_reg_ne = new QComboBox(RegNetworkElement);
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->addItem(QString());
        cb_reg_ne->setObjectName("cb_reg_ne");
        cb_reg_ne->setGeometry(QRect(0, 0, 301, 21));
        tbw_Filter->addTab(RegNetworkElement, QString());
        lbl_schritt4_alternative = new QLabel(centralwidget);
        lbl_schritt4_alternative->setObjectName("lbl_schritt4_alternative");
        lbl_schritt4_alternative->setGeometry(QRect(50, 440, 461, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Calibri")});
        lbl_schritt4_alternative->setFont(font4);
        le_alternativer_Filter = new QLineEdit(centralwidget);
        le_alternativer_Filter->setObjectName("le_alternativer_Filter");
        le_alternativer_Filter->setGeometry(QRect(50, 460, 281, 22));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(200, 660, 291, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btn_reset = new QPushButton(horizontalLayoutWidget_2);
        btn_reset->setObjectName("btn_reset");

        horizontalLayout_2->addWidget(btn_reset);

        btn_convert = new QPushButton(horizontalLayoutWidget_2);
        btn_convert->setObjectName("btn_convert");

        horizontalLayout_2->addWidget(btn_convert);

        formLayoutWidget_3 = new QWidget(centralwidget);
        formLayoutWidget_3->setObjectName("formLayoutWidget_3");
        formLayoutWidget_3->setGeometry(QRect(50, 560, 571, 31));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_Path_Browse = new QPushButton(formLayoutWidget_3);
        btn_Path_Browse->setObjectName("btn_Path_Browse");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, btn_Path_Browse);

        le_new_Path = new QLineEdit(formLayoutWidget_3);
        le_new_Path->setObjectName("le_new_Path");
        le_new_Path->setFont(font2);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, le_new_Path);

        lbl_schritt5 = new QLabel(centralwidget);
        lbl_schritt5->setObjectName("lbl_schritt5");
        lbl_schritt5->setGeometry(QRect(20, 500, 201, 41));
        lbl_schritt5->setFont(font1);
        lbl_schritt5->setWordWrap(true);
        lbl_schritt5_hinweis = new QLabel(centralwidget);
        lbl_schritt5_hinweis->setObjectName("lbl_schritt5_hinweis");
        lbl_schritt5_hinweis->setGeometry(QRect(50, 530, 481, 16));
        lbl_statusmeldung = new QLabel(centralwidget);
        lbl_statusmeldung->setObjectName("lbl_statusmeldung");
        lbl_statusmeldung->setGeometry(QRect(20, 600, 681, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Calibri")});
        font5.setPointSize(14);
        font5.setBold(true);
        lbl_statusmeldung->setFont(font5);
        lbl_statusmeldung->setAlignment(Qt::AlignCenter);
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(590, 670, 111, 21));
        lbl_ergebnis = new QLabel(centralwidget);
        lbl_ergebnis->setObjectName("label");
        lbl_ergebnis->setGeometry(QRect(10, 630, 701, 20));
        lbl_ergebnis->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 722, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tbw_Filter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl_program_title->setText(QCoreApplication::translate("MainWindow", "SMOPS-Konverter 0.9", nullptr));
        lbl_schritt1->setText(QCoreApplication::translate("MainWindow", "Schritt 1: Quell-Datei ausw\303\244hlen (.csv):", nullptr));
        btn_File_Browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        le_Dateipfad->setText(QCoreApplication::translate("MainWindow", "Bitte Dateipfad einf\303\274gen ", nullptr));
        lbl_schritt2->setText(QCoreApplication::translate("MainWindow", "Schritt 2: Zu filternde Spalte ausw\303\244hlen: ", nullptr));
        lbl_Spalten->setText(QCoreApplication::translate("MainWindow", "Folgende Spalten wurden erkannt, bitte die gew\303\274nschte ausw\303\244hlen:", nullptr));
        lbl_schritt3->setText(QCoreApplication::translate("MainWindow", "Schritt 3: Filterart f\303\274r SMOPS ausw\303\244hlen: ", nullptr));
        rb_isoneof->setText(QCoreApplication::translate("MainWindow", "is one of ", nullptr));
        rb_isnotoneof->setText(QCoreApplication::translate("MainWindow", "is not one of", nullptr));
        lbl_schritt4->setText(QCoreApplication::translate("MainWindow", "Schritt 4: Feldname f\303\274r neuen SMOPS-Filter: ", nullptr));
        cb_number->setItemText(0, QString());
        cb_number->setItemText(1, QCoreApplication::translate("MainWindow", "common_calling_party_number", nullptr));
        cb_number->setItemText(2, QCoreApplication::translate("MainWindow", "common_called_party_number", nullptr));
        cb_number->setItemText(3, QCoreApplication::translate("MainWindow", "reg_common_calling_party_number", nullptr));
        cb_number->setItemText(4, QCoreApplication::translate("MainWindow", "sip_contact", nullptr));
        cb_number->setItemText(5, QCoreApplication::translate("MainWindow", "first_leg_calling_party_number", nullptr));
        cb_number->setItemText(6, QCoreApplication::translate("MainWindow", "first_leg_called_party_number", nullptr));
        cb_number->setItemText(7, QCoreApplication::translate("MainWindow", "last_leg_called_party_number", nullptr));
        cb_number->setItemText(8, QCoreApplication::translate("MainWindow", "last_leg_called_party_number", nullptr));

        tbw_Filter->setTabText(tbw_Filter->indexOf(NumberElement), QCoreApplication::translate("MainWindow", "Number-Elements", nullptr));
        cb_ne->setItemText(0, QString());
        cb_ne->setItemText(1, QCoreApplication::translate("MainWindow", "common_first_leg_destination_network_element", nullptr));
        cb_ne->setItemText(2, QCoreApplication::translate("MainWindow", "common_2nd_leg_destination_network_element", nullptr));
        cb_ne->setItemText(3, QCoreApplication::translate("MainWindow", "common_3rd_leg_destination_network_element", nullptr));
        cb_ne->setItemText(4, QCoreApplication::translate("MainWindow", "common_4th_leg_destination_network_element", nullptr));
        cb_ne->setItemText(5, QCoreApplication::translate("MainWindow", "common_5th_leg_destination_network_element", nullptr));
        cb_ne->setItemText(6, QCoreApplication::translate("MainWindow", "common_last_leg_destination_network_element", nullptr));
        cb_ne->setItemText(7, QCoreApplication::translate("MainWindow", "common_first_leg_source_network_element", nullptr));
        cb_ne->setItemText(8, QCoreApplication::translate("MainWindow", "common_2nd_leg_source_network_element", nullptr));
        cb_ne->setItemText(9, QCoreApplication::translate("MainWindow", "common_3rd_leg_source_network_element", nullptr));
        cb_ne->setItemText(10, QCoreApplication::translate("MainWindow", "common_4th_leg_source_network_element", nullptr));
        cb_ne->setItemText(11, QCoreApplication::translate("MainWindow", "common_5th_leg_source_network_element", nullptr));
        cb_ne->setItemText(12, QCoreApplication::translate("MainWindow", "common_last_leg_source_network_element", nullptr));

        tbw_Filter->setTabText(tbw_Filter->indexOf(CallNeworkElement), QCoreApplication::translate("MainWindow", "Call-Network-Element", nullptr));
        cb_reg_ne->setItemText(0, QString());
        cb_reg_ne->setItemText(1, QCoreApplication::translate("MainWindow", "reg_common_first_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(2, QCoreApplication::translate("MainWindow", "reg_common_2nd_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(3, QCoreApplication::translate("MainWindow", "reg_common_3rd_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(4, QCoreApplication::translate("MainWindow", "reg_common_4th_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(5, QCoreApplication::translate("MainWindow", "reg_common_5th_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(6, QCoreApplication::translate("MainWindow", "reg_common_last_leg_destination_network_element", nullptr));
        cb_reg_ne->setItemText(7, QCoreApplication::translate("MainWindow", "reg_common_first_leg_source_network_element", nullptr));
        cb_reg_ne->setItemText(8, QCoreApplication::translate("MainWindow", "reg_common_2nd_leg_source_network_element", nullptr));
        cb_reg_ne->setItemText(9, QCoreApplication::translate("MainWindow", "reg_common_3rd_leg_source_network_element", nullptr));
        cb_reg_ne->setItemText(10, QCoreApplication::translate("MainWindow", "reg_common_4th_leg_source_network_element", nullptr));
        cb_reg_ne->setItemText(11, QCoreApplication::translate("MainWindow", "reg_common_5th_leg_source_network_element", nullptr));
        cb_reg_ne->setItemText(12, QCoreApplication::translate("MainWindow", "reg_common_last_leg_source_network_element", nullptr));

        tbw_Filter->setTabText(tbw_Filter->indexOf(RegNetworkElement), QCoreApplication::translate("MainWindow", "Reg-Network-Element", nullptr));
        lbl_schritt4_alternative->setText(QCoreApplication::translate("MainWindow", "Falls das gew\303\274nschte Feld nicht vorhanden ist, Feld-Name bitt ehier eintragen: ", nullptr));
        btn_reset->setText(QCoreApplication::translate("MainWindow", "Zur\303\274cksetzen", nullptr));
        btn_convert->setText(QCoreApplication::translate("MainWindow", "Konvertieren", nullptr));
        btn_Path_Browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        le_new_Path->setText(QCoreApplication::translate("MainWindow", "Bitte Dateipfad einf\303\274gen ", nullptr));
        lbl_schritt5->setText(QCoreApplication::translate("MainWindow", "Schritt 5: Zielpfad ausw\303\244hlen:", nullptr));
        lbl_schritt5_hinweis->setText(QCoreApplication::translate("MainWindow", " (erfolgt keine Eingabe, wird die Filter-Datei im Verzeichnis der Quelldatei gespeichert)", nullptr));
        lbl_statusmeldung->setText(QCoreApplication::translate("MainWindow", "Filter erfolgreich gebaut! ", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
        lbl_ergebnis->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

