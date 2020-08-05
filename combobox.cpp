#include "combobox.h"

#include <QScrollBar>
#include <QFontMetrics>
#include <QAbstractItemView>

ComboBox::ComboBox(QWidget *parent) :
    QComboBox(parent)
{
}

QString ComboBox::FitInWidth_(const QString &text)
{
    static const QFontMetrics fm(font());
    static const int max_width = rect().width() -
            view()->verticalScrollBar()->rect().height();

    QString final_text;
    QString intermediate_text;

    for (auto c : text)
    {
        if (fm.horizontalAdvance(intermediate_text + c) >= max_width)
        {
            final_text += intermediate_text;
            final_text += next_line_;
            intermediate_text = QString("");
        }
        intermediate_text += c;
    }

    if (!intermediate_text.isEmpty())
    {
        final_text += intermediate_text;
    }

    return final_text;
}

void ComboBox::addItem(const QString &text)
{
    QComboBox::addItem(FitInWidth_(text));
}
