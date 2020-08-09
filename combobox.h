#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QComboBox>

class QComboBox;

class ComboBox : public QComboBox
{
    Q_OBJECT

    Q_PROPERTY(WrapPolicy wrapPolicy READ wrapPolicy WRITE setWrapPolicy)
public:
    explicit ComboBox(QWidget *parent = nullptr);

public:
    void addItem(const QString& text);

    enum WrapPolicy {
        NoWrap,
        WrapBySymbols,
        WrapByWords
    };
    Q_ENUM(WrapPolicy)

    WrapPolicy wrapPolicy() const;
    void setWrapPolicy(WrapPolicy wrapPolicy);

private:
    const QString next_line_ = QString("\n");
    const QString separator_ = QString(" ");
    QString FitInWidth_(const QString& text);
    WrapPolicy wrapPolicy_;

};

#endif // CHECKBOX_H
