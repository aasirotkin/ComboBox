#include "combobox.h"

#include <QScrollBar>
#include <QFontMetrics>
#include <QAbstractItemView>

ComboBox::ComboBox(QWidget *parent) :
    QComboBox(parent),
    wordWrap_(false)
{
}

QString ComboBox::FitInWidth_(const QString &text)
{
    const int sep_length = separator_.length();
    const QFontMetrics fm(font());
    const int max_width = rect().width() -
            view()->verticalScrollBar()->rect().height();

    QString final_text("");
    QString intermediate_text("");
    const int text_length = text.length();
    int last_separator = text_length;

    for (auto& c : text)
    {
        if (fm.horizontalAdvance(intermediate_text + c) >= max_width)
        {
            if (isWordWrap())
            {
                final_text += intermediate_text.leftRef(last_separator);
                intermediate_text.remove(0, last_separator + sep_length);
                last_separator = text_length;
            }
            else
            {
                final_text += intermediate_text;
                intermediate_text.clear();
            }
            final_text += next_line_;
        }

        if (isWordWrap() && c == separator_)
        {
            last_separator = intermediate_text.length();
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

bool ComboBox::isWordWrap() const
{
    return wordWrap_;
}

void ComboBox::setWordWrap(bool wordWrap)
{
    wordWrap_ = wordWrap;
}
