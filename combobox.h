#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QComboBox>

class ComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit ComboBox(QWidget *parent = nullptr);

private:
    const QString next_line_ = QString("\n");
    QString FitInWidth_(const QString& text);

public:
    void addItem(const QString& text);

signals:

};

#endif // CHECKBOX_H
