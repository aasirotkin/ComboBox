#include "combobox.h"

#include <QApplication>

int main(int argv, char** argc)
{
    QApplication app(argv, argc);

    const int max_width = 500;

    ComboBox combo;

    combo.setWordWrap(true);
    combo.setFont(QFont("Arial", 14));
    combo.setFixedSize(max_width, 50);
    combo.setMaxVisibleItems(20);
    combo.setPlaceholderText("Do you like colors?");
    const QStringList& colors = QColor::colorNames();

    // Test with numbers, it shows what would be if the word is longer
    // than combobox width and setWordWrap is enabled
//    QString text;
//    for (int i = 0; i < 200; ++i)
//    {
//        if (i > 0 && i%30 == 0)
//        {
//            text += QString(" ");
//        }
//        text += QString::number(i);
//        combo.addItem(text);
//    }

    // Test with color names, it show what would be with common usage
    for (int i = 1; i < colors.count(); ++i)
    {
        QString text;
        for (int j = i - 1; j > -1; --j)
        {
            text += QString("%1 ").arg(colors.at(j));
        }
        text.remove(text.length()-1, 1);

        combo.addItem(text);
    }

    combo.show();

    return app.exec();
}
