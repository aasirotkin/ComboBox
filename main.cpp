#include "combobox.h"

#include <QApplication>

int main(int argv, char** argc)
{
    QApplication app(argv, argc);

    const int max_width = 500;
    const QString black("black ");
    const QString white("white ");

    ComboBox combo;
    combo.setFont(QFont("Arial", 16));
    combo.setFixedSize(max_width, 50);
    combo.setPlaceholderText("On which side are you?");

    for (int i = 1; i < 31; ++i)
    {
        QString text;
        for (int j = 0; j < i; ++j)
        {
            text += (j%2) ? white : black;
        }
        text.remove(text.length()-1, 1);

        combo.addItem(text);
    }

    combo.show();

    return app.exec();
}
