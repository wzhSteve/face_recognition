/********************************************************************************
** Form generated from reading UI file 'facerecognizer_gui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNIZER_GUI_H
#define UI_FACERECOGNIZER_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_facerecognizer_guiClass
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *ShowButton;
    QPushButton *CloseCamera;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QTextEdit *name;
    QHBoxLayout *horizontalLayout_5;
    QLabel *photo;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *TakePhoto;
    QLabel *label_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Train;
    QLabel *label_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QLabel *label_10;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *facerecognizer_guiClass)
    {
        if (facerecognizer_guiClass->objectName().isEmpty())
            facerecognizer_guiClass->setObjectName(QStringLiteral("facerecognizer_guiClass"));
        facerecognizer_guiClass->resize(863, 537);
        facerecognizer_guiClass->setMinimumSize(QSize(863, 537));
        facerecognizer_guiClass->setMaximumSize(QSize(863, 537));
        facerecognizer_guiClass->setStyleSheet(QStringLiteral("background-image: url(:/facerecognizer_gui/Resources/back.jpg);"));
        centralWidget = new QWidget(facerecognizer_guiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        ShowButton = new QPushButton(centralWidget);
        ShowButton->setObjectName(QStringLiteral("ShowButton"));
        ShowButton->setMinimumSize(QSize(100, 30));
        ShowButton->setMaximumSize(QSize(100, 30));

        verticalLayout->addWidget(ShowButton);

        CloseCamera = new QPushButton(centralWidget);
        CloseCamera->setObjectName(QStringLiteral("CloseCamera"));
        CloseCamera->setMinimumSize(QSize(100, 30));
        CloseCamera->setMaximumSize(QSize(100, 30));

        verticalLayout->addWidget(CloseCamera);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(verticalLayout_3);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(400, 465));
        label->setMaximumSize(QSize(400, 465));

        horizontalLayout_4->addWidget(label);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(200, 30));
        label_8->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(label_8);

        name = new QTextEdit(centralWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setMinimumSize(QSize(110, 30));
        name->setMaximumSize(QSize(110, 30));

        horizontalLayout->addWidget(name);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        photo = new QLabel(centralWidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setMinimumSize(QSize(92, 112));
        photo->setMaximumSize(QSize(92, 112));

        horizontalLayout_5->addWidget(photo);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        TakePhoto = new QPushButton(centralWidget);
        TakePhoto->setObjectName(QStringLiteral("TakePhoto"));
        TakePhoto->setMinimumSize(QSize(100, 30));
        TakePhoto->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(TakePhoto);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(60, 30));
        label_4->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(label_4);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Train = new QPushButton(centralWidget);
        Train->setObjectName(QStringLiteral("Train"));
        Train->setMinimumSize(QSize(100, 30));
        Train->setMaximumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(Train);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(60, 30));
        label_5->setMaximumSize(QSize(60, 30));

        horizontalLayout_3->addWidget(label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(200, 225));
        label_10->setMaximumSize(QSize(200, 225));

        horizontalLayout_6->addWidget(label_10);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(verticalLayout_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        facerecognizer_guiClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(facerecognizer_guiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        facerecognizer_guiClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(facerecognizer_guiClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        facerecognizer_guiClass->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(facerecognizer_guiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 863, 26));
        facerecognizer_guiClass->setMenuBar(menuBar);
        toolBar_2 = new QToolBar(facerecognizer_guiClass);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        facerecognizer_guiClass->addToolBar(Qt::TopToolBarArea, toolBar_2);

        retranslateUi(facerecognizer_guiClass);
        QObject::connect(TakePhoto, SIGNAL(clicked()), facerecognizer_guiClass, SLOT(on_TakePhoto_clicked()));
        QObject::connect(TakePhoto, SIGNAL(released()), facerecognizer_guiClass, SLOT(TakePhoto_clicked()));
        QObject::connect(Train, SIGNAL(clicked()), facerecognizer_guiClass, SLOT(Train_clicked()));
        QObject::connect(CloseCamera, SIGNAL(clicked()), facerecognizer_guiClass, SLOT(CloseCarmera_clicked()));
        QObject::connect(ShowButton, SIGNAL(clicked()), facerecognizer_guiClass, SLOT(ShowButton_clicked()));

        QMetaObject::connectSlotsByName(facerecognizer_guiClass);
    } // setupUi

    void retranslateUi(QMainWindow *facerecognizer_guiClass)
    {
        facerecognizer_guiClass->setWindowTitle(QApplication::translate("facerecognizer_guiClass", "facerecognizer_gui", Q_NULLPTR));
        label_2->setText(QString());
        ShowButton->setText(QString());
        CloseCamera->setText(QString());
        label->setText(QApplication::translate("facerecognizer_guiClass", "<html><head/><body><p><img src=\":/facerecognizer_gui/Resources/cameraback.jpg\"/></p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("facerecognizer_guiClass", "<html><head/><body><p><span style=\" font-weight:600;\">please enter your name</span></p></body></html>", Q_NULLPTR));
        photo->setText(QApplication::translate("facerecognizer_guiClass", "<html><head/><body><p><img src=\":/facerecognizer_gui/Resources/photoback.jpg\"/></p></body></html>", Q_NULLPTR));
        label_9->setText(QString());
        TakePhoto->setText(QString());
        label_4->setText(QApplication::translate("facerecognizer_guiClass", "<html><head/><body><p><span style=\" font-weight:600;\">state:</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QString());
        Train->setText(QString());
        label_5->setText(QApplication::translate("facerecognizer_guiClass", "<html><head/><body><p><span style=\" font-weight:600;\">state:</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QString());
        label_10->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("facerecognizer_guiClass", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("facerecognizer_guiClass", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class facerecognizer_guiClass: public Ui_facerecognizer_guiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNIZER_GUI_H
