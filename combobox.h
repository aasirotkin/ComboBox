#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QComboBox>

class QComboBox;

class ComboBox : public QComboBox
{
    Q_OBJECT

    Q_PROPERTY(bool wordWrap READ isWordWrap WRITE setWordWrap)
public:
    explicit ComboBox(QWidget *parent = nullptr);

private:
    const QString next_line_ = QString("\n");
    const QString separator_ = QString(" ");
    QString FitInWidth_(const QString& text);
    bool wordWrap_;

public:
    void addItem(const QString& text);
    bool isWordWrap() const;

public slots:
    void setWordWrap(bool wordWrap);

signals:

};

#endif // CHECKBOX_H
