#include "mylabel.h"

void MyLabel::setString(QString string_signal)
{
    m_label->setText(string_signal);
    emit send(string_signal);
};


