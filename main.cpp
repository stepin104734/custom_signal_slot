#include "mainwindow.h"

#include "QWidget"
#include "mylabel.h"
#include "QLineEdit"

#include "QVBoxLayout"
#include "QGridLayout"

#include "QObject"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QWidget *window = new QWidget;

    MyLabel *m_label_1 = new MyLabel;

    QLineEdit *m_le_text_1 = new QLineEdit;
    QLineEdit *m_le_text_2 = new QLineEdit;
    QVBoxLayout *m_vLayout = new QVBoxLayout;
    QGridLayout *m_gLayout = new QGridLayout;

    m_le_text_1->setClearButtonEnabled(1);
    m_le_text_2->setClearButtonEnabled(1);
    m_label_1->m_label->setStyleSheet("color:white;background-color:black");
    m_label_1->m_label->setAlignment(Qt::AlignCenter);
    m_le_text_1->setPlaceholderText("enter text here");
    m_le_text_2->setPlaceholderText("Enter text here");

    m_vLayout->addWidget(m_le_text_1);
    m_vLayout->addWidget(m_label_1->m_label);
    m_vLayout->addWidget(m_le_text_2);
    m_gLayout->addLayout(m_vLayout,1,1);
    window->setLayout(m_gLayout);

    QObject::connect(m_le_text_1, SIGNAL(textChanged(QString)), m_label_1, SLOT(setString(QString)));
    QObject::connect(m_label_1, SIGNAL(send(QString)), m_le_text_2, SLOT(setText(QString)));
    QObject::connect(m_le_text_2, SIGNAL(textChanged(QString)), m_label_1, SLOT(setString(QString)));
    QObject::connect(m_label_1, SIGNAL(send(QString)), m_le_text_1, SLOT(setText(QString)));

    window->show();

    return a.exec();
}
