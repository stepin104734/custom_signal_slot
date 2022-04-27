#ifndef MYLABEL_H
#define MYLABEL_H
#include"QObject"
#include "QLabel"


class MyLabel : public QLabel
{
    Q_OBJECT
public:
    QLabel *m_label = new QLabel;
public slots:
    void setString(QString);
signals:
    void send(QString);
};

#endif // MYLABEL_H
