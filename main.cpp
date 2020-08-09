#include "combobox.h"

#include <QApplication>
#include <QGridLayout>
#include <QLabel>

template<class T>
void testNumbers(T* box)
{
    // Test with numbers, it shows what would be if the word is longer
    // than combobox width and setWordWrap is enabled
    QString text;
    for (int i = 0; i < 200; ++i)
    {
        if (i > 0 && i%30 == 0)
        {
            text += QString(" ");
        }
        text += QString::number(i);
        box->addItem(text);
    }
}

template<class T>
void testColors(T* box, const QStringList& colors)
{
    // Test with color names, it show what would be with common usage
    for (int i = 1; i < colors.count(); ++i)
    {
        QString text;
        for (int j = i - 1; j > -1; --j)
        {
            text += QString("%1 ").arg(colors.at(j));
        }
        text.remove(text.length()-1, 1);

        box->addItem(text);
    }
}

template<class T>
T* createCombo(int font_size, int max_width,
               const QString& place_holder = "click to see")
{
    T* box = new T();
    box->setFont(QFont("Arial", font_size));
    box->setFixedSize(max_width, 50);
    box->setMaxVisibleItems(20);
    box->setPlaceholderText(place_holder);
    return box;
}

void fillCustomLayout(QGridLayout* lay, const QStringList& colors)
{
    int row = lay->rowCount();

    ComboBox* box1 = createCombo<ComboBox>(10, 500,
                                           "Colors: by symbol");
    ComboBox* box2 = createCombo<ComboBox>(12, 250,
                                           "Colors: by words");
    ComboBox* box3 = createCombo<ComboBox>(14, 250,
                                           "Numbers: by symbol");
    ComboBox* box4 = createCombo<ComboBox>(16, 500,
                                           "Numbers: by words");
    ComboBox* box5 = createCombo<ComboBox>(12, 500,
                                           "Colors: no wrap");
    ComboBox* box6 = createCombo<ComboBox>(12, 500,
                                           "Numbers: no wrap");

    box1->setWrapPolicy(ComboBox::WrapBySymbols);
    box2->setWrapPolicy(ComboBox::WrapByWords);
    box3->setWrapPolicy(ComboBox::WrapBySymbols);
    box4->setWrapPolicy(ComboBox::WrapByWords);

    testColors(box1, colors);
    testColors(box2, colors);
    testNumbers(box3);
    testNumbers(box4);
    testColors(box5, colors);
    testNumbers(box6);

    lay->addWidget(box1, row, 0);
    lay->addWidget(box2, row, 1);
    lay->addWidget(box3, ++row, 0);
    lay->addWidget(box4, row, 1);
    lay->addWidget(box5, ++row, 0);
    lay->addWidget(box6, row, 1);
}

void fillDefaultLayout(QGridLayout* lay, const QStringList& colors)
{
    int row = lay->rowCount();

    QComboBox* box1 = createCombo<QComboBox>(10, 500,
                                             "Colors: by symbol");
    QComboBox* box2 = createCombo<QComboBox>(12, 250,
                                             "Colors: by words");
    QComboBox* box3 = createCombo<QComboBox>(14, 250,
                                             "Numbers: by symbol");
    QComboBox* box4 = createCombo<QComboBox>(16, 500,
                                             "Numbers: by words");

    testColors(box1, colors);
    testColors(box2, colors);
    testNumbers(box3);
    testNumbers(box4);

    lay->addWidget(box1, row, 0);
    lay->addWidget(box2, row, 1);
    lay->addWidget(box3, ++row, 0);
    lay->addWidget(box4, row, 1);
}

int main(int argv, char** argc)
{
    QApplication app(argv, argc);

    const QStringList& colors = QColor::colorNames();

    QGridLayout* lay = new QGridLayout();

    lay->addWidget(new QLabel("Custom:"));
    fillCustomLayout(lay, colors);

    lay->addWidget(new QLabel("Default:"));
    fillDefaultLayout(lay, colors);

    QWidget* wgt = new QWidget();
    wgt->setLayout(lay);
    wgt->show();

    return app.exec();
}
