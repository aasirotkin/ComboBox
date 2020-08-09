#include "combobox.h"

#include <QScrollBar>
#include <QFontMetrics>
#include <QAbstractItemView>

ComboBox::ComboBox(QWidget *parent) :
    QComboBox(parent),
    wrapPolicy_(NoWrap)
{
}

QString ComboBox::FitInWidth_(const QString &text)
{
    const int sep_length = separator_.length();
    const bool wrapByWords = (wrapPolicy() == WrapByWords);
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
            if (wrapByWords)
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

        if (wrapByWords && c == separator_)
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
    QComboBox::addItem((wrapPolicy() == NoWrap) ? text : FitInWidth_(text));
}

ComboBox::WrapPolicy ComboBox::wrapPolicy() const
{
    return wrapPolicy_;
}

void ComboBox::setWrapPolicy(WrapPolicy wrapPolicy)
{
    wrapPolicy_ = wrapPolicy;
}
